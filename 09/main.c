#include "CLTheorem.h"
extern double lambdaExp;
int main(int argc, char const *argv[])
{
    int N[3]={2,5,10},m=1E5,seed=Seed();
    int *result1,*result2;
    double *result3;
    FILE* fp;
    char name[20],name_f[5]=".dat";
    int i,j,k,z=seed;
    double avg,mu,sigma,sqrtN,*SigmaP;
    for (i = 0; i < 3; i++)
    {
        //动态文件名
        name[0]=(char)(i+48);
        name[1]=0;
        strcat(name, name_f);
        if ((fp = fopen(name, "w")) == NULL)
	    {
		    return 0;
		    exit(0);
	    }
        //打印表头
        fprintf(fp,"Bin\tPoission\tExp\tseed=%d\n",seed);
        //遍历N
        for (j = 0; j < m; j++)
        {
            //循环抽样
            sqrtN=sqrt(N[i]);
            z=Schrage(z);
            SigmaP=BinoDis(0.8,5);
            result1=DisDirectSam(SigmaP,6,N[i],z);
            avg=0;mu=5*0.8;sigma=sqrt(5*0.8*0.2);
            //计算均值
            for (k = 0; k < N[i]; k++)
            {
                avg+=result1[k];
            }
            avg=avg/(double)N[i];
            fprintf(fp,"%.9e\t",(avg-mu)/(sigma/sqrtN));
            free(result1);free(SigmaP);
            SigmaP=PoissionDis(1,20);
            result2=DisDirectSam(SigmaP,20,N[i],z);
            avg=0;mu=1;sigma=1;
            for (k = 0; k < N[i]; k++)
            {
                avg+=result2[k];
            }
            avg=avg/(double)N[i];
            fprintf(fp,"%.9e\t",(avg-mu)/(sigma/sqrtN));
            free(result2);
            result3=ConDirectSam(ArcExpDis,N[i],z);
            avg=0;mu=1/lambdaExp;sigma=mu;
            for (k = 0; k < N[i]; k++)
            {
                avg+=result3[k];
            }
            avg=avg/(double)N[i];
            fprintf(fp,"%.9e\n",(avg-mu)/(sigma/sqrtN));
            free(result3);
        }
        printf("completed:%.2f%%\n",(double)(i+1)/3.0*100);
        fprintf(fp,"N=%d\n",N[i]);
    }
    fclose(fp);
}
