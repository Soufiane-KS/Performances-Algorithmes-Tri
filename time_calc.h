#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Fonction pour mesurer le temps
double measureTime(void (*functionToMeasure)(int[], int), int tableau[], int taille) {
    clock_t start, end;
    double res;

    start = clock(); // Record the start time

    // Appelez la fonction passée en paramètre avec les paramètres
    functionToMeasure(tableau, taille);

    end = clock();
    
    res = (double)(end - start) / CLOCKS_PER_SEC;

    return res;
}

// Votre fonction de tri (par exemple, tri_insertion)
/*void tri_insertion(int tableau[], int taille) {
    int i, j, cle;

    for (i = 1; i < taille; i++) {
        cle = tableau[i];
        j = i - 1;

        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j = j - 1;
        }

        tableau[j + 1] = cle;
    }
}


int main() {
    int taille = 100000;
    int tableau[100000];

    // Initialisez le générateur de nombres aléatoires
    srand((unsigned)time(NULL));

    printf("Tableau non trié de taille 1000000 : ");
    for (int i = 0; i < taille; i++) {
        tableau[i] = rand() % 100000;  // Remplissez le tableau avec des nombres aléatoires de 0 à 999
    }

    printf("\n");

    // Utilisez la fonction measureTime avec votre fonction à mesurer et les paramètres
    double executionTime = measureTime(bulles, tableau, taille);


    printf("\nLe temps d'exécution de la fonction est de %.8f secondes.\n", executionTime);

    return 0;
}

*/