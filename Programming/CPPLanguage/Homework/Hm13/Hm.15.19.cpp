#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Polynomial {
private:
    int size;
    double* coefficients;

public:
    Polynomial(int n = 1) : size(n) {
        coefficients = new double[size];
        for (int i = 0; i < size; i++) {
            coefficients[i] = 0.0;
        }
    }

    Polynomial(const Polynomial& other) : size(other.size) {
        coefficients = new double[size];
        for (int i = 0; i < size; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coefficients;
            size = other.size;
            coefficients = new double[size];
            for (int i = 0; i < size; i++) {
                coefficients[i] = other.coefficients[i];
            }
        }
        return *this;
    }

    void setCoeff(int i, double val) {
        if (i >= 0 && i < size) coefficients[i] = val;
    }

    double getCoeff(int i) const {
        return (i >= 0 && i < size) ? coefficients[i] : 0;
    }

    int getSize() const { return size; }

    void fromString(const string& str) {
        stringstream ss(str);
        vector<double> coeffs;
        double coeff;
        while (ss >> coeff) {
            coeffs.push_back(coeff);
        }
        
        delete[] coefficients;
        size = coeffs.size();
        coefficients = new double[size];
        for (int i = 0; i < size; i++) {
            coefficients[i] = coeffs[i];
        }
    }

    void print() const {
        for (int i = size - 1; i >= 0; i--) {
            if (coefficients[i] != 0) {
                cout << coefficients[i];
                if (i > 0) cout << "x^" << i;
                if (i > 0) cout << " + ";
            }
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1(3);
    p1.setCoeff(0, 1);
    p1.setCoeff(1, 2);
    p1.setCoeff(2, 3);
    
    cout << "p1: ";
    p1.print();

    Polynomial p2;
    p2.fromString("4 5 6");
    cout << "p2: ";
    p2.print();

    Polynomial p3;
    p3 = p1;
    cout << "p3: ";
    p3.print();

    return 0;
}