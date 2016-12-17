// Overheat Panel by TomorrowX3
// Description: 9 switch, 9 LED interface designed for use with Eve Online (can also be used as generic input)
// Toggling switches causes LEDs to flash and keyboards input sent.
// Code for Arduino Leonardo for use with Arduino IDE. Download here: https://www.arduino.cc/en/Main/Software

// This is quickly / poorly hacked together code by an Arduino beginner hobbyist, it works but is not efficient.
// Lots of room for improvement.

#include <Keyboard.h>

// Keyboard buttons. Change these (1 to 9) to match your in game EVE Overload Keyboard shortcuts (or which ever toggles you'd like). 
//See https://www.arduino.cc/en/Reference/KeyboardModifiers to use Keyboard Modifiers and change code from Keyboard.print() to Keyboard.press() 

int H1 = 1;
int H2 = 2;
int H3 = 3;

int M1 = 4;
int M2 = 5;
int M3 = 6;

int L1 = 7;
int L2 = 8;
int L3 = 9;

////----------------------------------


const long interval = 300; 

// Edit this value to change length of flash LED time (in ms)

////----------------------------------

// Declarations

int H1LED = 2;
int H1SWITCH = 5;
int H1active = 0;
int H1on = 0;
unsigned long H1previousMillis = 0;
int H1ledState = LOW; 

int H2LED = 1;
int H2SWITCH = 4;
int H2active = 0;
int H2on = 0;
unsigned long H2previousMillis = 0;
int H2ledState = LOW; 

int H3LED = 0;
int H3SWITCH = 3;
int H3active = 0;
int H3on = 0;
unsigned long H3previousMillis = 0;
int H3ledState = LOW; 

int M1LED = 8;
int M1SWITCH = 11;
int M1active = 0;
int M1on = 0;
unsigned long M1previousMillis = 0;
int M1ledState = LOW; 

int M2LED = 7;
int M2SWITCH = 10;
int M2active = 0;
int M2on = 0;
unsigned long M2previousMillis = 0;
int M2ledState = LOW; 

int M3LED = 6;
int M3SWITCH = 9;
int M3active = 0;
int M3on = 0;
unsigned long M3previousMillis = 0;
int M3ledState = LOW; 

int L1LED = 13;
int L1SWITCH = A1;
int L1active = 0;
int L1on = 0;
unsigned long L1previousMillis = 0;
int L1ledState = LOW; 

int L2LED = 12;
int L2SWITCH = A2;
int L2active = 0;
int L2on = 0;
unsigned long L2previousMillis = 0;
int L2ledState = LOW; 

int L3LED = A0;
int L3SWITCH = A3;
int L3active = 0;
int L3on = 0;
unsigned long L3previousMillis = 0;
int L3ledState = LOW; 

void setup() {
//setup (code to trigger once) goes here


//Set pin types (LED is output, Switch is PULLUP or INPUT_PULLUP to use internal resistor.)
  pinMode(H1LED,OUTPUT);
  pinMode(H1SWITCH, INPUT_PULLUP);

  pinMode(H2LED,OUTPUT);
  pinMode(H2SWITCH, INPUT_PULLUP);

  pinMode(H3LED,OUTPUT);
  pinMode(H3SWITCH, INPUT_PULLUP);

  pinMode(M1LED,OUTPUT);
  pinMode(M1SWITCH, INPUT_PULLUP);

  pinMode(M2LED,OUTPUT);
  pinMode(M2SWITCH, INPUT_PULLUP);

  pinMode(M3LED,OUTPUT);
  pinMode(M3SWITCH, INPUT_PULLUP);

  pinMode(L1LED,OUTPUT);
  pinMode(L1SWITCH, INPUT_PULLUP);

  pinMode(L2LED,OUTPUT);
  pinMode(L2SWITCH, INPUT_PULLUP);

  pinMode(L3LED,OUTPUT);
  pinMode(L3SWITCH, INPUT_PULLUP);

  // Analog Input


  // Enable Serial.  To read these debug notes press Tools > Serial Monitor and select 19200 on the bottom right!
  Serial.begin(19200);
  Serial.println("Starting.");
   Keyboard.begin();

}

