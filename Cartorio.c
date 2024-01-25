#include <stdio.h> // biblioteca de comunicaÃ§Ã£o com o usuário
# include <stdlib.h>//biblioteca de alocaÃ§Ã£o em memoria
#include <locale.h> //biblioteca de alocações de texto por região

int registro()//função responsavel por cadasttrar os usuários no sistema
// inicio criação das variáveis/strings
{   char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação das variáveis


    printf("Digigte o CPF a ser cadstrado: ");//coletando informações do usuário
    scanf("%s",cpf);//reponsavel por criar os valores da string

    strcpy (arquivo, cpf); // responsavel por copiar os valores da string

    FILE *file;// cria o arquivo
    file = fopen(arquivo,"w");// O "w"  significa criar um arquivo e escrever
    fprintf(file,cpf);//salvo o valor na variavel
    fclose(file);// fecho o arquivo


    file = fopen(arquivo,"a");// esse "a" é para atualizar a informação
    fprintf(file,",");//ponntar e separar os dados
    fclose(file);//fechando arquivo


    printf("Digite o nome a ser cadastrado: ");//coletando informações do usuário
    scanf("%s",nome);// %s refer-se a crisção de strings

    file = fopen(arquivo,"a");// abrindo o arquivo para atualizar
    fprintf(file,nome);//salvar o valor da variável
    fclose(file);//fechando arquivo


    file = fopen(arquivo,"a");// abrindo o arquivo para atualizar
    fprintf(file,","); // salvando o arquivo
    fclose(file);//fechando o arquivo

    printf("Digite o sobrenome a ser cadastrado: ");//coletando informações
    scanf("%s",sobrenome);// Criação da string

    file = fopen(arquivo,"a");//abrindo arquivo para atualizar
    fprintf(file,sobrenome);// salvando arquivo
    fclose(file);//fechando arquivo

    file = fopen(arquivo,"a");//abrindo arquivo para atualizar
    fprintf(file,",");//salvando o arquivo
    fclose(file);//fechar o arquivo

    printf("Digite  o cargo a ser cadastrado: ");// Coletando arquivo
    scanf("%s",cargo); // criando string

    file = fopen(arquivo,"a");// Abrindo arquivo
    fprintf(file,cargo); // Salvando variável
    fclose(file);//fechando arquivo

    system("pause");//Comando para pausar programa









}
int consulta()
{
    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem

    //Declarando variáveis no escopo local
    char cpf[40];
    char conteudo[200];
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    //finalizando a declaraçaõ das variaveis



    FILE * file;//Criar arquivo
    file = fopen(cpf,"r");//esse "r" é para ler o aquivo

    if(file == NULL)//verificação para consultar dados dos usuários
    {
        printf("Não é possível abrir o arquivo, não localizado!.\n");

    }

    while(fgets(conteudo,200,file) != NULL)//laco de repetiçao para procurar os dados dos usuários
    {
        printf("\nEssas são as informações do usuário:\n");
        printf("%s\n",conteudo,"\n");//Exibindo informações dos usuários
        printf("\n\n");// Salar linha 2x

    }

    system("pause");// pausar programa


}

int deletar()//Função ára deletar dados/ liberção de espaço
{
    //declarando as variáveis
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: "); //informar informações para deletar
    scanf("%s",cpf);// escaneando arquivo

    remove(cpf);// removendo CPF salvo

    FILE * file;// Acessando arquivo
    file = fopen(cpf,"r");//abrindo arquivo para ler

    if(file == NULL)//Se não encontrar, o CPf não estivar salvo
    {
        printf("O usuário não se encontra no sistema!.\n");//Exibindo mensagem de arquivo não encontrado
        system("pause");
    }else{// Caso  for encontrado arquivo declarado
        printf("O usuario foi deletado com sucesso!\n\n");// Delatado o CPF encotrado
        system("pause");// pausar sistema

    }

}

int main()
{
	int opcao=0;//Definindo a variÃ¡vel
	int laco =1;
	for(laco=1;laco=1;)
	{

	    system ("cls");

		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem


		printf("#####Cartório da EBAC#####\n\n");// Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
	 	printf("\t1-Registrar nomes\n");
	 	printf("\t2-Consultar nomes\n");
	 	printf("\t3-Deletar nomes nomes\n\n");//Final do menu
	 	printf("\t4-Sair do sistema!\n");
	 	printf("Opção:");


		scanf("%d",&opcao);

		system("cls");// Responsavel por limpar a tela

		switch(opcao) // Inicio da seleção do menu
		{
			case 1:
            registro();// chamada de funções

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
			printf("Essa opção não está disponivel");//Fim da seleção
			system("pause");
			break;


		}

	}
}



