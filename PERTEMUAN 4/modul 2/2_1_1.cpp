#include <iostream>
using namespace std;

struct node{
    int value;
    node* next;
};

node* head = NULL;
node* tail = NULL;


// Fungsi/jenis insert linked list
// 1. Insert first
void insertFirst(int n){
    node *newnode = new node;
    newnode->value = n;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}

// 2. Insert last
void insertLast(int n){
    node *newnode = new node;
    newnode->value = n;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        tail = head;
    }else{
        tail->next = newnode;
        tail = newnode;
    }
}

// 3. Insert after
void insertAfter(int n, int check){
    if(head == NULL){
        cout << "List kosong!" << endl;
        return;
    }
        
    node *newnode = new node;
    newnode->value = n;
    newnode->next = NULL;

    node *p = head;

    while(p != NULL && p->value != check){
        p = p->next;
    }

    if(p == NULL){
        cout << "Node dengan nilai " << check
             << " tidak ditemukan!" << endl;
        delete newnode;
    }else{
        newnode->next = p->next;
        p->next = newnode;

        if(p == tail){
            tail = newnode;
        }
    }
}


// Fungsi delete pada linked list
// 1. Delete Fisrt
void deleteFirst(){
    if(head == NULL){
        cout << "List kosong!" << endl;
        return;
    }

    node *temp = head;
    head = head->next;

    if(head == NULL){
        tail = NULL;
    }

    delete temp;
}

// 2. Delete last
void deleteLast(){
    if(head == NULL){
        cout << "List kosong!" << endl;
        return;
    }

    if(head == tail){
        delete head;
        head = tail = NULL;
        return;
    }

    node *p = head;

    while(p->next != tail){
        p = p->next;
    }

    delete tail;
    tail = p;
    tail->next = NULL;
}

// 3. Delete Middle
void deleteMiddle(int check){
    if(head == NULL){
        cout << "List kosong!" << endl;
        return;
    }

    if(head->value == check){
        deleteFirst();
        return;
    }

    node *p = head;

    while(p->next != NULL && p->next->value != check){
        p = p->next;
    }

    if(p->next == NULL){
        cout << "Node dengan nilai "
             << check       
             << " tidak ditemukan!" << endl;
    }else{
        node *temp = p->next;
        p->next = temp->next;

        if(temp == tail){
            tail = p;
        }

        delete temp;
    }
}

// Display
void display(){
    node *temp = head;

    cout << "Isi linked list: ";

    while(temp != NULL){
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main(){
    system("cls");
    cout << "Nilai mahasiswa:" << endl;
    int nilai, x;
    // do{
    //     cout << "Masukkan nilai mahasiswa (0 untuk berhenti): ";
    //     cin >> x;
    //     getchar();
    //     insertLast(x);
    //     display();
    // } while (nilai != 0);

    do { 
    cout << "Pilih" << endl;
    cout << "1. Insert First" << endl;
    cout << "2. Insert Last" << endl;
    cout << "3. Insert After" << endl;
    cout << "4. Delete First" << endl;
    cout << "5. Delete Last" << endl;
    cout << "6. Delete Middle" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih menu yang ingin digunakan: ";

    cin >> x;
    if (x == 1){
        cout << "Masukkan nilai: ";
        cin >> nilai;
        insertFirst(nilai);
        display();
    } else if (x == 2){
        cout << "Masukkan nilai: ";
        cin >> nilai;
        insertLast(nilai);
        display();
    } else if (x == 3){
        int y;
        cout << "Masukkan nilai: ";
        cin >> nilai;
        cout << "Masukkan nilai setelahnya: ";
        cin >> y;
        insertAfter(nilai, y);
        display();
    } else if (x == 4){
        deleteFirst();
        display();
    } else if (x == 5){
        deleteLast();
        display();
    } else if (x == 6){
        cout << "Masukkan nilai yang ingin dihapus: ";
        cin >> nilai;
        deleteMiddle(nilai);
        display();
    }
}while (x != 0);


    // insertFirst(10);
    // display();

    // insertFirst(5);
    // display();

    // insertLast(20);
    // display();

    // insertAfter(30,10);
    // display();

    // deleteFirst();
    // display();

    // deleteLast();
    // display();

    // deleteMiddle(30);
    // display();

    return 0;
}