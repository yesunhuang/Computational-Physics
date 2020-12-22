#include "SchrodingerEigen.h"
//一些全局变量
double R;double m;double E;

double inftyConstantV(double x)
{
    if (fabs(x)>(R/2.0)+Epsilon)
    {
        return (double)INT_MAX;
    }
    else
    {
        return 0;
    }
}

double schroNumerovF(double x)
{
    return -1.0*2*m*(E-SCHROV(x));
}

void findEigenValueToDat(char* name,
                         double* ESpan,int EStep,
                         double *xSpan,int xStep,double* initial,
                         double epsilon)
{
    double h=(ESpan[1]-ESpan[0])/(double)EStep;
    char nameIter[50],*nameE="_E_",*nameDat=".dat",nameEnum[10];
    nameIter[0]=0;
    strcat(nameIter,name);strcat(nameIter,nameE);
    double ** result,EIter;
    FILE *fp;

    //枚举能量
    int i,j,ENum=0,nameLen=strlen(nameIter);
    for (i = 0; i < EStep+1; i++)
    {
        EIter=ESpan[0]+h*i;
        E=EIter;
        result=NumerovSolver(schroNumerovF,initial,xSpan,xStep);
        //判断是否符合要求
        if (fabs(fabs(result[1][0])-fabs(result[1][xStep]))<epsilon)
        {
            //生成文件名
            nameIter[nameLen]=0;
            ENum++;
            strcat(nameIter,itoa(ENum,nameEnum,10));
            strcat(nameIter,nameDat);
            if ((fp = fopen(nameIter, "w")) == NULL)
	        {
		        exit(0);
	        }
            
            //印数据
            fprintf(fp,"E=%.9e\nx\ty\n",EIter);
            for ( j = 0; j < xStep+1; j++)
            {
                fprintf(fp,"%.9e\t%.9e\n",result[0][j],result[1][j]);
            }
            
            fclose(fp);
            free(result);
        }
    }
    

}