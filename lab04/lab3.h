#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>

// typedef int T;

using namespace std;

//Excercise 1: TwoStackFixed

template <class T> 
class TwoStackFixed{
    private:
        T* data;
        int size;
        int maxtop;
        int stack1;
        int stack2;
        
    public:
        TwoStackFixed(int size, int maxtop);
        void pushStack1(T value);
        void pushStack2(T value);
        T popStack1();
        T popStack2();
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
        ~TwoStackFixed();
        
    private:
        void print();
        void tester(string, T);
};

template <class T>
TwoStackFixed<T>::TwoStackFixed(int size, int maxtop){
    if(maxtop >= (size - 1) || maxtop < 0){
        cout << "Invalid contruction: No available space for a stack." << endl;
        cout << endl;
        exit(1);
    }
    this->size = size;
    this->maxtop = maxtop;
    data = new T[size];
    stack1 = 0;
    stack2 = size - 1;
    
    //Test:
    tester("Constructor", 0);
}

template <class T>
TwoStackFixed<T>::~TwoStackFixed(){
    delete []data;
    
    //Test:
    cout << "Destructor called" << endl << endl;
}

template <class T>
void TwoStackFixed<T>::pushStack1(T value){
    
    if(stack1 > maxtop){
        cout << "Error: Stack1 overflow. No changes made." << endl << endl;
        return;
    }
    data[stack1] = value;
    stack1++;
    
    //Test:
    tester("pushStack1", value);
}

template <class T>
void TwoStackFixed<T>::pushStack2(T value){
    if(stack2 <= maxtop){
        cout << "Error: Stack2 overflow. No changes made." << endl << endl;
        return;
    }
    data[stack2] = value;
    stack2--;
    
    //Test:
    tester("pushStack2", value);
}

template <class T>
void TwoStackFixed<T>::tester(string name, T value){
    cout << name << "(" << value << "):" << endl;
    print();
    cout << "maxtop : " << maxtop << endl;
    cout << "isFullStack1(): " << isFullStack1() << endl;
    cout << "isFullStack2(): " << isFullStack2() << endl;
    cout << "isEmptyStack1(): " << isEmptyStack1() << endl;
    cout << "isEmptyStack2(): " << isEmptyStack2() << endl;
    cout << endl;
}

template <class T>
void TwoStackFixed<T>::print(){
    cout << "Stack 1: ";
    for(int i = 0; i < size; i++){
        cout << data[i] << ' ';
    }
    cout << ":Stack 2" << endl;
}

template <class T>
T TwoStackFixed<T>::popStack1(){
    if(stack1 <= 0){
        cout << "Error: Stack1 underflow. No changes made." << endl << endl;
        return 0;
    }
    T toReturn = data[stack1];
    
    stack1--;
    data[stack1] = 0;
    
    //Test:
    tester("popStack1", 0);
    
    return toReturn;
}

template <class T>
T TwoStackFixed<T>::popStack2(){
    if(stack2 >= (size - 1)){
        cout << "Error: Stack2 underflow. No changes made." << endl << endl;
        return 0;
    }
    T toReturn = data[stack2];
    
    stack2++;
    data[stack2] = 0;
    
    //Test:
    tester("popStack2", 0);
    
    return toReturn;
}

template <class T>
bool TwoStackFixed<T>::isFullStack1(){
    if(stack1 > maxtop){
        return true;
    }
    return false;
}

template <class T>
bool TwoStackFixed<T>::isFullStack2(){
    if(stack2 <= maxtop){
        return true;
    }
    return false;
}

template <class T>
bool TwoStackFixed<T>::isEmptyStack1(){
    if(stack1 <= 0){
        return true;
    }
    return false;
}

template <class T>
bool TwoStackFixed<T>::isEmptyStack2(){
    if(stack2 >= (size - 1)){
        return true;
    }
    return false;
}

//Excercise 2: TwoStackOptimal

template <class T> 
class TwoStackOptimal{
    private:
        T* data;
        int size;
        int stack1;
        int stack2;
        
    public:
        TwoStackOptimal(int size);
        void pushStack1(T value);
        void pushStack2(T value);
        T popStack1();
        T popStack2();
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
        ~TwoStackOptimal();

        
    private:
        void print();
        void tester(string, T);
};

template <class T>
TwoStackOptimal<T>::TwoStackOptimal(int size){
    if(size <= 0){
        cout << "Invalid contruction: No available space for a stack." << endl;
        cout << endl;
        exit(1);
    }
    this->size = size;
    data = new T[size];
    stack1 = 0;
    stack2 = size - 1;
    
    //Test:
    tester("Constructor", 0);
}

template <class T>
TwoStackOptimal<T>::~TwoStackOptimal(){
    delete []data;
    
    //Test:
    cout << "Destructor called" << endl << endl;
    
}

template <class T>
void TwoStackOptimal<T>::pushStack1(T value){
    if(stack1 > stack2){
        cout << "Error: Stack1 overflow. No changes made." << endl << endl;
        return;
    }
    data[stack1] = value;
    stack1++;
    
    //Test:
    tester("pushStack1", value);
}

template <class T>
void TwoStackOptimal<T>::pushStack2(T value){
    if(stack2 < stack1){
        cout << "Error: Stack2 overflow. No changes made." << endl << endl;
        return;
    }
    data[stack2] = value;
    stack2--;
    
    //Test:
    tester("pushStack2", value);
}

