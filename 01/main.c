#include "Schrage16807.h"

void main() {
	//输出计算用
	int seed = Seed();

	/* debug测试块1
	printf("seed = %d \n",seed);
	int firstRandNum = Shrage(seed);
	printf("First random number = %d \n", firstRandNum);*/

	int N,i=0;
	double range[2] = { 0,1 };

	//double* randOut;
	//N,start,end
	//scanf("%d %lf %lf", &N, &range[0], &range[1]);
	/* debug测试块2
	randOut = RandN(seed, range, N);
	for ( i = 0; i < N; i++)
	{
		printf("%.9e ", randOut[i]);
	}
	printf("\n");*/
	//char name[30];
	/*plot 二维点产生块，debug测试块3
	scanf("%s", &name);
	RandNToDat(seed, range, N, name);
	int k=0,l=0;
	scanf("%d",&k);
	printf("%.9e",ReadAndCalAvg(name,k,N));
	scanf("%d", &l);
	printf("%.9e", ReadAndCalCorr(name, l, N));*/
	
	//二维点数据
	RandNToDat(seed, range, 10000, "data_plot.dat");


	//测试独立性与偏差
	int l[5] = { 1,6,10,15,20 }, k[5] = { 1, 2, 3, 4, 5 }, * p;
	FILE* fp;
	if ((fp = fopen("check.dat", "w")) == NULL)
	{
		exit(0);
	}
	//印表头
	fprintf(fp,"N\t");
	for (p = l; p <= &l[4]; p++)
	{
		fprintf(fp,"d=%d\t\t", *p);
	}
	for (p = k; p <= &k[4]; p++)
	{
		fprintf(fp,"k=%d\t\t", *p);
	}
	fprintf(fp, "\n");
	//自动测试多个范围
	for ( i = 1; i < 9; i++)
	{
		N = (int)pow(10, i);
		RandNToDat(seed, range,N, "data.dat");
		fprintf(fp,"%d\t",i);
		for (p = l; p <= &l[4]; p++)
		{
			fprintf(fp, "%.9e\t", ReadAndCalCorr("data.dat", *p, N));
		}
		for (p = k; p <= &k[4]; p++)
		{
			fprintf(fp, "%.9e\t", ReadAndCalAvg("data.dat", *p, N));
		}
		fprintf(fp, "\n");
		printf("complete:%d/8\n", i);
	}
	//记录种子
	fprintf(fp,"seed=%d\n", seed);
	fclose(fp);
}