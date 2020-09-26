#include "Fibonacci.h"

int Fibonacci(int* cache, int n, int q, int p)
{
	//���������
    long long I_n, I_nq, I_np, m=M_16807;
	I_np = cache[RecurrentIndex(max(p, q), n - p)];
	I_nq = cache[RecurrentIndex(max(p, q), n - q)];
	//����I_n
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
	//��ӡ��ͷ
	fprintf(fp, "x\ty\t\n");
	int* cache,cacheI=seed;
	double M = M_16807, lRange;
	//���������
	lRange = range[1] - range[0];
	if ((lRange) > (M) || ((range[1] - range[0]) <= 0))
	{
		return 0;
	}
	double scale = M / lRange;
	int i = 0,z;
	//���ɻ�������
	cache = (int*)malloc(max(p, q) * sizeof(int));
	//�����ʼ����
	for (i = 0; i < max(p, q); i++)
	{
		cacheI = Shrage(cacheI);
		cache[i] = cacheI;
	}
	//����Ļ��治��������������,�������˸����ļ���
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
	//��ȡ��ǩ
	fscanf(fp, "%s %s", &label1, &label2);
	int i = 0,count=0; double x = 0, y = 0, z=0;
	//��ȡ���¼��
	//��ʼ����
	fscanf(fp, "%lf %lf", &x, &y);
	for (i = 1; i < N; i++)
	{
		fscanf(fp, "%lf %lf", &y, &z);
		//��¼���������ĵ�
		if ((y>z) && (z>x))
		{
			count++;
		}
		x = y;
	}
	fclose(fp);
	return ((double)count / (double)(N-2));
}