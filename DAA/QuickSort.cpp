#include <iostream>

using namespace std;

int partition(int *arr, int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

// Randomized
int randomPartition(int *arr, int p, int r)
{
    int x = arr[r];
    int i = rand() % ((r - p) + 1) + p;
    cout << i << endl;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void radomizedQuickSort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = randomPartition(arr, p, r);
        radomizedQuickSort(arr, p, q - 1);
        radomizedQuickSort(arr, q + 1, r);
    }
}

int main()
{
    int A[] = {23, 34, 54, 123, 34, 56, 67676, 112};
    int n = sizeof(A) / sizeof(A[0]);
    radomizedQuickSort(A, 0, n - 1);
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}

//----------------------------------------------2---------------------------------------------
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <chrono>
// #include <random>

// using namespace std;

// // Function to partition the array for Quick Sort
// int partition(vector<int>& arr, int low, int high) {
//     int pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// // Deterministic Quick Sort
// void deterministicQuickSort(vector<int>& arr, int low, int high) {
//     if (low < high) {
//         int pivot = partition(arr, low, high);
//         deterministicQuickSort(arr, low, pivot - 1);
//         deterministicQuickSort(arr, pivot + 1, high);
//     }
// }

// // Randomized Quick Sort
// void randomizedQuickSort(vector<int>& arr, int low, int high) {
//     if (low < high) {
//         // Randomly select a pivot
//         int randomPivot = low + rand() % (high - low + 1);
//         swap(arr[randomPivot], arr[high]);
//         int pivot = partition(arr, low, high);
//         randomizedQuickSort(arr, low, pivot - 1);
//         randomizedQuickSort(arr, pivot + 1, high);
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     vector<int> arr(n);
//     vector<int> arrCopy;

//     // Initialize a random seed
//     srand(time(nullptr));

//     // Generate a random array
//     for (int i = 0; i < n; i++) {
//         arr[i] = rand();
//     }

//     arrCopy = arr;  // Make a copy of the array for both algorithms

//     // Deterministic Quick Sort
//     auto start = chrono::high_resolution_clock::now();
//     deterministicQuickSort(arr, 0, n - 1);
//     auto end = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
//     cout << "Deterministic Quick Sort took " << duration.count() << " microseconds" << endl;

//     // Randomized Quick Sort
//     start = chrono::high_resolution_clock::now();
//     randomizedQuickSort(arrCopy, 0, n - 1);
//     end = chrono::high_resolution_clock::now();
//     duration = chrono::duration_cast<chrono::microseconds>(end - start);
//     cout << "Randomized Quick Sort took " << duration.count() << " microseconds" << endl;

//     return 0;
// }
