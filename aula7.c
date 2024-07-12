#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int registrar() //fun��o por cadastrar os usuarios
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o
	
	printf("\nDigite o CPF para cadastro: ");//coletando inform��es do user
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores da string
	
	FILE *file; //criar arquivo
	file = fopen(arquivo, "w"); //abrir o arquivo e criar o arquivo (w � para escrever)
	fprintf(file,cpf); //salvar o arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nDigite o Nome para cadastro: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nQual o sobrenome ?: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nE qual � o Cargo ?: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	
	system("pause");
}	


int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("\nDigite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nArquivo n�o encontrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nAqui est� as informa��es: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF para ser Deletado: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra mais no sistema! \n");
		system("pause");
	}
	

	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese");
		
		printf("\tBem Vindo ao Cartorio da EBAC!\n");
		printf("Escolha a op��o desejada\n\n");
		printf("\t1 - Registrar Nome\n");
		printf("\t2 - Consultar Nome\n");
		printf("\t3 - Deletar Nome\n\n");
		printf("op��o\t");
		
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
				registrar(); //chamada de fun��es
				break;
				
			case 2:
				consultar();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
			printf("Op��o invalida!\n");
			system("pause");
			break;
		}
	}
}
