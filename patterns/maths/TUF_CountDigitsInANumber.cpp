/**
 * 
 * Source:    TUF
 * Problem:   Count digits in a number
 * Link:      https://takeuforward.org/data-structure/count-digits-in-a-number/
 *
 * 
 * Approach 1:
 * dividing a number by 10 decrease 1 digit, each successful division by 10 is a
 * +1 to total number of digits
 * 
 * 
 * Approach 2: OPTIMAL
 * (Log base 10 + 1) of any number gives the total number of digits
 * (int)(Log10(N) + 1) = total number of digits
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int countDigits(int N) {
  int digits = 0;
  int copyN = N;

  do {
    digits++;
    copyN /= 10;
  } while (copyN);

  return digits;
}

int countDigitsOptimal(int N) {
  if (N <= 0) return 1;
  int digits = log10(N) + 1;
  return digits;
}

int main() {
  int N;
  cin >> N;
  cout << "Brute Force Approach:\t" << countDigits(N) << "\n";
  cout << "Lograthmic approach:\t" << countDigitsOptimal(N) << "\n";
  return 0;
}