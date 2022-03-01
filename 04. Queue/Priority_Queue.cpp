/*
    Implementation of PRIORITY QUEUE
    using linkedList
*/

#include <stdexcept>

template <class T>
class PriorityQueue
{
private:
    // Queue's node
    class Node
    {
    public:
        T data;
        int priority;
        Node *next;
        Node(T x, int p) : data(x), priority(p), next(nullptr) {}
    };

    Node *front;

public:
    PriorityQueue<T>() : front(nullptr) {}

    bool isEmpty();             // checks if queue is empty
    void enqueue(T val, int p); // enqueue a node in queue
    void dequeue();             // dequeue a node in queue
    T getFront();               // return data of front node
};

// Function to check whether queue is empty or not
template <class T>
bool PriorityQueue<T>::isEmpty()
{
    if (front == nullptr)
        return true;
    else
        return false;
}

// Function to insert a node
template <class T>
void PriorityQueue<T>::enqueue(T val, int p)
{
    Node *ptr = new Node(val, p);
    if (front == nullptr || front->priority < p)
    {
        ptr->next = front;
        front - ptr;
    }
    else
    {
        Node *tmp = front;
        while (tmp->next != nullptr && tmp->next->priority >= p)
            tmp = tmp->next;
        ptr->next = tmp->next;
        tmp->next = ptr;
    }
}

// Function to remove higher priority node
template <class T>
void PriorityQueue<T>::dequeue()
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue underflow!");
    }
    else
    {
        Node *ptr = front;
        front = front->next;
        delete ptr;
    }
}

// Function to return data of front node
template <class T>
T PriorityQueue<T>::getFront()
{
    if (front == nullptr)
    {
        throw std::underflow_error("Queue underflow!");
    }
    else
    {
        return front->data;
    }
}
