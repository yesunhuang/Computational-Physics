#include "DEFun.h"

int RFunToDat(int seed, char* name, int N)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	fprintf(fp, "x\n");
	//定义迭代量
	int i,z;
	double x,xi,m = M_16807;
	z = Shrage(seed);
	//迭代产生
	for ( i = 0; i < N; i++)
	{
		xi = (double)z / m;
		x = sin(M_PI * (xi - 0.5));
		fprintf(fp,"%.9e\n", x);
		z = Shrage(z);
	}
	fclose(fp);
	return 1;
}

int LFunToDat(int seed,double m, char* name, int N)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	fprintf(fp, "x\n");
	//定义迭代量
	int i, z;
	double x, xi, M = M_16807;
	z = Shrage(seed);
	//迭代产生
	for (i = 0; i < N; i++)
	{
		xi = (double)z / M;
		x =m* tan(M_PI * (xi - 0.5));
		fprintf(fp, "%.9e\n", x);
		z = Shrage(z);
	}
	fclose(fp);
	return 1;
}
