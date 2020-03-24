#include <stdio.h>
#include <stdlib.h>
// #include <pthread.h>

//void* mul_runner (void* args)
//{

//}

int main (int argc, char *argv[])
{
    int MatOneR, MatOneC, MatTwoR, MatTwoC, i, j;

    printf("Enter Matrix-1 dimensions:\n");
    scanf("%d%d", &MatOneR, &MatOneC);
    int MatOne[MatOneR][MatTwoC];

    printf("\nEnter Elements:\n");
    for (i=0; i<MatOneR; i++)
        for (j=0; j<MatOneC; scanf("%d", &MatOne[i][j]), j++);
    
    printf("\nMatrix Elements:\n");
    for (i=0; i<MatOneR; i++)
    {
        for (j=0; j<MatOneC; j++)
        {
            printf("%d ", MatOne[i][j]);
        }
        printf("\n");
    }

    

    return 0;
}