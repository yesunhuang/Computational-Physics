#include "Marsaglia.h"

int MRandNToDat(int seed,  int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//��ӡ��ͷ
	fprintf(fp, "x\ty\n");
	int i,u,v;
	double x, y,r, nU,nV, m = M_16807;
	u = Shrage(seed);
	v = Shrage(u);
	//�����������������
	for ( i = 0; i < N; i++)
	{
		u = Shrage(v);
		v = Shrage(u);
		//�黯
		nU = -1+2*(double)u / m;
		nV = -1+2*(double)v / m;
		r = sqrt(pow(nU,2.0) + pow(nV, 2.0));
		if (r > 1)
		{
			i--;
			continue;
		}
		//����(x,y)��ֵ
		x = 2 * nU * sqrt(1 - pow(r, 2.0));
		y = 2 * nV * sqrt(1 - pow(r, 2.0));
		fprintf(fp, "%.9e\t%.9e\n", x, y);
	}
	fclose(fp);
	return 1;
}


