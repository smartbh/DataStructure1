#include <stdio.h>
#include <math.h>


typedef struct student {
	int id;
	double eng;
	double math;
}student;

double EngAvg(student *a)
{
	int i;
	int sum = 0;

	for (i = 0; i < 10; i++)
		sum += a[i].eng;

	return sum / 10;
}

double MathAvg(student *a)
{
	int i;
	int sum = 0;

	for (i = 0; i < 10; i++)
		sum += a[i].math;

	return sum / 10;
}
//���� �ְ��� �Լ�
void EngMaxscore(student *a) {
	int i;
	double Max = 0;
	int id;

	for (i = 0; i < 10; i++) {

		if (a[i].eng > Max)
		{
			Max = a[i].eng;
			id = a[i].id;
		}
	}

	printf("���� �ְ� ������ %.2lf �й��� %d \n", Max, id);

}
//���� �ְ��� �Լ�
void MathMaxscore(student *a) {
	int i;
	double Max = 0;
	int id;

	student temp;

	for (i = 0; i < 10; i++)
		if (a[i].math > Max)
		{
			Max = a[i].math;
			id = a[i].id;
		}

	printf("���� �ְ� ������ %.2lf �й��� %d \n", Max, id);

}

//���� ǥ������ ���ϱ�

double Engpyojun(student *a) {
	int i;
	int avg = 0;
	double square, stdDev = 0.0;

	for (i = 0; i < 10; i++)
		avg += a[i].eng;

	avg = avg / 10; // ���� ���� ���

	for (i = 0; i<10; i++)
	{
		
		square = (a[i].eng - avg) * (a[i].eng - avg);
		stdDev += (double)(square) / 10;
	}
	stdDev = sqrt(stdDev);

	return stdDev;
}

//���� ǥ������ ���ϱ�

double Mathpyojun(student *a) {
	int i;
	int avg = 0;
	double square, stdDev = 0.0;

	for (i = 0; i < 10; i++)
		avg += a[i].math;

	avg = avg / 10; // ���� ���� ���

	for (i = 0; i<10; i++)
	{

		square = (a[i].math - avg) * (a[i].math - avg);
		stdDev += (double)(square) / 10;
	}
	stdDev = sqrt(stdDev);

	return stdDev;
}


//���� �ְ���, �й� ���ϱ�
void TotalScore(student *a)
{
	int i , id;
	int id_array[10];
	double  Maxscore = 0;
	double totalscore[10];

	for (i = 0; i < 10; i++) //������ ���ؼ� �迭�� ����
	{
		totalscore[i] = a[i].eng + a[i].math; //����� ���� ���� ��ģ ����
		id_array[i] = a[i].id; //�� ������ �л� �й�
	}


	for (i = 0; i < 9; i++) //�������� ���ؼ� �ִ밪 ã��
	{
		if (totalscore[i] > Maxscore)
		{
			Maxscore = totalscore[i]; //�ִ밪
			id = id_array[i]; //�ִ밪�� �й�
		}
	}

	printf("���� �ְ��� �л��� �й��� ������ : %d, %.2lf\n", id, Maxscore);
}

//�й��Է����� ã��
int search(int n, student *a) {
	int i;
	int rank = 10;
	
	for (i = 0; i < 10; i++)
	{
		if (n == a[i].id)
		{
			printf("%d �й� �л��� ", n);
			printf("���� : %.2lf ",a[i].math);
			printf("���� : %.2lf ", a[i].eng);
			printf("���� : %.2lf\n", a[i].math+a[i].eng );
			return 0;
		}

	}

	
	printf("�й��� �ٽ� �Է�\n");
	return 1;
}

void main() {

	int student_num;

	student student[10] = { { 1234, 78, 87 },{ 1235,65,55},{1365,88,95},
							{2546,45,56},{3124,58,88},{1976,71,54},
							{1657,32,55},{2547,90,43},{2456,66,78},{1765,54,99} }; //�л� 10���� ������ ����

	printf("������ ��� ������ : %.2lf\n",EngAvg(student));

	printf(" \n");

	printf("������ ��� ������ : %.2lf\n", MathAvg(student));

	printf(" \n");

	EngMaxscore(student);

	printf(" \n");

	MathMaxscore(student);

	printf(" \n");

	printf("������� ǥ�������� : %.2lf\n", Engpyojun(student));

	printf(" \n");

	printf("���м����� ǥ�������� : %.2lf\n", Mathpyojun(student));

	printf(" \n");

	TotalScore(student);

	printf(" \n");

	do
	{
		printf("�л��� �й��� �Է��ϼ��� : ");
		scanf("%d", &student_num);
	} while (search(student_num, student));
}
