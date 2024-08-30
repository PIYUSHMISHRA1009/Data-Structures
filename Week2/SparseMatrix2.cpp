#include <iostream>
using namespace std;

const int MAX_NON_ZERO = 1000; // Arbitrary large number

int main() {
    int k, m;
    cout << "Enter the number of Rows:\t";
    cin >> k;
    cout << "Enter the number of Columns:\t";
    cin >> m;
    
    int arr[k][m];
    
    cout << "Enter the entries of the Sparse Matrix:\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
        cout << "\n";
    }

    cout << "The Sparse Matrix: \n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";
    
    int sparseArray[3 * MAX_NON_ZERO];
    int index = 0;
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                sparseArray[index++] = i;
                sparseArray[index++] = j;
                sparseArray[index++] = arr[i][j];
            }
        }
    }

    int nonZeroCount = index / 3;

    cout << "The 1-D Conversion of the Sparse Matrix is:\n";
    cout << "Row\tColumn\tValue\n";
    for (int i = 0; i < nonZeroCount; i++) {
        cout << sparseArray[3*i] << "\t" << sparseArray[3*i + 1] << "\t" << sparseArray[3*i + 2] << "\n";
    }

    cout << "\n";

    int reconstructedMatrix[k][m] = {0};

    for (int i = 0; i < nonZeroCount; i++) {
        int row = sparseArray[3*i];
        int col = sparseArray[3*i + 1];
        int value = sparseArray[3*i + 2];
        reconstructedMatrix[row][col] = value;
    }

    cout << "The Reconstructed Sparse Matrix:\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cout << reconstructedMatrix[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}

