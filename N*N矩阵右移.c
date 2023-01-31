//有N*N矩阵，根据给定的m值，将每行元素中的值均右移m个位置，左边置为0。

#include<stdio.h>
#include<malloc.h>

int main(){
	int m,N,i,j;
	printf("输入矩阵边长：");
	scanf("%d",&N);
	int **arr = (int **)malloc(sizeof(int)*N);
	for(i = 0;i < N;i++){
		arr[i] = (int *)malloc(sizeof(int)*N);
	}
	for(i = 0;i < N; i++){
		for(j = 0;j < N; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("输入右移距离：");
	scanf("%d",&m);
  
	for(i = 0;i < N;i++){
		for(j = N - 1;j >= 0;j--){
			if(j >= m){
				arr[i][j] = arr[i][j - m];
			}else{
				arr[i][j] = 0;
			}
		}
	}
  
	for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", arr[i][j]);
        }
            printf("\n");
    }
}
