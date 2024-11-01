#include <stdio.h> //biblioteca de comunica��o com o user
#include <stdlib.h> //biblioteca de aloca��o de espaco de memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca resposanvel por cuidar das string
//string � um conjunto de variaveis
int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio das variaveis/string 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das strings
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��o do usu�rio 
	scanf("%s", cpf); //%s refere a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w = escrever 
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadatrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
			
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if (file == NULL)
	{
		printf("CPF n�o encontrado!.\n"); //mostra que o cpf n�o foi encontrado
		system("pause");
	}
	else
	{
		remove(cpf); //remove  o cpf 
		printf("CPF removido com sucesso!\n"); //mostra que o cpf foi deletado com sucesso
		system("pause");
	}
	
}

int main()
{
	int opcao=0;
	int laco=1;

	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese_Brazil.1252"); //definindo linguagem

		printf("### cart�rio da ebac ###\n\n"); //inicio do menu 
		printf("escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registra nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:"); //fim do menu 
	
		scanf("%d", &opcao); //armazenamento do usu�rio
	
		system("cls"); //limpa a tela igual cs
		
		switch(opcao)
		{
			case 1:
			registro(); //chama de fun��es
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			default:
			printf("essa op��o n�o esta disponivel!\n");
			system("pause");
			break;
		}
		
	

	}
}
