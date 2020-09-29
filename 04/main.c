#include "DEFun.h"

void main()
{
	int N = 10000, seed = Seed();
	double m = 1.0;
	//输出到文件
	RFunToDat(seed, "rData.dat", N);
	LFunToDat(seed,m, "lData.dat", N);
}