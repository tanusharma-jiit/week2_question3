#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return tolower(c); });
}

void removePunctuation(string &word) {
    word.erase(remove_if(word.begin(), word.end(), [](unsigned char c) { return ispunct(c); }), word.end());
}

int main() {
    string paragraph;
    map<string, int> wordCount;

    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    stringstream ss(paragraph);
    string word;

    while (ss >> word) {
        removePunctuation(word);
        toLowerCase(word);
        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    for (const auto &entry : wordCount) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
