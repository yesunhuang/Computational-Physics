#include "DEFun.h"

void main()
{
	int N = 10000, seed = Seed();
	double m = 1.0;
	//������ļ�
	RFunToDat(seed, "rData.dat", N);
	LFunToDat(seed,m, "lData.dat", N);
}