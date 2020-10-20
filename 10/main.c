#include "Stick.h"

int main(int argc, char const *argv[])
{
    int seed=Seed();

    int tau=10,N=100000,tn=1000;
    //单次行走
    RWThetaToDat(seed,"data_s.dat",tn);
    printf("Complete single walk.\n");
    //算矩平均
    CalAvg(seed,"data_avg1.dat",N,tn,1);

    CalAvg(seed,"data_avg2.dat",N,tn,2);
    //算自相关
    CalCor(seed,"data_cor.dat",N,tn,tau);
    //打印种子
    printf("seed=%d",seed);
    system("pause");


}
