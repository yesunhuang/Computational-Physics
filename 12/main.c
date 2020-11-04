#include "SquarePerco.h"

void main(){
    int seed=Seed(),N=10;
    //蒙特卡洛
    int** map=MontePerco(0.7,seed,N);
    map=CalClusterToDat(map,"cluster_07.dat",N);
    //这里完全没有free
    map=MontePerco(0.3,seed,N);
    map=CalClusterToDat(map,"cluster_03.dat",N);

    map=MontePerco(0.1,seed,N);
    map=CalClusterToDat(map,"cluster_01.dat",N);    
    //打印种子
    printf("%d\n",seed);
    system("pause");
}
