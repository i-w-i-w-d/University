#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int number;
    char ch;
    bool first = true;
    
    while (in >> number) {
        if (number > 0) {
            if (!first) out << " ";
            out << number;
            first = false;
        }
        in >> ch;
    }
    
    in.close();
    out.close();
}