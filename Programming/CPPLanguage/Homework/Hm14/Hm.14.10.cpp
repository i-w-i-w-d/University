#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cout << "Введіть число N: ";
    cin >> N;
    
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }
    
    vector<string> lines;
    vector<bool> isNonEmpty;
    string line;
    int nonEmptyCount = 0;
    
    while (getline(inputFile, line)) {
        lines.push_back(line);
        if (!line.empty()) {
            nonEmptyCount++;
            isNonEmpty.push_back(true);
        } else {
            isNonEmpty.push_back(false);
        }
    }
    inputFile.close();
    
    bool hasChanges = false;
    ofstream outputFile("output.txt");
    int currentNonEmpty = 0;
    
    for (int i = 0; i < lines.size(); i++) {
        if (isNonEmpty[i]) {
            currentNonEmpty++;
            if (currentNonEmpty % N != 0) {
                outputFile << lines[i] << endl;
            } else {
                hasChanges = true;
            }
        } else {
            outputFile << lines[i] << endl;
        }
    }
    outputFile.close();
    
    if (hasChanges) {
        cout << "Файл оновлено!" << endl;
    } else {
        cout << "Файл залишено без змін!" << endl;
    }
}