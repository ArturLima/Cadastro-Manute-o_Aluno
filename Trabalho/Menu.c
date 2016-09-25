#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <time.h>
#include "Menu.h"


void menu_principal(Arvore * arv){
     int escolha;
     printf("\n\n\t\t\t--- Kappa Producoes---");
     printf("\n\n\t\t Trabalho de Estrutura de Dados 2");
     printf("\n\n\t\t0.1 Cadastro de aluno");
     printf("\n\n\t\t0.2 sair");
     printf("\n\n\t\t Escolha uma opcao: ");
     scanf("%d", &escolha);

     switch(escolha){
          case 1:
               system("cls");
          menu_cadastro(arv);
          break;

          case 2:
          exit(0);
          break;

          default:
          printf("\n\n\t\t tecla errada, tente outra vez");
          break;
     }
}

void menu_cadastro(Arvore * arv){
     int escolha;
     printf("\n\n\t\t0.1 Carregar os alunos");
     printf("\n\n\t\t0.2 Inserir um novo Aluno");
     printf("\n\n\t\t0.3 Listar os dados de todos os alunos por ordem");
     printf("\n\n\t\t0.4 Listar os dados dos alunos em um arquivo");
     printf("\n\n\t\t0.5 Consultar dados do aluno");
     printf("\n\n\t\t0.6 Alterar os dados");
     printf("\n\n\t\t0.7 Remover Aluno");
     printf("\n\n\t\t0.8 Remover dados dos alunos por matricula");
     printf("\n\n\t\t0.9 Remover todos os alunos");
     printf("\n\n\t\t10.0 Salvar os alunos");
     printf("\n\n\t\t11.0 Sair");
     printf("\n\n Escolha uma opcao: ");
     scanf("%d", &escolha);
     switch(escolha){
     case 1:
          system("cls");
          clock_t inicio = clock();
          printf(" Loading...");
          carregar_dados(arv);
          clock_t fim = clock();
          double tempo = ((fim - inicio) * 1000) /CLOCKS_PER_SEC;
           printf(" \n duracao: %.0lf ms", tempo);
           getch();
           system("cls");
           menu_cadastro(arv);
		  break;
     case 2:
          system("cls");
          inserir_aluno(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 3:
          system("cls");
          listar_dados_todos(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 4:
          system("cls");
          listar_dados_arquivo(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 5:
          system("cls");
          consultar_dado(arv);
          getch();
          system("cls");
           menu_cadastro(arv);
          break;
     case 6:
          system("cls");
          alterar_dado(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 7:
          system("cls");
          remover_aluno(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 8:
          system("cls");
          remover_aluno_arquivo(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 9:
     	  system("cls");
          remover_todos_aluno(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 10:
          system("cls");
          salvar_aluno(arv);
          getch();
          system("cls");
          menu_cadastro(arv);
          break;
     case 11:
    		exit(0);

     default:
        system("cls");
        printf("Tecla errada, tente novamente!");
        system("pause");
        system("cls");
        return menu_cadastro(arv);
        break;
     }
}
//pegar dados da string
char ** pegar_dados(char * string){

		char ** dados;
		char * nome;
        char * matricula;
		char * email;
		char * telefone;
		int i, j;

		dados = (char **) malloc(4* sizeof(char*));
		nome = (char *) malloc(40 * sizeof(char));
		matricula = (char *) malloc(10 * sizeof(char));
		email = (char *) malloc(40 * sizeof(char));
		telefone = (char *) malloc(10 * sizeof(char));

		//pegar nome
		for (i = 0, j = 0; string[i] != '|'; i++, j++)
		    nome[j] = string[i];
        nome[--j] = '\0';
        dados[0] = nome;

		// pegar a matricula
		for (i += 13, j = 0; string[i] != ' '; i++, j++)
		    matricula[j] = string[i];
		matricula[j] = '\0';
		dados[1] = matricula;

		// pegar o email
		for (i += 3, j = 0; string[i] != ' '; i++, j++)
		    email[j] = string[i];
		email[j] = '\0';
		dados[2] = email;

		// pegar o telefone
		for (i += 3, j = 0; string[i] != '\n'; i++, j++)
		    telefone[j] = string[i];
		telefone[j] = '\0';
		dados[3] = telefone;
		//printf("%s %s %s %s\n",nome, matricula, email, telefone );
		return dados;
}
//1
void carregar_dados(Arvore * arv){
	FILE * arquivo;
	char string[100];
	char ** dados;

	arquivo = fopen("C:\\Users\\Artur\\Desktop\\dados\\BDAlunos10e1v1.txt", "r");

	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
	}
    else{

		while( (fgets(string, sizeof string, arquivo))!=NULL ){

			dados = pegar_dados(string);
			inserir(arv, atoi(dados[1]),dados[1], dados[0],dados[2],dados[3]);
			//free(dados);
            }
	}
	fclose(arquivo);


}
//2
void inserir_aluno(Arvore * arv){
	char * nome, * email, * telefone, * matricula;
	char str[7];
	int i;
	nome = (char *) malloc(40 * sizeof(char));
	matricula = (char *) malloc(20 * sizeof(char));
	email = (char *) malloc(40 * sizeof(char));
	telefone = (char *) malloc(20 * sizeof(char));
	
	printf("digite um nome:\n");
	scanf("%s", nome);
	fflush(stdin);
	
	printf("digite um email:\n");
	scanf("%s", email);
	fflush(stdin);
	
	printf("digite um telefone:\n");
	scanf("%s", telefone);
	fflush(stdin);
	
	matricula[0] = '\0';
    sprintf(str, "%d", maior_matricula(arv) + 1);

    for (i = 0; i < (7 - strlen(str)); i++)
        strcat(matricula, "0");
        strcat(matricula, str);
        
	inserir(arv, maior_matricula(arv) + 1,matricula, nome, email, telefone);
	
	
}
//3
void listar_dados_todos(Arvore * arv){
	 printf("\n \tNome \t\tMatricula \tE-mail \t\t\tTelefone \n\n");
    imprimir(arv);
}
//4
void listar_dados_arquivo(Arvore * arv){
	FILE * arquivo;
	char string[100];
	char ** dados;
	

	arquivo = fopen("C:\\Users\\Artur\\Desktop\\dados\\PesqAlunos10e1.txt", "r");

	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
	}
    else{
		while( (fgets(string, sizeof string, arquivo))!=NULL ){
				dados = buscar(arv, atoi(string));
				if(dados == NULL){
					printf("nao encontrado %d \n", atoi(string));
				}
				else{
				printf(" %s"" %s"" %s"" %s\n", dados[0],dados[1],dados[2],dados[3]);
				}
            }
	}
	fclose(arquivo);
}
//5
void consultar_dado(Arvore * arv){
	char ** dados = NULL;
	int matricula;
	printf("insira a matricula que quer buscar:\n");
	scanf("%d", &matricula);
	
	dados = buscar(arv, matricula);
	if( dados == NULL){
		printf("nao encontrado!");
	}
	else{
		printf(" %s"" %s"" %s" " %s", dados[0], dados[1], dados[2], dados[3]);
	}
	getch();
}
//6
void alterar_dado(Arvore * arv){
	int matricula, escolha;
	char ** dados;
	char nome[30], email[30], telefone[10];
	
	
	printf("digite a matricula do aluno:\n");	
	scanf("%d", &matricula);
	
	dados = buscar(arv, matricula);
	
	printf("O que deseja alterar?\n");
	printf("0.1 nome\n");
	printf("0.2 email\n");
	printf("0.3 telefone\n");
	scanf("%d", &escolha);
	switch(escolha){
		case 1: 
			printf("Novo nome:\n");
			scanf("%s",nome);
			strcpy(dados[0], nome);
			break;
		case 2: 
			printf("Novo email:\n");
			scanf("%s",email);
			strcpy(dados[2], email);
			break;
		case 3: 
			printf("Novo telefone:\n");
			scanf("%s",telefone);
			strcpy(dados[3], telefone);
			break;
		
	}
	
}
//7
void remover_aluno(Arvore * arv){
	int matricula;
	
	printf("Digite uma matricula:");
	scanf("%d", &matricula);
	if(matricula < 1){
		printf("Erro");
	}else{
		remover(arv, matricula);
	}
	
	
}
//8
void remover_aluno_arquivo(Arvore * arv){
	FILE * arquivo;
	char string[100];
	char ** dados;

	arquivo = fopen("C:\\Users\\Artur\\Desktop\\dados\\PesqAlunos10e1.txt", "r");

	if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo\n");
	}
    else{

		while( (fgets(string, sizeof string, arquivo))!=NULL ){

				remover(arv, atoi(string));
            }
            printf("Remocao completa");
	}
	fclose(arquivo);
}
//9
void remover_todos_aluno(Arvore * arv){
	int i;
	int j = maior_matricula(arv);
	
	for(i= menor_matricula(arv); i <= j; i++){
		remover(arv,i);
	}
	printf("Remocao com sucesso");
}
//10
void salvar_aluno(Arvore * arv){
	FILE * arquivo;
	char ** dados;
	int j = maior_matricula(arv);
	int i;

	arquivo = fopen("C:\\Users\\Artur\\Desktop\\dados\\teste.txt", "w");
		if(arquivo == NULL){
			printf("Erro, nao foi possivel abrir o arquivo!");
		}
		else{
			for(i= menor_matricula(arv); i <= j; i++){
				dados = buscar(arv, i);
				if(dados != NULL){
				fprintf(arquivo, dados[0]);
				fprintf(arquivo, "\t");
				fprintf(arquivo, dados[1]);
				fprintf(arquivo, "\t");
				fprintf(arquivo, dados[2]);
				fprintf(arquivo, " ");
				fprintf(arquivo, dados[3]);
				fprintf(arquivo, "\n\0");
				}
			}
			printf("Salvo!");
		}
		
		
	fclose(arquivo);

}
