#include <stdio.h>
#include <string.h>
#include "client.h"

void enregistrerClient(Client clients[], int *nbClients) {
    if (*nbClients >= MAX_CLIENTS) {
        printf("Nombre maximum de clients atteint.\n");
        return;
    }
    Client c;
    printf("Nom du client: ");
    scanf(" %49[^\n]", c.nom);
    printf("Matricule du client (entier): ");
    scanf("%d", &c.matricule);
    
    // Vérifier si matricule existe déjà
    for (int i = 0; i < *nbClients; i++) {
        if (clients[i].matricule == c.matricule) {
            printf("Ce matricule existe déjà.\n");
            return;
        }
    }
    
    clients[*nbClients] = c;
    (*nbClients)++;
    printf("Client enregistré avec succès.\n");
}

int chercherClient(Client clients[], int nbClients, int matricule) {
    for (int i = 0; i < nbClients; i++) {
        if (clients[i].matricule == matricule)
            return i;
    }
    return -1; // non trouvé
}
