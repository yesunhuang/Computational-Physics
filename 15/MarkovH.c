#include"MarkovH.h"

double sigmax=1.0,sigmay=1.2;

double* MetroH(char* name,double (*r)[2],int n,int m,int N,double delta,int seed)
{
    //打开文件
    
    FILE* fp;
    
	if ((fp = fopen(name, "w")) == NULL)
	{
		return 0;
		exit(0);
	}
    fprintf(fp,"N\t");
    

    double* result=(double*)malloc(4*sizeof(double));
    int i,j,z=seed,accept=0;
    double M=M_16807,xi[2],p,deltaH,avg[3];
    //打印表头
    for ( i = 0; i < n; i++)
    {
        fprintf(fp,"x%d\ty%d\t",i,i);
    }
    fprintf(fp,"x^2\ty^2\tx^2+y^2\n");

    for ( i = 0; i < m+N; i++)
    {
        //初始化
        avg[0]=0.0;avg[1]=0.0;avg[2]=0.0;
        if (i>=m)
        {
            fprintf(fp,"%d\t",i-m+1);
        }
        //对每个点演化
        for ( j = 0; j < n; j++)
        {
            z=Schrage(z);
            xi[0]=-delta+((double)z/M_16807)*(2*delta);
            z=Schrage(z);
            xi[1]=-delta+((double)z/M_16807)*(2*delta);
            deltaH=(pow(r[j][0]+xi[0],2)-pow(r[j][0],2))/(2*sigmax)
                  +(pow(r[j][1]+xi[1],2)-pow(r[j][1],2))/(2*sigmay);
            z=Schrage(z);
            p=(double)z/M_16807;
            //判断是否演化
            if (exp(-deltaH)>p)
            {
                r[j][0]+=xi[0];
                r[j][1]+=xi[1];
                if (i>m)
                    accept++;
            }
            //打印和统计
            if (i>=m)
            {
                fprintf(fp,"%.9e\t%.9e\t",r[j][0],r[j][1]);
                avg[0]+=pow(r[j][0],2);
                avg[1]+=pow(r[j][1],2);
                avg[2]+=(pow(r[j][0],2)+pow(r[j][1],2));
            }
        }
        result[0]+=avg[0];result[1]+=avg[1],result[2]+=avg[2];
        avg[0]=avg[0]/(double)n;avg[1]=avg[1]/(double)n;avg[2]=avg[2]/(double)n;
        //打印阶段值
        if(i>=m)
        {
            fprintf(fp,"%.9e\t%.9e\t%.9e\n",avg[0],avg[1],avg[2]);
        }
    }
    result[0]=result[0]/(double)(n*N);
    result[1]=result[1]/(double)(n*N);
    result[2]=result[2]/(double)(n*N);
    result[3]=(double)accept/(double)(n*N);
    fclose(fp);
    return result;
}