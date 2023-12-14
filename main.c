#include<stdio.h>
#include<stdlib.h>
#include "time_calc.h"
#include "algos_tri.h"
#include "table_generate.h"
#include "tracer_courbe.h"
#define MAX_SIZE 100000



int main(int argc , char* argv[]){

    int *t;
    int i,choix,moyenneDeDonnees,conteur=0;
    double tempsMoyenneInsertion,tempsMoyenneBulle,tempsMoyenneSelection; //utilisé pour le lissage
  FILE* f = fopen("data.txt","w");
    if (f!=NULL)
    {
            fprintf(f,"0\t0\t0\t0\t\n");
    printf("\n|-----------------Comparaison du performance des algorithmes de tri-----------------|\nSelectionner l'un des tests a est effectue.(entre 1 et 4)\n\t1-test aleatoire.\n\t2-test favorable au algorithme insertion.\n\t3-test favorable au algorithme bulles.\n\t4-test favorable au algorithme selection.\n\tVotre choix:");
    scanf("%d",&choix);
    if(choix == 1|| choix == 2 || choix == 3 || choix == 4){
    for(int i = 0 ; i<= MAX_SIZE ; i+=1000){
            t = (int*)malloc(sizeof(int)*i);
            if (choix == 1)
            {
                generate_table(t,i);
            }else if(choix == 2){
                generate_insertion_sort_favorable(t,i);
            }else if(choix == 3){
                generate_bulle_sort_favorable(t,i);
            }else generate_selection_sort_favorable(t,i);
            conteur++;
            double time1 = measureTime(insertion,t,i);
            double time2 = measureTime(bulles,t,i);
            double time3 = measureTime(selection,t,i);
            tempsMoyenneInsertion+=time1;
            tempsMoyenneBulle+=time2;
            tempsMoyenneSelection+=time3;
            moyenneDeDonnees+=i;
            if(conteur%3 == 0){
            fprintf(f,"%d\t%lf\t%lf\t%lf\t\n",moyenneDeDonnees/3,tempsMoyenneInsertion/3,tempsMoyenneBulle/3,tempsMoyenneSelection/3);
            printf("%d\t%lf\t%lf\t%lf\t\n",moyenneDeDonnees/3,tempsMoyenneInsertion/3,tempsMoyenneBulle/3,tempsMoyenneSelection/3);
            tempsMoyenneInsertion =0;
            tempsMoyenneBulle=0;
            tempsMoyenneSelection=0;
            moyenneDeDonnees=0;
            }

        } }else {printf("ERREUR:vous devez choisir un nombre entre 1 et 4");
        exit(0);
        }
        fclose(f);
        tracer_courbe();

    }else
        printf("ouverture du fichier est imposiible !");

    return 0;
}
