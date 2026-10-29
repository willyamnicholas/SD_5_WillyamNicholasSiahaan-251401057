#include <iostream>
#include <queue>
using namespace std;

int main(){
    system("cls");
    queue<int> antrean;
    int input;

    while (cin >> input){
        antrean.push(input);
    } 
    
    do {
        cout << antrean.front() << " ";
        antrean.pop();

    } while (antrean.size() != 0);

    cout << endl;
    return 0;
}