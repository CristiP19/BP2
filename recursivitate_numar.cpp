#include <iostream> //conectarea bibliotecii standard din C++ de intrare/iesire
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
/*
primeste un numar natural n si returneaza:
- prin parametrul a numarul format cu cifrele pare ale lui n
- prin parametrul b numarul format cu cifrele impare ale lui n
*/

void cifre1 (int n, int &a, int &b){
    while (n!=0){
        if (n % 2 == 0) a = a*10 + n % 10;
            else b = b*10 + n % 10;
        n /= 10;
    }
}
void cifre2 (int n, int &a, int &b){
  if (n<=9)
     if (n % 2 == 0) {a=n; b=0;}
      else {b=n; a=0;}
  else {
        cifre2(n/10, a, b);
        if (n % 2 == 0) a=a*10 + n % 10;
        else b=b*10 + n % 10;
   }
}
int main () {
    int n, a=0, b=0;
    cout<<"Introdu un numar intreg: ";
    cin>>n;
    cifre1(n,a,b);
    cout<<"a="<<a<<" b="<<b<<endl;
    a=0; b=0;
    cifre2(n,a,b);
    cout<<"a="<<a<<" b="<<b<<endl;
    return 0;
}
