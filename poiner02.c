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
    printf("-----------------------\n");
    printf("有关const的尝试：\n");
    int i;
    int iConst=10;
    int * const pConst=&i;//定义了一个指针常量(指针是const)
    const int *pConstInt=&iConst;//定义了一个指向常量的指针(所指是const:不能通过指针去修改变量，并不能使得使得变量成为const)
    printf("pConst=%p\n",pConst);
    //pConst++;报错：expression must be a modifiable lvalue
    (*pConst) ++;
    printf("iConst=%d\n",iConst);
    printf("*pConstInt=%d\n",*pConstInt);
    //(*pConstInt) ++;报错: increment of read-only location '*pConstInt'
    printf("*pConstInt++=%d\n",*pConstInt);//不能通过指针去修改变量
    printf("iConst=%d\n",iConst);
    iConst++;
    printf("iConst++=%d\n",iConst++);//不能使得变量本身成为const
    int chine[] = {0,1,2,3,4};
    int *pChine = chine;
    printf("pChine=%p\n",pChine);
    printf("pChine+1=%p\n",pChine+1);
    printf("pChine[1]=%d\n",pChine[1]);
    printf("*(pChine+3)=%d\n",*(pChine+3));
    
    printf("sizeof(chine)=%d\n",sizeof(chine));
    printf("");
    getchar();    
    
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