#include "chaos.h"

double f(double xn,double lambda)
{
    return lambda*sin(M_PI*xn);
    //for test
    //return lambda*xn*(1-xn);
}

int classify(double* arr,int n,double fuz)
{
    int class=1,i;
    quickSort(arr,0,n-1);
    double current=arr[0];
    for ( i = 1; i < n; i++)
    {
        //判断是否是新类别
        if (((fabs(arr[i])>Epsilon)&&(fabs(current)>Epsilon)) &&
         fabs(arr[i]-current)/(max(fabs(current),fabs(arr[i])))>fuz)
        {
            current=arr[i];
            arr[i]=0;
            arr[class]=current;
            class++;
        }
    }
    return class;
}

int chaosToDat(char** name,double* lambda,int n,int M,int N,double RE)
{
    FILE* fp1,* fp2;
	if ((fp1 = fopen(name[0], "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //印表头
    fprintf(fp1,"lambda\tx\n");
    if ((fp2 = fopen(name[1], "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //印表头
    fprintf(fp2,"lambda\tclass\n");

    double* arr=(double *)malloc(N*sizeof(double));
    int i,j,class;
    double current;
    //初始化和遍历lambda
    for (i = 0; i < n; i++)
    {
        current=INITAL;
        //热化
        for ( j = 0; j < M; j++)
        {
            current=f(current,lambda[i]);
        }
        //求值
        arr[0]=current;
        for ( j = 1; j < N; j++)
        {
            arr[j]=f(arr[j-1],lambda[i]);
        }
        //整理
        class=classify(arr,N,RE);
        //打印
        fprintf(fp2,"%.9e\t%d\n",lambda[i],class);
        for ( j = 0; j < class; j++)
        {
            fprintf(fp1,"%.9e\t%.9e\n",lambda[i],arr[j]);
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 1;
}