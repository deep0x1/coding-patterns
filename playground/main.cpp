/**
 *
 * Source:    TUF
 * Problem:   Check if a number is prime or not
 * Link:
 * https://takeuforward.org/data-structure/check-if-a-number-is-prime-or-not/
 *
 *
 * Approach 1:
 * looping through all numbers upto N (exclusive) untill a factor is found
 * if no factor found its a prime
 *
 *
 * Approach 2: OPTIMAL
 * looping throught all numbers upto sqrtN (inclusive) untill a factor is found
 * if no factor found its a prime
 *
 */

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int N) {
  // edge case
  if (N <= 1) return false;

  for (int i = 2; i < N; i++) {
    if (N % i == 0) return false;
  }
  return true;
}

bool isPrimeOptimal(int N) {
  // edge case
  if (N <= 1) return false;

  int sqrtN = sqrt(N);
  for (int i = 2; i <= sqrtN; i++) {
    if (N % i == 0) return false;
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  cout << "Solution 1:\t" << isPrime(N) << "\n";
  cout << "Solution 2:\t" << isPrimeOptimal(N) << "\n";
  return 0;
}