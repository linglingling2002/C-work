//2、将整数转换为相应的一个字符数组。

#include <stdio.h>

char singleTrans(int c)
{
    char num = '0';
    switch(c)
    {
        case 1 : num = '1'; break;
        case 2 : num = '2'; break;
        case 3 : num = '3'; break;
        case 4 : num = '4'; break;
        case 5 : num = '5'; break;
        case 6 : num = '6'; break;
        case 7 : num = '7'; break;
        case 8 : num = '8'; break;
        case 9 : num = '9'; break;
        case 0 : num = '0'; break;
    default: num = 'e'; break;
    }
    return num;
}
char * str(int number)
{
    int i = 0;
    int flag = 0;
    char mid = '0';
    char * strs = malloc(sizeof(char) * 20);
    if(number < 0)
    {
        number = 0 - number;
        flag = 1;
    }
    if(0 == number)
    {
        return "0";
    }
    while(0 != number)
    {
        strs[i] = singleTrans(number % 10);
        i++;
        number = number / 10;
    }
    for(int m = 0; m < i / 2; m++)
    {
        mid = strs[m];
        strs[m] = strs[i - m - 1];
        strs[i - m - 1] = mid;
    }
    strs[i] = '\0';
    if(1 == flag)
    {
        for(int m = i; m >= 0; m--)
        {
            strs[m + 1] = strs[m];
        }
        strs[0] = '-';
    }
    return strs;
}
int main()
{
    int num = 0;
    scanf("%d", &num);
    printf("%s\n", str(num));
}