template <class T>
void TwoStackOptimal<T>::tester(string name, T value){
    cout << name << "(" << value << "):" << endl;
    print();
    cout << "isFullStack1(): " << isFullStack1() << endl;
    cout << "isFullStack2(): " << isFullStack2() << endl;
    cout << "isEmptyStack1(): " << isEmptyStack1() << endl;
    cout << "isEmptyStack2(): " << isEmptyStack2() << endl;
    cout << endl;
}

template <class T>
void TwoStackOptimal<T>::print(){
    cout << "Stack 1: ";
    for(int i = 0; i < size; i++){
        cout << data[i] << ' ';
    }
    cout << ":Stack 2" << endl;
}

template <class T>
T TwoStackOptimal<T>::popStack1(){
    if(stack1 <= 0){
        cout << "Error: Stack1 underflow. No changes made." << endl << endl;
        return 0;
    }
    T toReturn = data[stack1];
    
    stack1--;
    data[stack1] = 0;
    
    //Test:
    tester("popStack1", 0);
    
    return toReturn;
}

template <class T>
T TwoStackOptimal<T>::popStack2(){
    if(stack2 >= (size - 1)){
        cout << "Error: Stack2 underflow. No changes made." << endl << endl;
        return 0;
    }
    T toReturn = data[stack2];
    
    stack2++;
    data[stack2] = 0;
    
    //Test:
    tester("popStack2", 0);
    
    return toReturn;
}

template <class T>
bool TwoStackOptimal<T>::isFullStack1(){
    if(stack1 > stack2){
        return true;
    }
    return false;
}

template <class T>
bool TwoStackOptimal<T>::isFullStack2(){
    if(stack2 < stack1){
        return true;
    }
    return false;
}

template <class T>
bool TwoStackOptimal<T>::isEmptyStack1(){
    if(stack1 <= 0){
        return true;
    }
    return false;
}

template <class T>
bool TwoStackOptimal<T>::isEmptyStack2(){
    if(stack2 >= (size - 1)){
        return true;
    }
    return false;
}

//Assignment 3: Tower of Hanoi

template <typename T>
void recursion(int n, stack<T>& source, char a, stack<T>& temp, char b, stack<T>& destin, char c)
{
    if(n == 0)
        return;
    else if(n == 1)
    {
        cout << "Move " << source.top() << " from " << a << " to " << c << endl;
        destin.push(source.top()); source.pop();
        return;
    }
    else if(n == 2)
    {
        cout << "Move " << source.top() << " from " << a << " to " << b << endl;
        temp.push(source.top()); source.pop();
        
        cout << "Move " << source.top() << " from " << a << " to " << c << endl;
        destin.push(source.top()); source.pop();
        
        cout << "Move " << temp.top() << " from " << b << " to " << c << endl;
        destin.push(temp.top()); temp.pop();
        
        return;
    }
    else if(n == 3)
    {
        cout << "Move " << source.top() << " from " << a << " to " << c << endl;
        destin.push(source.top()); source.pop();
        
        cout << "Move " << source.top() << " from " << a << " to " << b << endl;
        temp.push(source.top()); source.pop();
        
        cout << "Move " << destin.top() << " from " << c << " to " << b << endl;
        temp.push(destin.top()); destin.pop();
        
        cout << "Move " << source.top() << " from " << a << " to " << c << endl;
        destin.push(source.top()); source.pop();
        
        if(n - 1 >= 0)
        {
            recursion(n-1, temp, b, source, a, destin, c);
        }
        return;
    }
    else if(n % 2 == 0){
        recursion(n-2, source, a, temp, b, destin, c);
        
        cout << "Move " << source.top() << " from " << a << " to " << b << endl;
        temp.push(source.top()); source.pop();
        
        recursion(n-2, destin, c, source, a, temp, b);
        
        cout << "Move " << source.top() << " from " << a << " to " << c << endl;
        destin.push(source.top()); source.pop();
        
        recursion(n-1, temp, b, source, a, destin, c);
        
        return;
    }
    
    else if(n % 2 == 1){
        recursion(n-2, source, a, temp, b, destin, c);
        
        cout << "Move " << source.top() << " from " << a << " to " << b << endl;
        temp.push(source.top()); source.pop();
        
        recursion(n-2, destin, c, source, a, temp, b);
        
        cout << "Move " << source.top() << " from " << a << " to " << c << endl;
        destin.push(source.top()); source.pop();
        
        recursion(n-1, temp, b, source, a, destin, c);
        
        return;
    }
    return;
}

template <typename T>
void showTowerStates(int n, stack<T>& source, stack<T>& temp, stack<T>& destin)
{
    char a = 'A';
    char b = 'B';
    char c = 'C';
    recursion(n, source, a, temp, b, destin, c);
}
template <typename T>
void printreverse(stack<T> stk)
{
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

template <typename T>
void recursiveStep(int n, stack<T>& A, char a, stack<T>& B, char b,
                          stack<T>& C, char c){
    if(n == 1){
        cout << "Moved " << A.top() << " from peg " << a << " to " << c << endl;
        C.push(A.top());
        A.pop();
    }
    else{
        recursiveStep(n - 1, A, a, C, c, B, b);
        recursiveStep(1, A, a, B, b, C, c);
        recursiveStep(n - 1, B, b, A, a, C, c);
    }
}

template <typename T>
void showTowerStates2(int n, stack<T>& A, stack<T>& B, stack<T>& C){
    char a = 'A';
    char b = 'B';
    char c = 'C';
    recursiveStep(n, A, a, B, b, C, c);
}

#endif