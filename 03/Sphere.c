#include "Sphere.h"

int SRandNToDat(int seed, double rho, int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//打印表头
	fprintf(fp, "x\ty\tz\n");
	int i,xi_1,xi_2;
	double x, y, z, nXi_1,nXi_2, m = M_16807;
	xi_1 = Shrage(seed);
	xi_2 = Shrage(xi_1);
	//迭代产生球面随机数
	for ( i = 0; i < N; i++)
	{
		//归化
		nXi_1 = (double)xi_1 / m;
		nXi_2 = (double)xi_2 / m;
		//计算(x,y,z)的值
		x = 2.0 * rho * sqrt(nXi_2 - pow(nXi_2, 2.0)) * cos(2.0 * M_PI * nXi_1);
		y = 2.0 * rho * sqrt(nXi_2 - pow(nXi_2, 2.0)) * sin(2.0 * M_PI * nXi_1);
		z = rho * (2.0 * nXi_2 - 1.0);
		fprintf(fp, "%.9e\t%.9e\t%.9e\n", x, y, z);
		xi_1 = Shrage(xi_2);
		xi_2 = Shrage(xi_1);
	}
	fclose(fp);
	return 1;
}

int NSRandNToDat(int seed, double rho, int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//打印表头
	fprintf(fp, "x\ty\tz\n");
	int i, xi_1, xi_2,xi_3;
	double x, y, z, nXi_1, nXi_2,nXi_3, r,m = M_16807;
	//迭代产生球面随机数
	xi_1 = Shrage(seed);
	xi_2 = Shrage(xi_1);
	xi_3 = Shrage(xi_2);
	for (i = 0; i < N; i++)
	{
		xi_1 = Shrage(xi_3);
		xi_2 = Shrage(xi_1);
		xi_3 = Shrage(xi_2);
		//归化
		nXi_1 =-1.0+ 2.0*(double)xi_1 / m;
		nXi_2 =-1.0+ 2.0*(double)xi_2 / m;
		nXi_3 =-1.0+ 2.0*(double)xi_3 / m;
		//求半径
		r = sqrt(pow(nXi_1, 2.0) + pow(nXi_2, 2.0) + pow(nXi_3, 2.0));
		if (r>1.0)
		{
			i--;
			continue;
		}
		//计算(x,y,z)的值
		x = rho / r * nXi_1;
		y = rho / r * nXi_2;
		z = rho / r * nXi_3;
		fprintf(fp, "%.9e\t%.9e\t%.9e\n", x, y, z);
	}
	fclose(fp);
	return 1;
}
