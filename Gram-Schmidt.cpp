#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
#include "Basis.h"


using namespace std;

double* splitStr (string str, int num)
{
    double* arr = new double[num];

    int index;
    for (int i = 0; i < num; i++)
    {
        index = str.find(',');
        double entry = stod(str.substr(0, index));

        *(arr + i) = entry;
        str = str.substr(index + 1);
    }

    return arr;
}

int main () //clang++ Gram-Schmidt.cpp -o g
{

    int numVectors;
    int sizeVectors;
    Basis* basis;
    Vector vectors[10];

    cout << "This is the Gram-Schmidt Calculator" << endl << endl;

    cout << "Number of vectors: ";
    cin >> numVectors;
    cout << "Size of vectors: ";
    cin >> sizeVectors; 
    cin.ignore(10000, '\n');

    for (int i = 0; i < numVectors; i++)
    {
        string str;
        cout << "Enter the values for vector " + to_string(i + 1) + " seperated by commas with no spaces: " << endl;
        getline(cin, str);

        double* array = splitStr(str, sizeVectors);
        *(vectors + i) = Vector(array, sizeVectors);

    }

    basis = new Basis(vectors, numVectors);

    cout << basis->print() << endl << endl;

    basis->gramSchidt();

    cout << basis->print() << endl;
}