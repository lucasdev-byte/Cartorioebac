#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //biblioteca de aloca��o de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo "W" significa escrever
	fprintf(file,cpf); //Salva o valor da vari�vel
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o foi encontrado no sistema!.\n");
		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	int opcao=0; //definindo as vari�veis
	int laco=1;
	char senha[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senha);
	
	comparacao = strcmp(senha,"admin");
	
	if(comparacao == 0)
    {
    	for(laco=1;laco=1;) //Inicio do la�o de repeti��o
    	{
			
        	system("cls");
    		
        	setlocale(LC_ALL,"portuguese"); //definindo a linguagem
    	
    		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
        	printf("Selecione a op��o desejada do menu:\n\n");
        	printf("\t1 - Registrar nomes\n");
        	printf("\t2 - Consultar nomes\n");
        	printf("\t3 - Deletar nomes\n");
        	printf("\t4 - Sair do sistema\n\n");
	    	printf("Op��o: "); //fim do menu
	
        	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
        	system("cls"); //Respons�vel por limpar a tela
	
            switch(opcao) //Inicio da sele��o
            {
            	case 1:
            	registro(); //Chamada de fun��es
            	break;
            	
            	case 2:
            	consulta();
            	break;
        	
            	case 3:
            	deletar();
            	break;
        	
            	case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;
            	
            	default:
            	printf("Essa op��o n�o est� disponivel!\n");
            	system("pause");
            	break;
	    	} //Fim da sele��o	   
    	} //Fim do la�o de repeti��o
    }
	else 
	  printf("senha incorreta!");
}
