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
	
	depois->.hora = 20; //Em caso de estruturas, colocamos o ponteiro entre parenteses quando trocamos um valor dentro(*depois) ou apenas usamos ->
	depois->.minuto = 55;
	depois->.segundos = 15;

	printf("%d:%d:%d", agora.hora, agora.minuto, agora.segundo);
}
