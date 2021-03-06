#include "Fibonacci.h"

int Fibonacci(int* cache, int n, int q, int p)
{
	//防溢出处理
    long long I_n, I_nq, I_np, m=M_16807;
	I_np = cache[RecurrentIndex(max(p, q), n - p)];
	I_nq = cache[RecurrentIndex(max(p, q), n - q)];
	//计算I_n
	I_n = (I_np OTimes I_nq)%m;
	I_n = (I_n>=0?I_n:-I_n);
	return (int)I_n;
}

int FibRandNToDat(int seed, double* range, int N, char* name, int p, int q)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//打印标头
	fprintf(fp, "x\ty\t\n");
	int* cache,cacheI=seed;
	double M = M_16807, lRange;
	//防溢出处理
	lRange = range[1] - range[0];
	if ((lRange) > (M) || ((range[1] - range[0]) <= 0))
	{
		return 0;
	}
	double scale = M / lRange;
	int i = 0,z;
	//生成缓存数组
	cache = (int*)malloc(max(p, q) * sizeof(int));
	//计算初始缓存
	for (i = 0; i < max(p, q); i++)
	{
		cacheI = Shrage(cacheI);
		cache[i] = cacheI;
	}
	//最初的缓存不算入生成数组内,这里用了个简洁的技巧
	for (i = 0; i < N; i++)
	{
		z = Fibonacci(cache, i, q, p);
		fprintf(fp, "%.9e\t", range[0] + ((double)z / scale));
		cache[RecurrentIndex(max(q, p), i)] = z;
		z = Fibonacci(cache, i+1, q, p);
		fprintf(fp, "%.9e\n", range[0] + ((double)z / scale));
	}
	free(cache);
	fclose(fp);
	return 1;
}

double ReadAndCalScale(char* name, int N)
{
	FILE* fp;
	if ((fp = fopen(name, "r")) == NULL)
	{
		return 0;
		exit(0);
	}
	char label1[20], label2[20];
	//读取标签
	fscanf(fp, "%s %s", &label1, &label2);
	int i = 0,count=0; double x = 0, y = 0, z=0;
	//读取与记录点
	//初始读入
	fscanf(fp, "%lf %lf", &x, &y);
	for (i = 1; i < N; i++)
	{
		fscanf(fp, "%lf %lf", &y, &z);
		//记录符合条件的点
		if ((y>z) && (z>x))
		{
			count++;
		}
		x = y;
	}
	fclose(fp);
	return ((double)count / (double)(N-2));
}
