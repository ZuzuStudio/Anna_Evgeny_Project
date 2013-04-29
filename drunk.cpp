#include "drunk.h"
#include <new>
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
bool dequeue(Queue &q)
{
    Node *p=q.beg;
    if (p)
    {
        q.beg=q.beg->link;
        Cards dt=p->data;
        p->data.mast = 0;
        p->data.znachenie=0;
        p->link = 0;
        delete p;
        p=NULL;
        if (!q.beg)
            q.end=NULL;
        return true;
    }
    else return false;
}
Cards onfront(Queue &q)
{
  //  if (q.beg)
        return q.beg->data;
  //  else return;
}

Cards onback(Queue &q)
{
  //    if (q.end)
        return q.end->data;
   // else return -1;
}
bool isempty(Queue q)
{
    if(q.beg!=0 && q.end!=0) return false;
    else return true;
}
void clear(Queue &q)
{
    Node *p;
    while(q.end)
    {
        p= q.end;
        q.end=q.end->link;
        p->data.mast=0;
        p->data.znachenie=0;
        delete p;
        p = NULL;
    }
}
