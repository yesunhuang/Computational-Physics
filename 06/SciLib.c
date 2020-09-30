#include "SciLib.h"

double ArcFun(double(*f)(double x), double fx,double* range, double atol)
{
	double start=-2.0, end=2.0,mid=0.0;
	int i = 0;
	if (range==NULL)
	{
		//找上下界
		if (f(mid)>fx)
		{
			for ( i = 0; i < 1024; i++)
			{
				if (f(start)<fx)
				{
					end = mid;
					break;
				}
				if (f(end)<fx)
				{
					start = mid;
					break;
				}
				start *= 2;
				end *= 2;
			}
		}
		else
		{
			for (i = 0; i < 1024; i++)
			{
				if (f(start) > fx)
				{
					end = mid;
					break;
				}
				if (f(end) > fx)
				{
					start = mid;
					break;
				}
				start *= 2;
				end *= 2;
			}
		}
	}
	else
	{
		start = range[0];
		end = range[1];
	}
	if (isinf(start))
	{
		return sqrt(-1.0);
	}
	//开始二分
	while (fabs(f(mid)-fx)>atol)
	{
		//不合法求值判断(针对非连续函数)
		if ((fx < f(start) && fx < f(end)) || (fx > f(start) && fx > f(end)))
		{
			return sqrt(-1.0);
		}
		if (start>end)
		{
			return sqrt(-1.0);
		}
		if (f(start)>f(end))
		{
			if (fx>f(mid))
			{
				end = mid;
			}
			else
			{
				start = mid;
			}
		}
		else
		{
			if (fx > f(mid))
			{
				start = mid;
			}
			else
			{
				end = mid;
			}
		}
		mid = (start + end) / 2;
	}
	return mid;
	
}
