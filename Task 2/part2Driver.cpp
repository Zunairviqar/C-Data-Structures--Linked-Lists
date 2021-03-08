#include <iostream>
#include <string>
#include <sstream>
#include "DLCirList.h"

void Part2DriverDoublyCircularLinkedListTest();
void ExampleCase();
void Part2Driver();

int main() {
    
    Part2DriverDoublyCircularLinkedListTest();
    ExampleCase();
    Part2Driver();
    return 0;
}

void Part2DriverDoublyCircularLinkedListTest()
{
    cout<<"Start Of Testing The Functions"<<endl;
    cout<<"-------------------------------"<<endl;
    
    CDLinkedList N;
    if (N.empty())
        cout<<"List is Empty"<<endl;
    else
        cout<<"List is not Empty"<<endl;
    
    N.add("A");
    N.add("B");
    
    if (N.empty())
        cout<<"List is Empty"<<endl;
    else
        cout<<"List is not Empty"<<endl;
    
    N.add("C");
    N.add("D");
    N.displayAll();
    N.reverseList(N);
    N.displayAll();
    cout<<"-------------------------------"<<endl;
    cout<<"End Of Testing The Functions"<<endl;
    cout<<endl;
}

void ExampleCase()
{
    cout<<"Start Of Example Case"<<endl;
    cout<<"-------------------------------"<<endl;
    
    CDLinkedList M;
    CDLinkedList T;
    int NofM = 4; //NofM = Number of Missionaries
    M.add("A");
    M.add("B");
    M.add("C");
    M.add("D");
    cout<< "The Missionaries Are: ";
    M.displayAll();
    
    srand((unsigned int)time(0));
    int Mtmp;
    int day = 1;
    Mtmp = NofM;
    string order[NofM];

            int RaN =3; //Random Number (3 for testing)
            while(Mtmp!=1)
            {
                string tmp = " ";
                for(int i =0; i < RaN; i ++)
                {
                    M.advanceB();
                }
                tmp = M.front();
                T.add(tmp);
                M.remove();
                Mtmp--;
            }
            cout<< M.front()<< " Is Consumed On Day "<< day<<endl;
            order[NofM-1] = M.front();
            M.remove();
            NofM--;
            day++;
            Mtmp= NofM;
            for(int i =0; i < NofM; i++)
            {
                M.add(T.front());
                T.remove();
                M.advanceF();
            }
    
            RaN =6; //Random Number (6 for testing)
            while(Mtmp!=1)
            {
                string tmp = " ";
                for(int i =1; i < RaN-1; i ++)
                {
                    M.advanceF();
                }
                if(RaN==1)
                    M.advanceB();
                tmp = M.front();
                T.add(tmp);
                M.remove();
                M.advanceF();
                Mtmp--;
            }
            cout<< M.front()<< " Is Consumed On Day "<< day<<endl;
            order[NofM-1] = M.front();
            M.remove();
            NofM--;
            day++;
            Mtmp= NofM;
            for(int i =0; i < NofM; i++)
            {
                M.add(T.front());
                T.remove();
                M.advanceF();
            }
    
            RaN =1; //Random Number (3 for testing)
            while(Mtmp!=1)
            {
                string tmp = " ";
                for(int i =0; i < RaN; i ++)
                {
                    M.advanceB();
                }
                tmp = M.front();
                T.add(tmp);
                M.remove();
                Mtmp--;
            }
            cout<< M.front()<< " Is Consumed On Day "<< day<<endl;
            order[NofM-1] = M.front();
            M.remove();
            NofM--;
            day++;
            Mtmp= NofM;
            for(int i =0; i < NofM; i++)
            {
                M.add(T.front());
                T.remove();
                M.advanceF();
            }
            
        cout<< M.front()<< " Is Consumed On Day "<< day<<endl;
        order[NofM-1] = M.front();
        M.remove();
    
        cout<< "Order In Which They Are Eaten Is";
        for(int i = 3; i >= 0; i --)
        {
            cout<< " " << order[i];
        }
        cout<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"End Of Example Case"<<endl;
    cout<<endl;
    

}

void Part2Driver()
{
    
    cout<<"Start Of Part 1 Driver"<<endl;
    cout<<"-------------------------------"<<endl;
    
    int M = 0;
    cout<<"Enter The Number Of Missionaries "<<endl;
    cin>>M;
    
    CDLinkedList ListOfM;
    CDLinkedList ListTmp;
    string name = " ";
    for (int i =1; i < M+1; i ++)
    {
        cout<<"Enter The Name Of Missionary "<< i<<endl;
        cin>>name;
        ListOfM.add(name);
    }
    cout<< "The Missionaries Are: ";
    ListOfM.displayAll();
        
    srand((unsigned int)time(0));
    int RemainingM,N,day;
    N = M;
    RemainingM = M;
    day = 1;
    string order[M];

    while(M!=1)
    {
        if(M%2==0)
        {
            int RaN = rand()%(100-1+1) + 1; //rand()%(b-a+1) + a (Between a and b)
            cout<< "The Number Drawn From The Hat is: "<<RaN<<endl;
            while(RemainingM!=1)
            {
                string tmp = " ";
                for(int i =0; i < RaN; i ++)
                {
                    ListOfM.advanceB();
                }
                tmp = ListOfM.front();
                ListTmp.add(tmp);
                ListOfM.remove();
                RemainingM--;
            }
            cout<< ListOfM.front()<< " Is Consumed On Day "<<day <<endl;
            order[M-1] = ListOfM.front();
            ListOfM.remove();
            M--;
            day++;
            RemainingM= M;
            for(int i =0; i < M; i++)
            {
                ListOfM.add(ListTmp.front());
                ListTmp.remove();
                ListOfM.advanceF();
            }
        }
        else if(M%2==1)
        {
            int RaN = rand()%(100-1+1) + 1;
            cout<< "The Number Drawn From The Hat is: "<<RaN<<endl;
            while(RemainingM!=1)
            {
                string tmp = " ";
                for(int i =1; i < RaN-1; i ++)
                {
                    ListOfM.advanceF();
                }
                if(RaN==1)
                    ListOfM.advanceB();
                tmp = ListOfM.front();
                ListTmp.add(tmp);
                ListOfM.remove();
                ListOfM.advanceF();
                RemainingM--;
            }
            cout<< ListOfM.front()<< " Is Consumed On Day "<<day<<endl;
            order[M-1] = ListOfM.front();
            ListOfM.remove();
            M--;
            day++;
            RemainingM= M;
            for(int i =0; i < M; i++)
            {
                ListOfM.add(ListTmp.front());
                ListTmp.remove();
                ListOfM.advanceF();
            }
        }
    }
    cout<< ListOfM.front()<< " Is Consumed On Day "<<day<< endl;
    order[M-1] = ListOfM.front();
    ListOfM.remove();
    cout<< "Order In Which They Are Eaten Is";
    for(int i = N-1; i >= 0; i --)
    {
        cout<< " " << order[i];
    }
    cout<<endl;

    cout<<"-------------------------------"<<endl;
    cout<<"End Of Part 1 Driver"<<endl;
    cout<<endl;
    
}
