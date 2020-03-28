#include<iostrem>
using namespace std;
class Queues
{
    int FRONT , REAR ,max;
    int queue_array[5];
public:
    Queues();
    void insert(int element);
    void remove();
    void display();
};
Queues::Queues()
{
    FRONT = -1;
    REAR = -1;
}
void Queues::insert(int element)
{
    if((FRONT == -1 && REAR == -1) || FRONT ==  REAR+1)
    {
        cout << "\n Queue overflow\n"<<endl;
        return;
    }
    if(FRONT==-1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else
    {
        if(REAR==max-1)
        {
            REAR = 0;
        }
        else
        {
            REAR = REAR +1;
        }
        queue_array[REAR] = element;
    }
}
void Queues::remove()
{
    if(FRONT == -1)
    {
        cout << "Queue underflow\n"<<endl;
        return;
    }
    cout << "The element deleted from the queue is :"<< queue_array[FRONT]<< endl<<endl;
    if(FRONT==REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
    else
    {
        if(FRONT==max-1)
            FRONT = 0;
        else
            FRONT =FRONT +1;

    }
}
void Queues :: display()
{
    int Front_Position = FRONT ;
    int Rear_Position = REAR;
    if(FRONT == max-1)
    {
        cout << "Queue is empty\n"<<endl;
        return;
    }
    cout << "\n Element in the queue"
}
