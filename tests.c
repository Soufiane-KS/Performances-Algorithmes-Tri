#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>
#include "time_calc.h"
#include "algos_tri.h"

void generate_table(int *t, int size)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++)
    {

        t[i] = rand() % 100000; // Remplissez le tableau avec des nombres aléatoires
       // printf("%d    ",t[i]);
    }
}



int main(){
    int *t;
    t = (int*)malloc(sizeof(int)*1000000);
    generate_table(t,1000000);
    printf("\n%.1000f",measureTime(bulles,t,1000000));
}
