// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int m, n;
    if (scanf("%d %d", &m, &n) != 2)
        return 0;

    int *table = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        table[i] = -1;

    for (int j = 0; j < n; j++)
    {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        int h = key % m;
        if (strcmp(op, "INSERT") == 0)
        {
            for (int i = 0; i < m; i++)
            {
                int index = (h + i * i) % m;
                if (table[index] == -1)
                {
                    table[index] = key;
                    break;
                }
            }
        }
        else if (strcmp(op, "SEARCH") == 0)
        {
            int found = 0;
            for (int i = 0; i < m; i++)
            {
                int index = (h + i * i) % m;
                if (table[index] == key)
                {
                    found = 1;
                    break;
                }
                if (table[index] == -1)
                    break;
            }
            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}