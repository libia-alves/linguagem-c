#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void menu(),cadastro(),cadastro_numero(),cadastro_email(),cadastro_data_de_nascimento(),ver_cadastro(),teste(),quest(),exit(),editar_contato(),excluir_contato();
int id,choice,CODIGO,escolha,escolha_edicao,escolha_edicao_novamente,id_escolha_excluir;
char nome[100],telefone[11],email[100],aniversario[10],novo_nome[100],novo_telefone[11],novo_email[100],novo_aniversario[100];
FILE * agenda;
FILE *pont_arq_pessoa;
void quest()
{
    printf("\nDigite caso:");
    printf("\n(0)->Deseja Voltar ao Menu Inicial");
    printf("\n(1)->Deseja sair \n->");
    scanf("%d",&choice);
    if (choice==0)
    {
        menu();
    }
    if (choice==1)
    {
        exit(1);
    }
    else
    {
    	printf("\nCodigo invalido!!!");
    	printf("\n------------------");
    	quest();
	}
}
int main()
{
  agenda = fopen("agenda.txt", "w+");
  fclose (agenda);
  menu();//inicio do codigo
}
void menu ()//void responsavel por abrir o menu principal
{
	setlocale(LC_ALL, "Portuguese");
    
    printf("---Bem vindo a agenda telefonica---\n\n");
    printf(" ------------------\n|1-Cadastrar   |\n|2-Consultar    |\n|3-Editar   |\n|4-Excluir    |\n|5-Sair            |\n ------------------");
    printf("\nDIGITE UM CODIGO:");
    scanf("%d",&CODIGO);
    //tabela de açoes
    while (1)
    {
    if (CODIGO==1)
    {
        cadastro();//redireciona ao inicio do cadastro
    }
    if (CODIGO==2)
    {
        ver_cadastro();
	}
	if (CODIGO==3)
	{
		editar_contato();
	}
	if (CODIGO==4)
	{
		excluir_contato();
	}
	if (CODIGO==5)
	{
		exit(1);
	}
	else 
	{
		printf("\nCodigo invalido!!\n");
		menu();
	}
    }
     quest();
    }
    


void cadastro ()
{
	id++;
    printf("--Cadastrando novo contato--\n");
    printf("Id: %d \n",id);
    printf("Nome:\n");
    scanf("%s",nome); 
    agenda = fopen("agenda.txt", "a+");                                             
    fprintf(agenda,"%d | %s |",id,nome);
    fclose (agenda);
    cadastro_numero();
}

void cadastro_numero()
{
	printf("\nTelefone:\n");
	scanf("%s",telefone);
    agenda = fopen("agenda.txt", "a+"); 
    fprintf(agenda," %s |",telefone);
    fclose(agenda);
    cadastro_email();
}

void cadastro_email()
{
	printf("\nEmail:\n");
	scanf("%s",email);
    agenda = fopen("agenda.txt", "a+"); 
    fprintf(agenda," %s |",email);
    fclose(agenda);
	cadastro_data_de_nascimento();
}

void cadastro_data_de_nascimento()
{
	printf("\nData de nascimento:\nSiga este modelo:\n-(00/00/0000)-\n");
	scanf("%s",aniversario);
	agenda = fopen("agenda.txt", "a+"); 
    fprintf(agenda," %s |\n",aniversario);
    fclose(agenda);
    printf("\n---Fim do cadastro---");
    quest();
}


typedef struct p
{
    int idPessoa;
	char nome[100];
    char numero[100];
    char email[100];
    char aniversario[10];
} PESSOA;

PESSOA listaPessoa[100];

void ver_cadastro()
{
    
    pont_arq_pessoa = fopen("agenda.txt", "a+");
    int contador_pessoa = 0;
    while((fscanf(pont_arq_pessoa,"%d | %s | %s | %s | %s |", &listaPessoa[contador_pessoa].idPessoa, listaPessoa[contador_pessoa].nome, listaPessoa[contador_pessoa].numero,listaPessoa[contador_pessoa].email,listaPessoa[contador_pessoa].aniversario))!=EOF )
    {
        contador_pessoa++;
    }
    
    int i;
    for(i=0; i<contador_pessoa;i++)
    {
        printf("%d | %s | %s | %s | %s |\n", listaPessoa[i].idPessoa, listaPessoa[i].nome, listaPessoa[i].numero, listaPessoa[i].email,listaPessoa[i].aniversario);
    }
    quest();
}

