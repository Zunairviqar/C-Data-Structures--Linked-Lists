#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;

#include "StackQueue.h"
#include "SLinkedList.h"

LinkedStack :: LinkedStack () : S() , n (0) { }// constructor

int LinkedStack :: size () const // number of items in the stack
{
    return n;
}

bool LinkedStack :: empty () const // is the stack empty ?
{
    return n == 0;
}

const string LinkedStack :: top () const throw ( StackEmpty )
{
    if ( empty () ) throw StackEmpty ( " Top of empty stack ");
    return S.front () ;
}

void LinkedStack :: push ( const string& e ) // push element onto stack
{
    ++n;
    S.addFront(e) ;
}

void LinkedStack :: pop () throw ( StackEmpty ) // pop the stack
{
    if ( empty () ) throw StackEmpty ( " Pop from empty stack ");
    --n;
    S. removeFront () ;
}

void LinkedStack ::displayStack ()
{
    if(S.empty())
        cout<<"(Empty Stack)"<<endl;
    else
        S.displayAll();
}

//---------------------------------------------------------------------------

PrintQueue::PrintQueue() : Stack1(), Stack2()  {}

int PrintQueue:: size () const
{
    int a =0;
    int b =0;
    int c =0;
    a = Stack1.size();
    b = Stack2.size();
    c = a + b;
    return c;
}

bool PrintQueue:: empty () const
{
    if (Stack1.empty() && Stack2.empty())
       {
           return true;
       }
    return false;
}
const string PrintQueue:: front () throw ( QueueEmpty )
{
    if (Stack1.empty() && Stack2.empty())
    {
        throw QueueEmpty ( "Queue is Empty ");
    }
    
    if(Stack2.empty())
    {
        while (!Stack1.empty())
        {
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
    }
    return Stack2.top();

}

void PrintQueue:: enqueue(const string& x)
{
    Stack1.push(x);
}

void PrintQueue::dequeue () throw ( QueueEmpty )
{
    // if both stacks are empty
    if (Stack1.empty() && Stack2.empty())
    {
        throw QueueEmpty ( "Queue is Empty ");
    }
     
           // if s2 is empty, move
           // elements from s1
    if (Stack2.empty())
    {
        while (!Stack1.empty())
        {
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
    }
        // return the top item from s2
    Stack2.pop();
}

void PrintQueue::display()
{
    cout<< "Contents Of The Input Stack"<<endl;
    Stack1.displayStack();
    cout<< "Contents Of The Output Stack"<<endl;
    Stack2.displayStack();
}
