#include "Marsaglia.h"

void main()
{
	int N = 10000, seed = Seed();
	MRandNToDat(seed, N, "mData.dat");
	printf("seed=%d", seed);
}