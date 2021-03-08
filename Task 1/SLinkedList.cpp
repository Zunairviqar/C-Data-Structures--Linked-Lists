#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;

#include "SLinkedList.h"
#include "StackQueue.h"



SLinkedList::SLinkedList () : head(NULL){}

SLinkedList::~SLinkedList () // destructor to clean up all nodes
{
    while(!empty())
        removeFront();
    head = NULL;
}

bool SLinkedList::empty() const // is list empty?
    {return head == NULL;}

const string SLinkedList::front() const // get front element
{
    if(!empty())
        return head->elem;
    else
        throw out_of_range("The List is empty ");
}

void SLinkedList::addFront(const string& elem) // add to front of list
{
    SNode*tmp = head;
    head = new SNode(elem);
    head->next = tmp;
}

void SLinkedList::removeFront() // remove front item list
{
    if(!empty())
    {
        SNode*tmp = head;
        head = head->next;
        delete tmp;
    }

}

void SLinkedList::displayAll() const
{
    SNode *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->elem<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
