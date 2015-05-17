/*
// Name: Tricia Pryer
// SID: 861051465
// Approach: Used nested for loops to iterate through the list and 
             swapped when necessary
// 
*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>  

using namespace std;

unsigned moves = 0;

template< typename L >
void selectionsort(L &l)
{
    moves = 0;
    typename L::iterator it = l.begin();
    
    for(; it != l.end(); it++)
    {
        typename L::iterator min = it;
        for(typename L::iterator it2 = it; it2 != l.end(); it2++)
        {
            //if it2->value < it->value, then swap
            if(*it2 < *min)
            {
                min = it2;
            }
        }
        if(it != min)
        {
            swap(*min, *it);
            moves++;
        }
    }
}