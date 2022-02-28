/*
    Sorting Algorithms

    1. Selection Sort   : O(n^2)
    2. Bubble Sort      : O(n^2)
    3. Insertion Sort   : O(n^2)
    4. Heap Sort        : O(nlogn)
    5. Quick Sort       : O(n^2) (Avg: nlogn)
    6. Merge Sort       : O(nlogn)
*/

#include <vector>
using namespace std;


class SortingAlgos
{
private:
    static void heapify(vector<int> &, int, int);
    static int partition(vector<int> &, int, int);
    static void merge(vector<int> &, int, int, int);

public:
    static void selectionSort(vector<int> &);
    static void bubbleSort(vector<int> &);
    static void insertionSort(vector<int> &);
    static void heapSort(vector<int> &);
    static void quickSort(vector<int> &, int, int);
    static void mergeSort(vector<int> &, int, int);
};


// 1. Selection Sort
void SortingAlgos::selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;

        swap(arr[minIndex], arr[i]);
    }
}


// 2. Bubble Sort
void SortingAlgos::bubbleSort(vector<int> &arr)
{
    int i, j, n = arr.size();
    bool isSwap;

    for (int i = 0; i < n - 1; i++)
    {
        isSwap = false;
        
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        
        if (!isSwap)
            break;
    }
}


// 3. Insertion Sort
void SortingAlgos::insertionSort(vector<int> &arr)
{
    int n = arr.size();
   
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}


// 4. Heap Sort
void SortingAlgos::heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void SortingAlgos::heapSort(vector<int> &arr)
{
    int n = arr.size();
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


// 5. Quick Sort
int SortingAlgos::partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    
    return i + 1;
}

void SortingAlgos::quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// 6. Merge Sort
void SortingAlgos::merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<int> L(n1, 0), R(n2, 0);
    
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0;
    int k = l;
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void SortingAlgos::mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}
