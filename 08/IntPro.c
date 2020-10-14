#include "IntPro.h"
int SphereDim;

double f1(double* x)
{
    //返回第一个函数
    return sqrt(x[0]+sqrt(x[0]));
}

double f2(double* x_vec)
{
    int i=0;
    double sum=0;
    //平方和
    for ( i = 0; i < 5; i++)
    {
        sum+=pow(x_vec[i],2.0);
    }
    return (6.0-sum);
}

double f3(double* x_vec)
{
    return 1.0;
}

int InArea12(double* x_vec)
{
    return 1;
}

int InArea3(double* x_vec)
{
    int i=0;
    double sum=0;
    //累加
    for ( i = 0; i < SphereDim; i++)
    {
        sum+=pow(x_vec[i],2.0);
    }
    if (sum<=1.0-Epsilon)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}