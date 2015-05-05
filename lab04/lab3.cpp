// /*
// Name: Tricia Pryer

// SID: 861051465

// Date: April 21, 2015

// Approach: 

// */
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cmath>
#include <stack>
#include <vector>
#include "lab3.h"

using namespace std;
/*
template <typename T>
void change(int n, stack<T> &source, stack<T> &temp, stack<T> &destin)
{
    if(n == 0)
        return;
    else if(n == 1)
    {
        destin.push(source.top()); source.pop();
        return;
    }
    else if(n == 2)
    {
        temp.push(source.top()); source.pop();
        destin.push(source.top()); source.pop();
        destin.push(temp.top()); temp.pop();
        return;
    }
    else if(n == 3)
    {
        destin.push(source.top()); source.pop();
        temp.push(source.top()); source.pop();
        temp.push(destin.top()); destin.pop();
        destin.push(source.top()); source.pop();
        if(n - 1 >= 0)
        {
            change(n-1, temp, source, destin);
        }
        return;
    }
    else if(n % 2 == 0){
        change(n-2, source, temp, destin);
        temp.push(source.top()); source.pop();
        change(n-2, destin, source, temp);
        destin.push(source.top()); source.pop();
        change(n-1, temp, source, destin);
        
        return;
    }
    
    else if(n % 2 == 1){
        change(n-2, source, temp, destin);
        temp.push(source.top()); source.pop();
        change(n-2, destin, source, temp);
        destin.push(source.top()); source.pop();
        change(n-1, temp, source, destin);
        
        return;
    }
    return;
}

template <typename T>
void showTowerStates(int n, stack<T>& source, stack<T>& temp, stack<T>& destin)
{
    if(n == 0)
        return;
    else if(n == 1)
    {
        destin.push(source.top()); source.pop();
        return;
    }
    else if(n == 2)
    {
        temp.push(source.top()); source.pop();
        destin.push(source.top()); source.pop();
        destin.push(temp.top()); temp.pop();
        return;
    }
    else if(n == 3)
    {
        destin.push(source.top()); source.pop();
        temp.push(source.top()); source.pop();
        temp.push(destin.top()); destin.pop();
        destin.push(source.top()); source.pop();
        if(n - 1 >= 0)
        {
            showTowerStates(n-1, temp, source, destin);
        }
        return;
    }
    else if(n % 2 == 0){
        showTowerStates(n-2, source, temp, destin);
        temp.push(source.top()); source.pop();
        showTowerStates(n-2, destin, source, temp);
        destin.push(source.top()); source.pop();
        showTowerStates(n-1, temp, source, destin);
        
        return;
    }
    
    else if(n % 2 == 1){
        showTowerStates(n-2, source, temp, destin);
        temp.push(source.top()); source.pop();
        showTowerStates(n-2, destin, source, temp);
        destin.push(source.top()); source.pop();
        showTowerStates(n-1, temp, source, destin);
        
        return;
    }
    return;
}

//template <typename T>
//void printreverse(stack<T> stk)
//{
    unsigned ssz = stk.size();
    //push onto vector and print the vecor so that it is not backwards
    vector<T> p;
    if(stk.empty())
        return;

    for(unsigned i = 0; i < ssz; i++)
    {
        p.push_back(stk.top());
        stk.pop();
    }
    
    //print vector backwards
    unsigned psz = p.size();
    for(unsigned j = psz - 1; j > 0; --j)
    {
        cout << p.at(j) << " ";
    }
    cout << p.at(0);
    return;
}
*/
// template <typename T>
// void showTowerStates2(int n, stack<T>& A, stack<T>& B, stack<T>& C){
//     if(n = 1){
//         C.push_back(A.top());
//         A.pop();
//     }
//     else{
//         showTowerStates2(n - 1, A, C, B);
//         showTowerStates2(1, A, B, C);
//         showTowerStates2(n - 1, B, A, C);
//     }
// }

int main()
{
        // //Excercise 1:
    // TwoStackFixed<int> A (5, 3);
    // A.pushStack1(20);
    // A.pushStack1(21);
    // A.pushStack1(22);
    // A.pushStack1(23);
    
    // A.pushStack2(45);
    // A.pushStack2(46);
    
    // A.popStack1();
    // A.popStack1();
    // A.popStack1();
    // A.popStack1();
    // A.popStack1();
    
    // A.popStack2();
    // A.popStack2();
    
    // //Exercise 2:
    // TwoStackOptimal<int> B (5);
    // B.pushStack1(20);
    // B.pushStack1(20);
    // B.pushStack1(20);
    // B.pushStack1(20);
    // B.pushStack1(20);
    
    
    // B.popStack1();
    // B.popStack1();
    // B.popStack1();
    // B.popStack1();
    
    
    // B.pushStack2(50);
    // B.pushStack2(50);
    // B.pushStack2(50);
    // B.pushStack2(50);
    // B.pushStack2(50);
    
    // B.popStack2();
    // B.popStack2();
    // B.popStack2();
    
    // B.pushStack1(20);
    // B.pushStack1(20);
    
    // //Exercise 3:

    stack<int> stack1;
    // stack1.push(9);
    // stack1.push(8);
    // stack1.push(7);
    // stack1.push(6);
    // stack1.push(5);
    stack1.push(4);
    stack1.push(3);
    stack1.push(2);
    stack1.push(1);
    
    cout << "stack1: "; printreverse(stack1); cout << endl;
    stack<int> stack2;
    stack<int> stack3;
    
    showTowerStates(stack1.size(), stack1, stack2, stack3);
    cout << "stack1: "; printreverse(stack1); cout << endl;
    cout << "stack2: "; printreverse(stack2); cout << endl;
    cout << "stack3: "; printreverse(stack3); cout << endl;
    
    return 0;
}