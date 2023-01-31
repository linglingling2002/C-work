//4、查找介于n1与n2（0<n1<n2<32768）之间所有满足下列条件的整数：
//(1)该数的十进制表示中有且仅有两个相同的数字位；
//(2)该数是素数。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char * str = malloc(sizeof(char) * 20);
    int length = 0;
    char mid = '0';

    scanf("%s", str);
    length = (int)strlen(str);
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if(str[i] > str[j])
            {
                mid = str[i];
                str[i] = str[j];
                str[j] = mid;
            }
        }
    }
    printf("%s\n", str);
}
