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

        int maxSum = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            int sum = matrix[i][j] + matrix[i][j+1] + matrix[i+1][j] + matrix[i+1][j+1];
            if (sum > maxSum) maxSum = sum;
        }
    }
    cout << "Макс. сумма подматрицы 2x2: " << maxSum << endl;

    int sum = 0;
    for (int j = 0; j < n; j++) sum += matrix[0][j];
    
    bool magic = true;
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) rowSum += matrix[i][j];
        if (rowSum != sum) magic = false;
    }
    
    cout << "Магический квадрат: " << (magic ? "Да" : "Нет") << endl;
    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        delete[] rotated[i];
    }
    delete[] matrix;
    delete[] rotated;
    
    return 0;
}
    
