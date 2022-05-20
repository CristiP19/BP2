#include <iostream>

using namespace std;

struct Node {
    int inf;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *newElement = (Node *) malloc(sizeof(Node));
    newElement->inf = data;
    newElement->left = NULL;
    newElement->right = NULL;
    return newElement;
}

Node *creare() {
    int nr;
    cout << "Valoarea: ";
    cin >> nr;
    if (nr != 0) {
        Node *newElement = newNode(nr);
        cout << "Introduceti descendentul stang al nodului " << newElement->inf << " :" << endl;
        newElement->left = creare();
        cout << "Introduceti descendentul drept al nodului " << newElement->inf << " :" << endl;
        newElement->right = creare();
        return newElement;
    }
}

void RSD(Node *root) {
    if (root == NULL) {
        return;
    } else {
        cout << root->inf << " ";
        RSD(root->left);
        RSD(root->right);
    }
}

void SRD(Node *root) {
    if (root == NULL) {
        return;
    } else {
        SRD(root->left);
        cout << root->inf << " ";
        SRD(root->right);
    }
}

void SDR(Node *root) {
    if (root == NULL) {
        return;
    } else {
        SDR(root->left);
        SDR(root->right);
        cout << root->inf << " ";
    }
}

int sumaDiv3(Node *root) {
    if (root == NULL) return 0;
    int sum = 0;
    if ((root->inf) % 3 == 0) sum = root->inf;
    return sum + sumaDiv3(root->left) + sumaDiv3(root->right);
}

bool toatePare(Node *root) {
    if (root == NULL) return true;
    if (root->inf % 2 != 0) return false;
    else return (toatePare(root->left) && toatePare(root->right));
}

int numaiDrept(Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right != NULL) return 1;
    return (numaiDrept(root->left) + numaiDrept(root->right));
}

int main() {
    Node *root = creare();
    cout << "Parcurgerea preordine (RSD):" << endl;
    RSD(root);
    cout << "Suma nodurilor care se impart la 3: " << sumaDiv3(root);
    if (toatePare(root)) {
        cout << "\nToate valorile din arbore sunt pare" << endl;
    } else {
        cout << "\nExista cel putin o valoare impara in arbore" << endl;
    }
    if (numaiDrept(root) != 0) {
        cout << "Sunt " << numaiDrept(root) << " noduri numai cu descendent drept";
    } else {
        cout << "In arbore nu sunt noduri care sa aiba numai descendent drept";
    }
    return 0;
}


