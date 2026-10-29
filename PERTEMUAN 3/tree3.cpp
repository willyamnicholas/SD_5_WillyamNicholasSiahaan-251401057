#include <iostream>
using namespace std;

struct node {
    int data;
    node* kanan;
    node* kiri;
};

node* akar = NULL;

// Fungsi menambahkan node
void addnode(node** akar, int value) {
    if(*akar == NULL) {
        node* baru = new node;
        baru -> data = value;
        baru -> kiri = NULL;
        baru -> kanan = NULL;
        *akar = baru;
    }
}

// Fungsi in order
void inOrder(node* akar) {
    if (akar != NULL) {
        inOrder(akar -> kiri);
        cout << akar -> data << " ";
        inOrder(akar -> kanan);
    }
}

// Fungsi pre order
void preOrder(node* akar) {
    if (akar != NULL) {
        cout << akar -> data << " ";
        preOrder(akar -> kiri);
        preOrder(akar -> kanan);
    }
}

// Fungsi post order
void postOrder(node* akar) {
    if (akar != NULL) {
        postOrder(akar -> kiri);
        postOrder(akar -> kanan);
        cout << akar -> data << " ";
    }
}

int main() {
    system("cls");

    addnode(&akar, 15);
    addnode(&akar -> kiri, 10);
    addnode(&akar -> kanan, 25);
    addnode(&akar -> kiri -> kiri, 7);
    addnode(&akar -> kiri -> kanan, 12);

    cout << "Tampilan In Order\n";
    inOrder(akar);
    cout << endl;
    cout << endl;

    cout << "Tampilan Post Order\n";
    postOrder(akar);
    cout << endl;
    cout << endl;

    cout << "Tampilan Pre Order\n";
    preOrder(akar);
    cout << endl;
    cout << endl;

    return 0;
}