#include "SchrodingerEigen.h"

extern double m=1;
extern double R=2;
extern double E=0;

int main(int argc, char const *argv[])
{
    double xSpan[]={-R/2.0,R/2.0};
    double initial[]={0,0.1};
    double ESpan[]={1,40};
    double epsilon=1E-3;
    
    int xStep=10000,EStep=6500;
    findEigenValueToDat("data0/data",ESpan,EStep,xSpan,xStep,initial,epsilon);
    

    return 0;
}
