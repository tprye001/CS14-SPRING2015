#include <iostream>
#include <map>

using namespace std;

// -*- bst.h -*-
#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST 
{
    class Node 
    { 
        // binary tree node
        public:
        Value value;
        Node* left;
        Node* right;
        bool selected;
        Node( const Value v = Value() )
        : value(v), left(nil), right(nil), selected(false)
        {}
        Value& content() 
        { 
            return value; 
        }
        bool isInternal() 
        { 
            return left != nil && right != nil; 
        }
        bool isExternal() 
        { 
            return left != nil || right != nil; 
        }
        bool isLeaf() 
        { 
            return left == nil && right == nil; 
        }
        int height() //fill 
        {
            // returns the height of the subtree rooted at this node
            if(isLeaf())
            {
                return 0;
            }
            if(this->right == nil)
            {
                return 1 + (this->left)->height();
            }
            else if(this->left == nil)
            {
                return 1 + (this->right)->height();
            }
            
            if(this->right->height() > this->left->height())
            {
                //go as far right as possible
                return 1 + (this->right)->height();
            }
            else if(this->right->height() <= this->left->height())
            {
                //go as far left as possible
                return 1 + (this->left)->height();
            }
            return 0;
        }
        int size() //fill
        {
            // returns the size of the subtree rooted at this node,
            int s = 0;
            
            // Base Case
            if (isLeaf())
                return 1;
    
            queue<Node *> q;
            q.push(this);
    
            while (true)
            {
                int cnt = q.size();
                
                if (cnt == 0)
                    return s;
         
                s++;
         
                // Dequeue all nodes of current level and Enqueue all
                // nodes of next level
                while (cnt > 0) //reset the queue
                {
                    Node *curr = q.front();
                    q.pop();
                    if (curr->left != nil)
                    {
                        q.push(curr->left);
                        cnt--;
                    }
                    if (curr->right != nil)
                    {
                        q.push(curr->right);
                        cnt--;
                    }
                    break;
                }
            }
        }
        
        void findSumPath_help(int sum, vector<int> &v)
        {
            if( this == nil ){
                
                return;
            }
            v.push_back( this->value );
            
            if( sum == sum1(v) ){
                //cout << "sum: " << sum << endl;
                return;
            }
            if( sum < sum1(v))
            {
                //cout << sum << " < " << sum1(v);
                v.pop_back();
                return; //to go back up to parent??
            }
            //findSum
            
            //if it is less than, add the next one
            if(left != nil)
            {
                //go left
                //v.push_back(left->value);
                left->findSumPath_help(sum, v);
            }
            if(right != nil)
            {
                //go right
                //v.push_back(right->value);
                right->findSumPath_help(sum, v);
            }
            return;
        }
        int sum1( vector<int> v)
        {
            int sum = 0;
            for( int i = 0; i < v.size(); i++ ){
                sum += v.at(i);
            }
            return sum;
        }
        
    }; 
    
    // Node
    // const Node* nil; // later nil will point to a sentinel node.
    public: 
    int count;
    Node* root;
    
    public:
        int height() //not necessary
        {
            // height of the overall tree.
            if(root == nil)
                return 0;
            return root->height();
        }
        int size() //fill- done!
        {
            // size of the overall tree.
            if(root == nil)
                return 0;
            return root->size();
        }
        bool empty() 
        { 
            return size() == 0; 
        }
        void print_node( const Node* n ) //fill- done, not checked
        {
            // Print the node’s value.
            cout << n->value;
            
            return;
        }
        bool search ( Value x ) //fill- done!
        {
            // search for a Value in the BST and return true iff it was found.
            int sz = size();
            if(sz == 0)
                return false;
                
            Node* curr = root;

            while(true/*!(curr->isLeaf())*/)
            {
                if(curr->isLeaf())         //base case 1
                {
                    if(x == curr->value)
                        return true;
                    else
                        return false;
                }
                
                else if(curr->value == x)      //base case 2-- FOUND!
                    return true;
                
                else if(curr->value < x)
                {//go right
                    if(curr->right != nil)
                        curr = curr->right;
                    else 
                        return false;
                }
                else if(curr->value > x)
                {//go left
                    if(curr->left != nil)
                        curr = curr->left;
                    else
                        return false;
                }
            }
            return false;
        }
        void preorder_help(Node* curr) const
        {
            while(curr->left != nil && curr->right == nil)
            {
                cout << curr->value << endl;
                curr = curr->left;
            }
            if(curr->isLeaf())            //basecase
            {
                cout << curr->value << endl;
                return;
            }
            if(curr->isInternal())        //has a left and a right node
            {
                cout << curr->value << endl;
                preorder_help(curr->left);
                preorder_help(curr->right);
            }
            if(curr->right != nil && curr->left == nil)
            {
                cout << curr->value << endl;
                preorder_help(curr->right);
            }
            return;
        }
        void preorder()const //fill
        {
            // Traverse and print the tree one Value per line in preorder.
            if(root == nil)
                return;

            Node* curr = root;
            preorder_help(curr);
            
            return;
        }
        void postorder_help(Node* curr) const
        {
            if(curr->left != nil && curr->right == nil)
            {
                postorder_help(curr->left);
                cout << curr->value << endl;
            }
            if(curr->isLeaf())            //base case
            {
                cout << curr->value << endl;
                return;
            }
            if(curr->isInternal())        //has a left and a right node
            {
                postorder_help(curr->left);
                postorder_help(curr->right);
                cout << curr->value << endl;
            }
            if(curr->right != nil && curr->left == nil)
            {
                postorder_help(curr->right);
                cout << curr->value << endl;
            }
            return;
        }
        void postorder()const //fill
        {
            // Traverse and print the tree one Value per line in postorder.
            if(root == nil)
                return;

            Node* curr = root;
            postorder_help(curr);
            return;
        }
        void inorder_help(Node* curr) const
        {
            if(curr->isInternal()) // has left and right
            {
                inorder_help(curr->left);
                cout << curr->value << endl;
                inorder_help(curr->right);
            }
            if(curr->left != nil && curr->right == nil)
            {
                inorder_help(curr->left);
                cout << curr->value << endl;
            }
            if(curr->right != nil && curr->left == nil)
            {
                cout << curr->value << endl;
                inorder_help(curr->right);
            }
            if(curr->isLeaf())
            {
                cout << curr->value << endl;
            }
            return;
        }
        void inorder()const //fill
        {
            // Traverse and print the tree one Value per line in inorder.
            if(root == nil)
                return;

            Node* curr = root;
            inorder_help(curr);
            return;
        }
        void v_push(Node* n, vector<Node*> &inOrd)
        {
            if(n->isInternal()) // has left and right
            {
                v_push(n->left, inOrd);
                inOrd.push_back(n);
                v_push(n->right, inOrd);
            }
            if(n->left != nil && n->right == nil)
            {
                v_push(n->left, inOrd);
                inOrd.push_back(n);
            }
            if(n->right != nil && n->left == nil)
            {
                inOrd.push_back(n);
                v_push(n->right, inOrd);
            }
            if(n->isLeaf())
            {
                inOrd.push_back(n);
            }
            return;
        }
        Value& operator[] (int n) //fill
        {
            // returns reference to the value field of the n-th Node.
            //in order
            if(size() == 0)
            {
                cout << "Error: Index does not exist." << endl;
                exit(0);
            }
            else if(n > size())
            {
                cout << "Error: Index does not exist." << endl;
                exit(0);
            }
            vector<Node*> inOrd;
            v_push(root, inOrd);
            return inOrd.at(n)->value;
        }
        
        BST() 
        : count(0), root(nil) {}
        
        void insert( Value X ) 
        { 
            root = insert( X, root ); 
        }
        Node* insert( Value X, Node* T ) 
        {
            // The normal binary-tree insertion procedure ...
            if ( T == nil )
            {
                T = new Node( X ); // the only place that T gets updated.
            } 
            else if ( X < T->value ) 
            {
                T->left = insert( X, T->left );
            } 
            else if ( X > T->value ) 
            {
                T->right = insert( X, T->right );
            } 
            else 
            {
                T->value = X;
            }
            // later, rebalancing code will be installed here 3
            return T;
        }
        void remove( Value X ) 
        { 
            root = remove( X, root ); 
        }
        Node* remove( Value X, Node*& T ) 
        {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) 
            {
                if ( X > T->value ) 
                {
                    T->right = remove( X, T->right );
                } 
                else if ( X < T->value ) 
                {
                    T->left = remove( X, T->left );
                } 
                else 
                { 
                    // X == T->value
                    if ( T->right != nil ) 
                    {
                        Node* x = T->right;
                        while ( x->left != nil ) 
                            x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } 
                    else if ( T->left != nil ) 
                    {
                        Node* x = T->left;
                        while ( x->right != nil ) 
                            x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } 
                    else 
                    { 
                        // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
            // later, rebalancing code will be installed here
            return T;
        }
        void okay( ) 
        { 
            okay( root ); 
        }
        void okay( Node* T ) 
        {
            // diagnostic code can be installed here
            return;
        }
        void minCover_help(Node* x)
        {
            if(root->isLeaf())
                return;
            if(x->left != nil)
            {
                if(x->left->isLeaf() == false)
                {
                    x->left->selected = true;
                    minCover_help(x->left);
                }
            }
            if(x->right != nil)
            {
                if(x->right->isLeaf() == false)
                {
                    x->right->selected = true;
                    minCover_help(x->right);
                }
            }
            return;
        }
        void minCover()
        {
            // find the smallest cover of the tree such that root is not part of vertex cover
            if(root->isLeaf())
            {
                return;
            }
            if(root->left != nil)
            {
                root->left->selected = true;
                minCover_help(root->left);
            }
            if(root->right != nil)
            {
                root->right->selected = true;
                minCover_help(root->right);
            }
            //minCover_help(root);
            return;
        }
        void displayMinCover_help(Node* curr, int &s)
        {
            //cout << "where does " << curr->value << " go?" << endl;
            if(curr->isInternal()) // has left and right
            {
                displayMinCover_help(curr->left, s);
                if(curr->selected == true)
                {
                    cout << curr->value << " ";
                    s++;
                }
                displayMinCover_help(curr->right, s);
            }
            if(curr->left != nil && curr->right == nil)
            {
                displayMinCover_help(curr->left, s);
                if(curr->selected == true)
                {
                    cout << curr->value << " ";
                    s++;
                }
            }
            if(curr->right != nil && curr->left == nil)
            {
                if(curr->selected == true)
                {
                    cout << curr->value << " ";
                    s++;
                }
                displayMinCover_help(curr->right, s);
            }
            if(curr->isLeaf())
            {
                if(curr->selected == true)
                {
                    cout << curr->value << " ";
                    s++;
                }
            }
            return;
        }
        void displayMinCover()
        {
            // Traverse and print the tree one Value per line in inorder.
            if(root == nil)
                return;
            minCover();
            int s = 0;
            Node* curr = root;
            displayMinCover_help(curr, s);
            cout << endl << s;
            return;
        }
        void findSumPath(Node* n, int sum, int buffer[])
        {
            if(n == nil)
                return;
                
            if(n->isLeaf() == true)
            {
                if(n->value == sum)
                {
                    cout << n->value << endl;
                }
                else
                {
                    cout << "0" << endl;
                }
            }
            vector<int> v;
            n->findSumPath_help(sum, v);
            for(int i = 0; i < v.size(); i++)
            {
                buffer[i] = v.at(i);
            }
            for(int i = 0; i < v.size(); i++)
            {
                cout << v.at(i) << " ";
            }
            cout << endl;
            return;
        }
        
        void vertSum_help(Node* node, int hd, map<int, int> &m )
        {
            if(node->isLeaf())
            {
                int x = m.find(hd)->second;
                m.insert(pair<int, int> (hd, x + node->value));
                return;
            }
            
            if(node->left != nil)
            {
                int x = m.find(hd - 1)->second;
                m.insert(pair<int, int> (hd - 1, x + node->value));
                vertSum_help(node->left, hd - 1, m);
            }
            if(node->right != nil)
            {
                int x = m.find(hd + 1)->second;
                m.insert(pair<int, int> (hd + 1, x + node->value));
                vertSum_help(node->right, hd + 1, m);
            }
            return;
        }
        
        void vertSum_help2(Node* node, int hd, map<int, int> &m )
        {
            if(node->left != nil)
            {
                vertSum_help2(node->left, hd - 1, m);
            }
            if(node->right != nil){
                vertSum_help2(node->right, hd + 1, m);
            }
            m[hd] += node->value;
            return;
        }
        
        void vertSum(Node* node, int hd, map<int, int>&m)
        {
            if(node == nil)
                return;
            
            vertSum_help2(node, hd, m);
            
            map<int, int>::iterator it = m.begin();
            for(; it != m.end(); it++)
            {
                cout << it->second << " ";
            }
            cout << endl;
        }
}; // BST
#endif