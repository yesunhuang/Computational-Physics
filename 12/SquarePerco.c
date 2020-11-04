#include "SquarePerco.h"

int** MontePerco(double p,int seed,int N)
{
    //边创建数组边遍历+蒙特卡洛
    int** map=(int**)malloc(N*sizeof(int*));
    int i,j,z=seed;
    double xi=0,M=M_16807;
    for ( i = 0; i < N; i++)
    {
        map[i]=(int*)malloc(N*sizeof(int));
        //标记值
        for (j = 0; j < N; j++)
        {
            z=Schrage(z);
            xi=(double)z/M_16807;
            if (xi<p)
            {
                map[i][j]=1;
            }
            else
            {
                map[i][j]=0;
            }
        }   
    }
    return map;
}


int** CalClusterToDat(int** map,char* name,int N)
{
    int** clusterMap=(int**)malloc(N*sizeof(int*));
    int i,j,count=0;
    FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return clusterMap;
		exit(0);
	}
    //打印表头
	fprintf(fp, "x\ty\tcluster\n");
    //初始化cluster地图
    for ( i = 0; i < N; i++)
    {
        clusterMap[i]=(int*)malloc(N*sizeof(int));
        for (j = 0; j < N; j++)
        {
           clusterMap[i][j]=-1;
        }   
    }
    //dfs访问
    for ( i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (clusterMap[i][j]==-1 && map[i][j]==1)
            {
                count++;
                clusterMap[i][j]=count;
                //深搜
                dfs(clusterMap,map,i,j,N);
            }
            
        }   
    }

     for ( i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
           fprintf(fp,"%d\t%d\t%d\n",i,j,clusterMap[i][j]); 
        }   
    }
    fclose(fp);
    return clusterMap;
}


int dfs(int** clusterMap,int** map,int x,int y,int N)
{
    if (x<0 || y<0 || y>=N || x>=N)
    {
        return 0;
    }
    //四个方向深搜
    if (x-1>=0 && clusterMap[x-1][y]==-1 && map[x-1][y]==1)
    {
        clusterMap[x-1][y]=clusterMap[x][y];
        dfs(clusterMap,map,x-1,y,N);
    }
    if (x+1<N && clusterMap[x+1][y]==-1&&map[x+1][y]==1)
    {
        clusterMap[x+1][y]=clusterMap[x][y];
        dfs(clusterMap,map,x+1,y,N);
    }
    if (y+1<N && clusterMap[x][y+1]==-1&&map[x][y+1]==1)
    {
        clusterMap[x][y+1]=clusterMap[x][y];
        dfs(clusterMap,map,x,y+1,N);
    }
    if (y-1>=0 && clusterMap[x][y-1]==-1&&map[x][y-1]==1)
    {
        clusterMap[x][y-1]=clusterMap[x][y];
        dfs(clusterMap,map,x,y-1,N);
    }
    return 1;
}