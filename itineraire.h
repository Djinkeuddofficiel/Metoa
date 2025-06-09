#ifndef ITINERAIRE_H
#define ITINERAIRE_H

typedef struct Noeud {
    char nomLieu[50];
    struct Noeud *suivant;
} Noeud;

typedef struct {
    Noeud *tete;
} ListeItineraire;

void initialiserItineraires(ListeItineraire itineraire[]);
void afficherItineraire(ListeItineraire *itineraire);

#endif
