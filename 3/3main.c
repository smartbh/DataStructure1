#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {

	int row; //행
	int col; //열
	int value; //값

}element;

typedef struct {

	element data[MAX_TERMS];

	int rows;		//행의 개수
	int cols;		//열의 개수
	int terms;		//항의 개수

}SparseMastrix;


//희소 행렬 덧셈 함수
//c = a + b

SparseMastrix sparse_matrix_add2(SparseMastrix a, SparseMastrix b)
{
	SparseMastrix c;
	int ca = 0, cb = 0, cc = 0;		//각 배열의 항목을 가리키는 인덱스


	//배열 a와 배열 b의 크기가 같은지를 확인
	if (a.rows != b.rows || a.cols != b.cols) 
	{
		fprintf(stderr, "희소행렬 크기 에러\n");
		exit(1);
	}

	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;

	while (ca < a.terms && cb < b.terms) 
	{
		//각 항목의 순차적인 번호를 계산한다.
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col;

		if (inda < indb)
		{
			//a 배열 항목이 앞에 있으면
			c.data[cc++] = a.data[ca++];
		}

		else if (inda == indb)
		{
			//a와 b가 같은 위치
			if ((a.data[ca].value + b.data[cb].value) != 0)
			{
				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}

			else
			{
				ca++;
				cb++;
			}
		}

		else
			// b배열 항목이 앞에 있음

			c.data[cc++] = b.data[cb++];
	}

	//배열 a나 b에 남아있는 항들을 배열c로 옮긴다.

	for (; ca < a.terms;)
		c.data[cc++] = a.data[ca++];

	for (; cb < b.terms;)
		c.data[cc++] = b.data[cb++];

	c.terms = cc;

	return c;
}

SparseMastrix change(SparseMastrix *m, int i, int j) //i행과 j행 변환하는 함수
{
	element temp;
	for (int t = 0; t < m->terms; t++)
	{
		if (m->data[t].row == i)			//입력받은 i행이 m.data[t].row 와 같으면 i와 j 변환
			m->data[t].row = j;

		else if (m->data[t].row == j)	//입력받은 j행이 m.data[t].row 와 같으면 j와 i 변환
			m->data[t].row = i;

		for(int j = 0;  j < m->terms; j++) //행 위주로 배열 재 정리? 왜안돼지 (1,1,5) (2,1,9) -> temp,a,b 세개 변수 사용 치환하듯
			for (int t = 1; t < m->terms; t++)
				if (m->data[t].row < m->data[j].row)
				{
					temp = m->data[j];
					m->data[j] = m->data[t];
					m->data[t] = temp;
				}
	}

}

int main() {
	int i, j;

	SparseMastrix m1 = { { { 1,1,5 },{ 2,2,9 } },3,3,2 };
	
	SparseMastrix m2 = { { { 0,0,5 },{ 2,2,9 } },3,3,2 };

	SparseMastrix m3;

	m3 = sparse_matrix_add2(m1, m2);


	printf("교환할 행을 입력하세요");
	
	while(1)
	{		
		scanf("%d %d", &i, &j);
		if ((i < 0 || i>3) || (j < 0 || j>3))
			printf("다시 입력하세요");
		else
			break;
	}
	printf("\n");

	printf("{{{%d,%d,%d},{%d,%d,%d}},%d,%d,%d\n", //기존 SparseMastrix m1
		m1.data[0].row, m1.data[0].col, m1.data[0].value,
		m1.data[1].row, m1.data[1].col, m1.data[1].value,
		m1.rows, m1.cols, m1.terms);

	change(&m1, i, j); //포인터로 해야 얘가 아예 데이터 부터 수정됨

	
	printf("{{{%d,%d,%d},{%d,%d,%d}},%d,%d,%d\n", //변경 SparseMastrix m1
		m1.data[0].row, m1.data[0].col, m1.data[0].value,
		m1.data[1].row, m1.data[1].col, m1.data[1].value,
		m1.rows, m1.cols, m1.terms);

	return 0;
}