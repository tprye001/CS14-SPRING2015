#include <iostream>
#include "selectionsort.h"
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main()
{
    // //VECTOR
    // vector<int> v;
    // v.push_back(2);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(1);
    // v.push_back(8);
    // v.push_back(9);
    // cout << "pre:  ";
    // for(int i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i) << "  ";
    // }
    // cout << endl;

    // selectionsort(v);
    // cout << "post: ";
    // for(int i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i) << "  ";
    // }
    // cout << endl;
    
    map<int, int> m;
    m.insert( pair<int, int> (1,2));
    m.insert( pair<int, int> (3,-1));
    m.insert( pair<int, int> (-1,3));
    m.insert( pair<int, int> (0,0));
    m.insert( pair<int, int> (2,3));
    m.insert( pair<int, int> (1,2));
    m.insert( pair<int, int> (1,-2));
    m.insert( pair<int, int> (8,10));    
    
    cout << "pre:  ";
    for(typename map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    selectionsort(m);
    cout << "post: ";
    for(typename map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    return 0;
}