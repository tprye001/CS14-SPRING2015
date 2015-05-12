//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Lab<02>
/// @brief Lab <02> for CS 14 <Spring 2015>
///
/// @author <Tricia Pryer> [tprye001@ucr.edu]
/// @date <April 7, 2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <002>
/// @par
///     Lab Section: <23>
/// @par
///     TA: <Dingwen Tao>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <list>

using namespace std;

template <typename T>
void rotate(list<T> &A, int n)
{
    typename::list<T>::iterator it;
    
    cout << "#input" << endl;
    for(it = A.begin(); it != A.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    //insert first n at the end
    it = A.begin(); 
    for(int i = 0; i <= n - 1 ; ++i, ++it)
    {
        A.insert(A.end(), *it);
    }
    
    //delete first n at the begining
    it = A.begin(); 
    for(int i = 0; i <= n - 1; ++i)
    {
        it = A.erase(it);
    }
    
    cout << endl << "#output" << endl;
    for(it = A.begin(); it != A.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    return;
}

template <typename T>
void mergeSortList(list<T> &A, list<T> &B)
{
    typename::list<T>::iterator ait;
    typename::list<T>::iterator bit;
    
    cout << "#input" << endl;
    for(ait = A.begin(); ait != A.end(); ait++)
    {
        cout << *ait << " ";
    }
    cout << endl;
    for(bit = B.begin(); bit != B.end(); bit++)
    {
        cout << *bit << " ";
    }
    cout << endl;
    
    ait = A.begin(); 
    bit = B.begin();
    while(ait != A.end())
    {
        if(*ait < *bit)
        {
            //insert here
            bit = B.insert(bit, *ait);
            ait++;
            bit++;
        }
        else if(*ait >= *bit)
        {
            //go next
            bit++;
        }
    }
    
    cout << endl << "#output" << endl;
    for(bit = B.begin(); bit != B.end(); bit++)
    {
        cout << *bit << " ";
    }
    cout << endl;
    
    return;
}

template <typename T>
void mergeList(list<T> &A, list<T> &B)
{
    //T temp;
    typename::list<T>::iterator ait;
    typename::list<T>::iterator bit;
    
    // {
//     // cout << "Enter list A (enter when done): ";
//     // cin >> temp;
//     // while(temp != \n)
//     // {
//     //     A.push_back(temp);
//     //     cin >> temp;
//     // }
// }
    // {
    // // cout << " Enter list B (enter when done): ";
    // // cin >> temp;
    // // B.push_back(temp);
    // // while(!cin)
    // // {
    // //     B.push_back(temp);
    // // }
    // }
    
    cout << "#input" << endl;
    for(ait = A.begin(); ait != A.end(); ait++)
    {
        cout << *ait << " ";
    }
    cout << endl;
    for(bit = B.begin(); bit != B.end(); bit++)
    {
        cout << *bit << " ";
    }
    cout << endl;
    
    ait = A.begin(); 
    bit = B.begin();
    while(ait != A.end())
    {
        bit = B.insert(bit, *ait);
        ait++;
        bit++;
        bit++;
    }
    
    cout << endl << "#output" << endl;
    for(bit = B.begin(); bit != B.end(); bit++)
    {
        cout << *bit << " ";
    }
    cout << endl;
    
    return;
}


int main()
{
    list<int> A;
    list<int> B;
    list<double> A1;
    list<double> B1;
    list<int> C;
    
    A.push_back(12);
    A.push_back(3);
    A.push_back(56);
    A.push_back(5);
    
    B.push_back(45);
    B.push_back(66);
    B.push_back(2);
    
    A1.push_back(3);
    A1.push_back(5);
    A1.push_back(12);
    A1.push_back(56);
    
    B1.push_back(2);
    B1.push_back(45);
    B1.push_back(66);
    
    C.push_back(3);
    C.push_back(5);
    C.push_back(15);
    C.push_back(20);
    C.push_back(40);
    C.push_back(60);
    
    cout << "Part A: " << endl;
    mergeList(A, B);
    cout << endl << "Part B: " << endl;
    mergeSortList(A1, B1);
    cout << endl << "Part C: " << endl;
    rotate(C, 3);
    return 0;
}
