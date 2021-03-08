#include "DLCirList.h"

CDLinkedList::CDLinkedList() :cursor(NULL) {}

CDLinkedList::~CDLinkedList () {while(!empty())remove();}

bool CDLinkedList::empty() const
{
    return this ->cursor == NULL; //cursor;
}

const string& CDLinkedList::back() const
{
    if(!empty())
        return this->cursor->elem;
    else
        throw runtime_error("List is Empty");
}

const string& CDLinkedList::front() const
{
    if(!empty())
        return this->cursor->next->elem;
    else
        throw runtime_error("List is Empty");
}

void CDLinkedList::advanceB(){cursor = cursor->prev;}

void CDLinkedList::advanceF() {cursor = cursor->next;}

//Insert a new node with element e immediately after the cursor
void CDLinkedList::add(const string& e)
{
    DCNode *n = new DCNode;
    n->elem = e;
    if(cursor == NULL)
    {
        n->next = n;
        n->prev = n;
        cursor =n;
    }
    else
    {
        n->next = cursor->next;
        n->prev = cursor;
        cursor->next->prev = n;
        cursor->next = n;
    }
}

//Remove the node immediately after the cursor
void CDLinkedList::remove()
{
    DCNode* old = cursor ->next;
    if(old == cursor)
    {
        cursor = NULL;
    }
    else
    {
        cursor ->next = old->next;
        old->next->prev = cursor;
        //Number of elements minus 1
    }
    delete old;
}

void CDLinkedList::displayAll() 
{
    DCNode* curr = cursor;
    //cout<<"Head->";
    do
    {
        cout<<curr->elem<<" ";
        curr=curr->prev;
    }while (curr->next!=cursor->next);
    cout<<endl;
}

void CDLinkedList::reverseList(CDLinkedList& L)
{
    CDLinkedList* T;
    T = new CDLinkedList;
    while (!L.empty()){
        string s = L.front();
        L.remove();
        T->add(s);
    }

    while (!T->empty()){
        string s = T->back();
        T->advanceB();
        T->remove();
        L.add(s);
    }
}
