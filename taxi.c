#include <stdio.h>
#include <string.h>
#include "taxi.h"


/*-------------------------------------------------------------------------------*/


void enregistrerTaxi(Taxi taxis[], int *nbTaxis) {
    if (*nbTaxis >= MAX_TAXIS) {
        printf("Nombre maximum de taxis atteint.\n");
        return;
    }
    Taxi t;
    printf("Couleur du taxi: ");
    scanf(" %19[^\n]", t.couleur);
    printf("Matricule du taxi (entier): ");
    scanf("%d", &t.matricule);
    
    // Vérifier si matricule existe déjà
    for (int i = 0; i < *nbTaxis; i++) {
        if (taxis[i].matricule == t.matricule) {
            printf("Ce matricule existe déjà.\n");
            return;
        }
    }
    
    printf("Itineraire du taxi (1-5): ");
    scanf("%d", &t.itineraire);
    if (t.itineraire < 1 || t.itineraire > 5) {
        printf("Itineraire invalide.\n");
        return;
    }
    
    taxis[*nbTaxis] = t;
    (*nbTaxis)++;
    printf("Taxi enregistré avec succès.\n");
}

/*-------------afficher les taxi-----------------------------------------------------------------------*/

void afficherTaxis(Taxi taxis[], int nbTaxis) {
    if (nbTaxis == 0) {
        printf("Aucun taxi enregistré.\n"); // on verifie si ona des taxis enregistrés
        return;
    }
    printf("Liste des taxis:\n");
    for (int i = 0; i < nbTaxis; i++) {
        printf("Matricule: %d, Couleur: %s, Itineraire: %d\n",
               taxis[i].matricule, taxis[i].couleur, taxis[i].itineraire);
    }
}


// fonction pour chercher un taxi par itineraire 


int chercherTaxiParItineraire(Taxi taxis[], int nbTaxis, int itineraire, int *indices, int max) {
    int count = 0;
    for (int i = 0; i < nbTaxis && count < max; i++) {
        if (taxis[i].itineraire == itineraire) {
            indices[count++] = i;
        }
    }
    return count;
}
