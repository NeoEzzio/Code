#include "RobotBT.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

/// @brief Constructor de la clase inicializa el BT con un Baudrate, HC05 38400, HC06 9600. Y envía "AT".
RobotBT::RobotBT(   int rxPin, int txPin, int buzzerPin, int vel,
                    int motorDer1, int motorDer2, 
                    int motorIzq3, int motorIzq4, int baudios = 9600)
    :   pinRxBT(rxPin), pinTxBT(txPin), pinBuzzer(buzzerPin), velocidad(vel),
        pinMotorDer1(motorDer1), pinMotorDer2(motorDer2),
        pinMotorIzq3(motorIzq3), pinMotorIzq4(motorIzq4) 
{
    BT = new SoftwareSerial(rxPin, txPin);
    BT->begin(baudios);
    delay(100);
    sendATCommand("AT");

    pinMode(motorDer1, OUTPUT);
    pinMode(motorDer2, OUTPUT);
    pinMode(motorIzq3, OUTPUT);
    pinMode(motorIzq4, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    analogWrite( motorDer1, 0 );
    analogWrite( motorDer2, 0 );
    analogWrite( motorIzq3, 0 );
    analogWrite( motorIzq4, 0 );
}

/// @brief Reproduce una nota en el buzzer.
void RobotBT::playTone(int note, int duration) {
    tone(pinBuzzer, note, duration);
    delay(duration * 1.30);
    noTone(pinBuzzer);
}

/// @brief Obtiene el valor de 'datos' recibido por el BT.
char RobotBT::getDatos() {
    if (BT->available()) {
        return (char)BT->read();  // Devolver el dato leído
    }
    return '\0';  // Devolver null character si no hay datos disponibles            // Devolver el dato leído
}

/// @brief Envía un comando AT al BT y escribe la respuesta en SERIAL
void RobotBT::sendATCommand(const String &command) {
    BT->println(command);
    delay(100);                // Esperar respuesta

    while (BT->available()) {
        char c = BT->read();
        Serial.write(c);  // Mostrar respuesta en el monitor serie
    }
}

/// @brief Limpia los datos de entrada del BT.
void RobotBT::clearBT(){
    while (BT->available()) {
        char c = BT->read();
        Serial.write(c);  // Mostrar respuesta en el monitor serie
    }
}

/// @brief Mueve el robot hacia adelante.
void RobotBT::moveForward() {
    analogWrite(pinMotorDer1, velocidad);
    analogWrite(pinMotorDer2, 0);
    analogWrite(pinMotorIzq3, velocidad);
    analogWrite(pinMotorIzq4, 0);
}

/// @brief Mueve el robot hacia atrás.
void RobotBT::moveBackward() {
    analogWrite(pinMotorDer1, 0);
    analogWrite(pinMotorDer2, velocidad);
    analogWrite(pinMotorIzq3, 0);
    analogWrite(pinMotorIzq4, velocidad);
}

/// @brief Gira el robot hacia la izquierda.
void RobotBT::turnLeft() {
    analogWrite(pinMotorDer1, velocidad);
    analogWrite(pinMotorDer2, 0);
    analogWrite(pinMotorIzq3, 0);
    analogWrite(pinMotorIzq4, 0);
}

/// @brief Gira el robot hacia la derecha.
void RobotBT::turnRight() {
    analogWrite(pinMotorDer1, 0);
    analogWrite(pinMotorDer2, 0);
    analogWrite(pinMotorIzq3, velocidad);
    analogWrite(pinMotorIzq4, 0);
}

/// @brief Detiene todos los motores del robot.
void RobotBT::stopMotors() {
    analogWrite(pinMotorDer1, 0);
    analogWrite(pinMotorDer2, 0);
    analogWrite(pinMotorIzq3, 0);
    analogWrite(pinMotorIzq4, 0);
}

/// @brief Gira el robot rápidamente hacia la derecha.
void RobotBT::turnRightFast() {
    analogWrite(pinMotorDer1, 0);
    analogWrite(pinMotorDer2, velocidad);
    analogWrite(pinMotorIzq3, velocidad);
    analogWrite(pinMotorIzq4, 0);
}

/// @brief Gira el robot rápidamente hacia la izquierda.
void RobotBT::turnLeftFast() {
    analogWrite(pinMotorDer1, velocidad);
    analogWrite(pinMotorDer2, 0);
    analogWrite(pinMotorIzq3, 0);
    analogWrite(pinMotorIzq4, velocidad);
}
