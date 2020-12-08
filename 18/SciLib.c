#include "SciLib.h"

int Factorial(int n)
{
	//�ݹ鷨
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
	//��������
	return Factorial(n)/Factorial(n-k);
}

int Combin(int n,int k)
{
	//��������
	return Permu(n,k)/Factorial(k);
}

int Schrage(int seed)
{
	//���󷵻�-1
	if (seed<0)
	{
		return -1;
	}
	//����Schrage
	int z = A_16807 * (seed % Q_16807) - R_16807 * (seed / Q_16807);
	//�ж�����
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
	//���������
	lRange = range[1] - range[0];
	//������
	int z = seed;
	if ((lRange)>(M)||((range[1] - range[0])<=0))
	{
		return NULL;
	}
	//���ɶ�̬����
	double* randArray = (double*)malloc(N * sizeof(double));
	//��������
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
	//��ȡʱ��
	time(&rawtime);
	//ת��Ϊ��ǰʱ��ʱ��
	info = localtime(&rawtime);
	info->tm_year = info->tm_year % 100;
	//��������
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
	//���������
	lRange = range[1] - range[0];
	//������
	int z = seed;
	if ((lRange) > (M) || ((range[1] - range[0]) <= 0))
	{
		return 0;
	}
	//��������
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
	//��ȡ��ǩ
	fscanf(fp,"%s %s",&label1,&label2);
	int i=0; double x=0,y=0,avrg=0;
	//�ۼ�
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
	//��ȡ��ǩ
	fscanf(fp, "%s %s", &label1, &label2);
	double avgX1=0, avgX2=0, avgXX=0,x=0,y=0;
	//������������
	double* randArray = (double*)malloc(l * sizeof(double));
	//Ԥ����
	int i= 0;
	for ( i = 0; i < l; i++)
	{
		fscanf(fp, "%lf %lf", &x, &y);
		randArray[i] = x;
		avgX1 += x; avgX2 += pow(x, 2);
	}
	//����avg x_n*x_n-l
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
	//�򵥵ļ���ѧ
	return rawIndex >= 0 ? rawIndex % (length) : length + (rawIndex % length);
}

double ArcFun(double(*f)(double x), double fx,double* range, double atol)
{
	double start=-2.0, end=2.0,mid=0.0;
	int i = 0;
	if (range==NULL)
	{
		//�����½�
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
	//��ʼ����
	while (fabs(f(mid)-fx)>atol)
	{
		//���Ϸ���ֵ�ж�(��Է���������)
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
	//��ֵ�ж�
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
	
	//��ʼ����
	while (end>start+1)
	{
		//C������ȡ����
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
	//����λ��ֵ
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
	//���������
	double M = M_16807,xi,x;
	//������
	int seed=Seed();
	int i = 0,z=seed;
	//��ӡ���Ӻͱ�ͷ
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		z=Schrage(z);
		xi=(double)z/M;
		//�㷴����
		x=Arcf(xi);
		fprintf(fp,"%.9e\n",x);
	}
	fclose(fp);
	return 1;
}

double* ConDirectSam(double (*Arcf)(double xi),int N,int seed)
{
	double* result=(double*)malloc(N*sizeof(double));
	//���������
	double M = M_16807,xi,x;
	//������
	int i = 0,z=seed;
	for (i = 0; i < N; i++)
	{
		z=Schrage(z);
		xi=(double)z/M;
		//�㷴����
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
	//���������
	double M = M_16807,xi;
	//������
	int seed=Seed();
	int i = 0,z=seed,x;
	//��ӡ���Ӻͱ�ͷ
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		z=Schrage(z);
		xi=(double)z/M;
		//�������
		x=BinarySearch(SigmaP,xi,Num);
		fprintf(fp,"%d\n",x);
	}
	fclose(fp);
	return 1;
}

int* DisDirectSam(double* SigmaP,int Num,int N,int seed)
{
	int* result=(int*)malloc(N*sizeof(int));
	//���������
	double M = M_16807,xi;
	//������
	int i = 0,z=seed,x;
	for (i = 0; i < N; i++)
	{
		z=Schrage(z);
		xi=(double)z/M;
		//�������
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
	//���������
	double M = M_16807,xi_1,xi_2,x;
	//������
	int seed=Seed();
	int i = 0,z1=seed,count=0;
	int z2=Schrage(z1);
	//��ӡ���Ӻͱ�ͷ
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		count++;
		//�������
		z1=Schrage(z2);
		z2=Schrage(z1);
		xi_1=(double)z1/M;
		xi_2=(double)z2/M;
		//�������
		x=Arcf(xi_1);
		//�ж��Ƿ�Ϸ�
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
	//���������
	double M = M_16807,xi_1,xi_2,x;
	//������
	int i = 0,z1=seed,count=0;
	int z2=Schrage(z1);
	for (i = 0; i < N; i++)
	{
		count++;
		//�������
		z1=Schrage(z2);
		z2=Schrage(z1);
		xi_1=(double)z1/M;
		xi_2=(double)z2/M;
		//�������
		x=Arcf(xi_1);
		//�ж��Ƿ�Ϸ�
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
	//��������
	int* z_vec=(int*)malloc(dim*sizeof(int));
	double* x_vec=(double*)malloc(dim*sizeof(double));
	double* result=(double*)malloc(2*sizeof(double));
	double* lrange=(double*)malloc(dim*sizeof(double));
	double M = M_16807,sum=0,V=1;
	
	//��ʼ�������
	z_vec[dim-1]=Schrage(seed);
	int i,j,count=0;
	//��ʼ����
	for ( i = 0; i <dim; i++)
	{
		lrange[i]=range[i][1]-range[i][0];
		V*=lrange[i];
	}
	
	for (i = 0; i < N; i++)
	{
		count++;
		//������Ҫ�������
		z_vec[0]=Schrage(z_vec[dim-1]);
		for (j = 1; j < dim; j++)
		{
			z_vec[j]=Schrage(z_vec[j-1]);
		}
		//���������
		for (j = 0; j < dim; j++)
		{
			x_vec[j]=range[j][0]+(double)z_vec[j]/M*lrange[j];
		}
		//��ѡ���ۼ�
		if (InArea(x_vec)==1)
		{
			sum+=f(x_vec);
		}
		else
		{
			i--;
		}
	}
	//����Ч��
	result[1]=(double)N/(double)count;
	//������ֽ��(Ҫ������Ч���)
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
	//�������
	double* result=(double*)malloc(2*sizeof(double));
	result[0]=0;
	//����������
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
	//��ƽ��
	result[0]=result[0]/(double)N;
	result[1]=(double)totalTrans/(double)N;
	return result;
}

void quickSort(double *arr,int left,int right)
{
    if(left < right)
	{
        //ȡ��׼��
		double key = arr[left];
		int low = left, high = right;
        //��׼��������
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
	//����Ԫ��
	for ( i = 0; i < N; i++)
	{
		z=Schrage(z);
		//�����������
		index=i+(int)((double)z/M_16807*(double)(N-i));
		temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
	}
	
}
