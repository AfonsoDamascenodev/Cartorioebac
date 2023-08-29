#include <stdio.h> //biblioteca de comunicaçao com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço na memorio
#include <locale.h> //biblioteca de alocação de texto por registro
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim criação das variaveis
	
	printf("digite o CPF a ser cadastrado:" ); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo o w significa escrever
	fprintf(file, cpf); //salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file, nome );
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf (file, sobrenome );
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf ("%s" ,cpf );
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("Não foi possivel abrir o arquivo, não localizado. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	system ("pause");	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF fo usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
		
	}
	
}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf("-------------- Cartorio da EBAC --------------\n\n"); //Inicio menu
		printf ("Escolha a opção desejada:\n\n ");
		printf ("\t1 Registrar\n");
		printf ("\t2 Consultar\n");
		printf ("\t3 Deletar\n\n");
		printf ("\t4 Sair do Sistema\n\n");
		printf ("opção:"); //fim menu
	
		scanf("%d", &opcao); //Armazenando escolha do usuario
	
		system("cls"); //reponsavel por limpar a tela
		
		switch(opcao)
		{
			case 1: 
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
		 	deletar();
			break;
			
			case 4:
				printf("Obrigado por usar nosso sistema/n");
				return 0;
				break;
			
			default:
			printf("Essa opção não esta disponivel\n");
			system ("pause");
				
				
		}
		
}
	}
