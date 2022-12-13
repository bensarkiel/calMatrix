/*
Programmer : Dwi Prabowo
Ket        : Calculator Matrix
*/
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
                result[i][j] = 0;
            }
        }
    }

    // Operator overload.
    int &operator()(int row, int col)
    {
        return matrix[row][col]; // digunakan untuk mengenalkan operator pada saat terjadi operasi perhitungan antar kelas matrik
    }

    // Input Matrix
    void getInput(char namaMatrix)
    {
        do
        {
            cout << "Masukkan Banyak Baris Matrix " << namaMatrix << " = ";
            cin >> row;
            cout << "Masukkan Banyak Kolom Matrix " << namaMatrix << " = ";
            cin >> col;
            if (row < 1 || col < 1 || row > 4 || col > 4)
            {
                cout << "Inputan tidak valid. Min size = 1x1 and max size = 4x4.\n";
            }
        } while (row < 1 || col < 1 || row > 4 || col > 4);

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

    // Print/Output matrix
    void displayMatrix()
    {

        for (int i = 0; i < row; i++)
        {
            cout << "|   ";
            for (int j = 0; j < col; j++)
            {

                cout << matrix[i][j];
                cout << setw(5);
            }
            cout << "   |";
            cout << endl;
        }
    }

    // Print hasil Operasi Matrix
    void displayResultMatrix(int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << "|   ";
            for (int j = 0; j < cols; j++)
            {
                cout << result[i][j];
                cout << setw(5);
            }
            cout << "   |";
            cout << endl;
        }
    }

    // perkalian skalar
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

    // penjumlahan Matrix
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
            cout << "Operasi penjumlahan tidak bisa dilakukan dengan matrix ini\n";
        }
    }

    // Pengurangan Matrix
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

    // Perkalian Matrix
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
                        result[i][j] += matrix[i][k] * m(k, j); // mengalikan matrix dari kelas dengan matrix inputan
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

    // Transpose matrix
    void transpose()
    {
        int temp = row;
        row = col;
        col = temp;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result[i][j] = matrix[j][i]; // baris = i, kolom = j
            }
        }
        cout << "hasil transpose : " << endl;

        displayResultMatrix(row, col);
    }

    // Cari Determinan Matrix
    int carideterminan()
    {
        double determinan = 0;
        float hasil1, hasil2, hasil3, hasil4;
        if (row == 1) // nilai hanya 1
        {
            determinan = matrix[0][0];
        }
        else if (row == 2) // ad-bc
        {
            determinan = (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
        }
        else if (row == 3) // metode ekspansi baris 1
        {
            determinan = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
        }
        else if (row == 4) // metode ekspansi baris 1
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++) // metode saurus
                {
                    hasil1 = (matrix[1][1] * matrix[2][2] * matrix[3][3]) + (matrix[1][2] * matrix[2][3] * matrix[3][1]) + (matrix[1][3] * matrix[2][1] * matrix[3][2]) - (matrix[3][1] * matrix[2][2] * matrix[1][3]) - (matrix[3][2] * matrix[2][3] * matrix[1][1]) - (matrix[3][3] * matrix[2][1] * matrix[1][2]);
                    hasil2 = (matrix[1][0] * matrix[2][2] * matrix[3][3]) + (matrix[1][2] * matrix[2][3] * matrix[3][0]) + (matrix[1][3] * matrix[2][0] * matrix[3][2]) - (matrix[3][0] * matrix[2][2] * matrix[1][3]) - (matrix[3][2] * matrix[2][3] * matrix[1][0]) - (matrix[3][3] * matrix[2][0] * matrix[1][2]);
                    hasil3 = (matrix[1][0] * matrix[2][1] * matrix[3][3]) + (matrix[1][1] * matrix[2][3] * matrix[3][0]) + (matrix[1][3] * matrix[2][0] * matrix[3][1]) - (matrix[2][1] * matrix[1][3] * matrix[3][0]) - (matrix[3][1] * matrix[2][3] * matrix[1][0]) - (matrix[3][3] * matrix[2][0] * matrix[1][1]);
                    hasil4 = (matrix[1][0] * matrix[2][1] * matrix[3][2]) + (matrix[1][1] * matrix[2][2] * matrix[3][0]) + (matrix[1][2] * matrix[2][0] * matrix[3][1]) - (matrix[3][0] * matrix[2][1] * matrix[1][2]) - (matrix[3][1] * matrix[2][2] * matrix[1][0]) - (matrix[3][2] * matrix[2][0] * matrix[1][1]);
                }
                // hitung determinan matriks
                determinan = (hasil1 * matrix[0][0] * 1) + (hasil2 * matrix[0][1] * -1) + (hasil3 * matrix[0][2] * 1) + (hasil4 * matrix[0][3] * -1);
            }
        }
        cout << '\n';
        cout << determinan;
        return determinan;
    }
};

int main()
{
    int pilihan, row, col;
    char A = 'A', B = 'B';
    string lanjut;
    Matrix a, b;
    do
    {
        system("cls");
        cout << "=================================================\n"
             << "|        Matrix Calculator by Dwi Prabowo       |\n"
             << "=================================================\n";
        cout << "-------------------------------------------------\n";
        cout << "|    Pilih 1 untuk Perkalian skalar             |\n"
             << "|    Pilih 2 untuk penjumlahan matrix           |\n"
             << "|    Pilih 3 untuk pengurangan matrix           |\n"
             << "|    Pilih 4 untuk perkalian matrix             |\n"
             << "|    Pilih 5 untuk transpose matrix             |\n"
             << "|    Pilih 6 untuk mencari determinan matrix    |\n"
                "-------------------------------------------------\n";

        cout << "Masukkan Pilihan Anda: ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            system("cls");
            a.getInput(A);
            cout << "Matrix A : " << endl;
            a.displayMatrix();
            cout << endl;
            a.perkalianSkalar();
        }
        else if (pilihan == 2)
        {
            system("cls");
            a.getInput(A);
            cout << "Matrix A : " << endl;
            a.displayMatrix();
            cout << endl;
            b.getInput(B);
            cout << "Matrix B : " << endl;
            b.displayMatrix();
            cout << endl;
            a.penjumlahanMatrix(b);
        }
        else if (pilihan == 3)
        {
            system("cls");
            a.getInput(A);
            cout << "Matrix A : " << endl;
            a.displayMatrix();
            cout << endl;
            b.getInput(B);
            cout << "Matrix B : " << endl;
            b.displayMatrix();
            cout << endl;
            a.penguranganMatrix(b);
        }

        else if (pilihan == 4)
        {
            system("cls");
            a.getInput(A);
            cout << "Matrix A : " << endl;
            a.displayMatrix();
            cout << endl;
            b.getInput(B);
            cout << "Matrix B : " << endl;
            b.displayMatrix();
            cout << endl;
            a.perkalianMatrix(b);
        }

        else if (pilihan == 5)
        {
            system("cls");
            a.getInput(A);
            cout << "Matrix A : " << endl;
            a.displayMatrix();
            cout << endl;
            a.transpose();
        }

        else if (pilihan == 6)
        {
            system("cls");
            a.getInput(A);
            cout << "Matrix A : " << endl;
            a.displayMatrix();
            cout << endl;
            cout << "Determinan matrix : ";
            a.carideterminan();
            cout << endl;
        }
        else
        {
            cout << "Inputan tidak valid, Pilihan Tidak tersedia!\n";
        }
        cout << "Lanjutkan? (Enter yes or no) ";
        cin.ignore();
        getline(cin, lanjut);
    } while (lanjut == "yes");

    system("pause");
    return EXIT_SUCCESS;
}
