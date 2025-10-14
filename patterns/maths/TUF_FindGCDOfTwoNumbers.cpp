/**
 *
 * Source:    TUF
 * Problem:   Find GCD of two numbers
 * Link:      https://takeuforward.org/data-structure/find-gcd-of-two-numbers/
 *
 *
 * Approach 1:
 * using min(N1, N2) as piviot point and decreating untill common factor found
 *
 *
 * Approach 2: OPTIMAL
 * using Euclid's Divison Algorithm, replacing Devident by devisor and devisor
 * by reminder
 *
 */

#include <bits/stdc++.h>
using namespace std;

int getGCD(int N1, int N2) {
  // edge case (zero)
  if (N1 == 0) return N2;
  if (N2 == 0) return N1;

  int minN = min(N1, N2);
  int gcf = 1;

  for (int i = minN; i >= 1; i--) {
    if (N1 % i == 0 && N2 % i == 0) {
      gcf = i;
      break;
    }
  }

  return gcf;
}

int getGCDOptimal(int N1, int N2) {
  // edge case (zero)
  if (N1 == 0) return N2;
  if (N2 == 0) return N1;

  int minN = min(N1, N2);
  int maxN = max(N1, N2);
  int temp = 0;

  // Euclid's Divison Algorithm
  while (maxN % minN) {
    temp = minN;
    minN = maxN % temp;
    maxN = temp;
  }

  return minN;
}

int main() {
  int N1, N2;
  cin >> N1 >> N2;
  cout << "Solution 1:\t" << getGCD(N1, N2) << "\n";
  cout << "Solution 1:\t" << getGCDOptimal(N1, N2) << "\n";
  return 0;
}