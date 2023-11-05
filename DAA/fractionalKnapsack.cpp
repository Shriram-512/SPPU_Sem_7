#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double v1 = (double)p1.first / p1.second;
    double v2 = (double)p2.first / p2.second;

    return v1 > v2;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    int w;
    cin >> w;
    sort(a.begin(), a.end(), compare);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (w >= a[i].second)
        {
            ans += a[i].first;
            w -= a[i].second;
            continue;
        }
        double vw = (double)a[i].first / a[i].second;
        ans += vw * w;
        w = 0;
        break;
    }
    cout << ans << endl;
}

//-------------------------------------2-----------------------------------------
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Item {
//     int weight;
//     int value;
// };

// bool compareItems(const Item &a, const Item &b) {
//     double ratioA = (double)a.value / a.weight;
//     double ratioB = (double)b.value / b.weight;
//     return ratioA > ratioB;
// }

// double fractionalKnapsack(vector<Item> items, int capacity) {
//     sort(items.begin(), items.end(), compareItems);

//     double maxTotalValue = 0.0;

//     for (const Item &item : items) {
//         if (capacity == 0) {
//             break;
//         }

//         if (item.weight <= capacity) {
//             maxTotalValue += item.value;
//             capacity -= item.weight;
//         } else {
//             double fraction = (double)capacity / item.weight;
//             maxTotalValue += fraction * item.value;
//             capacity = 0;
//         }
//     }

//     return maxTotalValue;
// }

// int main() {
//     int n;  // Number of items
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<Item> items(n);

//     for (int i = 0; i < n; i++) {
//         cout << "Enter the weight and value of item " << i + 1 << ": ";
//         cin >> items[i].weight >> items[i].value;
//     }

//     int capacity;
//     cout << "Enter the maximum capacity of the knapsack: ";
//     cin >> capacity;

//     double maxValue = fractionalKnapsack(items, capacity);

//     cout << "The maximum value that can be obtained: " << maxValue << endl;

//     return 0;
// }
