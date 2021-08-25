#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {

	int row; //��
	int col; //��
	int value; //��

}element;

typedef struct {

	element data[MAX_TERMS];

	int rows;		//���� ����
	int cols;		//���� ����
	int terms;		//���� ����

}SparseMastrix;


//��� ��� ���� �Լ�
//c = a + b

SparseMastrix sparse_matrix_add2(SparseMastrix a, SparseMastrix b)
{
	SparseMastrix c;
	int ca = 0, cb = 0, cc = 0;		//�� �迭�� �׸��� ����Ű�� �ε���


	//�迭 a�� �迭 b�� ũ�Ⱑ �������� Ȯ��
	if (a.rows != b.rows || a.cols != b.cols) 
	{
		fprintf(stderr, "������ ũ�� ����\n");
		exit(1);
	}

	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;

	while (ca < a.terms && cb < b.terms) 
	{
		//�� �׸��� �������� ��ȣ�� ����Ѵ�.
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col;

		if (inda < indb)
		{
			//a �迭 �׸��� �տ� ������
			c.data[cc++] = a.data[ca++];
		}

		else if (inda == indb)
		{
			//a�� b�� ���� ��ġ
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
			// b�迭 �׸��� �տ� ����

			c.data[cc++] = b.data[cb++];
	}

	//�迭 a�� b�� �����ִ� �׵��� �迭c�� �ű��.

	for (; ca < a.terms;)
		c.data[cc++] = a.data[ca++];

	for (; cb < b.terms;)
		c.data[cc++] = b.data[cb++];

	c.terms = cc;

	return c;
}

SparseMastrix change(SparseMastrix *m, int i, int j) //i��� j�� ��ȯ�ϴ� �Լ�
{
	element temp;
	for (int t = 0; t < m->terms; t++)
	{
		if (m->data[t].row == i)			//�Է¹��� i���� m.data[t].row �� ������ i�� j ��ȯ
			m->data[t].row = j;

		else if (m->data[t].row == j)	//�Է¹��� j���� m.data[t].row �� ������ j�� i ��ȯ
			m->data[t].row = i;

		for(int j = 0;  j < m->terms; j++) //�� ���ַ� �迭 �� ����? �־ȵ��� (1,1,5) (2,1,9) -> temp,a,b ���� ���� ��� ġȯ�ϵ�
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


	printf("��ȯ�� ���� �Է��ϼ���");
	
	while(1)
	{		
		scanf("%d %d", &i, &j);
		if ((i < 0 || i>3) || (j < 0 || j>3))
			printf("�ٽ� �Է��ϼ���");
		else
			break;
	}
	printf("\n");

	printf("{{{%d,%d,%d},{%d,%d,%d}},%d,%d,%d\n", //���� SparseMastrix m1
		m1.data[0].row, m1.data[0].col, m1.data[0].value,
		m1.data[1].row, m1.data[1].col, m1.data[1].value,
		m1.rows, m1.cols, m1.terms);

	change(&m1, i, j); //�����ͷ� �ؾ� �갡 �ƿ� ������ ���� ������

	
	printf("{{{%d,%d,%d},{%d,%d,%d}},%d,%d,%d\n", //���� SparseMastrix m1
		m1.data[0].row, m1.data[0].col, m1.data[0].value,
		m1.data[1].row, m1.data[1].col, m1.data[1].value,
		m1.rows, m1.cols, m1.terms);

	return 0;
}