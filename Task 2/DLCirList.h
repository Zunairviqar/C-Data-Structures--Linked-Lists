#ifndef DLCirList_hpp
#define DLCirList_hpp

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class DCNode
{
    private:
        string elem; //data element (type string in this case)
        DCNode* next; //Link (pointer) to the next Node
        DCNode* prev; //Link (pointer) to the previous Node
        friend class CDLinkedList;
        
    public:
        DCNode(): next(NULL), prev(NULL)
        {}
        DCNode(string elem) : elem(elem)
        {}
};

class CDLinkedList
{
    private:
        DCNode* cursor; // pointer to some node in the list
    public:
        CDLinkedList (); //Empty list constructor
        ~CDLinkedList (); //Destructor to clean up all nodes
        bool empty() const; //Is list empty?
        const string& front() const; //Return the element referenced by the cursor
        const string& back() const; //Return the element immediately after the cursor
        void add(const string& e); //Insert a new node with element e immediately after the cursor
        void remove(); //Remove the node immediately after the cursor
        void advanceB(); //Advance the cursor to the previous node in the list
        void advanceF(); //Advance the cursor to the next node in the list
        void reverseList(CDLinkedList& L); //Reverses all the elements in the list
        void displayAll() ; //Display all element of the list
};

#endif /* DLCirList_hpp */
