const int ledPin = 13; // Pin al que está conectado el LED

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // Configurar el pin del LED como salida
}

void loop() {
  if (Serial.available()) {
    char dato = Serial.read();
    Serial.print("Recibido: ");
    Serial.println(dato);
    digitalWrite(ledPin, HIGH); // Encender el LED
    delay(200); // Esperar 200 milisegundos
    digitalWrite(ledPin, LOW); // Apagar el LED
  }
}