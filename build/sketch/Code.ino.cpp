#include <Arduino.h>
#line 1 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino"
#include "RobotBT.h"

// Constantes para el Buzzer
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define DURATION_SHORT 150
#define DURATION_LONG 300

// Definición de pines para el módulo Bluetooth (HC-06)
#define RX_PIN 2    // Pin RX (recepción) para la comunicación serial
#define TX_PIN 3    // Pin TX (transmisión) para la comunicación serial

// Definimos el pin del buzzer
#define BUZZER_PIN 4

// Definición de pines para los motores del robot
#define MOTOR_DER_1 5   // Pin de control 1 del motor derecho
#define MOTOR_DER_2 6   // Pin de control 2 del motor derecho
#define MOTOR_IZQ_3 9   // Pin de control 1 del motor izquierdo
#define MOTOR_IZQ_4 11  // Pin de control 2 del motor izquierdo
#define VELOCIDAD 255

// Definición de configuración BT
#define BAUD_RATE 9600 // Para el HC-05
#define NOMBRE_BT "Dannalamaslinda"
#define PASSWORD_BT "2604"

RobotBT* robot;
int flag1 = -1;
int flag2 = -1;

#line 38 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino"
void setup();
#line 47 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino"
void loop();
#line 38 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino"
void setup() {
  Serial.begin(9600); // Inicializar la comunicación serial con el PC
  robot = new RobotBT(RX_PIN, TX_PIN, BUZZER_PIN, VELOCIDAD, MOTOR_DER_1, MOTOR_DER_2, MOTOR_IZQ_3, MOTOR_IZQ_4, BAUD_RATE);

  //robot->sendATCommand("AT+NAME=" + String(NOMBRE_BT));  // Establecer el nombre
  //robot->sendATCommand("AT+PSWD=" + String(PASSWORD_BT));  // Obtener el PIN actual
  robot->clearBT();  // Limpiar
}

void loop() {
  // Leer datos del Bluetooth
  char dato = robot->getDatos();
  switch (dato) {
  case 'F':
  Serial.println(dato);
    robot->moveForward();
    break;
  case 'B':
    robot->moveBackward();
    break;
  case 'L':
    robot->turnLeft();
    break;
  case 'R':
    robot->turnRight();
    break;
  case 'T':
    robot->playTone(NOTE_C4, DURATION_SHORT);
    robot->playTone(NOTE_D4, DURATION_SHORT);
    robot->playTone(NOTE_E4, DURATION_SHORT);
    robot->playTone(NOTE_C4, DURATION_SHORT);
    delay(DURATION_SHORT);

    robot->playTone(NOTE_E4, DURATION_SHORT);
    robot->playTone(NOTE_F4, DURATION_SHORT);
    robot->playTone(NOTE_G4, DURATION_LONG);
    delay(DURATION_SHORT);

    robot->playTone(NOTE_G4, DURATION_SHORT);
    robot->playTone(NOTE_F4, DURATION_SHORT);
    robot->playTone(NOTE_E4, DURATION_SHORT);
    robot->playTone(NOTE_C4, DURATION_LONG);
    delay(DURATION_LONG);
    break;
  case 'S':
    robot->turnLeftFast();
    break;
  case 'C':
    robot->turnRightFast();
    break;
  case '0':
    robot->stopMotors();
    break;
  }
}

