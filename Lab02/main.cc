#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <forward_list>
#include "lab2.h"

using namespace std;


bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

template <class T>
void printLots (forward_list <T> L, forward_list <int> P)
{
    typename::forward_list<T>::iterator itl;
    typename::forward_list<int>::iterator itp;
    for(itp = P.begin(); itp != P.end(); itp++)
    {
        itl = L.begin();
        for(int i = 0; i < *itp; i++)
        {
            itl++;
        }
        cout << *itl << " ";
    }
    return;
}

template <class T>
void print( forward_list<T> L)
{
    typename::forward_list<T>::iterator it;
    for(it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    return; 
}

template <class T>
void listCopy( forward_list<T> L, forward_list<T> &P ) 
{
    typename::forward_list<T>::iterator it;
    for(it = L.begin(); it != L.end(); it++)
    {
        P.push_front(*it);
    }
    return;
}
int primeCount(forward_list<int> lst)
{
    //base case: empty list
    if(lst.empty())
        return 0;
      
    int n = lst.front();
    //first num is prime 
    if(isPrime(n))
    {
        lst.pop_front();
        return (1 + primeCount(lst));
    }
    
    //first num is composite
    lst.pop_front();
    return primeCount(lst);
}

int main()
{
    //isPrime Test
    /*
    int x = 12;
    cout << isPrime(x) << endl;
    */
    
    //primeCount Test 
    /*
    forward_list<int> list1;
    for(int i = 0; i < 10; i++)
        list1.push_front(i);
        
    cout <<"number of primes: " << primeCount(list1) << endl; 
    */
    
    //List::elementSwap Test
    /*List<int> A;
    for(int i = 2; i<= 12; i++)
    {
        A.push_back(i);
    }
    A.push_back(44);
    cout << "size: " << A.size() << endl;
    A.print(); cout << endl;
    
    A.elementSwap(1);
    A.print(); cout << endl; */
    
    //listCopy Test
    /*forward_list<int> L;
     for(int i = 0; i < 10; ++i)
        L.push_front(i);
        
    cout << "L: "; print(L); cout << endl;
    forward_list<int> P;
    listCopy(L, P);
    cout << "P: "; print(P); cout << endl; */
    
    //printLots Test
    forward_list<int> P;
    P.push_front(0);
    P.push_front(9);
    P.push_front(3);
    
    forward_list<char> L;
    L.push_front('y');
    L.push_front('a');
    L.push_front('r');
    L.push_front('G');
    L.push_front(' ');
    L.push_front('i');
    L.push_front('c');
    L.push_front('a');
    L.push_front('r');
    L.push_front('T');
    
    cout << "L: "; print(L); cout << endl;
    cout << "P: "; print(P); cout << endl;
    
    cout << "L at P: "; printLots(L, P); cout << endl;
    return 0;
}
