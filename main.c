#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "taxi.h"
#include "itineraire.h"

void commanderTaxi(Client clients[], int nbClients, Taxi taxis[], int nbTaxis) {
    int matriculeClient;
    printf("Entrez votre matricule client: ");
    scanf("%d", &matriculeClient);
    int idxClient = chercherClient(clients, nbClients, matriculeClient);
    if (idxClient == -1) {
        printf("Client non enregistré.\n");
        return;
    }

    int itineraire;
    printf("Choisissez votre itineraire (1-5): ");
    scanf("%d", &itineraire);
    if (itineraire < 1 || itineraire > 5) {
        printf("Itineraire invalide.\n");
        return;
    }

    // Chercher un taxi disponible sur cet itinéraire
    int indices[MAX_TAXIS];
    int nbTrouves = chercherTaxiParItineraire(taxis, nbTaxis, itineraire, indices, MAX_TAXIS);

    if (nbTrouves == 0) {
        printf("Aucun taxi disponible sur cet itineraire.\n");
        return;
    }

    // Donner le premier taxi trouvé
    Taxi t = taxis[indices[0]];
    printf("Taxi assigné : Matricule %d, Couleur %s\n", t.matricule, t.couleur);
}

void afficherTrajetTaxi(Taxi taxis[], int nbTaxis, ListeItineraire itineraire[]) {
    int matriculeTaxi;
    printf("Entrez le matricule du taxi: ");
    scanf("%d", &matriculeTaxi);

    int idxTaxi = -1;
    for (int i = 0; i < nbTaxis; i++) {
        if (taxis[i].matricule == matriculeTaxi) {
            idxTaxi = i;
            break;
        }
    }
    if (idxTaxi == -1) {
        printf("Taxi non trouvé.\n");
        return;
    }

    int itin = taxis[idxTaxi].itineraire;
    printf("Trajet du taxi matricule %d (itineraire %d):\n", matriculeTaxi, itin);
    afficherItineraire(&itineraire[itin-1]);
}

int main() {
     printf("\n \nles itineraires sont:\n 1-nkolbisson->oyomabang->mec->citeVerte->mokolo\n 2-poste->marcheCentral->wada->tsinga->nkomkana\n 3-bastos->golf->emana->etoudi\n 4-madagascar->carriere->tonta->bankolo->leboudji\n 5-mokolo->madagascar->nkomkana->tsinga->briqueterie\n\n\n ");
    Client clients[MAX_CLIENTS];
    int nbClients = 0;

    Taxi taxis[MAX_TAXIS];
    int nbTaxis = 0;

    ListeItineraire itineraire[5];
    initialiserItineraires(itineraire);

    int choix;
    do {
        printf("\nMenu principal:\n");
        printf("1 - Enregistrer un client\n");
        printf("2 - Enregistrer un taxi\n");
        printf("3 - Afficher la liste des taxis\n");
        printf("4 - Afficher le trajet d'un taxi (par matricule)\n");
        printf("5 - Commander un taxi\n");
        printf("0 - Fermer le programme\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                enregistrerClient(clients, &nbClients);
                break;
            case 2:
                enregistrerTaxi(taxis, &nbTaxis);
                break;
            case 3:
                afficherTaxis(taxis, nbTaxis);
                break;
            case 4:
                afficherTrajetTaxi(taxis, nbTaxis, itineraire);
                break;
            case 5:
                commanderTaxi(clients, nbClients, taxis, nbTaxis);
                break;
            case 0:
                printf("Fermeture du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    // Libération mémoire liste chainée (optionnel)
    for (int i = 0; i < 5; i++) {
        Noeud *current = itineraire[i].tete;
        while (current) {
            Noeud *tmp = current;
            current = current->suivant;
            free(tmp);
        }
    }

    return 0;
}
