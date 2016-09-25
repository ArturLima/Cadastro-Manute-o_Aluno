typedef struct arvore Arvore;

Arvore * criar();


void destruir(Arvore * arv);


void imprimir(Arvore * arv);
void imprimir_nivel(Arvore * arv, int nvl);
void imprimir_alt(Arvore * arv);

int contar_nos(Arvore * arv);
int contar_folhas(Arvore * arv);
int altura(Arvore * arv);

char** buscar(Arvore * arv, int info);
void inserir(Arvore * arv, int info, char * matricula, char * nome, char * email,char * telefone);
void remover(Arvore * arv, int v);
int menor_matricula(Arvore * arv);
int maior_matricula(Arvore * arv);




