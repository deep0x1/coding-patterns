/**
 *
 * Source:    TUF
 * Problem:   Fractional Knapsack Problem : Greedy Approach
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * calcluate the value to weight ratio and sort our objects based on ratio, loop
 * through all sorted objects and add there value to max value while decreasing
 * capacity, if any objects weight is more than capacity we add ratio * capactiy
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct Obj {
  int pos;
  int value;
  int weight;
  double ratio;
};

bool comprator(Obj& o1, Obj& o2) { return o1.ratio > o2.ratio; }

double findMaxValue(vector<int>& val, vector<int>& wt, int capacity) {
  int n = val.size();
  vector<Obj> allObj(n);

  for (int i = 0; i < n; i++) {
    allObj[i].pos = i;
    allObj[i].value = val[i];
    allObj[i].weight = wt[i];
    allObj[i].ratio = (double)val[i] / (double)wt[i];
  }

  sort(allObj.begin(), allObj.end(), comprator);

  double maxValue = 0;
  for (int i = 0; i < n; i++) {
    if (allObj[i].weight <= capacity) {
      maxValue += allObj[i].value;
      capacity -= allObj[i].weight;
    } else {
      if (capacity > 0) {
        maxValue += allObj[i].ratio * capacity;
        capacity = 0;
      }
      break;
    }
  }

  return maxValue;
}

int main() {
  vector<int> val = {60, 100, 120};
  vector<int> wt = {10, 20, 30};
  int capacity = 50;
  double value = findMaxValue(val, wt, capacity);
  cout << value;
  return 0;
}