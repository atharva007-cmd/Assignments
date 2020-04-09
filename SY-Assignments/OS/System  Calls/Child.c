#include<stdio.h>
#include<stdlib.h>
#include "Function.h"

int main(int argc, char *argv[])
{
    int i=0, j, len=0;
    char str[1000], *token=NULL;
    int arr[1000];
    strcpy(str, argv[0]);

    token = strtok(str, ",");
    while (token!=NULL)
    {
        arr[i++] = atoi(token);
        token=strtok(NULL, ",");
        len++;
    }
    
    DescBubbleSort(arr, len);

    printf("Child\n");
    for (i=0; i<len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}