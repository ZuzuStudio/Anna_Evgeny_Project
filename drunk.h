#ifndef DRUNK_H
#define DRUNK_H
struct Cards
{
    int znachenie;
    char mast;
};
struct Node
{
    Cards data;
    Node *link;
};
struct Queue
{
    Node *beg, *end;
};

bool enqueue( Queue &q, Cards dt);
bool dequeue(Queue &q);
Cards onfront(Queue &q);
Cards onback(Queue &q);
bool isempty(Queue q);
void clear(Queue &q);
#endif


