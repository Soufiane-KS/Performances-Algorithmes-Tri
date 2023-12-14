#include <stdio.h>
#include <windows.h>

void generate_table(int *t, int size)
{
    // Initialisez le générateur de nombres aléatoires
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < size; i++)
    {
        t[i] = rand() % 100000; // Remplissez le tableau avec des nombres aléatoires 
    }
}

void generate_bulle_sort_favorable(int *t, int size) {

    srand((unsigned)time(NULL));
    
    // Remplissez le tableau avec des nombres aléatoires triés en ordre croissant
    for (int i = 0; i < size - 10; i++) {
        t[i] = i + 1;
    }
    
    // Ajoutez quelques éléments non triés à la fin
    for (int i = size - 10; i < size; i++) {
        t[i] = rand() % 100000;
    }
}


void generate_selection_sort_favorable(int *t, int size) {

    srand((unsigned)time(NULL));
    
    // Remplissez le tableau avec des nombres aléatoires triés en ordre décroissant
    for (int i = 0; i < size - 10; i++) {
        t[i] = size - i;
    }
    
    // Ajoutez quelques éléments non triés à la fin
    for (int i = size - 10; i < size; i++) {
        t[i] = rand() % 100000;
    }
}


void generate_insertion_sort_favorable(int *t, int size) {

    srand((unsigned)time(NULL));
    
    // Remplissez la majorité du tableau avec des nombres aléatoires triés en ordre croissant
    for (int i = 0; i < size - 10; i++) {
        t[i] = i + 1;
    }
    
    // Ajoutez quelques éléments désordonnés à la fin
    for (int i = size - 10; i < size; i++) {
        t[i] = rand() % 100000;
    }
}