/*
     BINARY SEARCH

     -- Binary Search
     -- Lower Bound
     -- Upper Bound
*/

#include <vector>
using namespace std;


// Binary Search
int binarySearch(vector<int> &arr, int x)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, skip left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, skip right half
        else
            right = mid - 1;
    }

    return -1;
}


// Lower Bound
int lowerBound(vector<int> &arr, int x)
{
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (x <= arr[mid])
            right = mid;
        else
            left = mid + 1;
    }

    if (left < arr.size() && arr[left] < x)
        return -1;

    return left;
}


// Upper Bound
int upperBound(vector<int> &arr, int x)
{
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (x >= arr[mid])
            left = mid + 1;
        else
            right = mid;
    }

    if (left < arr.size() && arr[left] <= x)
        return -1;

    return left;
}
