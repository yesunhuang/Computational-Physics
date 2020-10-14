#include "SciLib.h"

double ArcFun(double(*f)(double x), double fx,double* range, double atol)
{
	double start=-2.0, end=2.0,mid=0.0;
	int i = 0;
	if (range==NULL)
	{
		//找上下界
		if (f(mid)>fx)
		{
			for ( i = 0; i < 1024; i++)
			{
				if (f(start)<fx)
				{
					end = mid;
					break;
				}
				if (f(end)<fx)
				{
					start = mid;
					break;
				}
				start *= 2;
				end *= 2;
			}
		}
		else
		{
			for (i = 0; i < 1024; i++)
			{
				if (f(start) > fx)
				{
					end = mid;
					break;
				}
				if (f(end) > fx)
				{
					start = mid;
					break;
				}
				start *= 2;
				end *= 2;
			}
		}
	}
	else
	{
		start = range[0];
		end = range[1];
	}
	if (isinf(start))
	{
		return sqrt(-1.0);
	}
	//开始二分
	while (fabs(f(mid)-fx)>atol)
	{
		//不合法求值判断(针对非连续函数)
		if ((fx < f(start) && fx < f(end)) || (fx > f(start) && fx > f(end)))
		{
			return sqrt(-1.0);
		}
		if (start>end)
		{
			return sqrt(-1.0);
		}
		if (f(start)>f(end))
		{
			if (fx>f(mid))
			{
				end = mid;
			}
			else
			{
				start = mid;
			}
		}
		else
		{
			if (fx > f(mid))
			{
				start = mid;
			}
			else
			{
				end = mid;
			}
		}
		mid = (start + end) / 2;
	}
	return mid;
	
}

int BinarySearch(double* arr,double key,double len)
{
	int start=0,end=len-1;
	int mid=(start+end)/2;
	//边值判断
	if (key<arr[start])
	{
		return start;
	}
	if (key>arr[end])
	{
		return end+1;
	}
	//开始二分
	while (end>start+1)
	{
		//C是向下取整的
		if (arr[start]>arr[end])
		{
			if (key>arr[mid])
			{
				end = mid;
			}
			else
			{
				start = mid;
			}
		}
		else
		{
			if (key > arr[mid])
			{
				start = mid;
			}
			else
			{
				end = mid;
			}
		}
		mid = (start + end) / 2;
	}
	//返回位置值
	return end;
}

int ConDirectSamToDat(double (*Arcf)(double xi),char* name,int N)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//防溢出处理
	double M = M_16807,xi,x;
	//迭代量
	int seed=Seed();
	int i = 0,z=seed;
	//打印种子和表头
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		z=Shrage(z);
		xi=(double)z/M;
		//算反函数
		x=Arcf(xi);
		fprintf(fp,"%.9e\n",x);
	}
	fclose(fp);
	return 1;
}

int DisDirectSamToDat(double* SigmaP,char* name,int Num,int N)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//防溢出处理
	double M = M_16807,xi;
	//迭代量
	int seed=Seed();
	int i = 0,z=seed,x;
	//打印种子和表头
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		z=Shrage(z);
		xi=(double)z/M;
		//算抽样点
		x=BinarySearch(SigmaP,xi,Num);
		fprintf(fp,"%d\n",x);
	}
	fclose(fp);
	return 1;
}

int CSamToDat(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),char* name,int N)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	//防溢出处理
	double M = M_16807,xi_1,xi_2,x;
	//迭代量
	int seed=Seed();
	int i = 0,z1=seed,count=0;
	int z2=Shrage(z1);
	//打印种子和表头
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		count++;
		//算随机量
		z1=Shrage(z2);
		z2=Shrage(z1);
		xi_1=(double)z1/M;
		xi_2=(double)z2/M;
		//算抽样点
		x=Arcf(xi_1);
		//判断是否合法
		if (IsLegal(x,xi_2)==1)
		{
			fprintf(fp,"%.9e\n",x);
		}
		else
		{
			i--;
		}
		
	}
	fprintf(fp,"eta=%.9e\n",(double)N/(double)count);
	fclose(fp);
	return 1;
}


