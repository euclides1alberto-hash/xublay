#include <Arduino.h>
/*
 * Controle de 4 LEDs com 4 Botões - Arduino Uno
 * Cada botão alterna (toggle) o estado do seu LED correspondente
 *
 * Conexões:
 *   Botão 1 → Pino 2    LED 1 → Pino 8
 *   Botão 2 → Pino 3    LED 2 → Pino 9
 *   Botão 3 → Pino 4    LED 3 → Pino 10
 *   Botão 4 → Pino 5    LED 4 → Pino 11
 *
 * Observações:
 * - Botões ligados entre pino e GND (usando pull-up interno)
 * - LEDs com resistor de 220–330 Ω em série com o catodo → GND
 * - Detecta apenas o momento em que o botão é pressionado (flanco de descida)
 */

#define NUM_LEDS 4

// Pinos dos botões (conectados a GND quando pressionados)
const uint8_t pinBotao[NUM_LEDS] = {2, 3, 4, 5};

// Pinos dos LEDs
const uint8_t pinLed[NUM_LEDS]   = {8, 9, 10, 11};

// Estados anteriores dos botões (para detectar borda de descida)
uint8_t ultimoEstadoBotao[NUM_LEDS] = {HIGH, HIGH, HIGH, HIGH};

// Estado atual dos LEDs (true = ligado)
bool estadoLed[NUM_LEDS] = {false, false, false, false};

void setup() {
  Serial.begin(9600);
  delay(300);               // pequeno delay para estabilizar o Serial
  Serial.println("\n=== Controle 4 Botões + 4 LEDs - Iniciado ===\n");

  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    pinMode(pinBotao[i], INPUT_PULLUP);
    pinMode(pinLed[i],   OUTPUT);
    digitalWrite(pinLed[i], LOW);     // garante LEDs desligados no início
  }
  
  Serial.println("Pressione qualquer botão para alternar o LED correspondente.");
  Serial.println("--------------------------------------------");
}

void loop() {
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    uint8_t leituraAtual = digitalRead(pinBotao[i]);

    // Detecta quando o botão foi pressionado (HIGH → LOW)
    if (leituraAtual == LOW && ultimoEstadoBotao[i] == HIGH) {
      
      // Debounce simples
      delay(20);
      if (digitalRead(pinBotao[i]) == LOW) {   // ainda pressionado?
        
        // Alterna o estado do LED
        estadoLed[i] = !estadoLed[i];
        digitalWrite(pinLed[i], estadoLed[i] ? HIGH : LOW);

        // Mensagem no monitor serial
        Serial.print("Botão ");
        Serial.print(i + 1);
        Serial.print(" → LED ");
        Serial.print(i + 1);
        Serial.print(" ");
        Serial.println(estadoLed[i] ? "LIGADO" : "desligado");
      }
    }

    // Atualiza o estado anterior para a próxima leitura
    ultimoEstadoBotao[i] = leituraAtual;
  }
  
  // Aqui você pode adicionar outras tarefas não-bloqueantes se quiser
  // (ex: ler sensores, atualizar display, etc)
}