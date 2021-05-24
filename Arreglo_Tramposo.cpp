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

  // Get the numbers
  for (int i = 0; i < N + 2; i++) {
    int number;
    cin >> number;
    numbersVector.push_back(number);
  }

  // Sort the Vector in descending order
  sort(numbersVector.begin(),numbersVector.end());

  // Display the vector
  // DisplayContainer(numbersVector);

  // Sweep the vector
  suma = 0;
  ll left, right;
  bool success = false;
  
  for (ll i = 0; i < N; i++) {
    suma = numbersVector[i];
    for (ll j = i + 1; j < N + 1; j++) {
      ll span = j - i + 1;
      suma += numbersVector[j];
      if (suma == numbersVector[j+1] && span == N) {
        success = true;
        left = i;
        right = j;
        break;
      }
    }
    if (success == true) {
      for (ll i = left; i <= right; i++) {
            cout << numbersVector[i] << " ";
      }
      cout << endl;
      break;
    }
  }
  if (success == false) {
    cout << "-1" << endl;
  }
  return 0;
}
