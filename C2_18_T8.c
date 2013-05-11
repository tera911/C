#include <string.h>
#include <stdio.h>

#define N 100

struct QUEUE_DATA{
    int next;
    char name[80];
};

//大域変数
struct QUEUE_DATA queue[N];
int head, tail;

//キューの初期化
void init_queue(void){
    int i;
    head = -1;
    tail = 0;
    for(i = 0; i < N; i++){
        queue[i].next = -2;
    }
}

int append_queue(char name[]){
    //空いているデータ領域を探す
    int i;
    for(i = 0; i < N; i++){
        if(queue[i].next < 0)
            break;
    }
    if(i == N){
        printf("データを追加するための領域がありません。");
        return -1;
    }
    
    strcpy(queue[i].name, name);
    queue[i].next = -1;
    if(head == -1)
        head = i;
    else
        queue[tail].next = i;
    tail = i;
    return 0;
}

//キューからのデータの取得
int remove_queue(char name[]){
    int work;
    if(head == -1){
        printf("データは一つもありません。");
        return -1;
    }
    strcpy(name, queue[head].name);
    work = head;
    head = queue[head].next;
    queue[work].next = -2;
    if(head == -1)
        tail = -1;
    return 0;
}
int main(void){
    char buf[128];
    append_queue("aaa1");
    append_queue("aaa2");
    
    remove_queue(buf);
    printf("%s\n",buf);
    remove_queue(buf);
    printf("%s\n",buf);
    return (0);
}
