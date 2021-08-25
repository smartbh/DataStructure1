#include <stdio.h>
#include <math.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {									//���׽� ����ü Ÿ�� ����
	int degree;										//���׽��� ����
	float coef[MAX_DEGREE];							//���׽��� ���
}polynomial;

//C = A+B���⼭ A�� B�� ���׽��̴�.

polynomial poly_add1(polynomial A, polynomial B) // �ΰ��� ���׽��� ���� ���ο� ���׽��� ����� �Լ�
{
	polynomial C;									//��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;				//�迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);				//��� ���׽� ���� ���� ���� ���� ū ������ C�� ��������

	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b) {					//A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {			//A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {										//B�� > A��
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
		Poly += (A.coef[i] * pow(n, A.degree - i)); // �������� n�϶� ���׽��� ����� �ϴ¹�
	}

	printf("���׼��� ������ %d�� ������ ��� = %d\n",n ,Poly);
}
 

void delete(polynomial *A) //�迭 ���� �Լ�
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

polynomial eraseMaxdegree(polynomial p)  //�ְ����� ��� ���ְ� �� ������
{
	int i, k = 0;

	printf("���׽��� �ִ� ���� = %d\n", p.degree);

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
	result.coef[0] = 0;          // �ְ����� ��� 0���� ���� ����

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

	delete(&result);    //����� 0�� �� ���ֱ�

	*/
	printf("���׽��� �ִ� ���� = %d\n", result.degree);
	for (i = 0; i < result.degree + 1; i++)
		printf("%.0lf ", result.coef[i]);


	return result;

}

	
	
	

//���Լ�

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