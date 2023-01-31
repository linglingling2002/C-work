/**
7、找出符合以下条件的Troitsky数,将该数的首位数字移动到末位数字之后得到的数是原数的整数倍
      例如:将142857的首位数字1移动到末位之后得到的数是428571,而428571=3*142857,因此142857是Troitsky数
      编程要求：
      （1） 编写函数int Troitsky(long a[]),其功能是求出10000以内的所有Troitsky数,并将它们依次放入a指向的数组中,函数返回找到的Troitsky数的个数.
      （2）编写main函数，调用Troitsky函数,将运行结果输出到屏幕。
**/

#include <stdio.h>
#include <malloc.h>

int trans(int number)
{
    int i = 0;
    int mid = number;
    int mid2 = 1;

    while(0 != mid)
    {
        mid = mid / 10;
        i++;                        //number的位数
    }
    for(mid = 0; mid < i - 1; mid++)
    {
        mid2 = mid2 * 10;
    }
    mid = number;                   //废物利用？
    mid = mid % mid2;               //mid = 第一位之后的数字
    mid2 = (number - mid) / mid2;   //mid2 = 第一位的数字
    mid = mid * 10 + mid2;

    return mid;                     //返回转换后的数
}

int Troitsky(long a[])
{
    int num = 0;
    int numflag = 0;
    for(int i = 10; i < 10000; i++)
    {
        num = trans(i);             //转换后
        if((num % i) == 0)
        {
            a[numflag] = i;
            numflag++;
        }
    }
    return numflag;
}

int main()
{
    long * a = (long *)malloc(sizeof (long) * 10000);
    int num = Troitsky(a);
    printf("There are %d Troitsky number\n", num);
    for(int i = 0; i < num; i++)
    {
        printf("%ld\t", a[i]);
    }

    return 0;
}
