/**
 *
 * Source:    TUF
 * Problem:   Check if a number is Armstrong Number or not
 * Link:      https://takeuforward.org/maths/check-if-a-number-is-armstrong-number-or-not/
 *
 *
 * Approach 1: OPTIMAL
 * using to_string().length() method to find total number of digits
 * using (% 10, / 10) approach to loop thought all digits
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int N) {
  // edge case
  if (N < 0) return false;
  if (N == 0) return true;

  long long sumOfDigits = 0;
  int copy = N;
  int totalDigits = to_string(N).length();
  while (copy) {
    sumOfDigits += pow(copy % 10, totalDigits);
    copy /= 10;
  }
  
  return sumOfDigits == N;
}

int main() {
  int N;
  cin >> N;
  cout << "Solution 1:\t" << isArmstrong(N) << "\n";
  return 0;
}