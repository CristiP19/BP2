#include <iostream>
#include <string>
using namespace std;
struct Carte { int numar; string denumirea; string numele; int anul; int nr_exemplare;
};
struct nod { Carte info; nod *urm;};
void adauga_nod(nod *&prim, nod *&ultim );
nod *cauta (nod *p, string x);
int main (){
    nod *prim, *ultim, *p;
    int key;
    string caut;
    cout << "Daca doriti sa adaugati inserati 1" << endl;
    cin >> key;
    while (key ==1) {
        adauga_nod(prim, ultim);
        cout << "Daca doriti sa adaugati inserati 1" << endl;
        cin >> key;
    }
cout << "Introduceti denumirea cartii cautate" << endl;
cin >> caut;
p=cauta(prim,caut);
cout <<p->info.denumirea<< endl;
}
void adauga_nod(nod *&prim, nod *&ultim ){
    prim=new nod;
    ultim=prim;
    cout << "Introduceti numarul"<< endl;
    cin >> prim->info.numar;
    fflush(stdin);
    cout << "introduceti dunumirea"<< endl;
    cin >> prim->info.denumirea;
    fflush(stdin);
    cout << "introduceti numele autorului "<< endl;
    cin >> prim->info.numele;
    cout << "introduceti anul editiei"<< endl;
    cin >> prim->info.anul;
    cout << "introduceti numarul de exemplare"<< endl;
    cin >> prim->info.nr_exemplare;
    prim->urm=NULL;
}
nod *cauta (nod *p, string x){
    while (p->urm!=NULL&&p->urm->info.denumirea!=x)
        p=p->urm;
    return p;
}

