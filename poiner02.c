#include <stdio.h>

void minmax(int a[], int len, int *min, int *max);

void main()
{
    int a[] = {1,2,3,4,5,6,};
    int min,max;
    min=5;
    max=6;
    printf("main sizeof(a)=%d\n",sizeof(a));
    printf("main a=%p\n",a);
    printf("main min=%d\n",min);
    printf("main max=%d\n",max);
    minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
    printf("test0%d\n",sizeof(a));
    printf("test1%d\n",sizeof(int*));
}

void minmax(int a[], int len, int *min, int *max)
{
    int i;
    printf("minmax sizeof(a)=%d\n",sizeof(a));
    printf("minmax a=%p\n",a);
    *min = 10;
    *max = 50;
    printf("minmax min=%d\n",*min);
    printf("minmax max=%d\n",*max);
}