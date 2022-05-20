#include <iostream> //conectarea bibliotecii standard din C++ de intrare/iesire
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
/*
se citeste un vector cu n elemente numere naturale. Sa se inlocuiasca fiecare element al vectorului cu suma cifrelor 
cu aceeasi paritate ca si indicele elementului.

{123, 475, 924} => {2, 12, 6}
  0    1    2
*/
void citire(int A[], int n){
    cout<<"Introduceti elementele vectorului:"<<endl;
    for (int i = 0; i<n; i++){
        cin>>A[i];
    }
}

void afisare (int A[], int n){
    cout<<"Elementele vectorului:"<<endl;
    for (int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int sumCif(int m; int p){
    //1256 p=1 s=1+5
    int sum = 0;
    int c;
    while m != 0 {
        c %= 10;
        if (c % 2 == p) 
            sum += c;
        m /=  10;
    }
    return sum;
}

void inlocuire (int A[], int n){
    for (int i=0; i<n; i++){
        A[i] = sumCif(A[i], i%2);
    }
}

int main () {
    int A[100], n;
    cout<<"Numarul de elemente n = ";
    cin>>n;
    citire(A,n);
    afisare(A,n);
    inlocuire(A,n);
    afisare(A,n);
    return 0;
}
