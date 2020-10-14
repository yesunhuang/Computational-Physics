#include "CLTheorem.h"

//为什么要有这个？因为我没有类封装
double lambdaExp=0.1;

double* BinoDis(double p,int n)
{
    double* SigmaP=(double*)malloc((n+1)*sizeof(double));
    SigmaP[0]=(double)Combin(n,0)*pow(p,0.0)*pow(1-p,n);
    int i=0;
    //累加计算
    for ( i = 1; i < n+1; i++)
    {
        SigmaP[i]=SigmaP[i-1]+(double)Combin(n,i)*pow(p,i)*pow(1-p,n-i);
    }
    return SigmaP;
}

double* PoissionDis(double lambda,int n)
{
    double* SigmaP=(double*)malloc(n*sizeof(double));
    SigmaP[0]=exp(-lambda);
    int i=0;
    //累加计算
    for ( i = 1; i < n; i++)
    {
        SigmaP[i]=SigmaP[i-1]+pow(lambda,i)/(double)Factorial(i)*SigmaP[0];
    }
    return SigmaP;
}

double ArcExpDis(double xi)
{
    //返回反函数
    return -1.0/lambdaExp*log(1.0-xi);
}
