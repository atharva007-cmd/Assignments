#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define true 1
#define false 0
int itemsQueue[MAX_SIZE];
int count=0;
int FRONT=-1;
int REAR=-1;

int isEmpty(void) {
    if (count==0) {
        return true;
    } else {
        return false;
    }
}

int isFull(void) {
    if (count==MAX_SIZE) {
        return true;
    } else {
        return false;
    }
}

int enque (void) {
    int tmp;
    if ((FRONT == REAR) && FRONT == -1) {
        FRONT++;
        REAR++;
    }
    if (!isFull()) {
        itemsQueue[REAR] = (rand()%9)+count;
        tmp = itemsQueue[REAR];
        REAR=(REAR+1)%MAX_SIZE;
        count++;
    }
    return tmp;
}

int deque (void) {
    int tmp;
    if (!isEmpty()) {
        tmp = itemsQueue[FRONT];
        itemsQueue[FRONT]=-1;
        FRONT=(FRONT+1)%MAX_SIZE;
        count--;
    }
    if (count==0) {
        FRONT=-1;
        REAR=-1;
        memset(itemsQueue, 0, MAX_SIZE*sizeof(int));
    }
    return tmp;
}