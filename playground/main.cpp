#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  // First Half
  for (int i = 0; i < n; i++) {
    // Left Wing
    for (int j = 0; j <= i; j++) cout << "*";
    
    // Spaces
    int spaces = 2 * (n - i - 1);
    for (int j = 0; j < spaces; j++) cout << " ";
    
    // Right Wing
    for (int j = 0; j <= i; j++) cout << "*";
    
    cout << "\n";
  }

  // Second Half
  for (int i = 0; i < n; i++) {
    // Left Wing
    for (int j = 0; j < n - i; j++) cout << "*";
    
    // Spaces
    int spaces = 2 * i;
    for (int j = 0; j < spaces; j++) cout << " ";

    // Right Wing
    for (int j = 0; j < n - i; j++) cout << "*";

    cout << "\n";
  }
  return 0;
}