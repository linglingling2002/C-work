/*5、编写函数void change(char *a,char *b,char*c)。 函数功能是首先把b指向的字符串逆向存放，然后将a指向的字符串和b指向的字符串按排列顺序交叉合并到c指向的数组中，两个字符串中过长的剩余字符接在c指向数组的尾部。
例如，当a指向的字符串为"abcdefg"，b指向的字符串为"1324"时，c指向的数组中字符串应为"a4b2c3d1efg"。
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void change(char *a, char *b, char*c)
{
    int i = 0;
    char mid = '0';
    int length1 = (int)strlen(a);               //a长度
    int length2 = (int)strlen(b);               //b长度
    int length = length1 + length2;             //c预计长度

    for(int m = 0; m < length2 / 2; m++)        //b逆序
    {
        mid = b[m];
        b[m] = b[length2 - m - 1];
        b[length2 - m - 1] = mid;
    }
    for(i = 0; i < length; i++)
    {
        if(a[i] == '\0' || b[i] == '\0')        //交叉合并
        {
            break;
        }
        c[i * 2] = a[i];
        c[i * 2 + 1] = b[i];
    }
    if(a[i] != '\0')                            //a多余，继续复制
    {
        for(int j = 0; j < length; j++)
        {
            c[i * 2 + j] = a[i + j];
        }
    }
    else if(b[i] != '\0')                       //b多余
    {
        for(int j = 0; j < length; j++)
        {
            c[i * 2 + j] = b[i + j];
        }
    }
}
int main()
{
    char * a = malloc(sizeof(char) * 20);
    char * b = malloc(sizeof(char) * 20);
    char * c = malloc(sizeof(char) * 40);

    scanf("%s", a);
    printf("%s\n", a);
    scanf("%s", b);
    printf("%s\n", b);
    change(a,b,c);
    printf("%s\n", c);
    return 0;
}
