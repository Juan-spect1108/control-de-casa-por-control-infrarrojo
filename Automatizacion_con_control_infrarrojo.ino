
// designed by: Juan Rodrigo Guzman Martinez 

#include <IRremote.h> // Incluimos la liberia IRremote

#define boton  0xFF6897 // Definimos el codigo hexadecimal de la tecla 0 con el nombre de boton
#define boton1 0xFF30CF // Definimos el codigo hexadecimal de la tecla 1 con el nombre de boton1
#define boton2 0xFF18E7 // Definimos el codigo hexadecimal de la tecla 2 con el nombre de boton2
#define boton3 0xFF7A85 // Definimos el codigo hexadecimal de la tecla 3 con el nombre de boton3
#define boton4 0xFF10EF // Definimos el codigo hexadecimal de la tecla 4 con el nombre de boton4
#define boton5 0xFF38C7 // Definimos el codigo hexadecimal de la tecla 5 con el nombre de boton5
#define boton6 0xFF5AA5 // Definimos el codigo hexadecimal de la tecla 6 con el nombre de boton6
#define boton7 0xFF42BD // Definimos el codigo hexadecimal de la tecla 7 con el nombre de boton7
#define boton8 0xFF4AB5 // Definimos el codigo hexadecimal de la tecla 8 con el nombre de boton8
#define boton9 0xFF52AD // Definimos el codigo hexadecimal de la tecla 9 con el nombre de boton9

int Sensor=2; // Pin donde se conectara el sensor 
IRrecv irrecv (Sensor); // Declaramos un objeto y guardamos los datos recibidos en el sensor
decode_results Juan; // Declaramos una variable donde se almacenran los resultados 

int Foco1=3; // Definimos Foco1 en el pin 2 del arduino
int Foco2=4; // Definimos Foco2 en el pin 3 del arduino
int Foco3=5; // Definimos Foco3 en el pin 4 del arduino
int Ventilador1=6; // Definimos Ventilador1 en el pin 5 del arduino
int Ventilador2=7; // Definimos Ventilador2 en el pin 6 del arduino

void setup() {
Serial.begin(9600); // Inicializamos el monitor serial a 9600 baudios
irrecv.enableIRIn(); // Inicializamos el infrerrojo
pinMode(Foco1, OUTPUT); // Declaramos Foco1 como una salida
pinMode(Foco2, OUTPUT); // Declaramos Foco2 como una salida
pinMode(Foco3, OUTPUT); // Declaramos Foco3 como una salida
pinMode(Ventilador1, OUTPUT); // Declaramos Ventilador1 como una salida
pinMode(Ventilador2, OUTPUT); // Declaramos Ventilador2 como una salida
}

void loop() {
if(irrecv.decode(&Juan)){
Serial.println(Juan.value, HEX); // Imprimimos en el m onitor serial el codigo hexadecimal de cada tecla

if(Juan.value== boton){ // si el valor es igual al de el boton entonces enciende el Foco1
digitalWrite(Foco1, 1);
}
if(Juan.value== boton1){ // si el valor es igual al de el boton1 entonces apaga el Foco1
digitalWrite(Foco1, 0);
}
if(Juan.value== boton2){ // si el valor es igual al de el boton2 entonces enciende el Foco2
digitalWrite(Foco2, 1);
}
if(Juan.value== boton3){ // si el valor es igual al de el boton3 entonces apaga el Foco2
digitalWrite(Foco2, 0);
}
if(Juan.value== boton4){ // si el valor es igual al de el boton4 entonces enciende el Foco3
digitalWrite(Foco3, 1);
}
if(Juan.value== boton5){ // si el valor es igual al de el boton5 entonces apaga el Foco3
digitalWrite(Foco3, 0);
}
if(Juan.value== boton6){ // si el valor es igual al de el boton6 entonces enciende el Ventilador1
digitalWrite(Ventilador1, 1);
}
if(Juan.value== boton7){ // si el valor es igual al de el boton7 entonces apaga el Ventilador1
digitalWrite(Ventilador1, 0);
}
if(Juan.value== boton8){ // si el valor es igual al de el boton8 entonces enciende el Ventilador2
digitalWrite(Ventilador2, 1);
}
if(Juan.value== boton9){ // si el valor es igual al de el boton9 entonces apaga el Ventilador2
digitalWrite(Ventilador2, 0);
}
irrecv.resume(); // Empezamos un nueva recepcion 
}
delay(100); // Damos un retardo de 100 milisegundos
}
