// Wilmer Gaona Romero
// https://omegaup.com/arena/problem/OMI2015LENGUAJE2/
// 18.05.2021

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
a
typedef long long int ll;
ll  N = 0, K = 0, maxCounter = 1, counter = 1, 
    mostFrequentIndex  = 0, firstPosition = 0;
vector<ll> quantityVector;

// Display elements in container
template <typename T>
void DisplayContainer (const T &container)
{
  for (auto element = container.cbegin(); 
        element != container.cend(); 
        element++)
      cout << *element << ' ';
  cout << endl;
}

int main() {
  // Read the number of bottles
  cin >> N;

  // Read the extra millilitres of salsa
  cin >> K;

  // Store each bottle quantity 
  for (int i = 0; i < N; i++) {
    int quantity;
    cin >> quantity;
    quantityVector.push_back(quantity);
  }

  // Sort the Vector in descending order
  sort(quantityVector.begin(),quantityVector.end(),::greater());

  // Search for the most frequent element in the vector
  for (int i = 0; i < N - 1; i++) {
    if (quantityVector[i] == quantityVector[i+1]) {
      counter++;
    }
    else {
      if (maxCounter < counter) {
        maxCounter = counter;
        mostFrequentIndex = i;
      }
      counter = 1;
    }
  }
  // Check if the last but one is equal to the last element
  if (maxCounter < counter) {
    maxCounter = counter;
    mostFrequentIndex = N - 1;
  }

  // DisplayContainer(quantityVector);

  // cout  << "Most frequent element: " << quantityVector[mostFrequentIndex] 
  //      << " frequency: " << maxCounter << endl;

  // Fill in the next bottles of salsa
  if (mostFrequentIndex != N - 1) {
    int index = mostFrequentIndex;
    while (K > 0) {
      if (index == mostFrequentIndex) {
        ll fillQuantity = quantityVector[index] - quantityVector[index + 1];
        K -= fillQuantity;
        maxCounter++;
        index++;
      }
    }
  }
  else {
    ll fillQuantity = quantityVector[mostFrequentIndex-maxCounter] - quantityVector[mostFrequentIndex];
    while (K > 0) {
      K -= fillQuantity;
      maxCounter++;
    }
  }

  // cout  << "Max Counter: " << maxCounter 
  //       << " Most frequent element: " << quantityVector[mostFrequentIndex] << endl;

  cout << maxCounter << ' ' << quantityVector[mostFrequentIndex] << endl;
  return 0;
}
