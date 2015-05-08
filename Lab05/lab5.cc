#include <iostream>
#include <map>
#include "lab5.h"

using namespace std;

int main()
{
    BST<int> uno = BST<int>();
    
    uno.insert(50);
    uno.insert(20);
    uno.insert(10);
    uno.insert(40);
    uno.insert(35);
    uno.insert(45);
    uno.insert(60);
    uno.insert(70);
    
    cout << "Testcase1" << endl;
    cout << "Part 1: " << endl;
    uno.displayMinCover(); cout << endl;
    
    cout << "Part 2: " << endl;
    int sum = 80;
    int buffer[100];
    uno.findSumPath(uno.root, sum, buffer);
    
    cout << "Part 3: " << endl;
    map<int, int> m;
    uno.vertSum(uno.root, 0, m);

    BST<int> dos = BST<int>();

    cout << "Testcase2" << endl;
    cout << "Part 1: " << endl;
    dos.displayMinCover();
    
    cout << "Part 2: " << endl;
    dos.findSumPath(dos.root, sum, buffer);
    
    cout << "Part 3: " << endl;
    map<int, int> m2;
    dos.vertSum(dos.root, 0, m2);
    return 0;
}