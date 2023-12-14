#include"generate_matrix.h"
#include"convolusion_product.h"
#include"trace_matrix.h"

void display_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int N, p;

    printf("Entrez la taille de la matrice carree A (N) : ");
    scanf("%d", &N);
    
    printf("Entrez la valeur de p (1 <= 2p+1 <= N/3) : ");
    scanf("%d", &p);

    int **randomMatrix = get_random_matrice(N);

    printf("Elements de la matrice aleatoire :\n");
    display_matrix(randomMatrix, N);

    int matrixTrace = trace_matrice(randomMatrix, N);
    printf("Trace de la matrice : %d\n", matrixTrace);

    int **convMatrix = get_random_matrice(N);

    printf("Elements de la matrice de convolution :\n");
    display_matrix(convMatrix, p);

    int **convResult = conv_matrices(randomMatrix, convMatrix, N, p);
    printf("Resultat de la convolution :\n");
    display_matrix(convResult,N - p + 1 );

    free_matrix(randomMatrix, N);
    free_matrix(convMatrix, N);
    free_matrix(convResult, N - p + 1);
    return 0;
}