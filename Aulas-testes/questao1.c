#include <stdlib.h>
#include <stdio.h>

int main(){
	int soma = 0, alunos, *numeros, media, i, nota;
	printf("Informe a quantidade de alunos: ");
	scanf("%d", &alunos);
	numeros = (int *)malloc(alunos*sizeof(int));
	
	for(i = 0; i < alunos; i++){
		printf("\nInforme a nota do %d aluno: ", i+1);
		scanf("%d", &numeros[i]);
		soma += numeros[i];
	}
	media = soma / alunos;
	printf("a media dos alunos eh: %d", media);
	free(numeros);
}
