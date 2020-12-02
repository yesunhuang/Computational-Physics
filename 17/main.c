#include "chaos.h"

int main(int argc, char const *argv[])
{
    
    //文件名
    char name1[]="chaosXL.dat",name2[]="chaosLamL.dat";
    char** name=(char **)malloc(2*sizeof(char*));
    name[0]=name1;name[1]=name2;

    int M=10000,N=100,n=5000;
    int i;
    double step=(double)4/(double)n,RE=1E-5;

    //lambda数组
    double* lambda=(double *)malloc(n*sizeof(double));

    
    //初始化lambda数组,Large
    for ( i = 0; i < n; i++)
    {
        lambda[i]=0+(double)i*step;
    }
    
    chaosToDat(name,lambda,n,M,N,RE);

    //zoomin
    char name3[]="chaosX.dat",name4[]="chaosLam.dat";
    name[0]=name3;name[1]=name4;

    step=(double)1/(double)n;

    //初始化lambda数组
    for ( i = 0; i < n; i++)
    {
        lambda[i]=0+(double)i*step;
    }
    
    chaosToDat(name,lambda,n,M,N,RE);
    

    //more lambda
    char name5[]="chaosXMore.dat",name6[]="chaosLamMore.dat";
    name[0]=name5;name[1]=name6;

    step=(double)0.2/(double)n;

    //初始化lambda数组
    for ( i = 0; i < n; i++)
    {
        lambda[i]=0.7+(double)i*step;
    }
    
    chaosToDat(name,lambda,n,M,N,RE);

    

    return 0;
}