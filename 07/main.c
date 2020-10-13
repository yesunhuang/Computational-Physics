#include "SciLib.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
    /* code */
    double arr[7]={0,1.0,4.6,5.6,10.7,20.3,100.4};
    double key;
    scanf("%lf",&key);
    printf("%d",BinarySearch(arr,key,7));
    system("pause");
    return 0;
}

