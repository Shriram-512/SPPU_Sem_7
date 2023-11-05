#include <iostream>

using namespace std;

int nonRecursiveFibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    int sum = 0;

    for (int i = 2; i <= n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}

int recursiveFibonacci(int n)

{
    if (n <= 1)
    {
        return n;
    }

    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter the number of Fibonacci numbers to print: ";
    cin >> n;
    cout << "Non Recursive way: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nonRecursiveFibonacci(i) << " ";
    }

    cout << endl;
    cout << "Recursive Way: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << recursiveFibonacci(i) << " ";
    }

    return 0;
}

// Non-Recursive:

// Time complexity: O(n)
// Space complexity: O(1)

// Recursive:

// Time complexity: O(2^n)

// Space complexity: O(n)