void editar_contato()
{
	int id_escolha; 
    pont_arq_pessoa = fopen("agenda.txt", "a+");
    int contador_pessoa = 0;
    while((fscanf(pont_arq_pessoa,"%d | %s | %s | %s | %s |", &listaPessoa[contador_pessoa].idPessoa, listaPessoa[contador_pessoa].nome, listaPessoa[contador_pessoa].numero,listaPessoa[contador_pessoa].email,listaPessoa[contador_pessoa].aniversario))!=EOF )
    {
        contador_pessoa++;
    }
    fclose (pont_arq_pessoa);
    printf("Digite o ID do contato que deseja editar:");
    scanf("%d",&id_escolha);
    int i;
    for(i=0; i<contador_pessoa;i++)
    {
    fscanf(pont_arq_pessoa,"%d | %s | %s | %s | %s |", &listaPessoa[i].idPessoa, listaPessoa[i].nome, listaPessoa[i].numero, listaPessoa[i].email,listaPessoa[i].aniversario);
    	if(listaPessoa[i].idPessoa==id_escolha)
    	{
    	   printf("%d | %s | %s | %s | %s |\n", listaPessoa[i].idPessoa, listaPessoa[i].nome, listaPessoa[i].numero, listaPessoa[i].email,listaPessoa[i].aniversario);
    	   printf("->Deseja editar este contato?<-");
    	   printf("\n(0)->Sim\n(1)->Nao\n->");
    	   scanf("%d",&escolha);
    	   if(escolha==0)
    	   {
    	   	printf("\nO que deseja editar?\n");
    	   	printf("(0)->Nome\n(1)->Numero de Telefone\n(2)->Email\n(3)->Data de Aniversario\n->");
    	   	scanf("%d",&escolha_edicao);
    	   	if(escolha_edicao==0)
    	   	{
    	   		printf("Nome atual:%s",listaPessoa[i].nome);
    	   		printf("\nDigite o novo nome:");
    	   		scanf("%s",novo_nome);
    	   		strcpy(listaPessoa[i].nome,novo_nome);	
			}
    	   	if(escolha_edicao==1)
    	   	{
    	   		printf("Numero atual:%s",listaPessoa[i].numero);
    	   		printf("\nDigite o novo numero:");
    	   		scanf("%s",novo_telefone);
    	   		strcpy(listaPessoa[i].numero,novo_telefone);
			}
			if(escolha_edicao==2)
			{
				printf("Email atual:%s",listaPessoa[i].email);
    	   		printf("\nDigite o novo email:");
    	   		scanf("%s",novo_email);
    	   		strcpy(listaPessoa[i].email,novo_email);
			}
			if(escolha_edicao==3)
			{
			    printf("Data de aniversario atual:%s",listaPessoa[i].aniversario);
    	   		printf("\nDigite a nova data:");
    	   		scanf("%s",novo_aniversario);
    	   		strcpy(listaPessoa[i].aniversario,novo_aniversario);	
			}
			printf("%d | %s | %s | %s | %s |\n", listaPessoa[i].idPessoa, listaPessoa[i].nome, listaPessoa[i].numero, listaPessoa[i].email,listaPessoa[i].aniversario);
			agenda = fopen("agenda.txt", "w+");
			for(i=0;i<contador_pessoa;i++)
			{
			 fprintf(agenda,"%d | %s | %s | %s | %s |\n", listaPessoa[i].idPessoa, listaPessoa[i].nome, listaPessoa[i].numero, listaPessoa[i].email,listaPessoa[i].aniversario);	
			}
			fclose(agenda);
			printf("\nDeseja editar mais algo?\n");
			printf("(0)->Sim\n");
			printf("(1)->Nao\n");
			scanf("%d",&escolha_edicao_novamente);
			if(escolha_edicao_novamente==0)
			{
				editar_contato();
			}
			if(escolha_edicao_novamente==1)
			{
				quest();
			}
		   }
		  else
		   {
		   	printf("\nCodigo invalido!!\n");
		   	quest();
		   }
		}
		
    }
    
    printf("\nID invalido!!");
    printf("\n-------------");
    printf("\nRecomenda-se consultar seus contatos no menu ´´VER CONTATOS´´");
    printf("\n-------------");
    quest();
}
void excluir_contato()
{
	int i,contador_pessoa;
	printf("\nDigite o ID do contato que deseja excluir:");
	scanf("%d",&id_escolha_excluir);
	agenda = fopen ("agenda.txt", "r");
	while((fscanf(agenda,"%d | %s | %s | %s | %s |", &listaPessoa[contador_pessoa].idPessoa, listaPessoa[contador_pessoa].nome, listaPessoa[contador_pessoa].numero, listaPessoa[contador_pessoa].email, listaPessoa[contador_pessoa].aniversario))!=EOF )
    {
        contador_pessoa++;
    }
    fclose(agenda);
    agenda = fopen("agenda.txt", "w+");
			for(i=0;i<contador_pessoa;i++)
			{
			if (id_escolha_excluir != listaPessoa[i].idPessoa && listaPessoa[i].idPessoa != 0 )
			{
			
			 fprintf(agenda,"%d | %s | %s | %s | %s |\n", listaPessoa[i].idPessoa, listaPessoa[i].nome, listaPessoa[i].numero, listaPessoa[i].email, listaPessoa[i].aniversario);	
		    }
			}
			fclose(agenda);
	
   quest();
}



