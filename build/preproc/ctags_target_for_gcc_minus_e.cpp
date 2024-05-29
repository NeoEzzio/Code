# 1 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino"
# 2 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino" 2

// Constantes para el Buzzer
# 15 "C:\\Users\\david\\OneDrive\\Escritorio\\Microcontroladores\\robot\\Code\\Code.ino"
// Definición de pines para el módulo Bluetooth (HC-06)



// Definimos el pin del buzzer


// Definición de pines para los motores del robot






// Definición de configuración BT




RobotBT* robot;
int flag1 = -1;
int flag2 = -1;

void setup() {
  Serial.begin(9600); // Inicializar la comunicación serial con el PC
  robot = new RobotBT(2 /* Pin RX (recepción) para la comunicación serial*/, 3 /* Pin TX (transmisión) para la comunicación serial*/, 4, 255, 5 /* Pin de control 1 del motor derecho*/, 6 /* Pin de control 2 del motor derecho*/, 9 /* Pin de control 1 del motor izquierdo*/, 11 /* Pin de control 2 del motor izquierdo*/, 9600 /* Para el HC-05*/);

  //robot->sendATCommand("AT+NAME=" + String(NOMBRE_BT));  // Establecer el nombre
  //robot->sendATCommand("AT+PSWD=" + String(PASSWORD_BT));  // Obtener el PIN actual
  robot->clearBT(); // Limpiar
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
    robot->playTone(262, 150);
    robot->playTone(294, 150);
    robot->playTone(330, 150);
    robot->playTone(262, 150);
    delay(150);

    robot->playTone(330, 150);
    robot->playTone(349, 150);
    robot->playTone(392, 300);
    delay(150);

    robot->playTone(392, 150);
    robot->playTone(349, 150);
    robot->playTone(330, 150);
    robot->playTone(262, 300);
    delay(300);
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
