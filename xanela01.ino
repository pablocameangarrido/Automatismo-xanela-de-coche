// C++ code
/* Nesta práctica simularemos o funcionamento da ventanilla dun coche
*  
*  Autor: Pablo Cameán Garrido
*/

//Declaración de pines
#define PULS 10
#define MOTORUP 13
#define MOTORDOWN 12

//Declaración de variables
int contador = 0;
int motorActivo = 0;

void setup() {
  pinMode(PULS, INPUT_PULLUP);
  pinMode(MOTORUP, OUTPUT);
  pinMode(MOTORDOWN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PULS) == 1) {
    motorActivo = !motorActivo;  // Cambia el estado del motor activo

    // Apaga ambos motores al cambiar el motor activo
    digitalWrite(MOTORUP, LOW);
    digitalWrite(MOTORDOWN, LOW);

    if (motorActivo == 1) {
      digitalWrite(MOTORUP, HIGH);  // Activa el motor ascendente
      Serial.println("MotorUP activado");
    } else {
      digitalWrite(MOTORDOWN, HIGH);  // Activa el motor descendente
      Serial.println("MotorDOWN activado");
    }

    contador = 530; // Espera 7 segundos para apagar el motor
    
    while(digitalRead(PULS) == 1) { // Espera a que se suelte el pulsador
      delay(10);
    }
  }

  if (contador > 0) {
    contador -= 1;
    delay(10);
  } else {
    digitalWrite(MOTORUP, LOW);
    digitalWrite(MOTORDOWN, LOW);
    Serial.println("Ambos motores apagados");
  }

  Serial.print("Contador: ");
  Serial.println(contador);
}
