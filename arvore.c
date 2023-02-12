/*
 * arvore.c
 * Classe de implemantação da ED Árvore Clássica.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *raiz = NULL;

void setRaiz(No *no) {
	raiz = no;
}

No* getRaiz() {
	return raiz;
}

No* criar_no(No *pai, char elemento) {

	No *no = malloc(sizeof(No));
	no->valor = elemento;
	no->pai = pai;
	no->filho1 = NULL;
	no->filho2 = NULL;
	no->filho3 = NULL;

	return no;
}

void criar_raiz(char elemento) {

	if (raiz == NULL) {

		raiz = criar_no(NULL, elemento);
	} else {
		printf("Raiz já foi criada\n");
	}
}

void insert(No *raiz, char pai, char elemento) {

	if (raiz == NULL) {
		printf("Raiz nula. Insert de nó não permitido!\n");
		return;
	}

	No *no_pai = search(raiz, pai);

	if (no_pai != NULL) { /*I*/

		if (no_pai->filho1 == NULL) {
			no_pai->filho1 = criar_no(no_pai, elemento);
		} else if (no_pai->filho2 == NULL) {
			no_pai->filho2 = criar_no(no_pai, elemento);
		} else if (no_pai->filho3 == NULL) {
			no_pai->filho3 = criar_no(no_pai, elemento);
		} else {
			printf("O nó %c não possui mais filhos disponíveis.\n", pai);
		}
	} else {
		printf("O nó pai %c não pertence a árvore.\n", pai);
	}
}

No* search(No *no, char elemento) {

	if (no != NULL) {

		if (no->valor == elemento) {
			return no;
		} else {

			No *no_procurado;

			no_procurado = search(no->filho1, elemento);
			if (no_procurado != NULL)
				return no_procurado;

			no_procurado = search(no->filho2, elemento);
			if (no_procurado != NULL)
				return no_procurado;

			no_procurado = search(no->filho3, elemento);
			if (no_procurado != NULL)
				return no_procurado;

		}
	}
	return NULL;
}

void update(No *raiz, char elemento, char novo_valor) {

	No *no = search(raiz, elemento);

	if (no != NULL) {
		no->valor = novo_valor;
	} else {
		printf("Nó não encontrado. Impossível realizar update.");
	}
}

void delete(No *no) {

	No *pai = no->pai;

	delete_subtree(no);

	if (pai != NULL) {

		if (pai->filho1 == no) {
			pai->filho1 = NULL;
		}
		if (pai->filho2 == no) {
			pai->filho2 = NULL;
		}
		if (pai->filho3 == no) {
			pai->filho3 = NULL;
		}
	}
}

void delete_subtree(No *no) {

	if (no != NULL) {

		delete_subtree(no->filho1);
		delete_subtree(no->filho2);
		delete_subtree(no->filho3);

		free(no);
		no = NULL;
	}
}

void exibir_pre_ordem(No *no) {

	if (no != NULL) {

		printf("%c ", no->valor);
		exibir_pre_ordem(no->filho1);
		exibir_pre_ordem(no->filho2);
		exibir_pre_ordem(no->filho3);
	}

}
