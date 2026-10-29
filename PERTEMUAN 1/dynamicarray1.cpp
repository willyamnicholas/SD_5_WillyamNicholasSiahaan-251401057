#include <iostream>
using namespace std;

int main(){
    system("cls");
    int n;

    // Alokasi memori untuk array secara dinamis
    
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int* arr = new int[n];

    cout << "imputasi data" <<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Data ke-" << 1+i << ": ";
        cin >> arr[i];
    }

    cout <<endl;

    cout << "Output data"<< endl;
     for (int i = 0; i < n; i++)
    {
        cout << "Data ke-" << 1+i << ": "<< arr[i] << endl;

    }

    delete[]arr;
    return 0;
}     