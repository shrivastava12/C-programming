#include<iostream>
using namespace std;
class Queue
{
    int FRONT,REAR,Max;
    int queue_array[5];
public:
    Queue();
    void Insert(int element);
    void Remove();
    void Display();
};
Queue::Queue()
{
    FRONT = -1;
    REAR = -1;
    Max = 5;
}
void Queue :: Insert(int element)
{
    if((FRONT == 0 && REAR == Max-1) || FRONT == REAR + 1)
    {
        cout << "\n Queue overflow\n" <<endl;
        return;
    }
    if(FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else
    {
        if(REAR == Max -1)
        {
            REAR = 0;
        }
        else
        {
            REAR = REAR + 1;
        }
        queue_array[REAR] = element;

    }
}
void Queue :: Remove()
{
    if(FRONT == -1)
    {
        cout << " Queue Underflow\n"<<endl;
        return;
    }
    cout << "The element deleted from the queue is " << queue_array[FRONT]<<endl <<endl;
    if(FRONT == REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
    else
    {
        if(FRONT == Max-1)
        {
            FRONT = 0;
        }
        else
        {
            FRONT = FRONT +1;
        }
    }
}
void Queue :: Display()
{
    int Front_position = FRONT;
    int Rear_position = REAR;
    if(FRONT == -1)
    {
        cout << "Queue is empty\n"<<endl;
        return;
    }
    cout << "\n Element in the queue is :\n" <<endl;
    if(Front_position <= Rear_position)
    {
        while(Front_position <= Rear_position)
        {
            cout << queue_array[Front_position] << " " ;
            Front_position++;
        }
        cout << endl;
    }
    else
    {
        while(Front_position <= Max-1)
            //Traverse the list till the last  element of the queue
        {
            cout << queue_array[Front_position] << " ";
            Front_position++;
        }
        Front_position = 0;

        while(Front_position <= Rear_position)
        {
            cout << queue_array[Front_position] << " ";
            Front_position++;
        }
        cout << endl;
    }
}
int main()
{
    Queue obj;
    int num;;
    char ch;
    while(1)
    {
        cout << "Menu";
        cout << "\n 1. Implement insert operation" <<endl;
        cout << "2. Implement delete operation" <<endl;
        cout << "3. Delete value" <<endl;
        cout << "4. Exit" <<endl;
        cout << "Enter your choice from (1-4)";
        cin >> ch;
        switch(ch)
        {
        case '1':
            cout << "Enter a Number:";
            cin >> num;
            cout << endl;
            obj.Insert(num);

            break;
        case '2':
            {
                obj.Remove();
            }
            break;
        case '3':
            {
                obj.Display();
                cout << "\n";
            }
            break;
        case '4':
            {
                exit(0);
            }
            break;
        default:
            {
                cout << "Invalid option\n"<<endl;
            }
            break;
        }
    }
}
