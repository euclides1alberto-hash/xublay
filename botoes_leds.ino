/*
 * Controlo de 4 LEDs com 4 Botões - Arduino Uno
 * Cada botão liga/desliga o seu LED correspondente
 *
 * Ligações:
 *   Botão 1 → Pino 2   |   LED 1 → Pino 8
 *   Botão 2 → Pino 3   |   LED 2 → Pino 9
 *   Botão 3 → Pino 4   |   LED 3 → Pino 10
 *   Botão 4 → Pino 5   |   LED 4 → Pino 11
 *
 * Os botões usam resistência pull-up interna (INPUT_PULLUP).
 * Ligue cada botão entre o pino e GND.
 * Ligue cada LED em série com uma resistência de 220Ω para GND.
 */

// Pinos dos botões
const int BOTAO[4] = {2, 3, 4, 5};

// Pinos dos LEDs
const int LED[4] = {8, 9, 10, 11};

// Estado anterior de cada botão (para detetar mudança)
int estadoAnterior[4] = {HIGH, HIGH, HIGH, HIGH};

// Estado de cada LED (ligado/desligado)
bool ledLigado[4] = {false, false, false, false};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(BOTAO[i], INPUT_PULLUP); // Pull-up interno: botão solto = HIGH
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
  Serial.begin(9600);
  Serial.println("Sistema iniciado. Prima um botão para ligar/desligar o LED.");
}

void loop() {
  for (int i = 0; i < 4; i++) {
    int leitura = digitalRead(BOTAO[i]);

    // Detetar flanco descendente (botão pressionado)
    if (leitura == LOW && estadoAnterior[i] == HIGH) {
      delay(20); // Debounce: aguarda 20ms e confirma
      if (digitalRead(BOTAO[i]) == LOW) {
        ledLigado[i] = !ledLigado[i]; // Alterna estado do LED
        digitalWrite(LED[i], ledLigado[i] ? HIGH : LOW);

        Serial.print("Botão ");
        Serial.print(i + 1);
        Serial.print(" → LED ");
        Serial.print(i + 1);
        Serial.println(ledLigado[i] ? " LIGADO" : " DESLIGADO");
      }
    }

    estadoAnterior[i] = leitura;
  }
}
