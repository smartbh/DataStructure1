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
//영어 최고점 함수
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

	printf("영어 최고 점수는 %.2lf 학번은 %d \n", Max, id);

}
//수학 최고점 함수
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

	printf("수학 최고 점수는 %.2lf 학번은 %d \n", Max, id);

}

//영어 표준편차 구하기

double Engpyojun(student *a) {
	int i;
	int avg = 0;
	double square, stdDev = 0.0;

	for (i = 0; i < 10; i++)
		avg += a[i].eng;

	avg = avg / 10; // 영어 성적 평균

	for (i = 0; i<10; i++)
	{
		
		square = (a[i].eng - avg) * (a[i].eng - avg);
		stdDev += (double)(square) / 10;
	}
	stdDev = sqrt(stdDev);

	return stdDev;
}

//수학 표준편차 구하기

double Mathpyojun(student *a) {
	int i;
	int avg = 0;
	double square, stdDev = 0.0;

	for (i = 0; i < 10; i++)
		avg += a[i].math;

	avg = avg / 10; // 수학 성적 평균

	for (i = 0; i<10; i++)
	{

		square = (a[i].math - avg) * (a[i].math - avg);
		stdDev += (double)(square) / 10;
	}
	stdDev = sqrt(stdDev);

	return stdDev;
}


//총점 최고점, 학번 구하기
void TotalScore(student *a)
{
	int i , id;
	int id_array[10];
	double  Maxscore = 0;
	double totalscore[10];

	for (i = 0; i < 10; i++) //총점을 구해서 배열로 저장
	{
		totalscore[i] = a[i].eng + a[i].math; //영어와 수학 점수 합친 총점
		id_array[i] = a[i].id; //그 총점의 학생 학번
	}


	for (i = 0; i < 9; i++) //총점끼리 더해서 최대값 찾기
	{
		if (totalscore[i] > Maxscore)
		{
			Maxscore = totalscore[i]; //최대값
			id = id_array[i]; //최대값의 학번
		}
	}

	printf("총점 최고점 학생의 학번과 점수는 : %d, %.2lf\n", id, Maxscore);
}

//학번입력으로 찾기
int search(int n, student *a) {
	int i;
	int rank = 10;
	
	for (i = 0; i < 10; i++)
	{
		if (n == a[i].id)
		{
			printf("%d 학번 학생의 ", n);
			printf("수학 : %.2lf ",a[i].math);
			printf("영어 : %.2lf ", a[i].eng);
			printf("총점 : %.2lf\n", a[i].math+a[i].eng );
			return 0;
		}

	}

	
	printf("학번을 다시 입력\n");
	return 1;
}

void main() {

	int student_num;

	student student[10] = { { 1234, 78, 87 },{ 1235,65,55},{1365,88,95},
							{2546,45,56},{3124,58,88},{1976,71,54},
							{1657,32,55},{2547,90,43},{2456,66,78},{1765,54,99} }; //학생 10명의 데이터 저장

	printf("영어의 평균 점수는 : %.2lf\n",EngAvg(student));

	printf(" \n");

	printf("수학의 평균 점수는 : %.2lf\n", MathAvg(student));

	printf(" \n");

	EngMaxscore(student);

	printf(" \n");

	MathMaxscore(student);

	printf(" \n");

	printf("영어성적의 표준편차는 : %.2lf\n", Engpyojun(student));

	printf(" \n");

	printf("수학성적의 표준편차는 : %.2lf\n", Mathpyojun(student));

	printf(" \n");

	TotalScore(student);

	printf(" \n");

	do
	{
		printf("학생의 학번을 입력하세요 : ");
		scanf("%d", &student_num);
	} while (search(student_num, student));
}
