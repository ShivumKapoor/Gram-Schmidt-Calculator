#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>

using namespace std;

class Vector
{
    public:
        Vector (double* entries, int numEntries);
        Vector();
        double* getEntries();
        int getNumEntries();
        string print();
        double length();
        double dotProduct (Vector a);
        void transformation (double k);
        void normalize ();
        Vector operator- (Vector v_other);
        Vector operator* (double k);
    
    private:
        double* entries;
        int numEntries;
        double *a;
        string removeZeros (string num);
};

Vector::Vector(double* entries, int numEntries)
{
    this->entries = entries;
    this->numEntries = numEntries;
    this->a = new double[numEntries];
}

Vector::Vector()
{
    this->entries = 0;
    this->numEntries = 1;
    this->a = new double[1];
}

double* Vector::getEntries()
{
    return entries;
}

int Vector::getNumEntries()
{
    return numEntries;
}

string Vector::removeZeros (string num)
{
    int indexOfLast = num.length() - 1;

    if (num.substr(indexOfLast, indexOfLast) != "0")
    {
        return num;
    }

    while(num.substr(indexOfLast, indexOfLast) == "0")
    {
        num = num.substr(0, indexOfLast);
        indexOfLast--;
    }

    if (num.substr(indexOfLast, indexOfLast) == ".")
    {
        num += "00";
    }

    return num;
}

string Vector::print()
{
    
    string printedVector = "<" + removeZeros(to_string(*entries));

    for (int i = 1; i < numEntries; i++)
    {
        printedVector += ", " + removeZeros(to_string(*(entries + i)));
    }
    
    printedVector += ">";

    return printedVector;
}

double Vector::length()
{
    double total = 0;

    for (int i = 0; i < numEntries; i++)
    {
        double entry = *(entries + i);
        total += (entry * entry);
    }

    return total;
}

double Vector::dotProduct (Vector a)
{
    double total = 0;

    for (int i = 0; i < numEntries; i++)
    {
        total += *(this->entries + i) * *(a.entries + i);
    }

    return total;
}

void Vector::transformation (double k)
{
    for (int i = 0; i < numEntries; i++)
    {
        *(entries + i) = k * (*(entries + i));
    }
}

void Vector::normalize ()
{
    double k = 1/sqrt(length());
    transformation(k);
}

Vector Vector::operator- (Vector v_other)
{

    Vector v(a, numEntries);

    for (int i = 0; i < numEntries; i++)
    {
        *(this->a + i) = *(this->entries + i) - *(v_other.entries + i);
    }

    return v;
}

Vector Vector::operator* (double k)
{
     
    Vector v(a, numEntries);
    for (int i = 0; i < numEntries; i++)
    {
        *(this->a + i) = k * (*(this->entries + i));
    }

    return v;
}
