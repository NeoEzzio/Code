#include "RobotBT.h"

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

void setup() {
  robot = new RobotBT(RX_PIN, TX_PIN, BUZZER_PIN, VELOCIDAD, MOTOR_DER_1, MOTOR_DER_2, MOTOR_IZQ_3, MOTOR_IZQ_4, BAUD_RATE);

  //robot->sendATCommand("AT+NAME=" + String(NOMBRE_BT));  // Establecer el nombre
  //robot->sendATCommand("AT+PSWD=" + String(PASSWORD_BT));  // Establecer el PIN
  robot->clearBT();  // Limpiar
}

void loop() {
  // Leer datos del Bluetooth
  char dato = robot->getDatos();
  switch (dato) {
  case 'F':
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
    robot->playTone(100, 1000);
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
