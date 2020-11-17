#include "GammaInt.h"

//外部变量
extern double gamma;

int main(int argc, char const *argv[])
{
    int i,seed=Seed(),N,gamma_opm;
    double min_error=M_16807,trueValue;
    double *result,*result2;
    FILE* fp;
    trueValue=alpha*pow(beta,2);

    //不同gamma,同时寻找最优gamma
    if ((fp = fopen("Gammadata.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"gamma\tresult\teta\tseed=%d\n",seed);
    N=100000;
    for ( i = 1; i < 100; i++)
    {
        gamma=i;
        result=MetroMonteInt(Gammaf,Gammar,GammaarcXi,N,100,seed,1);
        fprintf(fp,"%d\t%.9e\t%.9e\n",i,result[0],result[1]);
        if (fabs(result[0]-trueValue)<min_error)
        {
            min_error=fabs(result[0]-trueValue);
            gamma_opm=gamma;
        }
    }
    fclose(fp);
    

    double range[1][2]={{0,1000}};
    //不同N
    gamma=gamma_opm;
	if ((fp = fopen("Ndata.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"N\tMeMresult\tMresult\teta\tseed=%d\n",seed);
    for ( i = 1; i < 318; i++)
    {
        N=100*i*i;
        result=MetroMonteInt(Gammaf,Gammar,GammaarcXi,N,100,seed,1);
        result2=MonteInt(Montef,1,range,GammaInArea,N,seed);
        fprintf(fp,"%d\t%.9e\t%.9e\t%.9e\n",N,result[0],result2[0],result[1]);
        if (i % 10==0)
        {
            printf("Completed:%.2f%%\n",(double)(i+1)/(double)318);
        }
        
    }
    fclose(fp);
    system("pause");
    return 0;
}
