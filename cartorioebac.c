#include <stdio.h> //biblioteca de comunicaçao com o usuario
#include <stdlib.h> //biblioteca de alocaçao de espaço em memoria
#include <locale.h>//biblioteca de alocaçoes de texto por regiao
#include <string.h>//biblioteca de string

int Registro()  //Função Responsavel por cadastrar o usuário
{
  //Criando variáveis/strings
     
  char arquivo[40];	
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  
  //Final das variáveis/strings
  
  printf("Digite seu cpf a ser cadastrado:"); //Coletando informações do usuário
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
    
    printf("Digite o nome a ser cadastrado:"); //Coleta informaçoes do usuário
    scanf("%s", nome); //%S Refere-se a string

    file = fopen(arquivo, "a");//Abrir o arquivo "a" significa salvar a escrita
    fprintf(file, nome);//Salvar o valor da variavel
    fclose(file); //Fechar o arquivo

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, "\nSobrenome:");//escrever no arquivo referenciado pelo ponteiro file
    fclose(file);//Fechar o arquivo

    printf("Digite o sobrenome a ser cadastrado:");//Coleta informaçoes do usuário
    scanf("%s", sobrenome);//%S Refere-se a string

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, sobrenome);//Salvar o valor da variavel
    fclose(file);//Fechar o arquivo

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, "\nCargo:");//escrever no arquivo referenciado pelo ponteiro file
    fclose(file);//Fechar o arquivo

    printf("Digite o cargo a ser cadastrado:");//Coleta informaçoes do usuário
    scanf("%s", cargo);//%S Refere-se a string

    file = fopen(arquivo, "a");//Abrir o arquivo ("a" significa abrindo o arquivo chamado arquivo no modo de escrita)
    fprintf(file, cargo);//Salvar o valor da variavel
    fprintf(file,"\n\n");
    fclose(file);//Fechar arquivo
  
  system("pause");//Pausa para o usuário 
}

int Consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Setando a Linguagem Portugues no codigo
	
	//Criando variáveis/strings
	
	char cpf[40];
	char conteudo[200];
	
	//Final das variáveis/strings
	
	printf("Digite o cpf a ser consultado: "); //Coleta informaçoes do usuário
	scanf("%s",cpf);//%S Refere-se a string
	
	FILE*file; //Criar o arquivo
	file=fopen(cpf,"r"); //função fopen tenta abrir o arquivo especificado pelo caminho cpf(O modo "r" é usado para leitura de arquivos)
	
	if(file==NULL)//está sendo usado para verificar se a tentativa de abrir o arquivo foi bem-sucedida
	{
		printf("Não foi possivel abrir o arquivo!.\n");//Escreve para o usuario o erro de não encontrar o arquivo
	}
	
	printf("Essas são as informações do usuario: \n\n ");
	
	while(fgets(conteudo,200,file)!=NULL)//está em um loop que lê linhas de um arquivo referenciado por file usando a função fgets
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
        printf("\nCPF Não encontrado!\n\n");
        system("pause");
    } else {
        fclose(file);

        if (remove(cpf) == 0) {
            printf("\nUsuário deletado com sucesso!\n\n");
            system("pause");
        } else {
            printf("\nErro ao deletar esse usuário\n\n");
            system("pause");
        }
    }  
}

int main()
{
	
  int opcao=0;  // Definindo as variáveis
  int rep=1;
  
  for(rep=1;rep==1;)
 {
 
   system("cls");
  
   setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
  
  
   printf("###Cartorio da Ebac###\n\n ");  // Inicio do Menu
  
   printf("Escolha a opção desejada no menu:\n\n");
   printf("\t1 - Registrar Nomes\n");
   printf("\t2 - Consultar Nomes\n");
   printf("\t3 - Deletar  os nomes\n\n "); 
   printf("Opção:"); // Fim do Menu
  
   scanf("%d",&opcao); // Armazenando a escolha do usuária
  
   system("cls"); //Responsável por limpas a tela
   
   switch(opcao) // Inicio da seleçao do menu
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
    printf("Essa opçao não está Disponivel!\n");
    system("pause");
   	break;
   	
   }

 }
}
