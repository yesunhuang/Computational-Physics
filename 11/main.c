#include "BackWalk.h"

int main(int argc, char const *argv[])
{
    int seed=Seed();
    //请勿把M调太高，原因参看理论计算的实现，100就会炸
    int N=1000000,M=40,i=2;
    
    //一维
    EstimateBWP(seed,"exp1.dat",1,N,M*4);
    CalOrder("exp1.dat","order1_exp.dat",M*4/2,i);
    FindTheoP("theo1.dat",M*4,1);
    CalOrder("theo1.dat","order1_theo.dat",M*4/2,i);

    //二维
    EstimateBWP(seed,"exp2.dat",2,N,M*2);
    CalOrder("exp2.dat","order2_exp.dat",M*2/2,i);
    FindTheoP("theo2.dat",M*2,2);
    CalOrder("theo2.dat","order2_theo.dat",M*2/2,i);

    //三维
    EstimateBWP(seed,"exp3.dat",3,N,M);
    CalOrder("exp3.dat","order3_exp.dat",M/2,i);
    FindTheoP("theo3.dat",M,3);
    CalOrder("theo3.dat","order3_theo.dat",M/2,i);
    

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
