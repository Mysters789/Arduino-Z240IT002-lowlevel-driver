//5V - Vdd & A 
//GND - Vss & K & RW
//potentiometer - V0
//D2 - RS (Instruction mode or ASCII mode) 
//D3 - Enable (HIGH when feeding data, LOW it ignore changes)
//D4 TO D11 - D0 TO D7 (8-BIT Instructions/ASCII)
//Buzzer = A0
// 

int AllUsedPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, A0};

void setup() {
  for (int i = 0; i < 11; i++) {
   pinMode(AllUsedPins[i], OUTPUT);
  }
  EntryModeSet();
  displayControl();
  functionSet();
  clearDisplay();
  digitalWrite(2, HIGH); //set the screen to ASCII data mode!
}

void loop() {
  for (int i=0; i<256; i++) {
    showBinNumber(i);
    delay(10);
    Enable();
  }
}

void Enable() {
 digitalWrite(3, HIGH);
 delay(1);
 digitalWrite(3, LOW);
}

void showBinNumber(int num) {
  for (int i = 2; i < 10; i++) {
    if (num%2)
      digitalWrite(AllUsedPins[i], HIGH);
    else
      digitalWrite(AllUsedPins[i], LOW);
    num/=2;
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
