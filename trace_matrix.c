#include<stdio.h>

int trace_matrice(int** m,int dim){
    int i ,tr = 0;
    for ( i = 0; i < dim ; i++)
    {
        tr+=m[i][i];
    }
    return tr;
}