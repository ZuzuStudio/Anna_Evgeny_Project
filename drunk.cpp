#include "drunk.h"
#include <new>
#include <cstdlib>
using namespace std;


bool enqueue( Queue &q,Cards dt)
{
    Node *p=NULL;
    p=new(nothrow) Node;
    if(!p) return false;
    else
    {
        p->data.mast=dt.mast;
        p->data.znachenie=dt.znachenie;
        p->link=NULL;
        if (q.end)
            q.end->link=p;
        q.end=p;
        if (!q.beg)
            q.beg=q.end;
        return true;
    }
}

Cards dequeue(Queue &q)
{
    Node *p=q.beg;
    if (isempty(q))
        // return ;
        q.beg=q.beg->link;
    Cards dt=p->data;
    p->data.mast = 0;
    p->data.znachenie=0;
    p->link = 0;
    delete p;
    p=NULL;
    return dt;
}

Cards onfront(Queue &q)
{
    //  if (q.beg)
    return q.beg->data;
    //  else return;
}

Cards onback(Queue &q)
{
    //if (q.end)
    return q.end->data;
    // else return -1;
}
bool isempty(Queue q)
{
    if(q.beg && q.end)
        return false;
    else
        return true;
}

void clear(Queue &q)
{
    Node *p;
    while(isempty(q))
    {
        p=q.end;
        q.end=p->link;
        p->data.mast=0;
        p->data.znachenie=0;
        p->link=0;
        delete p;
        p = NULL;
    }
}

void shuffling(Cards *coloda)
{
    for (int i = 0; i < 52; ++i)
    {
        int j = rand() % 52;
        Cards temp = coloda[i];
        coloda[i] = coloda[j];
        coloda[j] = temp;
    }
}

Queue united(Queue &a, Queue &b)
{
    Queue c;
    while (!isempty(a))
    {
        Cards temp=dequeue(a);
        enqueue(c, temp);

    }
    while (!isempty(b))
    {
        Cards temp=dequeue(b);
        enqueue(c, temp);
    }
    return c;
}


