#include <stdio.h> // biblioteca de comunicação com o usu�rio
# include <stdlib.h>//biblioteca de alocação em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o

int registro()//fun��o responsavel por cadasttrar os usu�rios no sistema
// inicio cria��o das vari�veis/strings
{   char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o das vari�veis


    printf("Digigte o CPF a ser cadstrado: ");//coletando informa��es do usu�rio
    scanf("%s",cpf);//reponsavel por criar os valores da string

    strcpy (arquivo, cpf); // responsavel por copiar os valores da string

    FILE *file;// cria o arquivo
    file = fopen(arquivo,"w");// O "w"  significa criar um arquivo e escrever
    fprintf(file,cpf);//salvo o valor na variavel
    fclose(file);// fecho o arquivo


    file = fopen(arquivo,"a");// esse "a" � para atualizar a informa��o
    fprintf(file,",");//ponntar e separar os dados
    fclose(file);//fechando arquivo


    printf("Digite o nome a ser cadastrado: ");//coletando informa��es do usu�rio
    scanf("%s",nome);// %s refer-se a cris��o de strings

    file = fopen(arquivo,"a");// abrindo o arquivo para atualizar
    fprintf(file,nome);//salvar o valor da vari�vel
    fclose(file);//fechando arquivo


    file = fopen(arquivo,"a");// abrindo o arquivo para atualizar
    fprintf(file,","); // salvando o arquivo
    fclose(file);//fechando o arquivo

    printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es
    scanf("%s",sobrenome);// Cria��o da string

    file = fopen(arquivo,"a");//abrindo arquivo para atualizar
    fprintf(file,sobrenome);// salvando arquivo
    fclose(file);//fechando arquivo

    file = fopen(arquivo,"a");//abrindo arquivo para atualizar
    fprintf(file,",");//salvando o arquivo
    fclose(file);//fechar o arquivo

    printf("Digite  o cargo a ser cadastrado: ");// Coletando arquivo
    scanf("%s",cargo); // criando string

    file = fopen(arquivo,"a");// Abrindo arquivo
    fprintf(file,cargo); // Salvando vari�vel
    fclose(file);//fechando arquivo

    system("pause");//Comando para pausar programa









}
int consulta()
{
    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem

    //Declarando vari�veis no escopo local
    char cpf[40];
    char conteudo[200];
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    //finalizando a declara�a� das variaveis



    FILE * file;//Criar arquivo
    file = fopen(cpf,"r");//esse "r" � para ler o aquivo

    if(file == NULL)//verifica��o para consultar dados dos usu�rios
    {
        printf("N�o � poss�vel abrir o arquivo, n�o localizado!.\n");

    }

    while(fgets(conteudo,200,file) != NULL)//laco de repeti�ao para procurar os dados dos usu�rios
    {
        printf("\nEssas s�o as informa��es do usu�rio:\n");
        printf("%s\n",conteudo,"\n");//Exibindo informa��es dos usu�rios
        printf("\n\n");// Salar linha 2x

    }

    system("pause");// pausar programa


}

int deletar()//Fun��o �ra deletar dados/ liber��o de espa�o
{
    //declarando as vari�veis
    char cpf[40];

    printf("Digite o CPF do usu�rio a ser deletado: "); //informar informa��es para deletar
    scanf("%s",cpf);// escaneando arquivo

    remove(cpf);// removendo CPF salvo

    FILE * file;// Acessando arquivo
    file = fopen(cpf,"r");//abrindo arquivo para ler

    if(file == NULL)//Se n�o encontrar, o CPf n�o estivar salvo
    {
        printf("O usu�rio n�o se encontra no sistema!.\n");//Exibindo mensagem de arquivo n�o encontrado
        system("pause");
    }else{// Caso  for encontrado arquivo declarado
        printf("O usuario foi deletado com sucesso!\n\n");// Delatado o CPF encotrado
        system("pause");// pausar sistema

    }

}

int main()
{
	int opcao=0;//Definindo a variável
	int laco =1;
	for(laco=1;laco=1;)
	{

	    system ("cls");

		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem


		printf("#####Cart�rio da EBAC#####\n\n");// Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
	 	printf("\t1-Registrar nomes\n");
	 	printf("\t2-Consultar nomes\n");
	 	printf("\t3-Deletar nomes nomes\n\n");//Final do menu
	 	printf("\t4-Sair do sistema!\n");
	 	printf("Op��o:");


		scanf("%d",&opcao);

		system("cls");// Responsavel por limpar a tela

		switch(opcao) // Inicio da sele��o do menu
		{
			case 1:
            registro();// chamada de fun��es

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
			printf("Essa op��o n�o est� disponivel");//Fim da sele��o
			system("pause");
			break;


		}

	}
}



