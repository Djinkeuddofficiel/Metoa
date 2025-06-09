#ifndef CLIENT_H
#define CLIENT_H

#define MAX_CLIENTS 300
#define NOM_MAX 50

typedef struct {
    char nom[NOM_MAX];
    int matricule;
} Client;

void enregistrerClient(Client clients[], int *nbClients);
int chercherClient(Client clients[], int nbClients, int matricule);

#endif
