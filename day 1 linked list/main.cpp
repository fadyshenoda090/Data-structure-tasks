#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
    Node *Prev;
    Node()
    {
        Data = 0;
        Next = Prev = NULL;
    }
    Node(int _data)
    {
        Data = _data;
        Next = Prev = NULL;
    }

};

class LinkedList
{
    Node *First;
    Node *Last;

public:
    LinkedList()
    {
        First = Last = NULL;
    }

    void Add(int data)
    {
        Node *newNode = new Node(data);
        if (First == NULL)
        {

            First = Last = newNode;
        }
        else
        {
            Last->Next = newNode;
            newNode->Prev = Last;
            Last = newNode;
        }
    }

    void Display()
    {
        Node *PDisplay = First;
        while (PDisplay != NULL)
        {
            cout << PDisplay->Data << endl;
            PDisplay = PDisplay->Next;
        }
    }
    void Displayrev()
    {
        Node *PDisplay = Last;
        while (PDisplay != NULL)
        {
            cout << PDisplay->Data << endl;
            PDisplay = PDisplay->Prev;
        }
    }
    Node *SearchNode(int value)
    {
        Node *PSearch = First;
        while (PSearch != NULL)
        {
            if (PSearch->Data == value)
            {
                return PSearch;
            }
            PSearch = PSearch->Next;
        }
        return NULL;
    }

    void insertAfter(Node *PAfter, int value)
    {
        Node *newNode = new Node(value);
        if (PAfter == Last)
        {
            Add(value);
        }
        else
        {
            newNode->Prev = PAfter;
            newNode->Next = PAfter->Next;
            PAfter->Next = newNode;
            newNode->Next->Prev = newNode;
        }
    }
    void insertbefore(Node *PAfter, int value)
    {
        Node *newNode = new Node(value);
        if (PAfter == First)
        {
            newNode->Prev=NULL;
            newNode->Next=First;
            First->Prev=newNode;
            First=newNode;
        }
        else
        {
            newNode->Prev=PAfter->Prev;
            newNode->Next=PAfter;
            PAfter->Prev=newNode;
            newNode->Prev->Next=newNode;
        }
    }
};
int main()
{
    LinkedList l;
    l.Add(20);
    l.Add(50);
    l.Add(10);
    l.Add(16);
    l.Add(80);

    Node *data = l.SearchNode(50);
    l.insertbefore(data,30);
    l.insertAfter(data, 40);
    l.Display();
    l.Displayrev();
    return 0;
}
