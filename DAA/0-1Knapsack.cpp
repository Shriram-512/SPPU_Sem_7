#include <iostream>

using namespace std;

int main()
{
    int capacity = 10;
    int items = 4;
    int price[items + 1] = {0, 3, 7, 2, 9};
    int wt[items + 1] = {0, 2, 2, 4, 5};
    int dp[items + 1][capacity + 1];

    for (int i = 0; i <= items; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                // There's nothing to add to Knapsack
                dp[i][j] = 0;
            }
            else if (wt[i] <= j)
            {
                // Choose previously maximum or value of current item + value of remaining weight
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else
            {
                // Add previously added item to knapsack
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W).
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W).
The use of 2-D array of size ‘N*W’.
*/

//----------------------------------------2-------------------------------------------
// #include <iostream>
// #include <vector>

// using namespace std;

// int knapsack(int capacity, vector<int> weights, vector<int> values, int n) {
//     vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

//     for (int i = 1; i <= n; i++) {
//         for (int w = 1; w <= capacity; w++) {
//             if (weights[i - 1] > w) {
//                 dp[i][w] = dp[i - 1][w];
//             } else {
//                 dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
//             }
//         }
//     }

//     return dp[n][capacity];
// }

// int main() {
//     int n;  // Number of items
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<int> weights(n);
//     vector<int> values(n);

//     for (int i = 0; i < n; i++) {
//         cout << "Enter the weight and value of item " << i + 1 << ": ";
//         cin >> weights[i] >> values[i];
//     }

//     int capacity;
//     cout << "Enter the maximum capacity of the knapsack: ";
//     cin >> capacity;

//     int maxValue = knapsack(capacity, weights, values, n);

//     cout << "The maximum value that can be obtained: " << maxValue << endl;

//     return 0;
// }
