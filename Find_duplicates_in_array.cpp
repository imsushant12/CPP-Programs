#include <bits/stdc++.h>
using namespace std;

int find_duplicate(const int arr[], int n)
{
    //no duplicates can be there if element is only one
    if (n <= 1)
        return -1;

    //we will use loop concept of Linked List, run two pinter at different speed
    //if both the pointers pint the same element, then loop is there. (duplicates)

    //initialize fast and slow
    int slow = arr[0];
    int fast = arr[arr[0]];

    // loop to enter in the cycle
    while (fast != slow)
    {
        // move one step for slow
        slow = arr[slow];

        // move two step for fast
        fast = arr[arr[fast]];
    }

    // loop to find entry point of the cycle
    fast = 0;
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main()
{
    const int arr[] = { 1, 2, 3, 4, 5, 6, 3 };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << find_duplicate(arr , n);

    return 0;
}
