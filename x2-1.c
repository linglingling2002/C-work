//1、从一个字符数组中读出相应的整数、实数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trans(char c)
{
    int num = 0;
    switch(c)
    {
        case '1' : num = 1; break;
        case '2' : num = 2; break;
        case '3' : num = 3; break;
        case '4' : num = 4; break;
        case '5' : num = 5; break;
        case '6' : num = 6; break;
        case '7' : num = 7; break;
        case '8' : num = 8; break;
        case '9' : num = 9; break;
        case '0' : num = 0; break;
    default: num = -1; break;
    }
    return num;
}
int main()
{
    int strlength = 0;
    int i = 0;
    int flag = 0;
    int pointnum = 0;
    double number = 0;
    char * str = (char *)malloc(sizeof(char) * 20);
    double result = 0;
    long result2 = 0;

    //str = "-358573445.6";
    scanf("%s", str);
    strlength = (int)strlen(str);

    for(i = 0; i < strlength; i++)
    {
        if(str[i] == '-')
        {
            flag = 1;                   //是负数
        }
        else if(str[i] == '.')
        {
            pointnum = 1;               //有小数
        }
        else if(trans(str[i]) != -1)    //数字
        {
            pointnum = pointnum * 10;
            number = number * 10 + trans(str[i]);
        }
        else                            //输入奇怪的内容
        {
            printf("Error!\n");
            return 0;
        }
    }

    if(1 == flag)
    {
        number = 0 - number;
    }
    if(pointnum > 0)
    {
        result = number / pointnum;
        printf("number = %lf\n", result);
    }
    else
    {
        result2 = (long)number;
        printf("number = %ld\n", result2);      //无小数就不输出小数
    }
    return 0;
}
