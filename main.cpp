#include <iostream>
#include "drunk.h"
#include <fstream>
using namespace std;

void push_coloda(Queue q)
{
    q.beg=NULL;
    q.end=NULL;
    ifstream fin("drunk");
    Cards b;
    fin>>b.mast;
    fin>>b.znachenie;
    while(!fin.eof())
    {
        enqueue(q,b);
        fin>>b.mast;
        fin>>b.znachenie;
    }

}
int main()
{
    Queue a;
    push_coloda(a);
    cout<<onfront(a).mast;
   // Cards temp;
   // temp=onfront(a);
    //cout<<temp.mast<<' '<<temp.znachenie;
    //Mast coloda[52];

    return 0;
}
