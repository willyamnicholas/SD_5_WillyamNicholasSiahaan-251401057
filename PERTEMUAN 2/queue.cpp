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
    insertLast(80);
    display();
 
    insertLast(20);
    display();

    insertLast(50);
    display();


    deleteFirst();
    display();

    deleteFirst();
    display();


    return 0;
}