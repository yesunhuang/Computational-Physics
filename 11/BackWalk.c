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
    int z=seed,d_update,reach,totalReach=0;
    double xi,M=M_16807;
    //循环求解
    for ( j = 0; j < maxStep; j++)
    {
        reach=0;
        for ( i = 0; i < N; i++)
        {
            if (r[i][0]==1)
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
                xi=xi-0.5;
                d_update=(int)(xi*2*d)+1;
                r[i][d_update]-=1;
            }
            r[i][0]=1;
            //判断是否到达
            for ( k = 1; k < d+1; k++)
            {
                if (r[i][k]!=0)
                {
                    r[i][0]=0;
                    break;
                }
            }
            if (r[i][0]==1)
            {
                reach++;
                totalReach++;
            }
        }
        if ((j+1)%2==0)
            fprintf(fp,"%d\t%.9e\n",j+1,(double)reach/(double)N);
    }
    fprintf(fp,"%d\n",totalReach);
    fclose(fp);
    //释放缓存
    for (i = 0; i < N; i++)
    {
        free(r[i]);
    }
    free(r);
    return 1;
}

int FindTheoP(char*name,int N,int d)
{ 
    FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"N\tP_d\n");
    int i,j,k,indexCache;
    double sum;
    //申请缓存数组
    double* pValue=(double*)malloc(sizeof(double)*(int)pow(N+1,d));
    double* pValue_old=(double*)malloc(sizeof(double)*(int)pow(N+1,d));
    for ( i = 0; i < (int)pow(N+1,d); i++)
    {
        pValue[i]=0;
        pValue_old[i]=0;
    }
    int* r;
    //遍历点
    for ( i = 0; i < N; i++)
    {
        if (i==0)
        {
            pValue_old[0]=1;
        }
        else
        {
            pValue_old[0]=0;
        }
        
        //更新值(注意这个程序完全没有优化，完全没有效率)
        for ( j = 0; j < (int)pow(N+1,d); j++)
        {
            sum=0;
            r=findDIndex(j,d,N);
            for (k = 0; k < d; k++)
            {
               r[k]=r[k]+1;
               indexCache=findLinIndex(r,d,N);
               sum+=pValue_old[indexCache];
               r[k]=r[k]-2;
               indexCache=findLinIndex(r,d,N);
               sum+=pValue_old[indexCache];
               r[k]=r[k]+1;
            }
            sum=sum/(2*d);
            pValue[j]=sum;
            free(r);
        }
        //复制旧数组
        for ( j = 1; j < (int)pow(N+1,d); j++)
        {
            pValue_old[j]=pValue[j];
        }
        if ((i+1) % 2==0)
            fprintf(fp,"%d\t%.9e\n",i+1,pValue[0]);
    }    
    fclose(fp);
    return 1;

}

int CalOrder(char* inName,char* outName,int m,int i)
{
    FILE* fp;
	if ((fp = fopen(inName, "r")) == NULL)
	{
		return 0;
		exit(0);
	}
    char label1[20],label2[20];
	//读取标签
	fscanf(fp,"%s %s",&label1,&label2);
    int j,n;
    //申请缓存
    //其实不用这么多，但是我比较懒
    double* cache=(double*)malloc(m*sizeof(double)),nu;
    for ( j = 0; j < m; j++)
    {
        fscanf(fp,"%d %lf",&n,&cache[j]);
    }
    fclose(fp);
	if ((fp = fopen(outName, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    for ( j = i+1; j < m-i; j++)
    {
        nu=log(cache[j+i]/cache[j-i])/log((double)(j+i)/(double)(j-i));
        fprintf(fp,"%d\t%.9e\n",j,nu);
    }
    fclose(fp);
    return 1;
}

int findLinIndex(int* index,int d,int N)
{
    int trueIndex=0,i;
    for (i = 0; i < d; i++)
    {
        trueIndex+=abs(index[i])*(int)pow(N,i);
    }
    return trueIndex;
}

int* findDIndex(int index,int d ,int N)
{
    int* DIndex=(int*)malloc(sizeof(int)*d);
    int indexCache=index;
    int i;
    for (i = d-1; i > -1; i--)
    {
        DIndex[i]=(int)index/(int)pow(N,i);
        index=index % (int)pow(N,i);
    }
    return DIndex;
}

