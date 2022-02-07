/*
    CIRCULAR QUEUE
*/

#include <iostream>
using namespace std;

#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int num)
{
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
    {
        cout << "OVERFLOW\n";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = num;
}

void dequeue()
{
    if (front == -1)
    {
        cout << "UNDERFLOW\n";
        return;
    }
    queue[front] = 0;
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

int peek()
{
    if (front == -1)
    {
        cout << "UNDERFLOW\n";
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (front == -1)
    {
        cout << "UNDERFLOW\n";
        return;
    }
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i = front; i < MAX; i++)
            cout << queue[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << queue[i] << " ";

        cout << endl;
    }
}

int main()
{

    // Inserting 4 elements in queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    // Display queue
    cout << "Queue after inserting {1, 2, 3, 4} :- ";
    display();

    // Insertion of another element results in overflow
    cout << "On inserting 5th element :- ";
    enqueue(5);

    // Display queue, prev element not inserted
    cout << "Queue after overflow :- ";
    display();

    // Print front element
    cout << "Front of queue :- " << peek() << endl;

    // Deleting 4 elements from queue
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    // Another call to dequeue would result in undeflow
    cout << "After deleting all elements, on calling dequeue again results in :- ";
    dequeue();

    return 0;
}
