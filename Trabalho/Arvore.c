#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

typedef struct no No;

struct arvore {
	No * raiz;
};

struct no {
	int info;
	char * matricula;
	char * nome;
	char * email;
	char * telefone;
	No * esq;
	No * dir;
};

Arvore * criar() {
   Arvore * a = malloc(sizeof(Arvore));
   a->raiz = NULL;
   return a;
}
//FEITO
void destruirNos(No * n){
    if(n != NULL) {
        destruirNos(n->esq);
        destruirNos(n->dir);
        free(n);
    }
}

void destruir(Arvore * a) {
	destruirNos(a->raiz);
	free(a);
}

void pre_ordem(No * raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->info);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}
//FEITO
void in_ordem(No * raiz) {
	if (raiz != NULL) {
		in_ordem(raiz->esq);
		//printf("%d ", raiz->info);
		in_ordem(raiz->dir);
	}
}
//FEITO
void pos_ordem(No * raiz) {
	if (raiz != NULL) {
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%s", raiz->nome);
		printf("%d ", raiz->info);
		printf("%s", raiz->email);
		printf("%s", raiz->telefone);
	}
}

int contar_nos_rec(No * raiz) {
	if (raiz != NULL) {
		return contar_nos_rec(raiz->esq) +
			   contar_nos_rec(raiz->dir) +
		       1;
	}
	return 0;
}

int contar_nos(Arvore * arv) {
	return contar_nos_rec(arv->raiz);
}

int contar_folhas_rec(No * raiz) {
	if (raiz != NULL) {
		if (raiz->esq != NULL || raiz->dir != NULL) {
			return contar_folhas_rec(raiz->esq)+
			   	   contar_folhas_rec(raiz->dir);
	    }
	    return 1;
	}
	return 0;
}

int contar_folhas(Arvore * arv) {
	return contar_folhas_rec(arv->raiz);
}

int altura_rec(No * raiz) {
	if (raiz != NULL) {
		int ae = altura_rec(raiz->esq);
		int ad = altura_rec(raiz->dir);
		return (ae > ad ? ae : ad) + 1;
	}
	return -1;
}

int altura(Arvore * arv) {
	
	return altura_rec(arv->raiz);
}

void in_ordem_rec(No * raiz){
	if(raiz != NULL){
		char ** dados;
		 in_ordem_rec(raiz->esq);
		 
		 	dados = (char**) malloc(4*sizeof(char*));
		 	dados[0] = raiz->nome;
        	dados[1] = raiz->matricula;
        	dados[2] = raiz->email;
        	dados[3] = raiz->telefone;
		 printf("\t%s \t%s \t%s \t%s \n", dados[0], dados[1], dados[2], dados[3]);
		 in_ordem_rec(raiz->dir);
	}
}
//FEITO
void imprimir(Arvore * arv) {
	if(arv->raiz == NULL)
		printf("\tCarregue a arvore para ver!\n");
	else
		in_ordem_rec(arv->raiz);

	printf("\n");
}

void impnvl_rec(No * raiz, int nvl) {
  if (raiz != NULL) {
     if (nvl == 0) {
	 	printf("%d ", raiz->info);
	 } else {
	     impnvl_rec(raiz->esq, nvl-1);
	     impnvl_rec(raiz->dir, nvl-1);
	 }
  }
}

void imprimir_nivel(Arvore * arv, int nvl) {
	impnvl_rec(arv->raiz, nvl);
	printf("\n");
}

int impalt_rec(No * raiz, int nvl) {
  if (raiz != NULL &&
      (nvl == 0 || impalt_rec(raiz->esq, nvl-1) ||
	               impalt_rec(raiz->dir, nvl-1))
	 ) {
 	printf("%d ", raiz->info);
 	return 1;
  }
  return 0;
}

void imprimir_alt(Arvore * arv) {
	impalt_rec(arv->raiz, altura(arv));
	printf("\n");
}
//FEITO
void inserir_rec(No * * praiz, int infor, char * matricula, char * nome, char * email,char * telefone) {
	No * raiz = *praiz;
	if (raiz != NULL) {
		if (infor < raiz->info) {
			inserir_rec(&raiz->esq, infor, matricula, nome, email, telefone);
		}
		if (infor > raiz->info) {
			inserir_rec(&raiz->dir, infor, matricula, nome, email, telefone);
		}
	} else {
		raiz = (No*)malloc(sizeof(No));
		raiz->info = infor;
		raiz->matricula = matricula;
        raiz->nome = nome;
		raiz->email= email;
		raiz->telefone = telefone;
		raiz->esq = NULL;
		raiz->dir = NULL;
		*praiz = raiz;
	}
}
//FEITO
void inserir(Arvore * arv, int infor, char * matricula, char * nome, char * email, char * telefone) {
	//arv->raiz = inserir_rec(arv->raiz, v);
	inserir_rec(&arv->raiz, infor, matricula, nome, email, telefone);
	/*No * ant = NULL, * raiz = arv->raiz;
	while (raiz != NULL && raiz->info != matricula) {
		ant = raiz;
		raiz = matricula < raiz->info ? raiz->esq : raiz->dir;
	}
	if (raiz == NULL) {
		raiz = malloc(sizeof(No));
		raiz->nome = nome;
		raiz->info = matricula;
		raiz->email= email;
		raiz->telefone = telefone;
		raiz->esq = NULL;
		raiz->dir = NULL;
		if (ant != NULL) {
			if (matricula < ant->info) {
				ant->esq = raiz;
			} else {
				ant->dir = raiz;
			}
		} else {
			arv->raiz = raiz;
		}
	}*/
}
//FEITO
char** buscar_rec(No * raiz, int info) {
	if (raiz != NULL) {
		if (info < raiz->info) {
			return buscar_rec(raiz->esq, info);
		}
		if (info > raiz->info) {
			return buscar_rec(raiz->dir, info);
		}

        char ** dados_do_aluno = (char**) malloc(4*sizeof(char*));

        dados_do_aluno[0] = raiz->nome;
        dados_do_aluno[1] = raiz->matricula;
        dados_do_aluno[2] = raiz->email;
        dados_do_aluno[3] = raiz->telefone;

		return dados_do_aluno;
	}
	return NULL;
}

