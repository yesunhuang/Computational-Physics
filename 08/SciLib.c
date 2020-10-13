#include "SciLib.h"

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
	//��ʼ����
	while (mid>start)
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
	//���������
	double M = M_16807,xi,x;
	//������
	int seed=Seed();
	int i = 0,z=seed;
	//��ӡ���Ӻͱ�ͷ
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		z=Shrage(z);
		xi=(double)z/M;
		//�㷴����
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
	//���������
	double M = M_16807,xi;
	//������
	int seed=Seed();
	int i = 0,z=seed,x;
	//��ӡ���Ӻͱ�ͷ
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		z=Shrage(z);
		xi=(double)z/M;
		//�������
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
	//���������
	double M = M_16807,xi_1,xi_2,x;
	//������
	int seed=Seed();
	int i = 0,z1=seed,count=0;
	int z2=Shrage(z1);
	//��ӡ���Ӻͱ�ͷ
	fprintf(fp, "x\tseed=%d\n",seed);
	for (i = 0; i < N; i++)
	{
		count++;
		//�������
		z1=Shrage(z2);
		z2=Shrage(z1);
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

double* MonteInt(double (*f)(double* x_vec),int dim,double** range,int (*InArea)(double* x_vec),int N,int seed)
{
	//��������
	int* z_vec=(int*)malloc(dim*sizeof(int));
	double* x_vec=(double*)malloc(dim*sizeof(double));
	double* result=(double*)malloc(2*sizeof(double));
	double* lrange=(double*)malloc(dim*sizeof(double));
	double M = M_16807,sum=0,V=1;
	
	//��ʼ�������
	z_vec[dim-1]=Shrage(seed);
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
		z_vec[0]=Shrage(z_vec[dim-1]);
		for (j = 1; j < dim; j++)
		{
			z_vec[j]=Shrage(z_vec[j-1]);
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
	result[0]=sum/(double)count;
	free(x_vec);
	free(z_vec);
	free(lrange);
	return result;
}

