#include "Sphere.h"

void main()
{
	int seed=Seed(), N = 10000;
	double rho = 10.0;
	//正常方法
	SRandNToDat(seed, rho, N, "sPlot.dat");
	//Naive方法
	NSRandNToDat(seed, rho, N, "nSPlot.dat");
	printf("%d", seed);
}