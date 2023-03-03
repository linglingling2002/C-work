/**有四个线程1、2、3、4。线程1的功能就是输出1，线程2的功能就是输出2，以此类推.........现在有四个文件ABCD。初始都为空。现要让四个文件呈如下格式：
 * A：1 2 3 4 1 2....
 * B：2 3 4 1 2 3....
 * C：3 4 1 2 3 4....
 * D：4 1 2 3 4 1....
 * 请设计程序。
**/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void * th_A(void * add)                     //A pthread, write 'A'
{
    FILE * fp = NULL;

    fp = fopen((char *)add, "a+");
    fseek(fp, 0, SEEK_END);                 //fp -> end
    fputc('1', fp);                         //write 'A'
    fputc(' ', fp);                         //write ' '
    fclose(fp);

    pthread_exit(NULL);
}

void * th_B(void * add)                     //B pthread, write 'B'
{
    FILE * fp = NULL;

    fp = fopen((char *)add, "a+");
    fseek(fp, 0, SEEK_END);                 //fp -> end
    fputc('2', fp);                         //write 'B'
    fputc(' ', fp);                         //write ' '
    fclose(fp);

    pthread_exit(NULL);
}

void * th_C(void * add)                     //C pthread, write 'C'
{
    FILE * fp = NULL;

    fp = fopen((char *)add, "a+");
    fseek(fp, 0, SEEK_END);                 //fp -> end
    fputc('3', fp);                         //write 'C'
    fputc(' ', fp);                         //write ' '
    fclose(fp);

    pthread_exit(NULL);
}

void * th_D(void * add)                     //D pthread, write 'D'
{
    FILE * fp = NULL;

    fp = fopen((char *)add, "a+");
    fseek(fp, 0, SEEK_END);                 //fp -> end
    fputc('4', fp);                         //write 'D'
    fputc(' ', fp);                         //write ' '
    fclose(fp);

    pthread_exit(NULL);
}


void file_a(char * add)             //write 1 2 3 4
{
    FILE * fp = NULL;
    pthread_t tid_a;
    pthread_t tid_b;
    pthread_t tid_c;
    pthread_t tid_d;
    void * pthread_return;
    int ret;

    ret = pthread_create(&tid_d, NULL, th_D, (void *)add);    //create D pthread
    ret = pthread_create(&tid_c, NULL, th_C, (void *)add);    //create C pthread
    ret = pthread_create(&tid_b, NULL, th_B, (void *)add);    //create B pthread
    ret = pthread_create(&tid_a, NULL, th_A, (void *)add);    //create A pthread
    
    ret = pthread_join(tid_a, &pthread_return);                  //A pthread finished
    ret = pthread_join(tid_b, &pthread_return);                  //B pthread finished
    ret = pthread_join(tid_c, &pthread_return);                  //C pthread finished
    ret = pthread_join(tid_d, &pthread_return);                  //D pthread finished

    printf("A.txt finished.\n");
}

void file_b(char * add)             //write 2 3 4 1
{
    FILE * fp = NULL;
    pthread_t tid_a;
    pthread_t tid_b;
    pthread_t tid_c;
    pthread_t tid_d;
    void * pthread_return;
    int ret;

    ret = pthread_create(&tid_a, NULL, th_A, (void *)add);    //create A pthread
    ret = pthread_create(&tid_d, NULL, th_D, (void *)add);    //create D pthread
    ret = pthread_create(&tid_c, NULL, th_C, (void *)add);    //create C pthread
    ret = pthread_create(&tid_b, NULL, th_B, (void *)add);    //create B pthread

    ret = pthread_join(tid_a, &pthread_return);                  //A pthread finished
    ret = pthread_join(tid_b, &pthread_return);                  //B pthread finished
    ret = pthread_join(tid_c, &pthread_return);                  //C pthread finished
    ret = pthread_join(tid_d, &pthread_return);                  //D pthread finished

    printf("B.txt finished.\n");
}

void file_c(char * add)             //write 3 4 1 2
{
    FILE * fp = NULL;
    pthread_t tid_a;
    pthread_t tid_b;
    pthread_t tid_c;
    pthread_t tid_d;
    void * pthread_return;
    int ret;

    ret = pthread_create(&tid_b, NULL, th_B, (void *)add);    //create B pthread
    ret = pthread_create(&tid_a, NULL, th_A, (void *)add);    //create A pthread
    ret = pthread_create(&tid_d, NULL, th_D, (void *)add);    //create D pthread
    ret = pthread_create(&tid_c, NULL, th_C, (void *)add);    //create C pthread

    ret = pthread_join(tid_a, &pthread_return);                  //A pthread finished
    ret = pthread_join(tid_b, &pthread_return);                  //B pthread finished
    ret = pthread_join(tid_c, &pthread_return);                  //C pthread finished
    ret = pthread_join(tid_d, &pthread_return);                  //D pthread finished

    printf("C.txt finished.\n");
}

void file_d(char * add)             //write 4 1 2 3
{
    FILE * fp = NULL;
    pthread_t tid_a;
    pthread_t tid_b;
    pthread_t tid_c;
    pthread_t tid_d;
    void * pthread_return;
    int ret;

    ret = pthread_create(&tid_c, NULL, th_C, (void *)add);    //create C pthread
    ret = pthread_create(&tid_b, NULL, th_B, (void *)add);    //create B pthread
    ret = pthread_create(&tid_a, NULL, th_A, (void *)add);    //create A pthread
    ret = pthread_create(&tid_d, NULL, th_D, (void *)add);    //create D pthread

    ret = pthread_join(tid_a, &pthread_return);                  //A pthread finished
    ret = pthread_join(tid_b, &pthread_return);                  //B pthread finished
    ret = pthread_join(tid_c, &pthread_return);                  //C pthread finished
    ret = pthread_join(tid_d, &pthread_return);                  //D pthread finished

    printf("D.txt finished.\n");
}

int main()
{
    file_a("a.txt");
    file_b("b.txt");
    file_c("c.txt");
    file_d("d.txt");

    return 0;
}
