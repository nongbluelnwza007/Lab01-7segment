// Define the pins connected to each segment of the 7-segment display
// Based on your Wokwi connections:
// A (r6) -> ESP32 Pin 19
// B (r5) -> ESP32 Pin 18
// C (r4) -> ESP32 Pin 5
// D (r1) -> ESP32 Pin 17
// E (r2) -> ESP32 Pin 16
// F (r3) -> ESP32 Pin 4
// G (r7) -> ESP32 Pin 0

const int segA = 19;
const int segB = 18;
const int segC = 5;
const int segD = 17;
const int segE = 16;
const int segF = 4;
const int segG = 0;

// Array to store the segment patterns for each digit (0-9)
// For a common cathode display: HIGH turns a segment ON, LOW turns it OFF
// {A, B, C, D, E, F, G}
byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Set all segment pins as OUTPUTs
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}

void loop() {
  // Loop through digits 0 to 9
  for (int i = 0; i <= 9; i++) {
    displayDigit(i); // Display the current digit
    delay(1000);     // Wait for 1 second (1000 milliseconds)
  }
}

// Function to display a specific digit on the 7-segment display
void displayDigit(int digit) {
  digitalWrite(segA, digits[digit][0]);
  digitalWrite(segB, digits[digit][1]);
  digitalWrite(segC, digits[digit][2]);
  digitalWrite(segD, digits[digit][3]);
  digitalWrite(segE, digits[digit][4]);
  digitalWrite(segF, digits[digit][5]);
  digitalWrite(segG, digits[digit][6]);
}
