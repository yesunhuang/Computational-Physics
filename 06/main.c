#include "GuassF.h"

void main() 
{
	//��������
	int seed = Seed(), N = 10000, n = 0;
	n = GRandNToDat(seed, N, "gData.dat");
	printf("seed=%d,total=%d", seed, n);
}