# 1 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino"
# 2 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino" 2

// Definición de pines para el módulo Bluetooth (HC-06)



// Definimos el pin del buzzer


// Definición de pines para los motores del robot






// Definición de configuración BT



RobotBT* robot;

void setup() {
  robot = new RobotBT(2 /* Pin RX (recepción) para la comunicación serial*/, 3 /* Pin TX (transmisión) para la comunicación serial*/, 4, 255, 5 /* Pin de control 1 del motor derecho*/, 6 /* Pin de control 2 del motor derecho*/, 9 /* Pin de control 1 del motor izquierdo*/, 11 /* Pin de control 2 del motor izquierdo*/, 9600 /* Para el HC-05*/);

  //robot->sendATCommand("AT+NAME=" + String(NOMBRE_BT));  // Establecer el nombre
  //robot->sendATCommand("AT+PSWD=" + String(PASSWORD_BT));  // Establecer el PIN
  robot->clearBT(); // Limpiar
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
