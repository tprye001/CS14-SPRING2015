#include "lab4.h"
#include <iostream>

using namespace std;

int main( int argc, char* argv[] ){
    
    // input check
    if( argc != 2 ){
        cout << "Error: Sample input: ./a.out 9" << endl;
        exit(1);
    }
    
    //converts c-char to int
    int max = atoi(argv[1]);

    // Ex.1 print pre-order
    cout << "pre-order" << endl;
    printPreOrder( 2, 1, max );
    
    // Ex.2 print post-order
    cout << "post-order" << endl;
    printPostOrder( 2, 1, max );
    
    // Ex.3 print sorted
    cout << "sorted" << endl;
    printSorted( 2, 1, max );
    
    return 0;
}
