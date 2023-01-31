//4、查找介于n1与n2（0<n1<n2<32768）之间所有满足下列条件的整数：
//(1)该数的十进制表示中有且仅有两个相同的数字位；
//(2)该数是素数。

#include <stdio.h>
int primeJudge(int num)
{
    int flag = 0;                   //是素数

    for(int i = 2; i < num; i++)
    {
        if((num % i) == 0)
        {
            flag = 1;               //不是素数
            break;
        }
    }
    return flag;
}
int twoSame(int num)
{
    int i = 0;
    int a[5] = {0};
    int flag = 0;

    while(num != 0)
    {
        a[i] = num % 10;
        i++;
        num = num / 10;
    }
    if(1 == i)
    {
        return 0;           //一位数
    }

    for(int j = 0; j < i - 1; j++)
    {
        for(int n = j + 1; n < i; n++)
        {
            if(a[j] == a[n])
            {
                flag++;
            }
        }
    }
    if(flag == 1)
    {
        return 1;           //符合要求
    }
    return 0;               //不符合
}

int main()
{
    int n1 = 0;
    int n2 = 0;
    printf("input n1,n2  0<n1<n2<32768\n");
    scanf("%d%d", &n1, &n2);
    for(int i = n1 + 1; i < n2; i++)
    {
        if(primeJudge(i) == 0 && twoSame(i) && i != 1)
        {
            printf("%d\t", i);
        }
    }
    return 0;
}
