#include <iostream>
#include "queue_func.h"
#include <fstream>
using namespace std;

void show_coloda( Cards *coloda)
{
    for (int i=0; i<52; i++)
        cout<<coloda[i].mast<<" "<<coloda[i].znachenie<<endl;
}

void push_coloda(Queue q)
{
    q.beg=NULL;
    q.end=NULL;
    ifstream fin("drunk");
    Cards coloda[52];
    int i=0;
    while(!fin.eof())
    {
        enqueue(q,*coloda);
        fin>>coloda[i].mast;
        fin>>coloda[i].znachenie;
        i++;
        if( i==52)
            break;
    }
    cout<<"Исходная колода:  "<<endl;
    show_coloda(coloda);
    cout<<"========"<<endl<<endl;
    shuffling(coloda);
    cout<<"После тасования карт:  "<<endl;
    show_coloda(coloda);
}

int main()
{
    Queue a;
    push_coloda(a);
    return 0;
}

