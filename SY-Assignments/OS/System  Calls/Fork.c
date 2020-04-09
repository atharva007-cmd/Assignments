#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "Function.h"

int main()
{
    int num, i, j, forkReturn;
    
    // Number of Elements
    printf("Enter number of elements: ");
    scanf("%d", &num);
    int arr[num];
    char str[1000], mainStr[num*4];

    // Actual Elements
    printf("Enter elements:\n");
    for (i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Converting Integer Array to String
    intToString (num, arr, str, mainStr);
    mainStr[(strlen(mainStr))-1]='\0';
    
    char *args[] = {mainStr, NULL};

    // fork
    forkReturn = fork();
    if (forkReturn == 0)
    {
        execv ("./Child", args);
    }
    else
    {
       execv ("./Parent", args);
    }

    return 0;
}