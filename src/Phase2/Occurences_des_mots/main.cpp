#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <regex>
#include <chrono>


using namespace std;
using namespace chrono;

map<string, int> MotOccurences(string text){

    map<string, int> MotCounter;

    ifstream inputFile(text);


    string line;
    regex wordRegex(R"([a-zA-Z]+)");

    while (getline(inputFile, line)) {
        smatch matches;
        auto wordsBegin = sregex_iterator(line.begin(), line.end(), wordRegex);
        auto wordsEnd = sregex_iterator();

        for (sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
            string word = (*i).str();

            for (char &c : word) c = tolower(c);

            MotCounter[word]++;
        }
    }

    return MotCounter;

}

int main() {

    
    auto start = high_resolution_clock::now();

     map<string, int> MotCounter = MotOccurences("roman.txt");

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    

    cout << "Occurences des mots:\n";
    for (const auto &entry : MotCounter) {
        cout << entry.first << ": " << entry.second << " fois\n";
    }

    cout << "\nTime taken by function MotOccurences is : "<<duration.count()<< " seconds "<<endl;

    return 0;
}
