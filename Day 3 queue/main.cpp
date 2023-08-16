#include <iostream>

using namespace std;

const int maxsize=4;
class queue
{
    int arr[maxsize];
    int front,rear;
public:
    queue()
    {
        front=rear=-1;
    }
    void enqueue(int element)
    {
        if(rear==maxsize-1)//array is full
        {
            cout<<"the array if full can not enqueue more elements\n";
            return;
        }


        if(front==-1 &&rear==-1)//array is not empty
        {
            front=rear=0;
        }

        else
        {
            rear++;
        }
        arr[rear]=element;
    }
    void dequeue()
    {
        if(front==-1 &&rear==-1)//array is empty
        {
            cout<<"the array is already empty\n";
        }
        else
        {
            int element=arr[front];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front++;
            }
        }
    }
    void display()
    {
         for (int i =front;i<maxsize;i++)
		{
			cout << arr[i]<<endl;
		}
    }
};
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.enqueue(50);
    q.display();
    return 0;
}
