#include "SciLib.h"

int Factorial(int n)
{
	//递归法
	if (n>0)
	{
		return Factorial(n-1)*n;
	}
	else
	{
		return 1;
	}
	
	
}

int Permu(int n,int k)
{
	//求排列数
	return Factorial(n)/Factorial(n-k);
}

int Combin(int n,int k)
{
	//求排列数
	return Permu(n,k)/Factorial(k);
}

int Schrage(int seed)
{
	//错误返回-1
	if (seed<0)
	{
		return -1;
	}
	//计算Schrage
	int z = A_16807 * (seed % Q_16807) - R_16807 * (seed / Q_16807);
	//判断正负
	if (z<0)
	{
		return z + M_16807;
	}
	else
	{
		return z;
	}
}

double* RandN(int seed, double* range, int N)
{
	double M = M_16807, lRange;
	//防溢出处理
	lRange = range[1] - range[0];
	//迭代量
	int z = seed;
	if ((lRange)>(M)||((range[1] - range[0])<=0))
	{
		return NULL;
	}
	//生成动态数组
	double* randArray = (double*)malloc(N * sizeof(double));
	//比例因子
	double scale = M/lRange;
	int i = 0;
	for ( i = 0; i < N; i++)
	{
		z = Schrage(z);
		randArray[i] = range[0]+ ((double)z/scale);
	}
	return randArray;
}

int Seed()
{
	int seed;
	time_t rawtime;
	struct tm* info;
	//获取时间
	time(&rawtime);
	//转化为当前时区时间
	info = localtime(&rawtime);
	info->tm_year = info->tm_year % 100;
	//计算种子
	seed = info->tm_year + 70 * (info->tm_min + 12 * (info->tm_mday\
		+ 31 * (info->tm_hour + 23 * (info->tm_min + 59 * (info->tm_sec)))));
	return seed;
}

int RandNToDat(int seed, double* range, int N, char* name)
{
	FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
	fprintf(fp, "x\ty\t\n");
	double M = M_16807, lRange;
	//防溢出处理
	lRange = range[1] - range[0];
	//迭代量
	int z = seed;
	if ((lRange) > (M) || ((range[1] - range[0]) <= 0))
	{
		return 0;
	}
	//比例因子
	double scale = M / lRange;
	int i = 0;
	for (i = 0; i < N; i++)
	{
		fprintf(fp,"%.9e\t", range[0] + ((double)z / scale));
		z = Schrage(z);
		fprintf(fp, "%.9e\n", range[0] + ((double)z / scale));
	}
	fclose(fp);
	return 1;
}

double ReadAndCalAvg(char* name, int k, int N)
{
	FILE* fp;
	if ((fp = fopen(name, "r")) == NULL)
	{
		return 0;
		exit(0);
	}
	char label1[20],label2[20];
	//读取标签
	fscanf(fp,"%s %s",&label1,&label2);
	int i=0; double x=0,y=0,avrg=0;
	//累加
	for ( i = 0; i < N; i++)
	{
		fscanf(fp,"%lf %lf",&x,&y);
		avrg+=pow(x,(double)k);
	}
	fclose(fp);
	return avrg/N;
}

double ReadAndCalCorr(char* name, int l, int N)
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
	double avgX1=0, avgX2=0, avgXX=0,x=0,y=0;
	//创建缓存数组
	double* randArray = (double*)malloc(l * sizeof(double));
	//预读入
	int i= 0;
	for ( i = 0; i < l; i++)
	{
		fscanf(fp, "%lf %lf", &x, &y);
		randArray[i] = x;
		avgX1 += x; avgX2 += pow(x, 2);
	}
	//计算avg x_n*x_n-l
	for ( i = l; i < N; i++)
	{
		fscanf(fp, "%lf %lf", &x, &y);
		avgX1 += x; avgX2 += pow(x, 2);
		avgXX += x * randArray[RecurrentIndex(l, i - l)];
		randArray[RecurrentIndex(l, i)] = x;
	}
	free(randArray);
	return (avgXX - pow(avgX1, 2) / N) / (avgX2 - pow(avgX1, 2) / N);
}

int RecurrentIndex(int length, int rawIndex)
{
	//简单的几何学
	return rawIndex >= 0 ? rawIndex % (length) : length + (rawIndex % length);
}

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
	if (arr[start]<arr[end])
	{
		if (key<arr[start])
		{
			return start;
		}
		if (key>arr[end])
		{
			return end+1;
		}
	}
	else
	{
		if (key>arr[start])
		{
			return start;
		}
		if (key<arr[end])
		{
			return end+1;
		}
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
		z=Schrage(z);
		xi=(double)z/M;
		//算反函数
		x=Arcf(xi);
		fprintf(fp,"%.9e\n",x);
	}
	fclose(fp);
	return 1;
}

