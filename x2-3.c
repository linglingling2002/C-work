//3、字符串数组的冒泡排序，从小到大

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
