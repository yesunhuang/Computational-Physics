#include "IntPro.h"

extern int SphereDim;
int main(int argc, char const *argv[])
{
    int seed=Seed(),N=1E5;
    double range1[1][2]={{0,2}};
    double range2[5][2]={{0,0.9},{0,0.8},{0,0.9},{0,2},{0,1.3}};
    /*Debug Area
    double* result=MonteInt(f1,1,range1,InArea12,10000,seed);
    printf("int=%.9e,eta=%.9e",result[0],result[1]);
    */
    FILE* fp;
	if ((fp = fopen("data1.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"logN\tint1\tint2\tseed=%d\n",seed);
    double* result1,*result2;
    int i,j;
    //循环测试多个范围
    for ( i = 2; i < 9; i++)
    {
        N=(int)pow(10.0,(double)i);
        result1=MonteInt(f1,1,range1,InArea12,N,seed);
        result2=MonteInt(f2,5,range2,InArea12,N,seed);
        printf("Completed:%.2f%%\n",(double)(i-1)/7.0*100.0);
        fprintf(fp,"%d\t%.9e\t%.9e\n",i,result1[0],result2[0]);
    }
    fclose(fp);

    N=1E6;
    if ((fp = fopen("data2.dat", "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"dim\tint\teta\tseed=%d\n",seed);

    //循环测试多个维度
    for ( i = 2; i < 9; i++)
    {
       double(* range)[2]=(double (*)[2])malloc(i*2*sizeof(double));
       SphereDim=i;
       for ( j = 0; j < i; j++)
       {
           range[j][0]=-1.0;
           range[j][1]=1.0;
       }
       result1=MonteInt(f3,i,range,InArea3,N,seed);
       printf("Completed:%.2f%%\n",(double)(i-1)/7.0*100.0);
       fprintf(fp,"%d\t%.9e\t%.9e\n",i,result1[0],result1[1]);
       free(range);
    }
    
    fclose(fp);
    system("pause");
    return 0;
}
