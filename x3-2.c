//子线程循环 3 次，接着主线程循环 6 次，接着又回到子线程循环 3 次，接着再回到主线程又循环6 次，如此循环50次，试写出代码。

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int thread1()
{
    int ret = 0;
    ret = pthread_self();
    printf("This is child pthread %d\n", ret);
    //sleep(1);
    pthread_exit("1");
}

int main(){
    pthread_t tid;
    void * pthread_return;
    int ret = 0;
    int i = 0;
    int num = 0;

    while(num <= 50)
    {
        for(i = 0; i < 3; i++)
        {
            printf("%d:", num);                             //account
            if(++num > 50)
            {
                break;
            }
            
            ret = pthread_create(&tid, NULL, (void *)thread1, NULL);        //create pthread 1
            if(ret != 0)
            {
                printf("Fail!\n");
            }
            //printf("Wait1...\n");
            ret = pthread_join(tid, &pthread_return); 
             
        }
                            //wait the pthread 1 exit
        if(ret != 0)
        {
            printf("Fail too...\n");
        }

        for(i = 0; i < 6; i++)                                               //main pthread
        {
            if(++num > 50)
            {
                break;
            }
            ret = pthread_self();
            printf("%d:This is main pthread %d\n", num, ret);
            //sleep(1);
        }
    }
    return 0;
}
