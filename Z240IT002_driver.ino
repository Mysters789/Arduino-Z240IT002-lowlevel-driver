//Enable (HIGH when feeding data, LOW it ignore changes)

//Pin 1 = D0
//Pin 2 = D1
//Pin 3 = D2
//Pin 4 = D3
//Pin 5 = GND
//Pin 6 = +3.3V
//Pin 7 = Chip select pin?
//Pin 8 = Data or instruction mode (1 = Data, 0 = command)
//Pin 9 = Write signal (3.3V if not used)
//Pin 10 = Read signal and MCU (3.3V if not used)
//Pin 11
//Pin 12
//Pin 13
//Pin 14
//Pin 15
//Pin 16 = +3.3v for backlight
//Pin 17 = -3.3v for backlight
//Pin 18 = -3.3v for backlight
//Pin 19 = -3.3v for backlight
//Pin 20 = -3.3v for backlight
//Pin 21 = Tearing effect output pin to sync MPU (low when not activated)
//Pin 22 = D4
//Pin 23 = D8
//Pin 24 = D9
//Pin 25 = D10
//Pin 26 = D11
//Pin 27 = D12
//Pin 28 = D13
//Pin 29 = D14
//Pin 30 = D15
//Pin 31 = RESET (GND to reset)
//Pin 32 = +3.3V
//Pin 33 = +3.3V
//Pin 34 = GND
//Pin 35 = D5
//Pin 36 = D6
//Pin 37 = D7

int AllUsedPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};

void setup() {
  for (int i = 0; i < 18; i++) {
    pinMode(AllUsedPins[i], OUTPUT);
  }
  EntryModeSet();
  displayControl();
  functionSet();
  clearDisplay();
  dataMode(); //set the screen to ASCII data mode!
}

void loop() {
  for (int i = 0; i < 65536; i++) {
    showBinNumber(i);
    delay(1);
    Enable(); //Feed data to screen
  }
}

void Enable() {
  digitalWrite(A5, HIGH);
  delay(1);
  digitalWrite(A5, LOW);
}

void showBinNumber(int num) {
  for (int i = 1; i < 17; i++) {
    if (num % 2)
      digitalWrite(AllUsedPins[i], HIGH);
    else
      digitalWrite(AllUsedPins[i], LOW);
    num /= 2;
  }
}

void clearDisplay() {
  digitalWrite(2, LOW); //INSTRUCTION MODE!
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Enable();
}

void cursorHome() {
  digitalWrite(2, LOW); //INSTRUCTION MODE!
  //digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Enable();
}

void entryModeSet() {
  digitalWrite(2, LOW); //INSTRUCTION MODE!
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Enable();
}

void displayControl() {
  digitalWrite(2, LOW); //INSTRUCTION MODE!
  digitalWrite(4, HIGH); //HIGH = cursor blink on, low = cursor blink off
  digitalWrite(5, HIGH); //HIGH = cursor on, low = cursor off
  digitalWrite(6, HIGH); //HIGH = display on, low = display off
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Enable();
}

void EntryModeSet() {
  digitalWrite(2, LOW); //INSTRUCTION MODE!
  digitalWrite(4, HIGH); //HIGH = Incriment cursor, low = decrement cursor
  digitalWrite(5, HIGH); //HIGH = shift display, low = don't shift display
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Enable();
}

void functionSet() {
  digitalWrite(2, LOW); //INSTRUCTION MODE!
  //digitalWrite(4, LOW);
  //digitalWrite(5, LOW);
  digitalWrite(6, LOW); //high = 5x10 font, low = 5x8 font
  digitalWrite(7, HIGH); //high = 2 line mode, low = 1 line mode
  digitalWrite(8, HIGH); //high = 8-bit data, low = 4-bit data
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Enable();
}

void instructionMode() {
  digitalWrite(2, LOW);
}

void dataMode() {
  digitalWrite(2, HIGH);
}


