#include <iostream>

using namespace std;

int main()
{
    cout << "Number of rows: \n";
    int rows;
    cin >> rows;

    cout << "Number of columns: \n";
    int columns;
    cin >> columns;

    if (rows <= 0 || columns <= 0) {
        cout << "Invalid number of rows/columns";
        return 1;
    }

    int** matrix = new int* [rows];
    int amount = 1;
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            cout << amount << " element: \n";
            cin >> matrix[i][j];
            amount++;
        }
    }

    bool* answer = new bool[rows];
    for (int i = 0; i < rows; i++) {
        bool isAsc = true;
        for (int j = 1; j < columns; j++) {
            if (matrix[i][j] <= matrix[i][j - 1]) {
                isAsc = false;
                break;
            }
        }
        if (isAsc) {
            answer[i] = true;
        }
        else {
            answer[i] = false;
        }
    }

    cout << "Answer: ";
    for (int i = 0; i < rows; i++) {
        cout << answer[i] << " ";
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] answer;

    return 0;
}
