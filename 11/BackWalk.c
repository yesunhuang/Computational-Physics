#include "BackWalk.h"

int EstimateBWP(int seed,char* name,int d,int N,int maxStep)
{
    FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"N\tP_d\n");
    int i,j,k;
    //申请位置缓存数组
    int **r=(int**)malloc(sizeof(int*)*N);
    for (i = 0; i < N; i++)
    {
        r[i]=(int*)malloc(sizeof(int)*(d+1));
        for ( j = 0; j < (d+1); j++)
        {
            r[i][j]=0;
        }   
    }
    int z=seed,d_update,reach;
    double xi,M=M_16807;
    //循环求解
    for ( j = 0; j < maxStep; j++)
    {
        fprintf(fp,"%d\t",j+1);
        reach=0;
        for ( i = 0; i < N; i++)
        {
            if (r[i][0]=1)
            {
                continue;
            }
            z=Schrage(z);
            xi=(double)z/M;
            if (xi<0.5)
            {
                d_update=(int)(xi*2*d)+1;
                r[i][d_update]+=1;
            }
            else
            {
                d_update=(int)(xi*d)+1;
                r[i][d_update]-=1;
            }
            r[i][0]=1;
            //判断是否到达
            for ( k = 1; i < d+1; i++)
            {
                if (r[i][k]!=0)
                {
                    r[i][0]=0;
                    break;
                }
            }
            if (r[i][0]=1)
            {
                reach++;
            }
        }
        fprintf(fp,"%.9e",(double)reach/(double)N);
    }
    fclose(fp);
    //释放缓存
    for (i = 0; i < N; i++)
    {
        free(r[i]);
    }
    free(r);
    return 1;
}