void loop() {
//main loop goes here

  
  // Check each switch to see if any are on
  H1active = digitalRead(H1SWITCH);
  H2active = digitalRead(H2SWITCH);
  H3active = digitalRead(H3SWITCH);
  M1active = digitalRead(M1SWITCH);
  M2active = digitalRead(M2SWITCH);
  M3active = digitalRead(M3SWITCH);
  L1active = digitalRead(L1SWITCH);
  L2active = digitalRead(L2SWITCH);
  L3active = digitalRead(L3SWITCH);


////H1 switch///
  if (H1active == HIGH && H1on == 0) {
Serial.println("H1: OFF");
Keyboard.print(H1);
H1on = 1;
delay(200); 

}
else
  if (H1active == LOW && H1on == 1) {
  {
  
  Serial.println("H1:  ON");
  Keyboard.print(H1);
  H1on = 0;
  delay(200); 
  }
}

if (H1on == 0){
  //digitalWrite(H1LED, HIGH);

unsigned long H1currentMillis = millis();
  if (H1currentMillis - H1previousMillis >= interval) {
    // save the last time you blinked the LED
    H1previousMillis = H1currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (H1ledState == LOW) {
      H1ledState = HIGH;
    } else {
      H1ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(H1LED, H1ledState);
  }
  
}
if (H1on == 1){
  digitalWrite(H1LED, LOW);
}
//-------///

////H2 switch///
  if (H2active == HIGH && H2on == 0) {
Serial.println("H2: OFF");
Keyboard.print(H2);
H2on = 1;
delay(200); 

}
else
  if (H2active == LOW && H2on == 1) {
  {
  
  Serial.println("H2:  ON");
  Keyboard.print(H2);
  H2on = 0;
  delay(200); 
  }
}

if (H2on == 0){
  //digitalWrite(H2LED, HIGH);
  
unsigned long H2currentMillis = millis();
  if (H2currentMillis - H2previousMillis >= interval) {
    // save the last time you blinked the LED
    H2previousMillis = H2currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (H2ledState == LOW) {
      H2ledState = HIGH;
    } else {
      H2ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(H2LED, H2ledState);
  }
  
}
if (H2on == 1){
  digitalWrite(H2LED, LOW);
}
//-------///

////H3 switch///
  if (H3active == HIGH && H3on == 0) {
Serial.println("H3: OFF");
Keyboard.print(H3);
H3on = 1;
delay(200); 

}
else
  if (H3active == LOW && H3on == 1) {
  {
  
  Serial.println("H3:  ON");
  Keyboard.print(H3);
  H3on = 0;
  delay(200); 
  }
}

if (H3on == 0){
  //digitalWrite(H3LED, HIGH);

unsigned long H3currentMillis = millis();
  if (H3currentMillis - H3previousMillis >= interval) {
    // save the last time you blinked the LED
    H3previousMillis = H3currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (H3ledState == LOW) {
      H3ledState = HIGH;
    } else {
      H3ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(H3LED, H3ledState);
  }

  
}
if (H3on == 1){
  digitalWrite(H3LED, LOW);
}
//-------///

////M1 switch///
  if (M1active == HIGH && M1on == 0) {
Serial.println("M1: OFF");
Keyboard.print(M1);
M1on = 1;
delay(200); 

}
else
  if (M1active == LOW && M1on == 1) {
  {
  
  Serial.println("M1:  ON");
  Keyboard.print(M1);
  M1on = 0;
  delay(200); 
  }
}

if (M1on == 0){
  //digitalWrite(M1LED, HIGH);

unsigned long M1currentMillis = millis();
  if (M1currentMillis - M1previousMillis >= interval) {
    // save the last time you blinked the LED
    M1previousMillis = M1currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (M1ledState == LOW) {
      M1ledState = HIGH;
    } else {
      M1ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(M1LED, M1ledState);
  }

  
}
if (M1on == 1){
  digitalWrite(M1LED, LOW);
}
//-------///

////M2 switch///
  if (M2active == HIGH && M2on == 0) {
Serial.println("M2: OFF");
Keyboard.print(M2);
M2on = 1;
delay(200); 

}
else
  if (M2active == LOW && M2on == 1) {
  {
  
  Serial.println("M2:  ON");
  Keyboard.print(M2);
  M2on = 0;
  delay(200); 
  }
}

if (M2on == 0){
  //digitalWrite(M2LED, HIGH);

  unsigned long M2currentMillis = millis();
  if (M2currentMillis - M2previousMillis >= interval) {
    // save the last time you blinked the LED
    M2previousMillis = M2currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (M2ledState == LOW) {
      M2ledState = HIGH;
    } else {
      M2ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(M2LED, M2ledState);
  }
}
if (M2on == 1){
  digitalWrite(M2LED, LOW);
}
//-------///

////M3 switch///
  if (M3active == HIGH && M3on == 0) {
Serial.println("M3: OFF");
Keyboard.print(M3);
M3on = 1;
delay(200); 

}
else
  if (M3active == LOW && M3on == 1) {
  {
  
  Serial.println("M3:  ON");
  Keyboard.print(M3);
  M3on = 0;
  delay(200); 
  }
}

if (M3on == 0){
  //digitalWrite(M3LED, HIGH);

    unsigned long M3currentMillis = millis();
  if (M3currentMillis - M3previousMillis >= interval) {
    // save the last time you blinked the LED
    M3previousMillis = M3currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (M3ledState == LOW) {
      M3ledState = HIGH;
    } else {
      M3ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(M3LED, M3ledState);
  }
}
if (M3on == 1){
  digitalWrite(M3LED, LOW);
}
//-------///

////L1 switch///
  if (L1active == HIGH && L1on == 0) {
Serial.println("L1: OFF");
Keyboard.print(L1);
L1on = 1;
delay(200); 

}
else
  if (L1active == LOW && L1on == 1) {
  {
  
  Serial.println("L1:  ON");
  Keyboard.print(L1);
  L1on = 0;
  delay(200); 
  }
}

if (L1on == 0){
  //digitalWrite(L1LED, HIGH);

      unsigned long L1currentMillis = millis();
  if (L1currentMillis - L1previousMillis >= interval) {
    // save the last time you blinked the LED
    L1previousMillis = L1currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (L1ledState == LOW) {
      L1ledState = HIGH;
    } else {
      L1ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(L1LED, L1ledState);
  }
}
if (L1on == 1){
  digitalWrite(L1LED, LOW);
}
//-------///

////L2 switch///
  if (L2active == HIGH && L2on == 0) {
Serial.println("L2: OFF");
 Keyboard.print(L2);
L2on = 1;
delay(200); 

}
else
  if (L2active == LOW && L2on == 1) {
  {
  
  Serial.println("L2:  ON");
  Keyboard.print(L2);
  L2on = 0;
  delay(200); 
  }
}

if (L2on == 0){
  //digitalWrite(L2LED, HIGH);

        unsigned long L2currentMillis = millis();
  if (L2currentMillis - L2previousMillis >= interval) {
    // save the last time you blinked the LED
    L2previousMillis = L2currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (L2ledState == LOW) {
      L2ledState = HIGH;
    } else {
      L2ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(L2LED, L2ledState);
  }
}
if (L2on == 1){
  digitalWrite(L2LED, LOW);
}
//-------///

////L3 switch///
  if (L3active == HIGH && L3on == 0) {
Serial.println("L3: OFF");
Keyboard.print(L3);
L3on = 1;
delay(200); 

}
else
  if (L3active == LOW && L3on == 1) {
  {
  
  Serial.println("L3:  ON");
  Keyboard.print(L3);
  L3on = 0;
  delay(200); 
  }
}

if (L3on == 0){
  //digitalWrite(L3LED, HIGH);

          unsigned long L3currentMillis = millis();
  if (L3currentMillis - L3previousMillis >= interval) {
    // save the last time you blinked the LED
    L3previousMillis = L3currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (L3ledState == LOW) {
      L3ledState = HIGH;
    } else {
      L3ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(L3LED, L3ledState);
  }
}
if (L3on == 1){
  digitalWrite(L3LED, LOW);
}
//-------///


  }



