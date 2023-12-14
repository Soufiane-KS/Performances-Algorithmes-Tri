#include <stdio.h>
#include <stdlib.h>

void afficher_table(int *t, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ,", *(t + i));
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge_sort(int *t,int size){
    if(size <=1 ){
        return;
    }
    int mid = size/2;
    int *left=(int*)malloc(sizeof(int)*mid);
    int *right;(int*)malloc(sizeof(int)*(size-mid));

    for (int i = 0; i < mid; i++)
    {
        left[i]=t[i];
    }
    for (int i = mid+1; i < size; i++)
    {
        right[i]=t[i];
    }
    
   
    
}

void merge(int *t1,int *t2){

}

void bulles(int *t, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                swap(&t[j], &t[j + 1]);
            }
        }
    }
}

void selection(int *t, int size)
{
    int imin;
    for (int i = 0; i < size - 1; i++)
    {
        imin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (t[j] < t[imin]){
                imin = j ;
            }
        }
        swap(&t[i],&t[imin]);
    }
}

void insertion(int *t, int size){
    int j,tmp;
    for (int i = 1; i < size; i++)
    {
        tmp = t[i];
        j=i-1;
        while (j>=0 && t[j]>tmp)
        {
            t[j+1] = t[j];
            j--;
        }
        t[j+1]=tmp;
    }
    
}

