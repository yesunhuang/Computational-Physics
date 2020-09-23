#include "Schrage16807.h"

void main() {
	//Êä³ö¼ÆËãÓÃ
	int seed = Seed();
	/*
	printf("seed = %d \n",seed);
	int firstRandNum = Shrage(seed);
	printf("First random number = %d \n", firstRandNum);*/
	//N,start,end
	int N,i=0;
	double range[2], * randOut;
	scanf("%d %lf %lf", &N, &range[0], &range[1]);
	/*randOut = RandN(seed, range, N);
	for ( i = 0; i < N; i++)
	{
		printf("%.9e ", randOut[i]);
	}
	printf("\n");*/
	char name[30];
	scanf("%s", &name);
	RandNToDat(seed, range, N, name);
	int k=0;
	scanf("%d",&k);
	printf("%.9e",ReadAndCalAvg(name,k,N));
}