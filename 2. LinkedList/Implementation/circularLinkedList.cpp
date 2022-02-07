/*
    CIRCULAR LINKED LIST
    - Check if CLL is empty
    - Display 
    - Insertion at beginning
    - Insertion at end
    - Search for a node
    - Deletion at beginning 
    - Deletion at end
*/

#include <iostream>

template <class T>
class CircularLinkedList
{
private:
    // Node of the linked list
    class Node
    {
    public:
        T data;     // data of the current node
        Node *next; // pointer to the next node

        Node(T val) : data(val), next(nullptr) {}
        Node() : data{}, next(nullptr) {}
    };

    // points to start of the linked list
    Node *head;

    // creates new node
    Node *newNode(T);

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    bool isEmpty();    // Returns true if list is empty, otherwise false
    void display();    // Traverses and prints the linked list
    void insertBeg(T); // Inserts a node at the beginning of the linked list
    void insertEnd(T); // Inserts a node at the end of the linked list
    bool search(T);    // Returns true if a node with given data is found
    void deleteBeg();  // Delete a node from the beginning of the linked list
    void deleteEnd();  // Delete a node from the emd of the linked list
};

// creates and returns new node of the linked list
template <class T>
LinkedList<T>::Node *LinkedList<T>::newNode(T val)
{
    Node *ptr = new Node(val);

    if (ptr == nullptr)
    {
        cout << "Overflow!!!" << endl;
        exit(1)
    }

    return ptr;
}

// Returns true if linked list is empty - O(1)
template <class T>
bool LinkedList<T>::isEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}

// Traverse and print the linked list - O(n)
template <class T>
void LinkedList<T>::display()
{
    if (isEmpty())
    {
        cout << "List is empty!!!" << endl;
        return;
    }

    Node *ptr = head;

    while (ptr->next != head)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << ptr->data << endl;
}

// Inserts the node at the beginning of the linked list - O(1)
template <class T>
void LinkedList<T>::insertBeg(T val)
{
    Node *ptr = newNode(val);
    if (isEmpty())
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        Node *cur = head;
        while (cur->next != head)
        {
            cur = cur->next;
        }
        cur->next = ptr;
        ptr->next = head;
        head = ptr;
    }
}

// Inserts the node at the end of the linked list - O(n)
template <class T>
void LinkedList<T>::insertEnd(T val)
{
    Node *ptr = newNode(val);
    if (isEmpty)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        Node *cur = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = ptr;
        ptr->next = head;
    }
}

// Returns true if a node with data equals val is found - O(n)
template <class T>
bool LinkedList<T>::search(T val)
{
    if (isEmpty())
        return false;

    Node *cur = head;

    while (cur->next != head)
    {
        if (val == cur->data)
            return true;
        curr = curr->next;
    }
    if (val == cur->data)
        return true;
    return false;
}

// Deletes a node from the beginning of the linked list - O(1)
template <class T>
void LinkedList<T>::deleteBeg()
{
    if (isEmpty())
    {
        cout << "Underflow!!!" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = head->next;
    temp = head;
    head = head->next;
    delete temp;
}

// Deletes a node from the end of the linked list - O(n)
template <class T>
void LinkedList<T>::deleteEnd()
{
    if (isEmpty())
    {
        cout << "Underflow!!!" << endl;
        return;
    }
    if (head->next == head)
    {
        Node *temp = head;
        head = nullptr;
        delete temp;
        return;
    }

    Node *cur = head;
    Node *prev = nullptr;

    while (cur->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = head;
    delete cur;
}

// Destructor of the LinkedList class
template <class T>
LinkedList<T>::~LinkedList()
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
