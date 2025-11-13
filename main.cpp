#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Размер матрицы: ";
    cin >> n;
    
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    
    cout << "Введите матрицу:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Ваша матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int** rotated = new int*[n];
    for (int i = 0; i < n; i++) {
        rotated[i] = new int[n];
        for (int j = 0; j < n; j++) {
            rotated[i][j] = matrix[n-j-1][i];
        }
    }
    
    cout << "Поворот на 90°:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }
