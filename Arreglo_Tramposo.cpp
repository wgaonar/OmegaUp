// Wilmer Gaona Romero
// 18.05.2021

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ll;
vector<ll> numbersVector;
ll N = 0, suma = 0;

// Display elements in container
template <typename T>
void DisplayContainer (const T &container) {
  for (auto element = container.cbegin(); 
        element != container.cend(); 
        element++)
    cout << *element << ' ';
  cout << endl;
}

int main() {
  // Read the numbers
  cin >> N;

  // Store each bottle quantity 
  for (int i = 0; i < N + 2; i++) {
    int number;
    cin >> number;
    numbersVector.push_back(number);
  }

  // Sort the Vector in descending order
  sort(numbersVector.begin(),numbersVector.end());

  // Sweep the vector
  bool continueSearch = true;
  ll leftBoundary = 0;
  while (continueSearch == true) {
    if (leftBoundary < N) {
      ll sum = numbersVector[leftBoundary];
      for (ll rightBoundary = leftBoundary + 1; 
              rightBoundary < N + 1; 
              rightBoundary++) {
        sum += numbersVector[rightBoundary];
        if (sum == numbersVector[rightBoundary + 1] && rightBoundary == leftBoundary + N - 1) {
          for (ll i = leftBoundary; i <= rightBoundary; i++) {
            cout << numbersVector[i] << " ";
          }
          cout << endl;
          continueSearch = false;
          break;
        }
      }
      leftBoundary++;
    }
    else {
      continueSearch = false;
      cout << "-1" << endl;
    }
  }
  return 0;
}
