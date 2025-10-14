/**
 *
 * Source:    TUF
 * Problem:   Print all Divisors of a given Number
 * Link:
 * https://takeuforward.org/data-structure/print-all-divisors-of-a-given-number/
 *
 *
 * Approach 1: OPTIMAL
 * factors mirror after sqrt(N)
 *
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> findFactors(int N) {
  int sqrtN = sqrt(N);
  vector<int> factors;

  for (int i = 1; i <= sqrtN; i++) {
    if (N % i == 0) {
      factors.push_back(i);
      if (i != N / i) factors.push_back(N / i);
    }
  }

  return factors;
}

int main() {
  int N;
  cin >> N;
  vector<int> factors = findFactors(N);
  sort(factors.begin(), factors.end());
  for (auto factor : factors) cout << factor << ", ";
  return 0;
}