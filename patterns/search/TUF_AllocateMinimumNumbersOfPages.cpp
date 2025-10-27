/**
 *
 * Source:    TUF
 * Problem:   Allocate Minimum Number of Pages
 * Link:
 * https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
 *
 *
 * Approach 1:
 * using binary search approach on possible answer range [max(), sum()]
 *
 */

#include <bits/stdc++.h>

using namespace std;

int countStudents(vector<int>& books, int pages) {
  int students = 1;
  long long totalPages = 0;
  for (int i = 0; i < books.size(); i++) {
    if (totalPages + books[i] <= pages) {
      totalPages += books[i];
    } else {
      students++;
      totalPages = books[i];
    }
  }

  return students;
}

int minimumPages(vector<int>& books, int m) {
  int left = *max_element(books.begin(), books.end());
  int right = accumulate(books.begin(), books.end(), 0);
  int ans = left;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int students = countStudents(books, mid);
    if (students > m) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return left;
}

int main() {
  int students = 4;
  vector<int> arr = {25, 46, 28, 49, 24};
  int ans = minimumPages(arr, students);
  cout << ans;
  return 0;
}