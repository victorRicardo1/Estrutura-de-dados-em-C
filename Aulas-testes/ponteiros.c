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
	
	depois->hora = 20; //Em caso de estruturas, colocamos o ponteiro entre parenteses quando trocamos um valor dentro(*depois) ou apenas usamos ->
	depois->minuto = 55;
	depois->segundo = 15;

	int soma = 100;
	
	struct horario antes;
	antes.hora = soma + depois->segundo;
	
		
	//printf("%d:%d:%d", agora.hora, agora.minuto, agora.segundo);
	
	//printf("\n%d", antes.hora);
	
	
	//Agora uma struct que possui um ponteiro
	
	struct horario2{
		int *hora;
		int *minuto;
		int *segundo;
	};
	struct horario2 now;
	int horaa = 100;
	int minut = 40;
	int segund = 33;
	
	now.hora = &horaa;
	now.minuto = &minut;
	now.segundo = &segund;
	
	//printf("\n%d:%d:%d", *now.hora, *now.minuto, *now.segundo);
	
	
	
	//Ponteiros em listas
	
	struct lista{
		int valor;
		struct lista *proximo;
	};	
	struct lista m1, m2, m3;
	struct lista *gancho = &m1;
	
	m1.valor = 10;
	m2.valor = 20;
	m3.valor = 30;
	
	m1.proximo = &m2;
	m2.proximo = &m3;
	m3.proximo = (struct lista *)0;
	
	while(gancho != (struct lista *)0){
		printf("%d\n", gancho->valor);
		gancho = gancho->proximo;
	}
		
}
