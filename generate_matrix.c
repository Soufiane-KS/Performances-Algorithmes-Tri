#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **get_random_matrice(int dim)
{
    int **m;
    int i, j;
    m = (int **)malloc(sizeof(int *) * dim);
    for (i = 0; i < dim; i++)
    {
        m[i] = (int *)malloc(sizeof(int));
    }
    srand(time(NULL));
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            m[i][j] = rand() % 5;
        }
    }

    return m;
}

int **surround_with_zeros(int **A, int oldSize)
{

    int newSize = oldSize + 2;

    A = (int **)realloc(A, newSize * sizeof(int *));
     for (int i = 0; i < newSize; i++)
    {
         if (i >= oldSize) {
            A[i] = (int *)malloc(newSize * sizeof(int));
        }

    }
    
    for (int i = 0; i < newSize; i++)
    {
        A[0][i]=0;
        A[i][0]=0;
        A[newSize-1][i]=0;
        A[i][newSize-1]=0;

    }
    

    

    return A;
}

void free_matrix(int **m, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        free(m[i]);
    }
    free(m);
}
