#include "ExpSample.h"
//全局变量
double *origin;
double* ReadAndPreCal(char* name,int N)
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
    double sum=0,pi;
    //循环量
    int i,xi;
    //生成动态数组
	double* SigmaP = (double*)malloc(N * sizeof(double));
    //读数据
    for ( i = 0; i < N; i++)
    {
        fscanf(fp,"%d %lf",&xi,&pi);
        origin[i]=pi;
        if (i>0)
        {
            SigmaP[i]=SigmaP[i-1]+pi;
        }
        else
        {
            SigmaP[i]=pi;
        }
        sum+=pi;
    }
    //归一化
    for ( i = 0; i < N; i++)
    {
  
        SigmaP[i]=SigmaP[i]/sum;
    }
    return SigmaP;
}

double ComArcf(double xi)
{
    double x;
    //算反函数
    if (xi<0.4285)
    {
        x=219.3878702*xi+(double)2900;
    }
    else
    {
        x=34.99347582*xi+2979.006524;
    }
    return x;
}

int ExpIsLegal(double x,double xi_2)
{
    //判断是否合法
    double Fx;
    if ((x>2900.0-Epsilon)&&(x<2994.0+Epsilon))
    {
        Fx=5672;
    }
    else
    {
        Fx=35560;
    }
    double pi;
    //找出地址
    int x_index=(int)(x-2900);
    if (origin[x_index]>xi_2*Fx)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}