#include "Schrage16807.h"

void main() {
	//²âÊÔÓÃ
	int seed = Seed();
	printf("seed = %d \n",seed);
	int firstRandNum = Shrage(seed);
	printf("First random number = %d \n", firstRandNum);
	//N,start,end
	int N, range[2],*randOut,i=0;
	scanf("%d %d %d", &N, &range[0], &range[1]);
	randOut = RandN(seed, range, N);
	for ( i = 0; i < N; i++)
	{
		printf("%d ", randOut[i]);
	}
	printf("\n");
	char name[30];
	scanf("%s", &name);
	RandNToDat(seed, range, N, name);
}