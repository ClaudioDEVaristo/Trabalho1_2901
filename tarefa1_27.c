// Inclusão de Bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"

// Define os pinos dos leds 
#define LED_VERM 11
#define LED_AMAR 12
#define LED_VERD 13

// Inicia os leds como saída
void setup(){
    gpio_init(LED_VERM);//Inicia o pino 11(vermelho)
    gpio_set_dir(LED_VERM, GPIO_OUT);//Define o pino 11 como Saída
    gpio_init(LED_AMAR);//Inicia o pino 12(amarelo)
    gpio_set_dir(LED_AMAR, GPIO_OUT);//Define o pino 12 como Saída
    gpio_init(LED_VERD);//Inicia o pino 13(verde)
    gpio_set_dir(LED_VERD, GPIO_OUT);//Define o pino 13 como Saída
}

// Função de callback do timer
bool repeating_callback_timer(struct repeating_timer *t){
    printf("Rotina de repetição\n");//Confirmação da ativação do timmer
    if(gpio_get(LED_VERM)){
        gpio_put(LED_VERM, 0);//Desliga o led vermelho
        gpio_put(LED_AMAR, 1);//Liga o led amarelo
    }
    else if(gpio_get(LED_AMAR)){
        gpio_put(LED_AMAR, 0);//Desliga o led amarelo
        gpio_put(LED_VERD, 1);//Liga o led verde
    }
    else if(gpio_get(LED_VERD)){
        gpio_put(LED_VERM, 1);//Liga o led vermelho
        gpio_put(LED_VERD, 0);//Desliga o led verde
    }
    return true;
}

//Função principal
int main() {
    stdio_init_all();//Inicia a comunicação serial
    setup();//Chama a função que inicia os pinos
    gpio_put(LED_VERM, 1);//Inicia com led vermelho aceso 
   
    struct repeating_timer timer;//Cria o timer

    add_repeating_timer_ms(3000, repeating_callback_timer, NULL, &timer);//Configura o timmer para 3 segundos
   
    while (true) {
        sleep_ms(1000);
        printf("1 segundo!\n");// Mensagem de confirmação de 1 segundo
    }
}