#include "chaos.h"

int main(int argc, char const *argv[])
{
    //文件名
    char name1[]="chaosX.dat",name2[]="chaosLam.dat";
    char** name=(char **)malloc(2*sizeof(char*));
    name[0]=name1;name[1]=name2;

    int M=10000,N=100,n=5000;
    int i;
    double step=(double)0.5/(double)n,RE=1E-5;

    //lambda数组
    double* lambda=(double *)malloc(n*sizeof(double));

    //初始化lambda数组
    for ( i = 0; i < n; i++)
    {
        lambda[i]=2.4+(double)i*step;
    }
    
    chaosToDat(name,lambda,n,M,N,RE);
    

    return 0;
}