#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itineraire.h"

static Noeud* creerNoeud(const char *nom) {
    Noeud *n = malloc(sizeof(Noeud));
    if (!n) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(n->nomLieu, nom);
    n->suivant = NULL;
    return n;
}

static void ajouterNoeud(ListeItineraire *liste, const char *nom) {
    Noeud *n = creerNoeud(nom);
    if (liste->tete == NULL) {
        liste->tete = n;
    } else {
        Noeud *tmp = liste->tete;
        while (tmp->suivant != NULL)
            tmp = tmp->suivant;
        tmp->suivant = n;
    }
}

void initialiserItineraires(ListeItineraire itineraire[]) {
    for (int i = 0; i < 5; i++)
        itineraire[i].tete = NULL;

    // Itinéraire 1 : nkolbisson->oyomabang->mec->citeVerte->mokolo
    ajouterNoeud(&itineraire[0], "nkolbisson");
    ajouterNoeud(&itineraire[0], "oyomabang");
    ajouterNoeud(&itineraire[0], "mec");
    ajouterNoeud(&itineraire[0], "citeVerte");
    ajouterNoeud(&itineraire[0], "mokolo");

    // Itinéraire 2 : poste->marcheCentral->wada->tsinga->nkomkana
    ajouterNoeud(&itineraire[1], "poste");
    ajouterNoeud(&itineraire[1], "marcheCentral");
    ajouterNoeud(&itineraire[1], "wada");
    ajouterNoeud(&itineraire[1], "tsinga");
    ajouterNoeud(&itineraire[1], "nkomkana");

    // Itinéraire 3 : bastos->golf->emana->etoudi
    ajouterNoeud(&itineraire[2], "bastos");
    ajouterNoeud(&itineraire[2], "golf");
    ajouterNoeud(&itineraire[2], "emana");
    ajouterNoeud(&itineraire[2], "etoudi");

    // Itinéraire 4 : madagascar->carriere->tonta->bankolo->leboudji
    ajouterNoeud(&itineraire[3], "madagascar");
    ajouterNoeud(&itineraire[3], "carriere");
    ajouterNoeud(&itineraire[3], "tonta");
    ajouterNoeud(&itineraire[3], "bankolo");
    ajouterNoeud(&itineraire[3], "leboudji");

    // Itinéraire 5 : mokolo->madagascar->nkomkana->tsinga->briqueterie
    ajouterNoeud(&itineraire[4], "mokolo");
    ajouterNoeud(&itineraire[4], "madagascar");
    ajouterNoeud(&itineraire[4], "nkomkana");
    ajouterNoeud(&itineraire[4], "tsinga");
    ajouterNoeud(&itineraire[4], "briqueterie");
}

void afficherItineraire(ListeItineraire *itineraire) {
    Noeud *current = itineraire->tete;
    while (current != NULL) {
        printf("%s", current->nomLieu);
        if (current->suivant != NULL)
            printf(" -> ");
        current = current->suivant;
    }
    printf("\n");
}
