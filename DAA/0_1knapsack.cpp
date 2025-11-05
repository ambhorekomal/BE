#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int value, weight;
};

int knapsackDP(int W, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++)
            if (items[i - 1].weight <= w)
                dp[i][w] = max(dp[i - 1][w],
                               items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            else
                dp[i][w] = dp[i - 1][w];

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "\nMaximum value = " << knapsackDP(W, items) << endl;
    return 0;
}
