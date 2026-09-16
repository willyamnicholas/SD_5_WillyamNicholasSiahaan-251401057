#include <iostream>
using namespace std;

int main (){
    system ("cls");

    int arr3[3][3][4];
    int nilai = 2;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                arr3[i][j][k] = nilai;
                nilai += 2;
            }
        }
        cout << "\n";
    }


    for (int i = 0; i < 3; i++){
        cout << "Lapis ke-" << i+1 << endl;
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                cout << arr3[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}