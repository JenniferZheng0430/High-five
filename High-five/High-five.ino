#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 10; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 11; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;


const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not`
int winner_pin;


void setup() {
  Serial.begin(9600);       // use the serial port
  softwareSerial.begin(9600);
  randomSeed(analogRead(A7));
  winner_pin = random(0, 6);
  Serial.println(winner_pin);

}

void loop() {
  int sensor0 = analogRead(A0);
  int sensor1 = analogRead(A1);
  int sensor2 = analogRead(A2);
  int sensor3 = analogRead(A3);
  int sensor4 = analogRead(A4);
  int sensor5 = analogRead(A5);
  int winner = analogRead(winner_pin);


  if (winner >= threshold) {
    //    tone(8,NOTE_C4);
    //    delay(400);
    //    noTone(8);

    if (player.begin(softwareSerial)) {
          //Serial.println("OK");
    
          // Set volume to maximum (0 to 30).
          player.volume(30);
          //Play the first MP3 file on the SD card
          player.play(1);

        } else {
          Serial.println("Connecting to DFPlayer Mini failed!");
        }
    Serial.println("Game Over! Start a New Round!");


  }

    if (winner_pin != 0 && sensor0 >= threshold) {
      if (player.begin(softwareSerial)) {
          //Serial.println("OK");
    
          // Set volume to maximum (0 to 30).
          player.volume(30);
          //Play the first MP3 file on the SD card
          player.play(2);

        } else {
          Serial.println("Connecting to DFPlayer Mini failed!");
        }
    }
    if (winner_pin != 1 && sensor1 >= threshold) {
      if (player.begin(softwareSerial)) {
          //Serial.println("OK");
    
          // Set volume to maximum (0 to 30).
          player.volume(30);
          //Play the first MP3 file on the SD card
          player.play(2);

        } else {
          Serial.println("Connecting to DFPlayer Mini failed!");
        }
    }
    if (winner_pin != 2 && sensor2 >= threshold) {
      if (player.begin(softwareSerial)) {
          //Serial.println("OK");
    
          // Set volume to maximum (0 to 30).
          player.volume(30);
          //Play the first MP3 file on the SD card
          player.play(2);

        } else {
          Serial.println("Connecting to DFPlayer Mini failed!");
        }
    }
    if (winner_pin != 3 && sensor3 >= threshold) {
      if (player.begin(softwareSerial)) {
          //Serial.println("OK");
    
          // Set volume to maximum (0 to 30).
          player.volume(30);
          //Play the first MP3 file on the SD card
          player.play(2);

        } else {
          Serial.println("Connecting to DFPlayer Mini failed!");
        }
    }
    if (winner_pin != 4 && sensor4 >= threshold) {
      if (player.begin(softwareSerial)) {
          //Serial.println("OK");
    
          // Set volume to maximum (0 to 30).
          player.volume(30);
          //Play the first MP3 file on the SD card
          player.play(2);

        } else {
          Serial.println("Connecting to DFPlayer Mini failed!");
        }
    }
    if (winner_pin != 5 && sensor5 >= threshold) {
      if (player.begin(softwareSerial)) {
          //Serial.println("OK");
    
          // Set volume to maximum (0 to 30).
          player.volume(30);
          //Play the first MP3 file on the SD card
          player.play(2);

        } else {
          Serial.println("Connecting to DFPlayer Mini failed!");
        }
    }


}

 
