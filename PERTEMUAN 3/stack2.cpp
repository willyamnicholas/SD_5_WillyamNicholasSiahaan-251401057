#include <iostream>
#include <stack>
using namespace std;

int main(){
    system("cls");
    stack<int> tumpukan;
    int input;

    while (cin >> input){
        tumpukan.push(input);
    } 
    
    do {
        cout << tumpukan.top() << " ";
        tumpukan.pop();

    } while (tumpukan.size() != 0);

    cout << endl;
    return 0;
}