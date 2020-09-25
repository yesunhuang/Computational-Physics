#include "Fibonacci.h"

int main()
{
	int seed = Seed();
	int p = 0, q = 0, N = 0,i=0;
	double range[2] = {0,1};
	////debug测试块1
	//p q N
	//scanf("%d%d%d", &p, &q, &N);
	////start end
	//scanf("%lf%lf", &range[0], &range[1]);
	//char name[20];
	////file name
	//scanf("%s", &name);
	//FibRandNToDat(seed, range, N, name, p, q);
	//double scale_F = ReadAndCalScale(name, N);
	//RandNToDat(seed, range, N, name);
	//double scale_16807 = ReadAndCalScale(name, N);
	//printf("%.9e\t%.9e", scale_F, scale_16807);
	
	//测试16807的比例
	FILE* fp;
	if ((fp = fopen("check_16807.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//打印表头
	fprintf(fp,"N\tscale\n");
	for ( i = 1; i < 8; i++)
	{
		N = (int)pow(10, i);
		RandNToDat(seed, range, N, "data_16807.dat");
		fprintf(fp, "%d\t%.9e\n", i, ReadAndCalScale("data_16807.dat", N));
	}
	//记录种子
	fprintf(fp, "seed=%d", seed);
	fclose(fp);
	printf("16807 test done!\n");

	//测试Fibonacci的比例
	if ((fp = fopen("paraCheck_F.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//打印表头
	fprintf(fp, "q\tp\tscale\n");
	double  bias_min = 100,scale,scale_s=1.0/6.0;
	int q_min = 0, p_min = 0;
	N = 10000;
	for ( q = 1; q < 101; q++)
	{
		for ( p = 1; p < 101; p++)
		{
			FibRandNToDat(seed, range, N,"data_F.dat", p, q);
			scale = ReadAndCalScale("data_F.dat", N);
			fprintf(fp, "%d\t%d\t%.9e\n", q, p, scale);
			if (fabs(scale-scale_s)<bias_min)
			{
				bias_min = fabs(scale - scale_s);
				q_min = q;
				p_min = p;
			}
		}
		printf("complete:%d/100\n", q);
	}
	//记录种子
	fprintf(fp, "seed=%d\tq_min=%d\tp_min=%d", seed,q_min,p_min);
	fclose(fp);
	printf("Fibonacci parameters test done!\n");
	
	if ((fp = fopen("check_F.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//打印表头
	fprintf(fp, "N\tscale\n");
	for (i = 1; i <8 ; i++)
	{
		N = (int)pow(10, i);
		FibRandNToDat(seed, range, N, "data_F.dat", p_min, q_min);
		fprintf(fp, "%d\t%.9e\n", i, ReadAndCalScale("data_F.dat", N));
	}
	//记录种子
	fprintf(fp, "seed=%d\tq=%d\tp=%d", seed,q_min,p_min);
	fclose(fp);
	printf("Fibonacci test done!\n");
	return 1;
}