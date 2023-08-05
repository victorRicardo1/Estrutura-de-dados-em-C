#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	int *p;
	int x = 10, y = 20;
	p = &x;
	*p = y;
	printf("%d %d", x, y); 
	//O input será 20 20, pois o ponteiro aponta para o endereço de memória de x, após isso, o valor de p que esta apontado para x se torna o valor de y;
	*/
	
	struct horario{
		int hora;
		int minuto;
		int segundo;
	};
	struct horario agora, *depois;
	depois = &agora;
	
	(*depois).hora = 20;
	(*depois).minuto = 55;
	(*depois).segundo = 15;
		
	printf("%d:%d:%d", agora.hora, agora.minuto, agora.segundo);
	
	int valor, cedulas_100, cedulas_50, cedulas_10, cedulas_5, cedulas_2;

    printf("Digite o valor em reais: ");
    scanf("%d", &valor);

    // Calculando as cédulas de 100
    cedulas_100 = valor / 100;

    // Calculando as cédulas de 50
    cedulas_50 = valor / 50;


    // Calculando as cédulas de 10
    cedulas_10 = valor / 10;


    // Calculando as cédulas de 5
    cedulas_5 = valor / 5;

    // Calculando as cédulas de 2
    cedulas_2 = valor / 2;

    printf("Cedulas de 100: %d\n", cedulas_100);
    printf("Cedulas de 50: %d\n", cedulas_50);
    printf("Cedulas de 10: %d\n", cedulas_10);
    printf("Cedulas de 5: %d\n", cedulas_5);
    printf("Cedulas de 2: %d\n", cedulas_2);

}
