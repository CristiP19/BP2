#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>

#define MAXLEN 100

using namespace std;

struct Carte
{
    int id;
    char denumire[MAXLEN];
    char nume[MAXLEN];
    int an;
    int exemplare;
};

struct Node
{
    Carte inf;
    Node *next;
};

Node *newNode(struct Carte carte)
{
    Node *newElement = (Node *)malloc(sizeof(struct Node));
    newElement->inf.id=carte.id;
    strcpy(newElement->inf.denumire, carte.denumire);
    strcpy(newElement->inf.nume, carte.nume);
    newElement->inf.an = carte.an;
    newElement->inf.exemplare = carte.exemplare;
    newElement->next = NULL;
    return newElement;
}

bool isEmpty(Node *lista)
{
    return lista == NULL;
}

void inserare(Node *&lista, struct Carte carte)
{
    Node *newElement = newNode(carte);
    if (isEmpty(lista))
    {
        lista = newElement;
        return;
    }
    else
    {
        Node *l = lista;
        while (l->next != NULL)
        {
            l = l->next;
        }
        l->next = newElement;
    }
}

void afisare(Node *lista)
{
    if (isEmpty(lista))
    {
        cout << "Lista este vida" << endl;
        return;
    }
    else
    {
        while (lista != NULL)
        {
            cout << lista->inf.id << " " << lista->inf.denumire << " " << lista->inf.nume << " " << lista->inf.an << " " <<lista->inf.exemplare << endl;
            lista = lista->next;
        }
    }
}

bool cautare(Node* lista, char denumire[MAXLEN]) {
    while(lista!=NULL) {
        if (strcmp(lista->inf.denumire, denumire)==0) {
            return true;
        }
        lista = lista->next;
    }
    return false;
}

int main() {
    Node* lista = NULL;
    struct Carte carte;
    int n;
    cout<<"Introduceti numarul de carti: ";
    cin>>n;
    for(int i=0; i<n; i++) {
        cout<<"Nr: "; cin>>carte.id;
        fflush(stdin);
        cout<<"Denumire: "; gets(carte.denumire);
        cout<<"Numele autorului: "; gets(carte.nume);
        cout<<"Anul editiei: "; cin>>carte.an;
        cout<<"Numarul de exemplare: "; cin>>carte.exemplare;
        inserare(lista, carte);
    }
    afisare(lista);
    char denumire[MAXLEN];
    fflush(stdin);
    cout<<"Denumirea cartii cautate: ";
    gets(denumire);
    if(cautare(lista, denumire)) {
        cout<<"Cartea " << denumire<<" este in lista";
    }
    else {
        cout<<"Cartea " << denumire << " nu este in lista";
    }
    return 0;
}
