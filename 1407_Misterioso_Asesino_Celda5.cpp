// 1407_Misterioso_Asesino_Celda5
// Wilmer Gaona Romero
// 20.05.2021

#include <iostream>

using namespace std;

int cells[101][101], roomWidth = 0, roomHeight = 0, numberCellsOccupied = 0;
int initialValue = 0, finalValue = 0, maxValues = 0, numberValidCells = 0;

int SetInitialValue (int &x, int &y) {
  int value;
  if((x == 1 && y == 1) || (x == 1 && x == roomWidth) ||
    (x == 1 && y == roomHeight) || (x == roomWidth && y == roomHeight)) {
      value = 1;
  }
  else if(x == 1 || x == roomWidth || y == 1 || y == roomHeight) {
    value = 2;
  }
  else {
    value = 4; 
  }
  return value;
}

int CheckNeighborhood (int &x, int&y) {
  // cout << "(" << x << "," << y << ")" << endl;
  for (int i = y - 1; i <= y + 1; i++) {
    if (i > 0 && i <= roomHeight) {
      for (int j = x - 1; j <= x + 1; j++) {
        if (j > 0 && j <= roomWidth) {
          if (cells[j][i] == 1 && j != x && i != y) {
            initialValue--;
            // cout << "\t" << "Minus 1 value by (" << j << ","<< i << ")" << endl; 
          }
        }
      }
    }
  }
  return initialValue;
}

void PrintMatrix(){
  cout << endl;
  for (int y = roomHeight; y > 0; y--) {
    for (int x = 1; x <= roomWidth; x++) {
        cout << cells[x][y] << " "; 
    }
    cout << endl;
  }
}

int main() {
  // Read the width and height of the room
  cin >> roomWidth >> roomHeight;

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
    cin >> x >> y;
    cells[x][y] = 1;
    initialValue = SetInitialValue(x,y);
    // cout << "initialValue: " << initialValue << endl;
    finalValue = CheckNeighborhood(x,y);
    // cout << "finalValue: " << finalValue << endl;
    // PrintMatrix();
    numberValidCells -= finalValue;
  }

  
  // Show the matrix
  // PrintMatrix();

  // Show the number of valid cells
  // cout << "number of valid cells: " << numberValidCells << endl;
  cout << numberValidCells << endl;

  return 0;
}
