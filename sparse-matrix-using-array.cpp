// By Rajesh Reddy
#include<iostream>
using namespace std;

int main() {
    int rows, cols, nonZeroCount = 0;
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];

        for(int j = 0; j < cols; j++) {
            cout << "Enter the element at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
            if(matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    int **sparseMatrix = new int*[3];
    for(int i = 0; i < 3; i++) {
        sparseMatrix[i] = new int[nonZeroCount];
    }

    int k = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparseMatrix[0][k] = i;
                sparseMatrix[1][k] = j;
                sparseMatrix[2][k] = matrix[i][j];
                k++;
            }
        }
    }

    cout << "Sparse Matrix Representation: " << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < nonZeroCount; j++) {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;

    for(int i = 0; i < 3; i++) {
        delete [] sparseMatrix[i];
    }
    delete [] sparseMatrix;

    return 0;
}
