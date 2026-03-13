/**
 *
 * Source:    TUF
 * Problem:   N meetings in one room
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/n-meetings-in-one-room
 *
 *
 * Time: O(N)
 * Space: O(N)
 *
 *
 * Approach:
 * sorting both vectors based on end vector and then using greedy approach (can
 * current meeting start, it it can we add it to meetings)
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> findMaxMeetings(vector<int>& start, vector<int>& end) {
  vector<int> indeces(start.size());
  iota(indeces.begin(), indeces.end(), 0);
  sort(indeces.begin(), indeces.end(), [end](int i, int j) {
    if (end[i] == end[j]) return i < j;
    return end[i] < end[j];
  });

  vector<int> meetings;
  int lastMeetingEnd = 0;
  for (auto n : indeces) {
    if (start[n] >= lastMeetingEnd) {
      meetings.push_back(n + 1);
      lastMeetingEnd = end[n];
    }
  }

  return meetings;
}

int main() {
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> end = {2, 4, 5, 7, 9, 9};
  vector<int> sol = findMaxMeetings(start, end);
  for (auto n : sol) cout << n << ", ";
  return 0;
}