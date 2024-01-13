#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <chrono>


using namespace std;
using namespace chrono;

map<string, int> MotOccurences(string text){

    map<string, int> MotCounter;

    ifstream inputFile(text);


    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
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
