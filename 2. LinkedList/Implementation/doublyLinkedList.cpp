/*
    DOUBLY LINKED LIST

    Operations performed:
    - Check if DLL is empty
    - Display
    - Insertion at beginning
    - Insertion at end
    - Insertion before a node
    - Insertion after a node
    - Search a node
    - Count total number of nodes
    - Delete start node
    - Delete end node
*/

#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList
{
private:
    // Node of the linked list
    class Node
    {
    public:
        T data;     // data of the current node
        Node *next; // pointer to the next node
        Node *prev; // pointer to the previous node

        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
        Node() : data{}, next(nullptr), prev(nullptr) {}
    };

    // points to start of the linked list
    Node *head;

    // creates new node
    Node *newNode(T);

public:
    DoublyLinkedList() : head(nullptr) {}
    ~DoublyLinkedList();
    bool isEmpty();          // Returns true if list is empty, otherwise false
    void display();          // Traverses and prints the linked list
    void insertBeg(T);       // Inserts a node at the beginning of the linked list
    void insertEnd(T);       // Inserts a node at the end of the linked list
    void insertBefore(T, T); // Inserts a node before the node with given data
    void insertAfter(T, T);  // Inserts a node after the node with given data
    bool search(T);          // Returns true if a node with given data is found
    int totalNodes();        // Returns total number of node in the linked list
    void deleteBeg();        // Delete a node from the beginning of the linked list
    void deleteEnd();        // Delete a node from the end of the linked list
};

// creates and returns new node of the linked list
template <class T>
typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::newNode(T val)
{
    Node *ptr = new Node(val);

    if (ptr == nullptr)
    {
        cout << "Overflow!!!" << endl;
        exit(1);
    }

    return ptr;
}

// Returns true if linked list is empty - O(1)
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}

// Traverse and print the linked list - O(n)
template <class T>
void DoublyLinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "List is empty!!!" << endl;
        return;
    }

    Node *ptr = head;

    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Inserts the node at the beginning of the linked list - O(1)
template <class T>
void DoublyLinkedList<T>::insertBeg(T val)
{
    Node *ptr = newNode(val);
    if (isEmpty())
    {
        head = ptr;
        return;
    }
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}

// Inserts the node at the end of the linked list - O(n)
template <class T>
void DoublyLinkedList<T>::insertEnd(T val)
{
    Node *ptr = newNode(val);

    if (isEmpty)
    {
        head = ptr;
        return;
    }

    Node *cur = head;
    while (cur->next != nullptr)
        cur = cur->next;

    cur->next = ptr;
    ptr->prev = cur;
}

// Inserts the node before the node with the given data - O(n)
template <class T>
void DoublyLinkedList<T>::insertBefore(T val, T data)
{
    if (isEmpty() || head->data == data)
    {
        insertBeg(val);
        return;
    }

    Node *ptr = newNode(val);
    Node *cur = head;

    while (cur != nullptr && cur->data != data)
    {
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "No node present with data equals " << data << "!!!" << endl;
        return;
    }

    ptr->next = cur;
    ptr->prev = cur->prev;
    cur->prev->next = ptr;
    cur->prev = ptr;
}

// Inserts the node after the node with given data - O(n)
template <class T>
void DoublyLinkedList<T>::insertAfter(T val, T data)
{
    if (isEmpty() || head->data == data)
    {
        insertEnd(val);
        return;
    }

    Node *ptr = newNode(val);
    Node *cur = head;

    while (cur != nullptr && cur->data != data)
        cur = cur->next;

    if (cur == nullptr)
    {
        cout << "No node present with data equals " << data << "!!!" << endl;
        return;
    }

    ptr->prev = cur;
    ptr->next = cur->next;
    cur->next->prev = ptr;
    cur->next = ptr;
}

// Returns true if a node with data equals val is found - O(n)
template <class T>
bool DoublyLinkedList<T>::search(T val)
{
    if (isEmpty())
        return false;

    Node *cur = head;

    while (cur != nullptr)
    {
        if (val == cur->data)
            return true;
        cur = cur->next;
    }

    return false;
}

// Returns the count of total number of nodes present - O(n)
template <class T>
int DoublyLinkedList<T>::totalNodes()
{
    int count = 0;
    Node *cur = head;

    while (cur != nullptr)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

// Deletes a node from the beginning of the linked list - O(1)
template <class T>
void DoublyLinkedList<T>::deleteBeg()
{
    if (isEmpty())
    {
        cout << "Underflow!!!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}

// Deletes a node from the end of the linked list - O(n)
template <class T>
void DoublyLinkedList<T>::deleteEnd()
{
    if (isEmpty())
    {
        cout << "Underflow!!!" << endl;
        return;
    }

    if (head->next == nullptr)
    {
        Node *temp = head;
        head = nullptr;
        delete temp;
        return;
    }

    Node *cur = head;

    while (cur->next != nullptr)
    {
        cur = cur->next;
    }

    cur->prev->next = nullptr;
    delete cur;
}

// Destructor of the LinkedList class
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node *temp = nullptr;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    head = nullptr;
}
