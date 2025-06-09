#ifndef TAXI_H
#define TAXI_H

#define MAX_TAXIS 200
#define COULEUR_MAX 20

typedef struct {
    char couleur[COULEUR_MAX];
    int matricule;
    int itineraire;  // entre 1 et 5 des  itinéraires proposés
} Taxi;

void enregistrerTaxi(Taxi taxis[], int *nbTaxis);
void afficherTaxis(Taxi taxis[], int nbTaxis);
int chercherTaxiParItineraire(Taxi taxis[], int nbTaxis, int itineraire, int *indices, int max);

#endif
