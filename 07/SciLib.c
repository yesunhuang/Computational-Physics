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
	//��ֵ�ж�
	if (key<arr[start])
	{
		return start;
	}
	if (key>arr[end])
	{
		return end+1;
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


