#include <stdio.h>
#include <math.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {									//다항식 구조체 타입 선언
	int degree;										//다항식의 차수
	float coef[MAX_DEGREE];							//다항식의 계수
}polynomial;

//C = A+B여기서 A와 B는 다항식이다.

polynomial poly_add1(polynomial A, polynomial B) // 두개의 다항식을 더해 새로운 다항식을 만드는 함수
{
	polynomial C;									//결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;				//배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);				//결과 다항식 차수 둘의 차수 비교후 큰 차수가 C의 차수가됨

	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b) {					//A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {			//A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {										//B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}

	
	}

	return C;

}

void eval(polynomial A, int n)
{
	int i = 0;

	int Poly = 0;

	for (i = 0; i < A.degree+1; i++)
	{
		Poly += (A.coef[i] * pow(n, A.degree - i)); // 미지수가 n일때 다항식의 계산을 하는법
	}

	printf("다항수에 미지수 %d를 대입한 결과 = %d\n",n ,Poly);
}
 

void delete(polynomial *A) //배열 삭제 함수
{
	int i,j;
	int item;

	for (i = 0; i < A->degree; i++)
	{
		item = A->coef[i];
		if (item == 0)
		{
			for (j = i; j < (A->degree); j++)
				A->coef[j] = A->coef[j + 1];
		}
	}	
}

polynomial eraseMaxdegree(polynomial p)  //최고차항 계수 없애고 항 내리기
{
	int i, k = 0;

	printf("다항식의 최대 차수 = %d\n", p.degree);

	for (i = 0; i < p.degree + 1; i++)
		printf("%.0lf ", p.coef[i]);

	printf("\n");


	polynomial result = p;

	result.coef[0] = 0;
	while (result.coef[k] == 0) {
		k++;
	}

	for (i = 0; i<result.degree; i++) {
		result.coef[i] = result.coef[k + i];
	}
	result.degree -= k;

	/*
	result.coef[0] = 0;          // 최고차항 계수 0으로 만들어서 삭제

	for (i = 0; i < result.degree + 1; i++) //
	{
	if (result.coef[i] == 0)
	{
	result.degree--;
	continue;
	}
	else if (result.coef[i] != 0)
	break;

	printf("%.0lf ", result.coef[i]);
	}

	printf("\n");

	delete(&result);    //계수가 0인 항 없애기

	*/
	printf("다항식의 최대 차수 = %d\n", result.degree);
	for (i = 0; i < result.degree + 1; i++)
		printf("%.0lf ", result.coef[i]);


	return result;

}

	
	
	

//주함수

int main()
{
	char C;

	int n;

	polynomial a = { 5,{3,6,0,0,0,10} };

	polynomial b = { 4,{7,0,5,0,1} };

	polynomial c;

	polynomial p = { 5,{10,0,0,0,6,1} };
	
	c = poly_add1(a, b);

	scanf("%d", &n);

	eval(p, n);

	printf("\n");

	eraseMaxdegree(a);

	printf("\n");

	eraseMaxdegree(b);

	printf("\n");

	eraseMaxdegree(p);
	
	return 0;
}