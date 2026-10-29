#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
};

node* head = NULL;
node* tail = NULL;

// fungsi insert linked list
// 1. Insert First
void insertFirst(int n) {
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        newnode -> next = head;
        head = newnode;
    }
}


// 2. Insert Last
void insertLast(int n) {
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = head; 
    } else {
        tail -> next = newnode;
        tail = newnode;
    }
}


// 3. Insert After
void insertAfter (int n, int check) {
    if(head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    node *p = head;
    while (p != NULL && p -> value != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
        delete newnode;
    } else {
        newnode -> next = p -> next;
        p -> next = newnode;
        if (p == tail) {
            tail = newnode;
        }
    }
}

// fungsi delete pada Linked List
//3. Delete Middle
void deleteMiddle(int check) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    if (head -> value == check) {
        node *temp = head;
        head = head -> next;
        if (head == NULL) tail = NULL;
        delete temp;
        return;
    }

    node *p = head;
    while (p -> next != NULL && p -> next -> value != check) {
        p = p -> next;
    }

    if (p -> next == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan!\n";
    } else {
        node *temp = p -> next;
        p -> next = temp -> next;
        if (temp == tail) tail = p;
        delete temp;
    }
}

void display() {
    node *temp = head;
    cout << "Isi linked list: ";
    while (temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}


int main() {
    system("cls");
    int x, nilai, check;
    char ulang = 'n';
    cout << "Nilai Mahasiswa\n";

    do {
        cout << "Masukkan nilai: ";
        cin >> x;
        if (x != -1) insertLast(x);
        getchar();
        display();
    } while (x != -1);

    
    do {
        system("cls");

        cout << "Pilih\n";
        cout << "1. Add first\n"; 
        cout << "2. Add last\n"; 
        cout << "3. Add after\n";
        cout << "4. Delete data\n";

        cin >> x;
        getchar();

        if (x == 1) {
            cout << "Masukkan nilai: ";
            cin >> nilai;
            getchar();
            insertFirst(nilai);
            display();
        } else if (x == 2) {
            cout << "Masukkan nilai: ";
            cin >> nilai;
            getchar();
            insertLast(nilai);
            display();
        } else if (x == 3) {
            cout << "Masukkan nilai: ";
            cin >> nilai;
            getchar();

            cout << "Masukkan setelah nilai: ";
            cin >> check;
            insertAfter(nilai, check);
            display();
        } else if (x == 4) {
            cout << "Masukkan nilai yang mau dihapus: ";
            cin >> nilai;
            deleteMiddle(nilai);
            display();
        }
        cout << "Mau ulang lagi? (Y/N)";
        cin >> ulang;
    } while (ulang != 'n' || ulang != 'N');

    return 0;
}