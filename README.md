# Robot Móvil Controlado por Bluetooth

Este proyecto implementa un robot móvil controlado a través de Bluetooth, utilizando un módulo HC-05 y programación orientada a objetos en Arduino. El robot puede realizar movimientos precisos en diferentes direcciones y reproducir sonidos utilizando un buzzer.

## Descripción

El código fuente proporcionado en este repositorio está diseñado para controlar un robot móvil utilizando un dispositivo móvil a través de Bluetooth. El robot puede realizar las siguientes acciones:

- Moverse hacia adelante, hacia atrás, hacia la izquierda y hacia la derecha.
- Reproducir sonidos utilizando un buzzer.

El proyecto está diseñado para competir en la RoboCopa UNICAUCA 2022, cumpliendo con todos los requisitos y especificaciones establecidos en el reglamento.

## Funciones Importantes

### Constructor

El constructor `RobotBT()` inicializa el objeto `RobotBT` con los parámetros necesarios para configurar el robot y la comunicación Bluetooth.

## Funciones de Movimiento
### moveForward(): 
Mueve el robot hacia adelante.
### moveBackward(): 
Mueve el robot hacia atrás.
### turnLeft(): 
Gira el robot hacia la izquierda.
### turnRight(): 
Gira el robot hacia la derecha.

## Funciones de Control del Buzzer
###playTone(int note, int duration): 
Reproduce una nota musical con una duración específica en el buzzer.

## Funciones de Comunicación Bluetooth
### getDatos(): 
Obtiene el dato recibido por el módulo Bluetooth.
### isAvailableBT(): 
Verifica si hay datos disponibles en el módulo Bluetooth.
### sendATCommand(const String &command): 
Envía un comando AT al módulo Bluetooth y muestra la respuesta en el monitor serie.
Configuración Personalizada
El usuario puede personalizar los siguientes parámetros según sus necesidades:

### rxPin, txPin: 
Pines de recepción y transmisión del módulo Bluetooth.
### buzzerPin: 
Pin al que está conectado el buzzer.
### vel: 
Velocidad de los motores del robot.
### motorDer1, motorDer2, motorIzq3, motorIzq4: 
Pines de control de los motores del robot.
### baudios:
 Velocidad de comunicación del módulo Bluetooth (por defecto, 9600).

## Uso de Aplicaciones Móviles
Se puede utilizar cualquier aplicación desde un dispositivo móvil para controlar el robot. Se recomienda la aplicación "Arduino Bluetooth Control", pero no es obligatorio. Si se utiliza otra aplicación, se deben configurar los botones correspondientes. Para utilizar otras aplicaciones, se recomienda asignar los siguientes botones para los siguientes comandos:

- T: 
Mover hacia adelante (forward).
- B: 
Mover hacia atrás (backward).
- L: 
Girar hacia la izquierda (turn left).
- R: 
Girar hacia la derecha (turn right).
- S: 
Giro rápido a la izquierda (turn left fast).
- C: 
Giro rápido a la derecha (turn right fast).
- 0: 
Detener todos los motores (stop).
