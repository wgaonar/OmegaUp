// 1407_Misterioso_Asesino_Celda5
// https://omegaup.com/arena/problem/asesino/#problems
// Wilmer Gaona Romero
// 20.05.2021

#include <iostream>

using namespace std;

int cells[102][102], roomWidth = 0, roomHeight = 0;
int numberCellsOccupied = 0, numberValidCells = 0;

void PrintMatrix(){
  for (int y = 1; y <= roomHeight; y++) {
    for (int x = 1; x <= roomWidth; x++) {
        cout << cells[y][x] << " "; 
    }
    cout << endl;
  }
  cout << endl;
}

int CheckNeighborhood (int i, int j) {
  // cout << "(" << i << "," << j << ")" << endl;
  
  if (cells[i][j] != 1) {
    if (cells[i][j + 1] != 1) {
      if (cells[i + 1][j] != 1) {
        if (cells[i + 1][j + 1] != 1)
          return 1;
      }
    }
  }
  return 0;
}

int main() {
  // Read the height and width of the room
  cin >> roomHeight >> roomWidth;

  // Read the number of occupied cells
  cin >> numberCellsOccupied;

  // Calculates the initial and maximum possibilities
  numberValidCells = 0;

  // Fill the matrix of cells with 0s
  for (int i = 1; i <= roomHeight; i++) {
    for (int j = 1; j <= roomWidth; j++) {
        cells[i][j] = 0;
    }
  }
  
  // Enter the matrix of cells with the positions of occupied cells
  while(numberCellsOccupied--) {
    int x;
    int y;
    cin >> y >> x;

    cells[y][x] = 1;
  }
  
  // PrintMatrix();

  if (roomHeight < 2 || roomWidth < 2)
    cout << 0 << endl;
  else {
    for (int i = 1; i < roomHeight; i++) {
      for (int j = 1; j < roomWidth; j++) {
        int value = CheckNeighborhood(i, j);
        numberValidCells +=  value;
        // cout << numberValidCells << endl;
      }
    }
    cout << numberValidCells << endl;
  }

  return 0;
}
