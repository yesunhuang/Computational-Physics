#include "Stick.h"

int RWThetaToDat(int seed,char* name,int tn)
{
    FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
	fprintf(fp, "t\tu_x\t\n");
	double M = M_16807;
	//迭代量
	int i = 0,z=seed;
    double xi,ux=0;
	for (i = 0; i < tn; i++)
	{   
        fprintf(fp,"%d\t%.9e\n",i,ux);
        xi=(double)z/M_16807;
		if (xi>P_THETA)
        {
            ux+=DELTA_THETA;
        }
        else
        {
            ux-=DELTA_THETA;
        }
		z = Schrage(z);
	}
	fclose(fp);
    return 1;
}

int CalAvg(int seed,char* name,int N,int tn,int l)
{
    printf("Start Calculate avg l=%d.\n",l);
    FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"t\t<x^%d>\n",l);
	int i,j, z=seed;
    double xi,avg;
    //创建缓存数组
    double* ux=(double*)malloc(N*sizeof(double));
    //初始化
    for ( i = 0; i < N; i++)
    {
        ux[i]=0.0;
    }
    //迭代计算
    for ( i = 0; i <tn; i++)
    {
        fprintf(fp,"%d\t",i);
        avg=0.0;
        //演化与计算
        for ( j = 0; j < N; j++)
        {
            avg+=pow(ux[j],(double)l);
            z=Schrage(z);
            xi=(double)z/M_16807;
            if (xi>P_THETA)
            {
                ux[j]+=DELTA_THETA;
            }
            else
            {
                ux[j]-=DELTA_THETA;
            }
        }
        avg=avg/(double)N;
        fprintf(fp,"%.9e\n",avg);
        printf("Completed %.2f%%\n",(double)i/(double)(tn-1)*100);
    }
    fclose(fp);  
    free(ux);
    return 1;
}

int CalCor(int seed,char* name,int N,int tn,int tau)
{
    printf("Start Calculate C(t;%d)\n",tau);
    FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"t\tC\n");
	int i,j, z=seed;
    double xi,C_tau;
    //创建缓存数组
    double* ux=(double*)malloc(N*sizeof(double));
    double* ux_tau=(double*)malloc(N*sizeof(double));
    //初始化
    for ( i = 0; i < N; i++)
    {
        ux[i]=0.0;
    }
    //迭代计算
    for ( i = 0; i <tn; i++)
    {
        fprintf(fp,"%d\t",i);
        C_tau=0;
        //演化与计算
        for ( j = 0; j < N; j++)
        {
            //记录tau时间点量
            if (i==tau)
            {
                ux_tau[j]=ux[j];
            }
            if (i>=tau)
            {
                C_tau+=ux[j]*ux_tau[j];
            }
            z=Schrage(z);
            xi=(double)z/M_16807;
            if (xi>P_THETA)
            {
                ux[j]+=DELTA_THETA;
            }
            else
            {
                ux[j]-=DELTA_THETA;
            }
        }
        C_tau=C_tau/(double)N;
        if (i<tau)
        {
            fprintf(fp,"Null\n");
        }
        else
        {
            fprintf(fp,"%.9e\n",C_tau);
        }
        printf("Completed %.2f%%\n",(double)i/(double)(tn-1)*100);
    }
    fclose(fp);  
    free(ux);
    return 1;
}