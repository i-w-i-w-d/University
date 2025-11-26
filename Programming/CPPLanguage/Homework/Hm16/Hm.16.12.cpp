#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Equation {
protected:
    double a, b;
public:
    Equation(double a_val, double b_val) : a(a_val), b(b_val) {}
    virtual ~Equation() {}
    virtual double f(double x) const = 0;
    virtual void display() const = 0;
    
    bool hasRealRoot() const {
        return f(a) * f(b) <= 0;
    }
    
    double findRoot() const {
        double left = a, right = b;
        for (int i = 0; i < 1000; i++) {
            double mid = (left + right) / 2;
            if (f(mid) == 0 || (right - left) < 1e-6) return mid;
            if (f(left) * f(mid) < 0) right = mid;
            else left = mid;
        }
        return (left + right) / 2;
    }
    
    double getA() const { return a; }
    double getB() const { return b; }
};

class LinearEquation : public Equation {
    double k, c;
public:
    LinearEquation(double a, double b, double k_val, double c_val) 
        : Equation(a, b), k(k_val), c(c_val) {}
    double f(double x) const override { return k * x + c; }
    void display() const override { cout << k << "x + " << c << " = 0"; }
};

class CubicEquation : public Equation {
    double a3, a2, a1, a0;
public:
    CubicEquation(double a, double b, double a3_val, double a2_val, double a1_val, double a0_val)
        : Equation(a, b), a3(a3_val), a2(a2_val), a1(a1_val), a0(a0_val) {}
    double f(double x) const override { return a3*x*x*x + a2*x*x + a1*x + a0; }
    void display() const override { cout << a3 << "x³ + " << a2 << "x² + " << a1 << "x + " << a0 << " = 0"; }
};

class SineEquation : public Equation {
    double amp, freq, phase, shift;
public:
    SineEquation(double a, double b, double amp_val, double freq_val, double phase_val, double shift_val)
        : Equation(a, b), amp(amp_val), freq(freq_val), phase(phase_val), shift(shift_val) {}
    double f(double x) const override { return amp * sin(freq*x + phase) + shift; }
    void display() const override { cout << amp << "sin(" << freq << "x + " << phase << ") + " << shift << " = 0"; }
};

class ExponentialEquation : public Equation {
    double coeff, exp_coeff, constant;
public:
    ExponentialEquation(double a, double b, double coeff_val, double exp_coeff_val, double constant_val)
        : Equation(a, b), coeff(coeff_val), exp_coeff(exp_coeff_val), constant(constant_val) {}
    double f(double x) const override { return coeff * exp(exp_coeff * x) + constant; }
    void display() const override { cout << coeff << "e^(" << exp_coeff << "x) + " << constant << " = 0"; }
};

int main() {
    vector<Equation*> eqs = {
        new LinearEquation(-10, 10, 2, -4),
        new CubicEquation(-5, 5, 1, 0, -2, 0),
        new SineEquation(-3, 3, 1, 1, 0, -0.5),
        new ExponentialEquation(-2, 2, 1, 1, -10)
    };
    
    cout << "Рівняння без розв'язків:\n";
    for (auto eq : eqs) {
        if (!eq->hasRealRoot()) {
            eq->display(); cout << endl;
        }
    }
    
    double max_root = -1e9;
    for (auto eq : eqs) {
        if (eq->hasRealRoot()) {
            max_root = max(max_root, eq->findRoot());
        }
    }
    cout << "Найбільший корінь: " << max_root << endl;
    
    double common_a = -1e9, common_b = 1e9;
    for (auto eq : eqs) {
        common_a = max(common_a, eq->getA());
        common_b = min(common_b, eq->getB());
    }
    bool common_interval = common_a <= common_b;
    cout << "Спільний інтервал: " << (common_interval ? "так" : "ні") << endl;
    
    double sum = 0;
    for (auto eq : eqs) {
        if (eq->hasRealRoot()) sum += eq->findRoot();
    }
    cout << "Сума коренів: " << sum << endl;
    
    for (auto eq : eqs) delete eq;
}