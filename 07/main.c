#include "ExpSample.h"
extern double* origin;
int main(int argc, char const *argv[])
{
    /* debug 块1
    double arr[7]={0,1.0,4.6,5.6,10.7,20.3,100.4};
    double key;
    scanf("%lf",&key);
    printf("%d",BinarySearch(arr,key,7));
    system("pause");
    return 0;
    */
   int Num=114,N=1E5;
   origin=(double*)malloc(Num * sizeof(double));
   //读数据，预运算
   double* SigmaP=ReadAndPreCal("data.TXT",Num);
   //直接抽样
   //DisDirectSamToDat(SigmaP,"data_direct.dat",Num,N);
   //舍选抽样
   CSamToDat(ComArcf,ExpIsLegal,"data_com.dat",N);
   return 0;
}

