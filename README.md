# Controle de LEDs com Temporizador periódico

Este projeto controla três LEDs (vermelho, amarelo e verde) conectados ao Raspberry Pi Pico. Os LEDs alternam automaticamente em um ciclo de 3 segundos com base em um temporizador periódico.

## Requisitos

- Raspberry Pi Pico
- Três LEDs (vermelho, amarelo e verde)
- Três resistores (330Ω)
- Ambiente de desenvolvimento configurado para o Pico (SDK do Raspberry Pi) e simulador Wokwi integrado ao VScode

## Conexões dos LEDs

| Cor do LED  | Pino do Pico |
|------------|-------------|
| Vermelho   | GPIO 11     |
| Amarelo    | GPIO 12     |
| Verde      | GPIO 13     |

## Funcionamento do Programa

- O LED vermelho acende inicialmente.
- A cada 3 segundos, os LEDs alternam conforme a sequência:
  - Vermelho → Amarelo
  - Amarelo → Verde
  - Verde → Vermelho
- O programa exibe mensagens no console serial a cada segundo para depuração.

