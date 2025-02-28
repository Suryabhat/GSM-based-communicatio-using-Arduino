#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX for GSM module

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(2000);
  sendATCommand("AT");
  delay(1000);
  sendATCommand("AT+CMGF=1");
  delay(1000);
  sendATCommand("AT+CLIP=1");
  delay(1000);
  sendATCommand("ATA");
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'C':
        makeCall("+918123629524");
        break;
      case 'S':
        sendSMS("+918123629524", "Hello, this is an SMS from Arduino!");
        break;
      case 'R':
        Serial.println("Waiting for an incoming call...");
        break;
      case 'G':
        getSignalStrength();
        break;
      case 'B':
        getBatteryLevel();
        break;
      //default:
        //Serial.println("Invalid command. Available commands: C (Call), S (Send SMS), R (Receive call), G (Get signal strength), B (Get battery level)");
    }
  }

  if (mySerial.available()) {
    String response = mySerial.readString();
    if (response.indexOf("RING") != -1) {
      Serial.println("Incoming Call!");
      answerCall();
    }
  }
}

void sendATCommand(String command) {
  mySerial.println(command);
  delay(1000);
  while (mySerial.available()) {
    char c = mySerial.read();
    Serial.print(c);
  }
  Serial.println();
}

void makeCall(String phoneNumber) {
  sendATCommand("ATD" + phoneNumber + ";");
  delay(10000);
  sendATCommand("ATH");
}

void sendSMS(String phoneNumber, String message) {
  sendATCommand("AT+CMGS=\"" + phoneNumber + "\"");
  delay(1000);
  mySerial.print(message);
  mySerial.write(26);
}

void answerCall() {
  sendATCommand("ATA");
}

void getSignalStrength() {
  sendATCommand("AT+CSQ");
}

void getBatteryLevel() {
  sendATCommand("AT+CBC");
}
