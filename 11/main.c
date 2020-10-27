#include "BackWalk.h"

int main(int argc, char const *argv[])
{
    int seed=Seed();
    //请勿把M调太高，原因参看理论计算的实现，100就会炸
    int N=1000000,M=40,i;
    
    //一维
    EstimateBWP(seed,"exp1.dat",1,N,M);
    CalOrder("exp1.dat","order1.dat",M/2,2);
    FindTheoP("theo1.dat",M,1);

    //二维
    EstimateBWP(seed,"exp2.dat",2,N,M);
    CalOrder("exp2.dat","order2.dat",M/2,2);
    FindTheoP("theo2.dat",M,2);

    //三维
    EstimateBWP(seed,"exp3.dat",3,N,M);
    CalOrder("exp3.dat","order3.dat",M/2,2);
    FindTheoP("theo3.dat",M,3);
    

    /*debug 块
    FindTheoP("Theo.dat",4,2);

    int r[3]={1,22,3},index,i,*dIndex;
    index=findLinIndex(r,3,100);
    printf("%d\n",index);
    dIndex=findDIndex(index,3,100);
    for ( i = 0; i < 3; i++)
    {
        printf("%d ",dIndex[i]);
    }
    */
    

    printf("seed=%d\n",seed);
    system("pause");
    return 0;
    
}
