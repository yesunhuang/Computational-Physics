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

int* RandN(int seed, int* range, int N)
{
	unsigned int M = M_16807,lRange,rRange;
	M += 1;
	//���������
	if (range[0]<=0)
	{
		lRange = -range[0];
		rRange = range[1];
		lRange =lRange + rRange +1;
	}
	else
	{
		lRange = range[1] - range[0] + 1;
	}
	//������
	int z = seed;
	if ((lRange)>(M)||((range[1] - range[0])<=0))
	{
		return NULL;
	}
	//���ɶ�̬����
	int* randArray = (int*)malloc(N * sizeof(int));
	//��������
	unsigned int scale = M/lRange;
	int i = 0;
	for ( i = 0; i < N; i++)
	{
		z = Shrage(z);
		randArray[i] = range[0]+ (int)(z/scale);
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
	info->tm_year -= 100;
	//��������
	seed = info->tm_year + 70 * (info->tm_min + 12 * (info->tm_mday\
		+ 31 * (info->tm_hour + 23 * (info->tm_min + 59 * (info->tm_sec)))));
	return seed;
}

int RandNToDat(int seed, int* range, int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	fprintf(fp, "x\ty\t\n");
	unsigned int M = M_16807, lRange, rRange;
	M += 1;
	//���������
	if (range[0] <= 0)
	{
		lRange = -range[0];
		rRange = range[1];
		lRange = lRange + rRange + 1;
	}
	else
	{
		lRange = range[1] - range[0] + 1;
	}
	//������
	int z = seed;
	if ((lRange) > (M) || ((range[1] - range[0]) <= 0))
	{
		return 0;
	}
	//��������
	unsigned int scale = M / lRange;
	int i = 0;
	for (i = 0; i < N; i++)
	{
		fprintf(fp,"%d\t", range[0] + (int)(z / scale));
		z = Shrage(z);
		fprintf(fp, "%d\n", range[0] + (int)(z / scale));
	}
	fclose(fp);
	return 1;
}

