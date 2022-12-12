#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <algorithm>

using namespace std;

class Matrix
{
public:
    int row, col, scalar;
    int matrix[10][10];
    int tempmatrix[10][10];
    int result[10][10];

public:
    // Default Constructor.
    Matrix()
    {
        row = 0;
        col = 0;
        scalar = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
                tempmatrix[10][10];
                result[i][j] = 0;
            }
        }
    }

    // Constructor.
    Matrix(int r, int c, int s)
    {
        row = r;
        col = c;
        scalar = s;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
                tempmatrix[10][10];
                result[i][j] = 0;
            }
        }
    }

    // Operator overload.
    int &operator()(int row, int col)
    {
        return matrix[row][col];
    }
    // Get matrix size and populate all matrix elements.
    void getInput()
    {
        do
        {
            cout << "Masukkan Banyak Baris Matrix = ";
            cin >> row;
            cout << "Masukkan Banyak Kolom Matrix = ";
            cin >> col;
            if (row < 1 || col < 1 || row > 10 || col > 10)
            {
                cout << "Inputan tidak valid. Min size = 1x1 and max size = 10x10.\n";
            }
        } while (row < 1 || col < 1 || row > 10 || col > 10);

        cout << "Urutan input matrix dari kiri atas ke kanan bawah\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Matrix Input (" << i << "," << j << ") = ";
                cin >> matrix[i][j];
            }
        }
    }

    // Output the full matrix to the screen in matrix representation.
    void displayMatrix()
    {

        for (int i = 0; i < row; i++)
        {
            cout << " |";
            for (int j = 0; j < col; j++)
            {

                cout << setw(3) << matrix[i][j];
                cout << " ";
            }
            cout << " |";
            cout << endl;
        }
    }

    // Output the full resultant matrix to the screen in matrix representation.
    void displayResultMatrix(int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << " |";
            for (int j = 0; j < cols; j++)
            {
                cout << setw(3) << result[i][j];
                cout << " ";
            }
            cout << " |";
            cout << endl;
        }
    }

    // Perform scalar multiplication.
    void perkalianSkalar()
    {
        cout << "Masukkan nilai skalar untuk mengalikan matrix: ";
        cin >> scalar;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] *= scalar;
            }
        }
        cout << "hasil perkalian matrix dengan skalar " << scalar << " : " << endl;
        displayMatrix();
    }

    // Perform matrix addition.
    void penjumlahanMatrix(Matrix m)
    {
        if (row == m.row && col == m.col)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrix[i][j] += m(i, j);
                }
            }
            cout << "hasil penjumlahan : " << endl;
            displayMatrix();
        }
        else
        {
            cout << "Operasi penambahan tidak bisa dilakukan dengan matrix ini\n";
        }
    }

    void penguranganMatrix(Matrix m)
    {
        if (row == m.row && col == m.col)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrix[i][j] -= m(i, j);
                }
            }
            cout << "hasil pengurangan : " << endl;
            displayMatrix();
        }
        else
        {
            cout << "Operasi pengurangan tidak bisa dilakukan dengan matrix ini\n";
        }
    }

    // Perform matrix multiplication.
    void perkalianMatrix(Matrix m)
    {
        if (col == m.row)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < m.col; j++)
                {
                    result[i][j] = 0;
                    for (int k = 0; k < m.row; k++)
                    {
                        result[i][j] += matrix[i][k] * m(k, j);
                    }
                }
            }
            cout << "hasil perkalian : " << endl;
            displayResultMatrix(row, m.col);
        }
        else
        {
            cout << "operasi perkalian tidak bisa dilakukan dengan matrix ini\n";
        }
    }

    // Transpose matrix.
    void transpose()
    {
        int temp = row;
        row = col;
        col = temp;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result[i][j] = matrix[j][i];
            }
        }
        cout << "hasil transpose : " << endl;

        displayResultMatrix(row, col);
    }

    // Swaps two rows.
    void swapRows(int row1, int row2)
    {
        if (row1 < row && row2 < row)
        {
            int temp[1][col];
            for (int i = 0; i < col; i++)
            {
                temp[0][i] = matrix[row1][i];
                matrix[row1][i] = matrix[row2][i];
                matrix[row2][i] = temp[0][i];
            }
        }
        else
        {
            cout << "Tidak bisa mengakses spesifik baris\n";
        }
    }

    int carideterminan(Matrix a, int row)
    {
        double determinan = 0;
        float hasil1, hasil2, hasil3, hasil4;
        if (col == row)
        {

            if (row == 1)
            {
                determinan = matrix[0][0];
                return determinan;
            }
            else if (row == 2)
            {
                determinan = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
                return determinan;
            }
            else if (row == 3)
            {
                determinan = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
                return determinan;
            }
            else if (row == 4)
            {
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                        hasil1 = (matrix[1][1] * matrix[2][2] * matrix[3][3]) + (matrix[1][2] * matrix[2][3] * matrix[3][1]) + (matrix[1][3] * matrix[2][1] * matrix[3][2]) - (matrix[3][1] * matrix[2][2] * matrix[1][3]) - (matrix[3][2] * matrix[2][3] * matrix[1][1]) - (matrix[3][3] * matrix[2][1] * matrix[1][2]);

                    hasil2 = (matrix[1][0] * matrix[2][2] * matrix[3][3]) + (matrix[1][2] * matrix[2][3] * matrix[3][0]) + (matrix[1][3] * matrix[2][0] * matrix[3][2]) - (matrix[3][0] * matrix[2][2] * matrix[1][3]) - (matrix[3][2] * matrix[2][3] * matrix[1][0]) - (matrix[3][3] * matrix[2][0] * matrix[1][2]);

                    hasil3 = (matrix[1][0] * matrix[2][1] * matrix[3][3]) + (matrix[1][1] * matrix[2][3] * matrix[3][0]) + (matrix[1][3] * matrix[2][0] * matrix[3][1]) - (matrix[2][1] * matrix[1][3] * matrix[3][0]) - (matrix[3][1] * matrix[2][3] * matrix[1][0]) - (matrix[3][3] * matrix[2][0] * matrix[1][1]);

                    hasil4 = (matrix[1][0] * matrix[2][1] * matrix[3][2]) + (matrix[1][1] * matrix[2][2] * matrix[3][0]) + (matrix[1][2] * matrix[2][0] * matrix[3][1]) - (matrix[3][0] * matrix[2][1] * matrix[1][2]) - (matrix[3][1] * matrix[2][2] * matrix[1][0]) - (matrix[3][2] * matrix[2][0] * matrix[1][1]);

                    // hitung determinan matriks
                    cout << '\n';

                    determinan = (hasil1 * matrix[0][0] * 1) + (hasil2 * matrix[0][1] * -1) + (hasil3 * matrix[0][2] * 1) + (hasil4 * matrix[0][3] * -1);

                    return determinan;

                    /**
                    // output hasil determinan matriks
                    cout << "Determinan Matriks A = " << (hasil1 * matrix[0][0] * 1) << " + " << (hasil2 * matrix[0][1] * -1) << " + " << (hasil3 * matrix[0][2] * 1) << " + " << (hasil4 * matrix[0][3] * -1) << " = " << determinan << endl;
                    */
                }
            }
            else
            {
                {
                    for (int x = 0; x < row; x++)
                    {
                        int subi = 0;
                        for (int i = 1; i < row; i++)
                        {
                            int subj = 0;
                            for (int j = 0; j < row; j++)
                            {
                                if (j == x)
                                    continue;
                                tempmatrix[subi][subj] = matrix[i][j];
                                subj++;
                            }
                            subi++;
                        }
                        // Recursive
                        determinan = determinan + (pow(-1, x) * matrix[0][x] * carideterminan(a, row - 1));
                    }
                }
                return determinan;
            }
        }
        else
        {
            cout << "Tidak bisa menemukan determinan matrix. (kolom == baris)\n";
        }
        return EXIT_SUCCESS;
        // cout << "The determinan of this matrix is: " << determinan << endl;
    }
};

