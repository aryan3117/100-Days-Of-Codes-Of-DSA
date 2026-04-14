// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
#include <stdio.h>

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[1000], index[1000], size = 0;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        int found = -1;
        for (int j = 0; j < size; j++)
        {
            if (prefix[j] == sum)
            {
                found = j;
                break;
            }
        }

        if (found != -1)
        {
            int len = i - index[found];
            if (len > maxLen)
                maxLen = len;
        }
        else
        {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);
    return 0;
}