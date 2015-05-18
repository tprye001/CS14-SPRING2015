#include <iostream>
#include "selectionsort.h"
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

int main()
{
    //VECTOR
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(8);
    v.push_back(9);
    cout << "pre:  ";
    for(unsigned i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "  ";
    }
    cout << endl;

    selectionsort(v);
    cout << "post: ";
    for(unsigned i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "  ";
    }
    cout << endl;
    
    list<pair<int, int> > m;
    
    m.push_back( pair<int, int> (1,2));
    m.push_back( pair<int, int> (3,-1));
    m.push_back( pair<int, int> (-1,3));
    m.push_back( pair<int, int> (0,0));
    m.push_back( pair<int, int> (2,3));
    m.push_back( pair<int, int> (1,2));
    m.push_back( pair<int, int> (1,-2));
    m.push_back( pair<int, int> (8,10));    
    
    cout << "pre:  ";
    for(typename list<pair<int, int> >::iterator it = m.begin(); 
        it != m.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    selectionsort(m);
    cout << "post: ";
    for(typename list<pair<int, int> >::iterator it = m.begin(); 
        it != m.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    cout << "0 copies and " << 3*moves << " moves" << endl;
    
    list<pair<int, int> > n;
    n.push_back( pair<int, int> (10,2));
    n.push_back( pair<int, int> (-3,-1));
    n.push_back( pair<int, int> (-8,0));
    n.push_back( pair<int, int> (1,1));
    n.push_back( pair<int, int> (1,1));
    n.push_back( pair<int, int> (0,0));
    n.push_back( pair<int, int> (10,2));
    n.push_back( pair<int, int> (5,5));
    n.push_back( pair<int, int> (5,-5)); 
    n.push_back( pair<int, int> (0,0));
    n.push_back( pair<int, int> (10,2));
    
    cout << "pre:  ";
    for(typename list<pair<int, int> >::iterator it = n.begin(); 
        it != n.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    selectionsort(n);
    cout << "post: ";
    for(typename list<pair<int, int> >::iterator it = n.begin(); 
        it != n.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    cout << "0 copies and " << 3*moves << " moves" << endl;

    cout << "pre:  ";
    for(typename list<pair<int, int> >::iterator it = m.begin(); 
        it != m.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    selectionsort(m);
    cout << "post: ";
    for(typename list<pair<int, int> >::iterator it = m.begin(); 
        it != m.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    cout << "0 copies and " << 3*moves << " moves" << endl << endl; 
    
    cout << "Question 2. Part b" << endl;
    list<pair<int, string> > o;
    o.push_back( pair<int, string> (10, "start"));
    o.push_back( pair<int, string> (10, "end"));
    o.push_back( pair<int, string> (2, "2"));
    o.push_back( pair<int, string> (1, "1"));
    
    cout << "pre: ";
    for(typename list<pair<int, string> >::iterator it = o.begin(); 
        it != o.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    selectionsort(o);
    cout << "post: ";
    for(typename list<pair<int, string> >::iterator it = o.begin(); 
        it != o.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    
    
    
    return 0;
}