int main()
{
    int choice, row, col;
    string proceed, remakeMatrix;
    int i, j, n;
    // float a[100][100], d[100][100], deter;
    Matrix a, b;
    do
    {
        system("cls");
        cout << "=================================================\n"
             << "|        Matrix Calculator by Dwi Prabowo       |\n"
             << "=================================================\n";
        cout << "*            Matrix yang digunakan:             *\n";
        a.displayMatrix();
        cout << "-------------------------------------------------\n";
        cout << "|    Pilih 1 untuk Perkalian skalar             |\n"
             << "|    Pilih 2 untuk penjumlahan matrix           |\n"
             << "|    Pilih 3 untuk pengurangan matrix           |\n"
             << "|    Pilih 4 untuk perkalian matrix             |\n"
             << "|    Pilih 5 untuk transpose matrix             |\n"
             << "|    Pilih 6 untuk mencari determinan matrix    |\n"
                "-------------------------------------------------\n";

        cout << "Masukkan Pilihan Anda: ";
        cin >> choice;
        if (choice == 1)
        {
            if (a.row == 0)
            {
                a.getInput();
                cout << "Matrix A : " << endl;
                a.displayMatrix();
            }
            a.perkalianSkalar();
        }
        else if (choice == 2)
        {
            if (a.row == 0)
            {

                a.getInput();
                cout << "Matrix A : " << endl;
                a.displayMatrix();
                b.getInput();
                cout << "Matrix B : " << endl;
                b.displayMatrix();
            }
            else
            {
                cout << "Operasi Ini membutuhkan matrix kedua. Silahkan Inputkan Matrix kedua.\n";
                b.getInput();
                cout << "Matrix B : " << endl;
                b.displayMatrix();
            }
            a.penjumlahanMatrix(b);
        }
        else if (choice == 3)
        {
            if (a.row == 0)
            {

                a.getInput();
                cout << "Matrix A : " << endl;
                a.displayMatrix();
                b.getInput();
                cout << "Matrix B : " << endl;
                b.displayMatrix();
            }
            else
            {
                cout << "Operasi Ini membutuhkan matrix kedua. Silahkan Inputkan Matrix kedua.\n";
                b.getInput();
                cout << "Matrix B : " << endl;
                b.displayMatrix();
            }
            a.penguranganMatrix(b);
        }

        else if (choice == 4)
        {
            if (a.row == 0)
            {

                a.getInput();
                cout << "Matrix A : " << endl;
                a.displayMatrix();
                b.getInput();
                cout << "Matrix B : " << endl;
                b.displayMatrix();
            }
            else
            {
                cout << "Operasi Ini membutuhkan matrix kedua. Silahkan Inputkan Matrix kedua.\n";
                b.getInput();
                cout << "Matrix B : " << endl;
                b.displayMatrix();
            }
            a.perkalianMatrix(b);
        }

        else if (choice == 5)
        {
            if (a.row == 0)
            {

                a.getInput();
                cout << "Matrix A : " << endl;
                a.displayMatrix();
            }
            a.transpose();
        }

        else if (choice == 6)
        {
            if (a.row == 0)
            {

                a.getInput();
                cout << "Matrix A : " << endl;
                a.displayMatrix();
            }
            cout << "Determinan matrix : " << a.carideterminan(a, a.row) << endl;
        }

        cout << "Lanjutkan? (Enter yes or no) ";
        cin.ignore();
        getline(cin, proceed);
        // cin >> proceed;
        // transform(proceed.begin(), proceed.end(), proceed.begin(), ::tolower);
        if (proceed == "yes")
        {
            cout << "Ketik yes untuk membuat matrix baru || Ketik no untuk menggunakan matrix saat ini.\n";
            cin.ignore();
            getline(cin, remakeMatrix);
            // cin >> remakeMatrix;
            // transform(remakeMatrix.begin(), remakeMatrix.end(), remakeMatrix.begin(), ::tolower);
            if (remakeMatrix == "yes")
            {
                a.getInput();
                a.displayMatrix();
            }
        }
    } while (proceed == "yes");

    system("pause");
    return EXIT_SUCCESS;
}
