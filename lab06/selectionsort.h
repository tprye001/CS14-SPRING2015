#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>  

using namespace std;


template< typename L >
void selectionsort(L &l)
{
    typename L::iterator it = l.begin();
    int s = l.size();
    
    for(; it != l.end(); it++)
    {
        for(typename L::iterator it2 = it; it2 != l.end(); it2++)
        {
            //if it2->value < it->value, then swap
            if(it2 < it)
            {
                //swap(it2->second, it->second);
                iter_swap(it2, it);
            }
        }
    }
}