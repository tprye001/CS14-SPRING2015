#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<chrono>
#include <set>
#include <unordered_set>
using namespace std;

vector<string> words(string infile)
{
    //Constructor that accepts the name of the dictionary file.
    vector<string> words;
    ifstream fin;
    fin.open(infile.c_str());
    
    if(!fin)
    {
        cout << "Error Opening" << infile << endl;
        exit(-1);
    }
    
    while(fin)
    {
        string s;
        fin >> s;
        words.push_back(s);
    }
    return words;
}

void TreeInsert(set<string>& S, vector<string> &W, int n)
{
    for(int i = 0; i < n; ++i)
    {
        S.insert(W.at(i));
    }
}

void HashTableInsert(unordered_set<string>& S, vector<string> &W, int n)
{
    for(int i = 0; i < n; ++i)
    {
        S.insert(W.at(i));
    }
}

void randomize(vector<string> &W)
{
    for(int i = 0; i < W.size(); i++)
    {
        swap( W.at(i) , W.at( rand() % W.size() ));
    }
}

double timeInsertTree(vector<string> &W, int n){
    double sum = 0;
    
    for(int i = 0; i < 10; i++){
        randomize(W);
        set<string> S;
        
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        //start timer 
        
        TreeInsert(S, W, n);
        
        //end timer
        end = chrono::system_clock::now();
        
        chrono::duration<double> elapsedSeconds = end - start;
        
        sum += elapsedSeconds.count();
    }
    
    return sum * 100; // sum / 10 * 1000 gives time im ms
}

double timeInsertHash(vector<string> &W, int n){
    double sum = 0;
    
    for(int i = 0; i < 10; i++){
        randomize(W);
        unordered_set<string> S;
        
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        //start timer 
        
        HashTableInsert(S, W, n);
        
        //end timer
        end = chrono::system_clock::now();
        
        chrono::duration<double> elapsedSeconds = end - start;
        
        sum += elapsedSeconds.count();
    }
    
    return sum * 100;
}

double timeTreeFind(vector<string> &W, int n){
    double sum = 0;
    
    for(int i = 0; i < 10; i++){
        randomize(W);
        
        set<string> S;
        
        TreeInsert(S, W, n);
        
        set<string>::iterator it = S.begin();
        chrono::time_point<chrono::system_clock> start, end;
        double findSum = 0;
        
        for(int i = 0; i < n; i++){
            start = chrono::system_clock::now();
            //start timer 
            
            S.find(*it);
            
            //end timer
            end = chrono::system_clock::now();
            
            chrono::duration<double> elapsedSeconds = end - start;
            
            it++;
            findSum += elapsedSeconds.count();
        }
        sum += findSum / n;
    }
    
    return sum * 100;
}

double timeHashFind(vector<string>& W, int n)
{
    double sum = 0;
    
    for(int i = 0; i < 10; i++){
        randomize(W);
        
        unordered_set<string> S;
        
        HashTableInsert(S, W, n);
        
        unordered_set<string>::iterator it = S.begin();
        chrono::time_point<chrono::system_clock> start, end;
        double findSum = 0;
        
        for(int i = 0; i < n; i++){
            start = chrono::system_clock::now();
            //start timer 
            
            S.find(*it);
            
            //end timer
            end = chrono::system_clock::now();
            
            chrono::duration<double> elapsedSeconds = end - start;
            
            it++;
            findSum += elapsedSeconds.count();
        }
        sum += findSum / n;
    }
    
    return sum * 100;
}