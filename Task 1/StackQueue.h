#ifndef StackQueue_hpp
#define StackQueue_hpp

#include<iostream>
#include<string>
#include<exception>
using namespace std;

#include "SLinkedList.h"


class StackEmpty : public logic_error {
public :
StackEmpty ( const string & err ): logic_error (err) {}
};


class QueueEmpty : public logic_error {
public :
QueueEmpty ( const string & err ): logic_error (err) {}
};


class LinkedStack  // stack as a linked list
{
private : // member data
    SLinkedList S; // linked list of elements
    int n; // number of elements

public:
    LinkedStack () ; // constructor
    int size () const ; // number of items
    bool empty () const ; // is the stack empty ?
    const string top () const throw ( StackEmpty ); // the top element
    void push ( const string & e); // push element onto stack
    void pop () throw ( StackEmpty ); // pop the stack
    void displayStack();
};

class PrintQueue
{
private:
    LinkedStack Stack1;
    LinkedStack Stack2;
    
public:
    PrintQueue();
    int size () const ;
    bool empty () const ;
    const string front () throw ( QueueEmpty );
    void enqueue( const string& x);
    void dequeue() throw ( QueueEmpty ) ;
    void display();
};

#endif /* StackQueue_hpp */
