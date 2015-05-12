#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printPreOrder( int m, int n, int max ){
    if( max > m + n )
        cout << m << ' ' << n << endl;
    else
        return;
    
    printPreOrder( 2*m - n, m, max );
    printPreOrder( 2*m + n, m, max );
    printPreOrder( m + 2*n, n, max );
    
    if(m == 2){
        printPreOrder( 3, 1, max);
    }
}

void printPostOrder( int m, int n, int max ){
    if( max < m + n ) 
        return;
    
    printPostOrder( 2*m - n, m, max );
    printPostOrder( 2*m + n, m, max );
    printPostOrder( m + 2*n, n, max );    

    cout << m << ' ' << n << endl;
    
    if(m == 2)
        printPostOrder( 3, 1, max);
}

//Exercise 3
struct Number
{
    int m;
    int n;
};

class CompareNumber
{
    public:
        bool operator()(Number& n1, Number& n2)
        {
            if( n1.m + n1.n > n2.m + n2.n )
                return true;
            else 
                return false;
        }
};

template<typename T>
void putQueue( int m, int n, int max, T &q)
{
    if( max > m + n )
    {
        Number a; 
        a.m = m;
        a.n = n;

        q.push(a);
    }
    else
        return;
    
    putQueue( 2*m - n, m, max, q );
    putQueue( 2*m + n, m, max, q );
    putQueue( m + 2*n, n, max, q );
    
    if(m == 2)
        putQueue( 3, 1, max, q );
}

void printSorted( int m, int n, int max)
{
    priority_queue< Number, vector<Number>, CompareNumber> q;
    putQueue( m, n, max, q );
    
    while(!q.empty())
    {
        cout << q.top().m << " " << q.top().n << endl;
        q.pop();
    }
}
