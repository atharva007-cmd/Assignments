/**
 * - Matrix Multiplication using Multi-Threading
 * - Author: Atharva Marathe
 * - Date: 02/04/2020
 * 
 * - This is a simple user-friendly program that demonstrates 
 *   Multi-Threading concept through matrix-multiplication.
 * 
 * - Compile: gcc -Wall -Werror -std=c99 -pthread MatrixMultiplication.c -o MatrixMultiplication
 * - Run: ./MatrixMultiplication
 * 
 * - Input:
 *   - Manual Input for Matrix Elements
 *   - Random generation of Matrix Elements
 * 
 * - Output: Resultant Matrix
 *  
 * - Limits/Known bugs: 
 *   - The datatype of sub-arrays in the structure is INT
 *   - The sub-arrays aren't dynamically allocated (MAX_SIZE 100) 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

#define MAX 100

struct element_info
{
    int size;
    int arrayOne[MAX], arrayTwo[MAX];
    int result[MAX];
};

void* mul_runner (void*);
pthread_mutex_t t_mutex = PTHREAD_MUTEX_INITIALIZER;

int main (int argc, char *argv[])
{
    int MatOneR, MatOneC, MatTwoR, MatTwoC;
    int i, j, k, m, x;

    
    // Getting Matrices Dimensions (Custom Input)
    printf("Enter Matrix-1 dimensions:\n");
    scanf("%d%d", &MatOneR, &MatOneC);
    printf("\nEnter Matrix-2 dimensions:\n");
    scanf("%d%d", &MatTwoR, &MatTwoC);

    // Generating Random Dimensions (Optional - Automated Input)
    /*srand(time(NULL));
    MatOneR = (rand()%10 + 1);
    MatOneC = MatTwoR = (rand()%10 + 1);
    MatTwoC = (rand()%10+ 1);*/
    
    // Checking if Matrices are compatible
    if (MatOneC!=MatTwoR)
    {
        perror("\n[ERROR]: Uncompatible Matrices\n");
        exit(EXIT_FAILURE);
    }

    
    // Declaring Matrices
    int MatOne[MatOneR][MatOneC];
    int MatTwo[MatTwoR][MatTwoC];
    int MatResult[MatOneR][MatTwoC];
    

    struct element_info my_element_info[MatOneR][MatTwoC];
    for (i=0; i<MatOneR; i++)
        for (j=0; j<MatTwoC; j++)
            my_element_info[i][j].size=MatTwoR;     // Assigning Input Matrix Size

    
    // Getting Matrix-1 elements (Custom Input)
    printf("\n\nEnter Elements Matrix-1:\n");
    for (i=0; i<MatOneR; i++)
        for (j=0; j<MatOneC; scanf("%d", &MatOne[i][j]), j++);

    // Random Elements Assignment (Optional Automated Input)
    /*for (i=0; i<MatOneR; i++)
        for (j=0; j<MatOneC; MatOne[i][j]=(rand()%15), j++);*/
    
    // Displaying Matrix-1
    printf("\nMatrix 1:\n");
    for (i=0; i<MatOneR; i++)
    {
        for (j=0; j<MatOneC; j++)
            printf("%d ", MatOne[i][j]);
        printf("\n");
    }


    
    // Getting Matrix-2 elements (Custom Input)
    printf("\nEnter Elements Matrix-2:\n");
    for (i=0; i<MatTwoR; i++)
        for (j=0; j<MatTwoC; scanf("%d", &MatTwo[i][j]), j++);

    // Random Element Assignment (Optional Automated Input)
    /*for (i=0; i<MatTwoR; i++)
        for (j=0; j<MatTwoC; MatTwo[i][j]=(rand()%15), j++);*/
    
    // Displaying Matrix-2
    printf("\nMatrix 2:\n");
    for (i=0; i<MatTwoR; i++)
    {
        for (j=0; j<MatTwoC; j++)
            printf("%d ", MatTwo[i][j]);
        printf("\n");
    }


    
    // Initializing a buffer array
    int send_arrays [MatOneR*MatTwoC][MatOneC];
    for (i=0, k=0; i<MatOneR; i++, k++)
        for (j=0, m=0; j<MatOneC; j++, m++)
            send_arrays[k][m] = MatOne[i][j];       // Getting appropriate HORIZONTAL pair from Matrix-1
    
    for (i=0, k=MatOneR; i<MatTwoC; i++, k++)
        for (j=0, m=0; j<MatTwoR; j++, m++)
            send_arrays[k][m] = MatTwo[j][i];       // Getting appropriate VERTICAL pair from Matrix-2



    // Assigning appropriate sub-arrays to the struct object
    for (i=0; i<MatOneR; i++)
        for (j=0; j<MatTwoC; j++)
            for (x=0, m=0; x<MatOneC; x++, m++)
                my_element_info[i][j].arrayOne[m] = send_arrays[i][x];              // Assigning those pairs to sub-arrays

    for (i=0; i<MatOneR; i++)
        for (j=0; j<MatTwoC; j++)
            for (x=0, m=0; x<MatOneC; x++, m++)
                my_element_info[i][j].arrayTwo[m] = send_arrays[j+MatOneR][x];      // Assigning those pairs to sub-arrays



    // Spawn Threads
    pthread_t t_tids [MatOneR*MatTwoC];

    // Thread Attributes
    pthread_attr_t t_attr;
    pthread_attr_init (&t_attr);

    // Thread Create method
    m=0;
    for (i=0; i<MatOneR; i++)
        for (j=0; j<MatTwoC; j++)
            pthread_create (&t_tids[m++], &t_attr, mul_runner, &my_element_info[i][j]);

    // Thread Join Method
    for (i=0; i<MatOneR*MatTwoC; i++)
        pthread_join (t_tids[i], NULL);

    
    // Calculating Final Resultant Matrix
    for (i=0; i<MatOneR; i++)
        for (j=0; j<MatTwoC; j++)
        {
            x=0;
            for (k=0; k<MatOneC; k++)
                x+= my_element_info[i][j].result[k];        // Adding the result sub-array to get final answer
            MatResult[i][j] = x;
        }

    
    // Dislaying Resultant Matrix
    printf("\nResult:\n");
    for (i=0; i<MatOneR; i++)
    {
        for (j=0; j<MatTwoC; j++)
            printf("%d ", MatResult[i][j]);
        printf("\n");
    }

    return 0;
}


// Thread Function
void* mul_runner (void* args)
{
    struct element_info *fs_struct = (struct element_info*) args;
    for (int i=0; i<fs_struct->size; i++)
    {
        // Locking Essential Part
        pthread_mutex_lock (&t_mutex);
        
        fs_struct->result[i] = (fs_struct->arrayOne[i] * fs_struct->arrayTwo[i]);       // Multiplying appropriate sub-array elements
        
        // Unlocking Essential Part
        pthread_mutex_unlock (&t_mutex);
    }
    pthread_exit (NULL);
}