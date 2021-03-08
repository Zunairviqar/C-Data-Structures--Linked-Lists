#include <iostream>

#include "StackQueue.h"
#include "SLinkedList.h"

using namespace std;

void Part1DriverFunctionsTest();
void Part1Driver();

// main function
int main()
{
    Part1DriverFunctionsTest();
    PrintQueue print;
    string name;
    int x=0;
    do {
    cout<<"Enter 1 To Add A Job To The Queue"<<endl;
    cout<<"Enter 2 To Print A Job From The Queue"<<endl;
    cout<<"Enter 3 To Check The Size Of The Queue"<<endl;
    cout<<"Enter 4 To Check If The Queue Is Empty"<<endl;
    cout<<"Enter 5 To Display The Elements Of The Queue"<<endl;
    cout<<"Enter 6 To Exit"<<endl;
    cin>> x;
    
    if(x==1)
    {
        cout<<"Enter The Name Of The Printing Job To Add"<<endl;
        cin>>name;
        print.enqueue(name);
    }
    else if (x==2)
    {
        cout<<print.front()<<" Is Removed"<<endl;;
        print.dequeue();
    }
    else if (x==3)
    {
        cout<<"The Size Of The Queue Is ";
        cout<<print.size()<<endl;
    }
    else if (x==4)
    {
        if (print.empty()==true)
            cout<<"Queue Is Empty"<<endl;
        else
            cout<<"Queue Is Not Empty"<<endl;
    }
    else if (x==5)
    {
        print.display();
    }
    else if(x==6)
    {
        return 0;
    }
    else
    {
        cout<<"Invalid Number Entered"<<endl;
    }
    }while(x!=6);
    return 0;
}

void Part1DriverFunctionsTest()
{
    cout<<"Start Of Functions Testing"<<endl;
    cout<<"------------------------------"<<endl;
    PrintQueue q;

    cout<<"Inserting 3 Elements In The Queue"<<endl;
    q.enqueue("Q");
    q.enqueue("W");
    q.enqueue("E");
    
    cout<< "Front Element " <<q.front()<<endl;
    cout<< "Size Of The Queue " <<q.size()<<endl;
    
    q.display();
    
    cout<< "Deleting 2 Elements From The Queue"<<endl;
    q.dequeue();
    q.dequeue();
    
    if (q.empty()==true)
        cout<<"Queue Is Empty"<<endl;
    else
        cout<<"Queue Is Not Empty"<<endl;
    
    cout<< "Front Element "<<q.front()<<endl;
    cout<< "Size Of The Queue " <<q.size()<<endl;
    
    cout<< "Deleting Last Elements From The Queue"<<endl;
    q.dequeue();
    
    if (q.empty()==true)
        cout<<"Queue Is Empty"<<endl;
    else
        cout<<"Queue Is Not Empty"<<endl;
    
    cout<<"------------------------------"<<endl;
    cout<<"End Of Function Testing"<<endl;
    cout<<endl;
}
