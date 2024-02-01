#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em memoria
#include <locale.h>//biblioteca de aloca�oes de texto por regiao
#include <string.h>//biblioteca de string

int Registro()  //Fun��o Responsavel por cadastrar o usu�rio
{
  //Criando vari�veis/strings
     
  char arquivo[40];	
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  
  //Final das vari�veis/strings
  
  printf("Digite seu cpf a ser cadastrado:"); //Coletando informa��es do usu�rio
  scanf("%s", cpf); //%S Refere-se a string
  
  strcpy(arquivo,cpf); //Copiar o valor das strings
  FILE *file;  //Criar o arquivo
    
    file = fopen(arquivo, "w"); //Abrir o arquivo e o "W" significa escrever
    fprintf(file, "\nCpf:"); //escrever no arquivo referenciado pelo ponteiro file
    fprintf(file, cpf); //Salva o valor da variavel
    fclose(file); //FEcha o arquivo

    file = fopen(arquivo, "a"); //Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, "\nNome:"); //escrever no arquivo referenciado pelo ponteiro file
    fclose(file);  //Fecha o arquivo
    
    printf("Digite o nome a ser cadastrado:"); //Coleta informa�oes do usu�rio
    scanf("%s", nome); //%S Refere-se a string

    file = fopen(arquivo, "a");//Abrir o arquivo "a" significa salvar a escrita
    fprintf(file, nome);//Salvar o valor da variavel
    fclose(file); //Fechar o arquivo

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, "\nSobrenome:");//escrever no arquivo referenciado pelo ponteiro file
    fclose(file);//Fechar o arquivo

    printf("Digite o sobrenome a ser cadastrado:");//Coleta informa�oes do usu�rio
    scanf("%s", sobrenome);//%S Refere-se a string

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, sobrenome);//Salvar o valor da variavel
    fclose(file);//Fechar o arquivo

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, "\nCargo:");//escrever no arquivo referenciado pelo ponteiro file
    fclose(file);//Fechar o arquivo

    printf("Digite o cargo a ser cadastrado:");//Coleta informa�oes do usu�rio
    scanf("%s", cargo);//%S Refere-se a string

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, cargo);//Salvar o valor da variavel
    fprintf(file,"\n\n");
    fclose(file);//Fechar arquivo
  
  system("pause");//Pausa para o usu�rio 
}

int Consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Setando a Linguagem Portugues no codigo
	
	//Criando vari�veis/strings
	
	char cpf[40];
	char conteudo[200];
	
	//Final das vari�veis/strings
	
	printf("Digite o cpf a ser consultado: "); //Coleta informa�oes do usu�rio
	scanf("%s",cpf);//%S Refere-se a string
	
	FILE*file; //Criar o arquivo
	file=fopen(cpf,"r"); //fun��o fopen tenta abrir o arquivo especificado pelo caminho cpf(O modo "r" � usado para leitura de arquivos)
	
	if(file==NULL)//est� sendo usado para verificar se a tentativa de abrir o arquivo foi bem-sucedida
	{
		printf("N�o foi possivel abrir o arquivo!.\n");//Escreve para o usuario o erro de n�o encontrar o arquivo
	}
	
	printf("Essas s�o as informa��es do usuario: \n\n ");
	
	while(fgets(conteudo,200,file)!=NULL)//est� em um loop que l� linhas de um arquivo referenciado por file usando a fun��o fgets
	{
		
		printf("%s",conteudo);
	}
	
	  system("pause");
}
int Deletar() 
{
    char cpf[40];

    printf("Digite o cpf que deseja deletar:");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("\nCPF N�o encontrado!\n\n");
        system("pause");
    } else {
        fclose(file);

        if (remove(cpf) == 0) {
            printf("\nUsu�rio deletado com sucesso!\n\n");
            system("pause");
        } else {
            printf("\nErro ao deletar esse usu�rio\n\n");
            system("pause");
        }
    }  
}

int main()
{
	
  int opcao=0;  // Definindo as vari�veis
  int rep=1;
  
  for(rep=1;rep==1;)
 {
 
   system("cls");
  
   setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
  
  
   printf("###Cartorio da Ebac###\n\n ");  // Inicio do Menu
  
   printf("Escolha a op��o desejada no menu:\n\n");
   printf("\t1 - Registrar Nomes\n");
   printf("\t2 - Consultar Nomes\n");
   printf("\t3 - Deletar  os nomes\n\n "); 
   printf("Op��o:"); // Fim do Menu
  
   scanf("%d",&opcao); // Armazenando a escolha do usu�ria
  
   system("cls"); //Respons�vel por limpas a tela
   
   switch(opcao) // Inicio da sele�ao do menu
   {
   	case 1:
   	Registro();
  	break;
  	
  	case 2:
  	Consulta();	
    break;
  	
  	case 3:
  	Deletar();
   	break;
   	
   	default:
    printf("Essa op�ao n�o est� Disponivel!\n");
    system("pause");
   	break;
   	
   }

 }
}
