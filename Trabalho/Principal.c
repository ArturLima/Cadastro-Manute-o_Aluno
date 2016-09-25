#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include "Menu.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Arvore * arv = criar();
	
    menu_principal(arv);
	
	
	
	getch();
	return 0;
}
