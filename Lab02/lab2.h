// /*
// Name: Tricia Pryer

// SID: 861051465

// Date: April 21, 2015

// Approach: 

// */
template <class T>

class TwoStackFixed
{
    private:
        int size;
        int maxtop;
        
    public: 
        TwoStackFixed(int size, int maxtop );
        void pushStack1(T value);
        void pushStack2(T value);
        T popStack1();
        T popStack2();
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
};
#endif

TwoStackFixed::TwoStackFixed(int size, int maxtop )
{
    /*constructor that constructs array of size and constructs empty stacks with
    maxtop specifying the partition for stacks.
    HOW DOES USER SPECIFY THE FIXED AMOUNT OF SPACE FOR EACH STACK? */

    size = size;
    maxtop = maxtop;
    
    T array [size];
}

void TwoStackFixed::pushStack1(T value)
{
    /*to push element into first stack.*/
    return;
}

void TwoStackFixed::pushStack2(T value)
{
    /*to push element into second stack. */ 
    return;
}

//T TwoStackFixed::popStack1()
//{
    /*to pop element from first stack.*/
//}

//T TwoStackFixed::popStack2()
//{
    /*to pop element from second stack.*/
    //return;
//}

//bool TwoStackFixed::isFullStack1()
//{
    /*helper function to check whether first stack is full. */
//}

//bool TwoStackFixed::isFullStack2()
//{
    /* helper function to check whether second stack is full.*/
//}

//bool TwoStackFixed::isEmptyStack1()
//{
    /* helper function to check whether first stack is empty. */
//}

//bool TwoStackFixed::isEmptyStack2()
//{
    /* helper function to check whether second stack is empty */
//}
