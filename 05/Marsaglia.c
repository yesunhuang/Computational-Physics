#include "Marsaglia.h"

int MRandNToDat(int seed,  int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//打印表头
	fprintf(fp, "x\ty\n");
	int i,u,v;
	double x, y,r, nU,nV, m = M_16807;
	u = Shrage(seed);
	v = Shrage(u);
	//迭代产生球面随机数
	for ( i = 0; i < N; i++)
	{
		u = Shrage(v);
		v = Shrage(u);
		//归化
		nU = -1+2*(double)u / m;
		nV = -1+2*(double)v / m;
		r = sqrt(pow(nU,2.0) + pow(nV, 2.0));
		if (r > 1)
		{
			i--;
			continue;
		}
		//计算(x,y)的值
		x = 2 * nU * sqrt(1 - pow(r, 2.0));
		y = 2 * nV * sqrt(1 - pow(r, 2.0));
		fprintf(fp, "%.9e\t%.9e\n", x, y);
	}
	fclose(fp);
	return 1;
}


