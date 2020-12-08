#include "Fractal.h"

int DLASimuToDat(char* name,int N,int seed)
{
    //标记数组
    int map[BOUND_SIZE*2+1][BOUND_SIZE*2+1],i,j;
    //初始化
    for ( i = 0; i < BOUND_SIZE*2+1; i++)
        for (j=0;j<BOUND_SIZE*2+1;j++)
            map[i][j]=0;
    map[BOUND_SIZE+1][BOUND_SIZE+1]=1;
    //位置数组
    int (*pos)[2]=(int(*)[2])malloc(sizeof(int)*2*N);
    pos[0][0]=0;pos[0][1]=0;
    //shuffle用
    double *index=(double*)malloc(sizeof(double)*N);
    int z=seed,x,y; double M=M_16807;
    double xi1,xi2;
    for ( i = 1; i < N; i++)
    {

        index[i]=i+0.1;
        //产生粒子
        z=Schrage(z);xi1=(double)z/M_16807;
        z=Schrage(z);xi2=(double)z/M_16807;
        pos[i][0]=-PUMP_SIZE+2*PUMP_SIZE*xi1;
        pos[i][1]=-PUMP_SIZE+2*PUMP_SIZE*xi2;
        //随机行走
        while (1)
        {
            z=Schrage(z);xi1=(double)z/M_16807;
            z=Schrage(z);xi2=(double)z/M_16807;
            if (xi1>0.5)    pos[i][0]+=1;
            else    pos[i][0]-=1;
            if (xi2>0.5)    pos[i][1]+=1;
            else    pos[i][1]-=1;
            //判断出界
            if (abs(pos[i][0])>=OUT_SIZE||abs(pos[i][1])>=OUT_SIZE)
            {
                i--;
                break;
            }
            //判断粘连
            if (abs(pos[i][0])<BOUND_SIZE-1&&abs(pos[i][1])<BOUND_SIZE-1)
            {
                x=pos[i][0]+BOUND_SIZE;y=pos[i][1]+BOUND_SIZE;
                if (map[x+1][y]==1||map[x-1][y]==1||
                    map[x][y-1]==1||map[x][y+1]==1)
                {
                    map[x][y]=1;

                    if (i%POCESS==0)
                        printf("Completed:%.2f%%\n",
                        (double)i/(double)N*100.0);
                    break;
                }
                
            }
        }
    }
    
    //shuffle索引数组
    //z=Schrage(z);
    //shuffle(index,N,z);

    FILE* fp;
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //打印表头
    fprintf(fp,"N\tx\ty\n");
    for ( i = 0; i < N; i++)
    {
        fprintf(fp,"%d\t%d\t%d\n",i,
                pos[(int)index[i]][0],
                pos[(int)index[i]][1]);
    }
    free(pos);
    free(index);
    fclose(fp);
    return 1;
}


int SandboxCal(char* nameIn,char* nameOut,int N,double* r,int r_len)
{
    FILE* fp;
	if ((fp = fopen(nameIn, "r")) == NULL)
	{
		return 0;
		exit(0);
	}
	char label1[20];
	//读取标签
	fscanf(fp,"%s\t%s\t%s",&label1,&label1,&label1);

    //个数数组
    int* Nr=(int*)malloc(sizeof(int)*r_len);
    int i,x,y,n;
    for ( i = 0; i < r_len; i++)
        Nr[i]=0;
    

    //读数据
    for ( i = 0; i < N; i++)
    {
        fscanf(fp,"%d\t%d\t%d",&n,&x,&y);
        n=BinarySearch(r,(double)max(abs(x),abs(y)),r_len);
        if (n<r_len)
            Nr[n]++;
    }
    fclose(fp);

    //输出数据
    if ((fp = fopen(nameOut, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //印表头
    fprintf(fp,"r\tN(r)\n");

    n=0;
    //印数据
    for (i = 0; i < r_len; i++)
    {
        n=n+Nr[i];
        fprintf(fp,"%.9e\t%d\n",r[i],n);
    }
    free(Nr);
    fclose(fp);
    return 1;
}


int NRgCal(char* nameIn,char* nameOut,int* N,int N_len)
{
    FILE* fp1,*fp2;
	if ((fp1 = fopen(nameIn, "r")) == NULL)
	{
		return 0;
		exit(0);
	}
	char label1[20];
	//读取标签
	fscanf(fp1,"%s\t%s\t%s",&label1,&label1,&label1);

    if ((fp2 = fopen(nameOut, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    //印表头
    fprintf(fp2,"N\tRg\n");

    int i,j=0,x,y,n,count=0;
    double sum_r2=0;
    //读数据
    for ( i = 1; i <= N[N_len-1]; i++)
    {
        fscanf(fp1,"%d\t%d\t%d",&n,&x,&y);
        sum_r2+=x*x+y*y;
        if (i==N[j])
        {
            fprintf(fp2,"%d\t%.9e\n",i,sqrt(sum_r2/(double)i));
            while (N[j]<=i)
                j++;
            count=0;
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 1;
}