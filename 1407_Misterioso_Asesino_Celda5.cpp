// 1407_Misterioso_Asesino_Celda5
// https://omegaup.com/arena/problem/asesino/#problems
// Wilmer Gaona Romero
// 20.05.2021

#include <iostream>

using namespace std;

int cells[102][102], roomWidth = 0, roomHeight = 0, numberCellsOccupied = 0;
int initialValue = 0, finalValue = 0, maxValues = 0, numberValidCells = 0;

int SetInitialValue (int i, int j) {
  int value;
  if((j == 1 && i == 1) || (j == roomWidth && i == 1) ||
    (j == 1 && i == roomHeight) || (j == roomWidth && i == roomHeight)) {
      value = 1;
  }
  else if(j == 1 || j == roomWidth || i == 1 || i == roomHeight) {
    value = 2;
  }
  else {
    value = 4; 
  }
  return value;
}


int CheckNeighborhood (int i, int j) {
  // cout << "(" << i << "," << j << ")" << endl;

  // above row
  if (cells[i - 1][j - 1] == 1) initialValue--;
  if (cells[i - 1][j] == 1) initialValue -= 2;
  if (cells[i - 1][j + 1] == 1) initialValue--;

  // same row
  if (cells[i][j - 1] == 1) initialValue -= 2;
  if (cells[i][j + 1] == 1) initialValue -= 2;

  // below row
  if (cells[i + 1][j - 1] == 1) initialValue--;
  if (cells[i + 1][j] == 1) initialValue -= 2;
  if (cells[i + 1][j + 1] == 1) initialValue--;

  if (initialValue < 0)
    initialValue = 0;
  return initialValue;
}

void PrintMatrix(){
  for (int y = 1; y <= roomHeight; y++) {
    for (int x = 1; x <= roomWidth; x++) {
        cout << cells[y][x] << " "; 
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  // Read the height and width of the room
  cin >> roomHeight >> roomWidth;

  // Read the number of occupied cells
  cin >> numberCellsOccupied;

  // Calculates the initial and maximum possibilities
  numberValidCells = (roomWidth - 1) * (roomHeight - 1);

  // Fill the matrix of cells with 0s
  for (int i = 1; i <= roomHeight; i++) {
    for (int j = 1; j <= roomWidth; j++) {
        cells[i][j] = 0;
    }
  }
  
  // Enter the matrix of cells with the positions of occupied cells
  int x = 0;
  int y = 0;
  for (int i = 0; i < numberCellsOccupied; i++) {
    cin >> y >> x;
    cells[y][x] = 1;
    initialValue = SetInitialValue(y,x);
    // cout << "initialValue: " << initialValue << endl;
    finalValue = CheckNeighborhood(y,x);
    // cout << "finalValue: " << finalValue << endl;
    // PrintMatrix();
    numberValidCells -= finalValue;
  }

  if (roomHeight < 2 || roomWidth < 2)
    cout << 0;
  else
    cout << numberValidCells << endl;

  return 0;
}
