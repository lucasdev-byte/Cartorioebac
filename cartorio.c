#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocação de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo "W" significa escrever
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"portuguese"); //definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não foi encontrado no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Inicio do laço de repetição
	{
    	
    	system("cls");
		
    	setlocale(LC_ALL,"portuguese"); //definindo a linguagem
    	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
    	printf("Selecione a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usuário
	
    	system("cls"); //Responsável por limpar a tela
	
        switch(opcao) //Inicio da seleção
        {
        	case 1:
        	registro(); //Chamada de funções
        	break;
        	
        	case 2:
        	consulta();
        	break;
        	
        	case 3:
        	deletar();
        	break;
        	
        	default:
        	printf("Essa opção não está disponivel!\n");
        	system("pause");
        	break;
		} //Fim da seleção	   
	} //Fim do laço de repetição



}
