/*
    Implementation of various operation of array
    - Dynamic memory allocation using smart pointer
    - Insert element at end
    - Insert element at a position
    - Replace value at a position with new value
    - Get element
    - Search for a value
    - Display array
    - Remove an element
*/

#include <iostream>
#include <memory>
using namespace std;

class Array
{
private:
    // length of the array
    int size = 0;
    // maximum number of elements that can be stored
    int capacity = 0;
    // smart pointer to dynamic array
    unique_ptr<int[]> p;

public:
    // Constructor
    Array(int n = 16) : p(new (nothrow) int[n]())
    {
        capacity = n;
        size = 0;
    }

    // increase size of the array
    bool reAllocate();
    // insert new element in the end
    bool insert(int);
    // insert new element at given position
    bool insert(int, int);
    // replace value at given position with new value
    bool replace(int, int);
    // get value at given position
    int get(int);
    // check whether the given value is present
    bool search(int);
    // print all values
    void display();
    // remove element at given position
    void remove(int);
};

bool Array::reAllocate()
{
    unique_ptr<int[]> p2(new (nothrow) int[capacity * 2]());
    // memory is successfully allocated
    if (p2 != nullptr)
    {
        capacity = capacity * 2;
        // copy values from old location to new
        for (int i = 0; i < size; i++)
            p2[i] = p[i];
        // move ownership from p2 to p
        p = move(p2);
        return true;
    }

    return false;
}

bool Array::insert(int x)
{   // no space is available to insert new element
    if (size == capacity)
    {
        bool ok = reAllocate();
        if (!ok)
        {
            return false;
        }
    }

    // insert at end and change size
    p[size] = x;
    size++;

    return true;
}

bool Array::insert(int x, int pos)
{
    
    --pos;
    if (size == capacity)
    {
        bool ok = reAllocate();
        if (!ok)
        {
            return false;
        }
    }
    // shift elements to right to create space at pos
    for (int i = size - 1; i >= pos; i--)
    {
        p[i + 1] = p[i];
    }
    // insert at pos
    p[pos] = x;
    size++;

    return true;
}

bool Array::replace(int x, int pos)
{  
    --pos;
    p[pos] = x;
    return true;
}

int Array::get(int pos)
{
    --pos;
    return p[pos];
}

bool Array::search(int x)
{  
    for (int i = 0; i < size; i++)
    {
        if (p[i] == x)
            return true;
    }
    return false;
}

void Array::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";
}

void Array::remove(int pos)
{
    pos--;
    // elements after pos is shifted to left 
    for (int i = pos + 1; i < size; i++)
    {
        p[i - 1] = p[i];
    }
    // last element is made 0 and size is reduced by 1
    p[size - 1] = 0;
    size--;
}
