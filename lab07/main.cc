#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <set>
#include <chrono>
#include <unordered_set>
#include "lab7.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "Usage: wordladder <dictionary_file> <data_file> \n";
        exit(-1);
    }
    string dataFile = argv[2];
    ofstream fout;
    fout.open(dataFile.c_str());
    if(!fout.is_open())
    {
        exit(-1);
    }
    srand (time(NULL));
    
    vector<string> wordList = words(argv[1]);
    int wordListSize = 5000;
    for(int i = 0; i < 10; i++)
    {
        fout << wordListSize << '\t'
             << timeInsertTree(wordList, wordListSize) << '\t'
             << timeInsertHash(wordList, wordListSize) << '\t'
             << timeTreeFind(wordList, wordListSize) << '\t'
             << timeHashFind(wordList, wordListSize) << '\t'
             << endl;
        wordListSize += 5000;
    }
}