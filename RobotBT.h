#ifndef ROBOTBT_H
#define ROBOTBT_H

#include <Arduino.h>
#include <SoftwareSerial.h>

/// @brief Clase que representa un robot controlado a distancia mediante Bluetooth.
class RobotBT {
private:
    // Atributos
    SoftwareSerial* BT; ///< Comunicación Bluetooth.
    const int velocidad; ///< Velocidad de los motores.
    
    const int pinRxBT; ///< Pin RX para la comunicación Bluetooth.
    const int pinTxBT; ///< Pin TX para la comunicación Bluetooth.
    const int pinBuzzer; ///< Pin del buzzer.
    const int pinMotorDer1; ///< Pin de control 1 del motor derecho.
    const int pinMotorDer2; ///< Pin de control 2 del motor derecho.
    const int pinMotorIzq3; ///< Pin de control 1 del motor izquierdo.
    const int pinMotorIzq4; ///< Pin de control 2 del motor izquierdo.

public:
    // Métodos
    /// @brief Constructor de la clase inicializa el BT con un Baudrate, HC05 38400, HC06 9600. Y envía "AT".
    /// @param pinRxBT PIN Arduino que recibe la señal del Tx del BT.
    /// @param pinTxBT PIN Arduino que envía la señal al Rx del BT.
    /// @param pinBuzzer PIN Arduino que envía la señal para el Buzzer.
    /// @param velocidad Velocidad de los motores.
    /// @param pinMotorDer1 Pin de control 1 del motor derecho PWM.
    /// @param pinMotorDer2 Pin de control 2 del motor derecho PWM.
    /// @param pinMotorIzq3 Pin de control 1 del motor izquierdo PWM.
    /// @param pinMotorIzq4 Pin de control 2 del motor izquierdo PWM.
    RobotBT(    int pinRxBT, int pinTxBT, int pinBuzzer, int velocidad,
                int pinMotorDer1, int pinMotorDer2,
                int pinMotorIzq3, int pinMotorIzq4, int baudios = 9600
            );

    /// @brief Obtiene el valor de 'datos' recibido por el BT.
    char getDatos();

    /// @brief Limpia los datos de entrada del BT.
    void clearBT();

    /// @brief Envía un comando AT al BT y escribe la respuesta en SERIAL
    void sendATCommand(const String &command);

    /// @brief Reproduce una nota en el buzzer.
    /// @param note Nota a reproducir (frecuencia en Hz).
    /// @param duration Duración de la nota (en mili segundos).
    void playTone(int note, int duration);

    /// @brief Mueve el robot hacia adelante.
    void moveForward();

    /// @brief Mueve el robot hacia atrás.
    void moveBackward();

    /// @brief Gira el robot hacia la izquierda.
    void turnLeft();

    /// @brief Gira el robot hacia la derecha.
    void turnRight();

    /// @brief Detiene todos los motores del robot.
    void stopMotors();

    /// @brief Gira el robot rápidamente hacia la izquierda.
    void turnLeftFast();

    /// @brief Gira el robot rápidamente hacia la derecha.
    void turnRightFast();
};

#endif