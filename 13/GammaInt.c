#include "GammaInt.h"

double gamma=0.5;

double Gammaf(double x)
{
    return pow((x-alpha*beta),2);
}

double Gammar(double x0, double x)
{
    //����accept����
    return pow(x/x0,alpha-1)*exp(-(x-x0)/beta)*exp((x-x0)/gamma);
}

double GammaarcXi(double x0,double xi)
{
    //����ת�ƺ���������
    return -gamma*log(xi);
}

double Montef(double* x)
{
    double f0;
    f0=(1./(beta*Gamma_alpha))*pow((x[0]/beta),alpha-1)*exp(-x[0]/beta);
    return Gammaf(x[0])*f0;
}

int GammaInArea(double* x_vec)
{
    return 1;
}