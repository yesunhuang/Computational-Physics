#include "Sphere.h"

void main()
{
	int seed=Seed(), N = 10000;
	double rho = 10.0;
	//��������
	SRandNToDat(seed, rho, N, "sPlot.dat");
	//Naive����
	NSRandNToDat(seed, rho, N, "nSPlot.dat");
	printf("%d", seed);
}