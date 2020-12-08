#include "Fractal.h"
#define RLEN 25

int main(int argc, char const *argv[])
{   
    //印种子
    FILE* fp;
	if ((fp = fopen("seed.txt", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    int N=20000,seed=Seed(),i;
    fprintf(fp,"seed=%d",seed);

    
    //DLA模拟
    printf("Begin simulate DLA\n");
    DLASimuToDat("DLASimu.dat",N,seed);
    

    //Sandbox
    printf("Begin sandbox calculation\n");
    double r[RLEN];
    for ( i = 0; i < RLEN; i++)
    {
        r[i]=(double)(i+1)*(FOCUS_SIZE/RLEN);
    }
    SandboxCal("DLASimu.dat","SandboxCal.dat",N,r,RLEN);
    
    //回旋半径
    printf("Begin Rg calculation\n");
    int Ni[RLEN];
    double base=exp(log(N)/(double)RLEN);
    for ( i = 0; i < RLEN; i++)
    {
        Ni[i]=(int)pow(base,i+1);
    }
    NRgCal("DLASimu.dat","NRgCal.dat",Ni,RLEN);


    //
    

    return 0;
}
