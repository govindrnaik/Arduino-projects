// Define Pins

const int startEmulation = 2;      // switch to turn on and off mouse emulation
const int mouseLeftButton = 4;    // input pin for the mouse left Button
const int joystickX = A1;         // joystick X axis  
const int joystickY = A0;         // joystick Y axis

// parameters for reading the joystick:
int cursorSpeed = 10;               // output speed of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = cursorSpeed/4;      // resting threshold
int center = cursorSpeed/2;         // resting position value

boolean mouseIsActive = false;    // whether or not to control the mouse
int lastSwitchState = LOW;        // previous switch state

void setup() {
  pinMode(startEmulation, INPUT_PULLUP);   // the switch pin
  pinMode(mouseLeftButton, INPUT_PULLUP);  // the left mouse button pin
  
  Mouse.begin();  // take control of the mouse
}

void loop() {
  // read the switch:
  int switchState = digitalRead(startEmulation);
  
  // if it's changed and it's high, toggle the mouse state:
  if (switchState != lastSwitchState) {
    if (switchState == LOW) {
      mouseIsActive = !mouseIsActive;
    }
  }
  
  // save switch state for next loop:
  lastSwitchState = switchState;

  // read and scale the two axes:
  int xReading = readAxis(A1);
  int yReading = readAxis(A0);

  // if the mouse control state is active, move the mouse:
  if (mouseIsActive) {
    Mouse.move(xReading, yReading, 0); // (x, y, scroll mouse wheel)
  }  

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  if (digitalRead(mouseLeftButton) == HIGH) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
      delay(100); // delay to enable single and double-click
    }
  }
  
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  delay(responseDelay);
}

/*
  reads an axis (0 or 1 for x or y) and scales the
 analog input range to a range from 0 to 
 */

int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, cursorSpeed);

  // if the output reading is outside from the
  // rest position threshold,  use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}
