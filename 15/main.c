#include "MarkovH.h"

extern double sigmax;
extern double sigmay;

int main(int argc, char const *argv[])
{
    int i,j,n=20,N=1000,m=100,seed=Seed();
    double delta=1.9;
    //打印种子
    
    FILE* fp;
	if ((fp = fopen("result.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    fprintf(fp,"seed=%d\n",seed);

    double(*r)[2] = (double(*)[2])malloc(sizeof(double) * n * 2);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			//初始化
			r[i][j]=(double)i/(double)n;
		}
    }

    //演化抽样
    double *result=MetroH("data.dat",r,n,m,N,delta,seed);

    fprintf(fp,"x^2=%.9e\ny^2=%.9e\nx^2+y^2=%.9e\neta=%.9e\n",
            result[0],result[1],result[2],result[3]);

    fclose(fp);

    return 0;
}
