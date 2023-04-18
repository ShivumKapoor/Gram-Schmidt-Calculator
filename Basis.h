#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
#include "Vector.h"
using namespace std;

class Basis
{
    public:
        Basis(Vector* vectors, int numVectors);
        string print();
        void gramSchidt();

    private:
        Vector* vectors;
        int numVectors;
};

Basis::Basis(Vector* vectors, int numVectors)
{
    this->vectors = vectors;
    this->numVectors = numVectors;
}

string Basis::print()
{
    string printedBasis = "[" + (*(vectors)).print();

    for (int i = 1; i < numVectors; i++)
    {
        printedBasis += ", " + (*(vectors + i)).print();
    }

    printedBasis += "]";

    return printedBasis;
}

void Basis::gramSchidt ()
{

    (vectors)->normalize(); //U1 done

    for (int i = 1; i < numVectors; i++)
    {
        Vector v = *(vectors + i);

        Vector new_v = v * 1;

        for (int j = 0; j < i; j++)
        {
            Vector u = *(vectors + j);

            double dotProduct = v.dotProduct(u);
            double constant_k = dotProduct / u.length();

            Vector newVector = u * constant_k;
            new_v = new_v - newVector;
        }

        new_v.normalize();
        *(vectors + i) = new_v;

    }
}