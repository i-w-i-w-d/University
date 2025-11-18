#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    char symbol;
    
    cout << "Введіть речення: ";
    getline(cin, sentence);
    cout << "Введіть символ: ";
    cin >> symbol;
    
    vector<string> words;
    stringstream ss(sentence);
    string word;
    
    while (ss >> word) {
        if (!word.empty() && word.back() == symbol) {
            words.push_back(word);
        }
    }
    
    cout << "Слова, що закінчуються на '" << symbol << "': ";
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;
    
    return 0;
}