// C++ code
/* 
Nesta práctica simularemos o funcionamento simplificado da xanela dun coche
   
Cando prememos unha vez, o pulsador activa un motor 
que move o vidro cara arriba; ao premer unha segunda vez,
parase o motor, ao volver a pulsar, o pulsador activa outro motor 
que move o vidro cara abaixo.
Tanto as entradas como as saídas son dixitais, polo que imos 
activar os motores mediante dous relés.
Cada un dos motores para ao estar aceso 7 segundos ou ao pulsar o seu
final de carreira correspondente.

Autor: Pablo Cameán Garrido
Data: Febreiro 2024
*/

//Declaración de pines
#define PULS 10       // Pulsador
#define MOTORUP 13    // Motor de subida
#define MOTORDOWN 12  // Motor de baixada
#define FC1 11        // Final de carreira 1
#define FC2 9         // Final de carreira 2

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
    
    // Apaga ambos motores ó cambiar o motor activo
    digitalWrite(MOTORUP, LOW);
    digitalWrite(MOTORDOWN, LOW);
    if (contador > 0){
    contador = 0; 
    }
    else  {
      motorActivo = !motorActivo;  // Cambia o estado do motor activo
      if (motorActivo == 1) {  
    digitalWrite(MOTORUP, HIGH);  // Activa o MotorUP
      Serial.println("MotorUP activado");
 
    } 
    	else {
      		digitalWrite(MOTORDOWN, HIGH);  // Activa o MotorDOWN
      		Serial.println("MotorDOWN activado");
          
    		} 
      contador = 500; // Espera 7 segundos para apagar o motor
    }
       while(digitalRead(PULS) == 1) { // Espera a que se solte o pulsador
      	delay(10);
    	}
  }

  
  if (contador > 0) {
  /*Se un motor está activado ao pulsar o seu final 
    de carreira correspondente este apagarase */
  
    if (digitalRead(FC1) && motorActivo){
     digitalWrite(MOTORUP, LOW);                
    } else if (digitalRead(FC2) && !motorActivo) {
       digitalWrite(MOTORDOWN, LOW); 
    }
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
