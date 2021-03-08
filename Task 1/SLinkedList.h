#ifndef SLinkedList_hpp
#define SLinkedList_hpp

#include<iostream>
#include<string>
#include<exception>
using namespace std;


class SNode
{
    private:
        string elem; //data element (type string in this case)
        SNode* next; //Link (pointer) to the next Node
        
    public:
        SNode(string newelem)
        {
            elem = newelem;
        }
        friend class SLinkedList;

};

class SLinkedList
{
    private:
        SNode* head; // pointer to the head of list
    public:
        SLinkedList (); // empty list constructor
        ~SLinkedList (); // destructor to clean up all nodes
        bool empty() const; // is list empty?
        const string front() const; // get front element
        void addFront(const string& elem); // add to front of list
        void removeFront(); // remove front item list
        void displayAll() const;
    
        friend class LinkedStack;
};

#endif /* SLinkedList_hpp */
