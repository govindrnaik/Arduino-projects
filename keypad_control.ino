
#include <Keypad.h>
int a[9] =  {0,0,0,0,0,0,0,0,0};
char x = 'x';
char d = '-';
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
char board[3][3] = {
  {d,d,d},
  {d,d,d},
  {d,d,d},
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {

  if (x == '0') {
    x = 'x';
  }else {
    x = '0';
  }
  if (key == '1') {
    board[0][0] = x;
    printBoard();
  }else if (key == '2') {
    board[0][1] = x;
    printBoard();
  }else if (key == '3') {
    board[0][2] = x;
    printBoard();
  }else if (key == '4') {
    board[1][0] = x;
    printBoard();
  }else if (key == '5') {
    board[1][1] = x;
    printBoard();
  }else if (key == '6') {
    board[1][2] = x;
    printBoard();
  }else if (key == '7') {
    board[2][0] = x;
    printBoard();
  }else if (key == '8') {
    board[2][1] = x;
    printBoard();
  }else if (key == '9') {
    board[2][2] = x;
    printBoard();
  }else if (key == '*') {
    board[0][0] = d;
    board[0][1] = d;
    board[0][2] = d;
    board[1][0] = d;
    board[1][1] = d;
    board[1][2] = d;
    board[2][0] = d;
    board[2][1] = d;
    board[2][2] = d;
    printBoard();
  }

  }
}


void printBoard() {
  Serial.println(" ");
  Serial.print(board[0][0]);
  Serial.print(" ");
  Serial.print(board[0][1]);
  Serial.print(" ");
  Serial.print(board[0][2]);
  Serial.println(" ");
  Serial.print(board[1][0]);
  Serial.print(" ");
  Serial.print(board[1][1]);
  Serial.print(" ");
  Serial.print(board[1][2]);
  Serial.println(" ");
  Serial.print(board[2][0]);
  Serial.print(" ");
  Serial.print(board[2][1]);
  Serial.print(" ");
  Serial.print(board[2][2]);
  Serial.println(" ");


}