//FEITO
char** buscar(Arvore * arv, int info) {
	return buscar_rec(arv->raiz, info);
	/*
    No * raiz = arv->raiz;
	while (raiz != NULL && raiz->info != info) {
		raiz = info < raiz->info ? raiz->esq : raiz->dir;
	}
	return raiz != NULL;
	*/
}
//FEITO
No * remover_maior_rec(No * * praiz) {

	No * raiz = *praiz;
	if (raiz->dir != NULL) {
		return remover_maior_rec(&raiz->dir);
	}
	*praiz = raiz->esq;
	return raiz;
}
//FEITO
No * remover_menor_rec(No * * praiz) {

	No * raiz = *praiz;
	if (raiz->esq != NULL) {
		return remover_menor_rec(&raiz->esq);
	}
	*praiz = raiz->dir;
	return raiz;

 /*  //NÃO REC
    int me;
	No * ant = NULL, * raiz = *praiz;
	while (raiz->esq != NULL) {
		ant = raiz;
		raiz = raiz->esq;
	}
	if (ant != NULL) {
		ant->esq = raiz->dir;
	} else {
		*praiz = raiz->dir;
	}
	me = raiz->info;
	free(raiz);
	return me;*/


}
//FEITO
void remover_rec(No * * praiz, int v) {
	No * raiz = *praiz;
	if (raiz != NULL) {
		if (v < raiz->info) {
			remover_rec(&raiz->esq, v);
		} else
		if (v > raiz->info) {
			remover_rec(&raiz->dir, v);
		} else {
			//Folha
			if (raiz->esq == NULL && raiz->dir == NULL) {
				*praiz = NULL;
				free(raiz->nome);
				free(raiz->matricula);
				free(raiz->email);
				free(raiz->telefone);
				free(raiz);
			} else {
				//Dois filhos
				if (raiz->esq != NULL && raiz->dir != NULL)  {
					//raiz->info = remover_maior_rec(&raiz->esq);
					 *praiz = remover_menor_rec(&raiz->dir);
					 (*praiz)->dir = raiz->dir;
					 (*praiz)->esq = raiz->esq;

				} else { //Um filho
					if (raiz->esq != NULL)  {
						*praiz = raiz->esq;
					} else {
						*praiz = raiz->dir;
					}
					free(raiz->nome);
				    free(raiz->matricula);
                    free(raiz->email);
				    free(raiz->telefone);
					free(raiz);

				}
			}
		}
	}
}
//ALTERAR
void ajustar_ant(Arvore * arv, No * ant, int v, No * no) {
	if (ant != NULL) {
		if (v < ant->info) {
			ant->esq = no;
		} else {
			ant->dir = no;
		}
	} else {
		arv->raiz = no;
	}
}
//FEITO
void remover(Arvore * arv, int info) {
	remover_rec(&arv->raiz, info);
	/*No * ant = NULL, * raiz = arv->raiz;
	while (raiz != NULL && raiz->info != v) {
		ant = raiz;
		raiz = v < raiz->info ? raiz->esq : raiz->dir;
	}
	if (raiz != NULL) {
		//Folha
		if (raiz->esq == NULL && raiz->dir == NULL) {
			ajustar_ant(arv, ant, v, NULL);
			free(raiz);
		} else {
			//Dois filhos
			if (raiz->esq != NULL && raiz->dir != NULL)  {
				//raiz->info = remover_maior(&raiz->esq);
				raiz->info = remover_menor(&raiz->dir);
			} else { //Um filho
				if (raiz->esq != NULL)  {
					ajustar_ant(arv, ant, v, raiz->esq);
				} else {
					ajustar_ant(arv, ant, v, raiz->dir);
				}
				free(raiz);
			}
		}
	}*/
}

//FEITO
int menor_matricula(Arvore * arv){
	No * raiz = arv->raiz;
	while (raiz->esq != NULL) {
		raiz = raiz->esq;
	}
	return raiz->info;
}
//FEITO
int maior_matricula(Arvore * arv){
	No * raiz = arv->raiz;
	while (raiz->dir != NULL) {
		raiz = raiz->dir;
	}
	return raiz->info;
}
