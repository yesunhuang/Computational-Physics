#include "GuassF.h"

int GRandNToDat(int seed, int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//定义迭代量
	double M = M_16807,nXi_1,nXi_2,x,Con=1.0/sqrt(2.0*M_PI);
	int i = 0, n = 0,xi_1 = Shrage(seed);
	int xi_2 = Shrage(xi_1);
	//生成随机数
	for ( i = 0; i < N; i++)
	{
		n++;
		xi_1 = Shrage(xi_2);
		xi_2 = Shrage(xi_1);
		nXi_1 = (double)xi_1 / M;
		nXi_2 = (double)xi_2 / M;
		//求反函数
		x = ArcFun(LorentzF, nXi_1, NULL, G_Atol);
		if ((nXi_2*0.93/(1+pow(x,4.0)))>(Con*exp(-x*x/2.0)))
		{
			i--;
			continue;
		}
		//打印
		fprintf(fp, "%.9e\n", x);
	}
	
	fclose(fp);
	return n;
}

double LorentzF(double x)
{
	double f, cache = sqrt(2) * x;
	f = log(x * x + cache + 1) - log(x * x - cache + 1);
	f += 2 * (atan(cache + 1) + atan(cache - 1));
	f = f / (4.0 * M_PI) + 0.5;
	return f;
}
