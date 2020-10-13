#include "Schrage16807.h"

int Shrage(int seed)
{
	//���󷵻�-1
	if (seed<0)
	{
		return -1;
	}
	//����Shrage
	int z = A_16807 * (seed % Q_16807) - R_16807 * (seed / Q_16807);
	//�ж�����
	if (z<0)
	{
		return z + M_16807;
	}
	else
	{
		return z;
	}
}

double* RandN(int seed, double* range, int N)
{
	double M = M_16807, lRange;
	//���������
	lRange = range[1] - range[0];
	//������
	int z = seed;
	if ((lRange)>(M)||((range[1] - range[0])<=0))
	{
		return NULL;
	}
	//���ɶ�̬����
	double* randArray = (double*)malloc(N * sizeof(double));
	//��������
	double scale = M/lRange;
	int i = 0;
	for ( i = 0; i < N; i++)
	{
		z = Shrage(z);
		randArray[i] = range[0]+ ((double)z/scale);
	}
	return randArray;
}

int Seed()
{
	int seed;
	time_t rawtime;
	struct tm* info;
	//��ȡʱ��
	time(&rawtime);
	//ת��Ϊ��ǰʱ��ʱ��
	info = localtime(&rawtime);
	info->tm_year = info->tm_year % 100;
	//��������
	seed = info->tm_year + 70 * (info->tm_min + 12 * (info->tm_mday\
		+ 31 * (info->tm_hour + 23 * (info->tm_min + 59 * (info->tm_sec)))));
	return seed;
}

int RandNToDat(int seed, double* range, int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	fprintf(fp, "x\ty\t\n");
	double M = M_16807, lRange;
	//���������
	lRange = range[1] - range[0];
	//������
	int z = seed;
	if ((lRange) > (M) || ((range[1] - range[0]) <= 0))
	{
		return 0;
	}
	//��������
	double scale = M / lRange;
	int i = 0;
	for (i = 0; i < N; i++)
	{
		fprintf(fp,"%.9e\t", range[0] + ((double)z / scale));
		z = Shrage(z);
		fprintf(fp, "%.9e\n", range[0] + ((double)z / scale));
	}
	fclose(fp);
	return 1;
}

double ReadAndCalAvg(char* name, int k, int N)
{
	FILE* fp;
	if ((fp = fopen(name, "r")) == NULL)
	{
		return 0;
		exit(0);
	}
	char label1[20],label2[20];
	//��ȡ��ǩ
	fscanf(fp,"%s %s",&label1,&label2);
	int i=0; double x=0,y=0,avrg=0;
	//�ۼ�
	for ( i = 0; i < N; i++)
	{
		fscanf(fp,"%lf %lf",&x,&y);
		avrg+=pow(x,(double)k);
	}
	fclose(fp);
	return avrg/N;
}

double ReadAndCalCorr(char* name, int l, int N)
{
	FILE* fp;
	if ((fp = fopen(name, "r")) == NULL)
	{
		return 0;
		exit(0);
	}
	char label1[20], label2[20];
	//��ȡ��ǩ
	fscanf(fp, "%s %s", &label1, &label2);
	double avgX1=0, avgX2=0, avgXX=0,x=0,y=0;
	//������������
	double* randArray = (double*)malloc(l * sizeof(double));
	//Ԥ����
	int i= 0;
	for ( i = 0; i < l; i++)
	{
		fscanf(fp, "%lf %lf", &x, &y);
		randArray[i] = x;
		avgX1 += x; avgX2 += pow(x, 2);
	}
	//����avg x_n*x_n-l
	for ( i = l; i < N; i++)
	{
		fscanf(fp, "%lf %lf", &x, &y);
		avgX1 += x; avgX2 += pow(x, 2);
		avgXX += x * randArray[RecurrentIndex(l, i - l)];
		randArray[RecurrentIndex(l, i)] = x;
	}
	free(randArray);
	return (avgXX - pow(avgX1, 2) / N) / (avgX2 - pow(avgX1, 2) / N);
}

int RecurrentIndex(int length, int rawIndex)
{
	//�򵥵ļ���ѧ
	return rawIndex >= 0 ? rawIndex % (length) : length + (rawIndex % length);
}



