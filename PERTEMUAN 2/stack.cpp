#include <iostream>
using namespace std;

struct node{
    int value;
    node* next;
};

node* head = NULL;
node* tail = NULL;


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
    insertLast(100);
    display();

    insertLast(30);
    display();

    insertLast(20);
    display();


    deleteLast();
    display();

    deleteLast();
    display();


    return 0;
}