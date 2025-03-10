int ledpin = 13;
bool parpadeoActivo = false; // Variable para controlar el parpadeo

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();

    if (isAlpha(data)) { // Si es una letra, activa el parpadeo
      Serial.println("Parpadeo activado");
      parpadeoActivo = true;
    } else if (data == '0') { // Si recibe '0', detiene el parpadeo
      Serial.println("Parpadeo detenido");
      parpadeoActivo = false;
      digitalWrite(ledpin, LOW);
    }
  }

  // Si el parpadeo está activo, hacer parpadear el LED
  if (parpadeoActivo) {
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin, LOW);
    delay(500);
  }
}