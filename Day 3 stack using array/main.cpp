#include <iostream>

using namespace std;
const int maxsize=4;
class stack
{
    int top;
    int arr[maxsize];
public:
    stack():top(-1) {}
    void push(int element)
    {
        if(top>=maxsize-1)
        {
            cout<<"the array is full\n";
        }
        else
        {
            top++;
            arr[top]=element;
        }
    }
    bool peek(int &value)
    {
        if(top==-1) //arr is empty
        {
            return true;
        }
        else  //arr is not empty
        {
            value=arr[top];
            return false;
        }
    }
    bool pop(int &value)
    {
        if(top ==-1)
        {
            return true;
        }
        else
        {
            value=arr[top];
            top--;
            return false;
        }
    }
    void display()
    {
       for (int i = top; i >= 0; i--)
		{
			cout << arr[i]<<endl;
		}
    }
};


int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    int elemment,elemment2;
    bool isempty=s.peek(elemment);
    if(isempty)
    {
        cout<<"array is empty \n";
    }
    else
    {
        cout<<"array is not empty and the element to be deleted is :"<<elemment<<endl;
    }
    s.push(60);
    bool isempty2=s.pop(elemment2);
    if(isempty2)
    {
        cout<<"the array is empty\n";
    }
    else
    {
        cout<<"array is not empty and the deleted element is :"<<elemment2<<endl;
    }
    s.display();
    return 0;
}
