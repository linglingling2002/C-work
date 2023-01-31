//6、对N行N列二维数组的每一行排序，偶数行(0当作偶数)由小到大排序，奇数行由大到小排序

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void smallBig(int *str, int N)         //从小到大
{
    int mid = 0;
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(str[i] > str[j])
            {
                mid = str[i];
                str[i] = str[j];
                str[j] = mid;
            }
        }
    }
}

void bigSmall(int *str, int N)         //从大到小
{
    int mid = 0;
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(str[i] < str[j])
            {
                mid = str[i];
                str[i] = str[j];
                str[j] = mid;
            }
        }
    }
}

int main()
{
    int i = 0;
    int j = 0;
    int N = 0;

    printf("input N:\n");
    scanf("%d", &N);
    int **arr = (int **)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * N);
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);            //输入
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(i % 2 == 0)
        {
            smallBig(arr[i], N);           //偶数，小->大
        }
        else
        {
            bigSmall(arr[i], N);           //奇数
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);           //输出
        }
        printf("\n");
    }
    return 0;
}
