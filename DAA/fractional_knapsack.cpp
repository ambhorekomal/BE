#include <bits/stdc++.h>
using namespace std;

struct Item {
    double profit, weight;
};

bool cmp(Item a, Item b) {
    return (a.profit / a.weight) > (b.profit / b.weight);
}

int main() {
    int n;
    double capacity;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> capacity;

    vector<Item> items(n);
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> items[i].profit >> items[i].weight;

    sort(items.begin(), items.end(), cmp);

    double totalProfit = 0.0;
    for (auto &it : items) {
        if (capacity >= it.weight) {
            totalProfit += it.profit;
            capacity -= it.weight;
        } else {
            totalProfit += it.profit * (capacity / it.weight);
            break;
        }
    }

    cout << "Maximum profit in Knapsack = " << totalProfit << endl;
    return 0;
}
