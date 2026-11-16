
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Dynamic Programming (Bottom-Up Approach)

int knapsack(vector<int> profit, vector<int> wt, int capacity) {

    int n = profit.size();

    vector<vector<int>> t(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i < n + 1; i++) {

        for (int j = 1; j < capacity + 1; j++) {

            if (wt[i - 1] <= j) {

                t[i][j] = max(
                    profit[i - 1] + t[i - 1][j - wt[i - 1]],
                    t[i - 1][j]
                );

            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][capacity];
}

int main() {

    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> profit(n);
    vector<int> wt(n);

    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    cout << "\nMaximum Profit = "
         << knapsack(profit, wt, capacity) << endl;

    return 0;
}
