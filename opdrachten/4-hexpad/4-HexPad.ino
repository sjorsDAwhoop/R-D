#include <Keypad.h>
String code = "#0000";
String input = "";
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};
int lamp_standby = 13;
int lamp_error = 12;
int lamp_correct = 11;

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){

  pinMode(lamp_standby, OUTPUT);
  pinMode(lamp_error, OUTPUT);
  pinMode(lamp_correct, OUTPUT);

  digitalWrite(lamp_standby, HIGH);
  digitalWrite(lamp_error, HIGH);
  digitalWrite(lamp_correct, HIGH);
  
  Serial.begin(9600);

  Serial.println("Set a code: ");
  while(Serial.available() == 0);
  code = Serial.readString();

  digitalWrite(lamp_standby, LOW);

  Serial.println("Code has been set to: " + code);

}

void loop(){
  char customKey = customKeypad.getKey();

  if (customKey){
    Serial.println(customKey);
    //Serial.println(customKey);
    input += customKey;
  }

  if(input.length() == code.length()) checkCode();
}

void checkCode() {
  digitalWrite(lamp_standby, HIGH);
  if(input == code) {
    Serial.println("code correct");
    digitalWrite(lamp_correct, LOW);
    delay(1000);
    digitalWrite(lamp_correct, HIGH);
  }
  else {
    Serial.println("Wrong Code");
    digitalWrite(lamp_error, LOW);
    delay(1000);
    digitalWrite(lamp_error, HIGH);
  } 
  input = "";
  digitalWrite(lamp_standby, LOW);
}
