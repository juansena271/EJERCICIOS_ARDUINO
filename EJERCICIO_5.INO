const int ledBits[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int contador = 0;

void setup() {
  // Configurar los pines de los LEDs
  for(int i = 0; i < 8; i++) {
    pinMode(ledBits[i], OUTPUT);
  }
  
  // Configurar el pin del botón
  pinMode(10, INPUT);
}

void loop() {
  // Detectar la presión del botón
  if (digitalRead(10) == LOW) {
    contador = (contador + 1) % 4;  // Cambiar patrón (0, 1, 2, 3)
    delay(300);  // Delay para evitar rebotes del botón
  }

  // Ejecutar el patrón según el valor de 'contador'
  switch (contador) {
    case 0:
      // Patrón 1: LEDs encendidos de izquierda a derecha
      for (int i = 0; i < 8; i++) {
        digitalWrite(ledBits[i], HIGH);
        delay(300);
        digitalWrite(ledBits[i], LOW);
      }
      break;
      
    case 1:
      // Patrón 2: LEDs encendidos de derecha a izquierda
      for (int i = 7; i >= 0; i--) {
        digitalWrite(ledBits[i], HIGH);
        delay(300);
        digitalWrite(ledBits[i], LOW);
      }
      break;
      
    case 2:
      // Patrón 3: Todos los LEDs encendidos
      for (int i = 0; i < 8; i++) {
        digitalWrite(ledBits[i], HIGH);
      }
      delay(300);
      // Apagar todos los LEDs
      for (int i = 0; i < 8; i++) {
        digitalWrite(ledBits[i], LOW);
      }
      break;

    case 3:
      // Patrón 4: LEDs encendidos en pares (extremos hacia el centro)
      for (int i = 0; i < 4; i++) {
        digitalWrite(ledBits[i], HIGH);
        digitalWrite(ledBits[7-i], HIGH);
        delay(300);
        digitalWrite(ledBits[i], LOW);
        digitalWrite(ledBits[7-i], LOW);
      }
      break;
  }
}