double* ConDirectSam(double (*Arcf)(double xi),int N,int seed)
{
	double* result=(double*)malloc(N*sizeof(double));
	//防溢出处理
	double M = M_16807,xi,x;
	//迭代量
	int i = 0,z=seed;
	for (i = 0; i < N; i++)
	{
		z=Schrage(z);
		xi=(double)z/M;
		//算反函数
		x=Arcf(xi);
		result[i]=x;
	}
	return result;
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
		z=Schrage(z);
		xi=(double)z/M;
		//算抽样点
		x=BinarySearch(SigmaP,xi,Num);
		fprintf(fp,"%d\n",x);
	}
	fclose(fp);
	return 1;
}

int* DisDirectSam(double* SigmaP,int Num,int N,int seed)
{
	int* result=(int*)malloc(N*sizeof(int));
	//防溢出处理
	double M = M_16807,xi;
	//迭代量
	int i = 0,z=seed,x;
	for (i = 0; i < N; i++)
	{
		z=Schrage(z);
		xi=(double)z/M;
		//算抽样点
		x=BinarySearch(SigmaP,xi,Num);
		result[i]=x;
	}
	return result;
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
	int z2=Schrage(z1);
	//打印种子和表头
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		count++;
		//算随机量
		z1=Schrage(z2);
		z2=Schrage(z1);
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

double* ComSam(double (*Arcf)(double xi_1),int (*IsLegal)(double x,double xi_2),int N,int seed)
{
	double* result=(double *)malloc((N+1)*sizeof(double));
	//防溢出处理
	double M = M_16807,xi_1,xi_2,x;
	//迭代量
	int i = 0,z1=seed,count=0;
	int z2=Schrage(z1);
	for (i = 0; i < N; i++)
	{
		count++;
		//算随机量
		z1=Schrage(z2);
		z2=Schrage(z1);
		xi_1=(double)z1/M;
		xi_2=(double)z2/M;
		//算抽样点
		x=Arcf(xi_1);
		//判断是否合法
		if (IsLegal(x,xi_2)==1)
		{
			result[i]=x;
		}
		else
		{
			i--;
		}
		
	}
	result[N]=(double)N/(double)count;
	return result;
}

double* MonteInt(double (*f)(double* x_vec),int dim,double (*range)[2],int (*InArea)(double* x_vec),int N,int seed)
{
	//创建缓存
	int* z_vec=(int*)malloc(dim*sizeof(int));
	double* x_vec=(double*)malloc(dim*sizeof(double));
	double* result=(double*)malloc(2*sizeof(double));
	double* lrange=(double*)malloc(dim*sizeof(double));
	double M = M_16807,sum=0,V=1;
	
	//初始化随机数
	z_vec[dim-1]=Schrage(seed);
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
		z_vec[0]=Schrage(z_vec[dim-1]);
		for (j = 1; j < dim; j++)
		{
			z_vec[j]=Schrage(z_vec[j-1]);
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
	result[0]=sum/(double)count*V;
	free(x_vec);
	free(z_vec);
	free(lrange);
	return result;
}

double* MetroMonteInt(double (*f)(double x),
				      double (*r)(double x_0,double x),
				      double (*arcXi)(double x_0,double xi),
				      int N,int M,int seed,
				      double x0)
{
	int z=seed;
	double M0=M_16807,xi,x=x0,x_guess,p;
	int i,totalTrans=0;
	//结果数组
	double* result=(double*)malloc(2*sizeof(double));
	result[0]=0;
	//抽样并计算
	for (i = 0; i < N+M; i++)
	{
		xi=(double)z/M0;
		z=Schrage(z);
		x_guess=arcXi(x,xi);
		z=Schrage(z);
		xi=(double)z/M0;
		p=min(1,r(x,x_guess));
		if (p>xi)
		{
			x=x_guess;
			if (i>=M)
			{
				totalTrans++;
			}
		}
		
		if (i>=M)
		{
			result[0]+=f(x);
		}
	}
	//求平均
	result[0]=result[0]/(double)N;
	result[1]=(double)totalTrans/(double)N;
	return result;
}

void quickSort(double *arr,int left,int right)
{
    if(left < right)
	{
        //取基准数
		double key = arr[left];
		int low = left, high = right;
        //标准快排流程
		while(low < high)
		{
			while(arr[high] >= key && low < high)
				high--;
			arr[low] = arr[high];
			
			while(arr[low] <= key && low < high)
				low++;
			arr[high] = arr[low];
		}
		arr[low] = key;
		
		quickSort(arr, left, low - 1);
		quickSort(arr, low + 1, right);
	}

}

void shuffle(double *arr,int N,int seed)
{
	int i,z=seed,index;
	double temp,M=M_16807;
	//遍历元素
	for ( i = 0; i < N; i++)
	{
		z=Schrage(z);
		//产生随机索引
		index=i+(int)((double)z/M_16807*(double)(N-i));
		temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
	}
	
}
