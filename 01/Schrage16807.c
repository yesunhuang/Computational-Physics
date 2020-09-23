#include "Schrage16807.h"

int Shrage(int seed)
{
	//错误返回-1
	if (seed<0)
	{
		return -1;
	}
	//计算Shrage
	int z = A_16807 * (seed % Q_16807) - R_16807 * (seed / Q_16807);
	//判断正负
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
	//防溢出处理
	lRange = range[1] - range[0];
	//迭代量
	int z = seed;
	if ((lRange)>(M)||((range[1] - range[0])<=0))
	{
		return NULL;
	}
	//生成动态数组
	double* randArray = (double*)malloc(N * sizeof(double));
	//比例因子
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
	//获取时间
	time(&rawtime);
	//转化为当前时区时间
	info = localtime(&rawtime);
	info->tm_year = info->tm_year % 100;
	//计算种子
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
	//防溢出处理
	lRange = range[1] - range[0];
	//迭代量
	int z = seed;
	if ((lRange) > (M) || ((range[1] - range[0]) <= 0))
	{
		return 0;
	}
	//比例因子
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
	return 0.0;
}

double ReadAndCalCorr(char* name, int l, int N)
{
	return 0.0;
}



