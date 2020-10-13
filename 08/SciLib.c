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
	//开始二分
	while (mid>start)
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
	return mid;
	
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

double* MonteInt(double (*f)(double* x_vec),int dim,double** range,int (*InArea)(double* x_vec),int N,int seed)
{
	//创建缓存
	int* z_vec=(int*)malloc(dim*sizeof(int));
	double* x_vec=(double*)malloc(dim*sizeof(double));
	double* result=(double*)malloc(2*sizeof(double));
	double* lrange=(double*)malloc(dim*sizeof(double));
	double M = M_16807,sum=0,V=1;
	
	//初始化随机数
	z_vec[dim-1]=Shrage(seed);
	int i,j,count=0;
	//初始化域
	for ( i = 0; i <dim; i++)
	{
		lrange[i]=range[i][1]-range[i][0];
		V*=lrange[i];
	}
	
	for (i = 0; i < N; i++)
	{
		count++;
		//生成需要的随机数
		z_vec[0]=Shrage(z_vec[dim-1]);
		for (j = 1; j < dim; j++)
		{
			z_vec[j]=Shrage(z_vec[j-1]);
		}
		//生成坐标点
		for (j = 0; j < dim; j++)
		{
			x_vec[j]=range[j][0]+(double)z_vec[j]/M*lrange[j];
		}
		//舍选与累加
		if (InArea(x_vec)==1)
		{
			sum+=f(x_vec);
		}
		else
		{
			i--;
		}
	}
	//计算效率
	result[1]=(double)N/(double)count;
	//计算积分结果(要考虑有效体积)
	result[0]=sum/(double)count;
	free(x_vec);
	free(z_vec);
	free(lrange);
	return result;
}


