/*
 * teste_ponteiros_lista_ligada.c
 *
 * Copyright 2012 emp.justine <emp.justine@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct tipo_um_no {
  struct tipo_um_no *proximo;
  int conteudo;
} um_no;

typedef struct tipo_uma_lista {
  um_no *cabeca_da_lista;
  um_no *pe_da_lista;
} uma_lista;

uma_lista* preparar_minha_lista() {
  uma_lista *nova_lista;
  nova_lista = NULL;

  nova_lista = malloc(sizeof(uma_lista));

  if (nova_lista != NULL) {
    nova_lista -> cabeca_da_lista = NULL;
    nova_lista -> pe_da_lista = NULL;
  }
  else {
    printf("\nOH CRAP NO LIST HEAD ALLOCATED!\n");
  }
  return nova_lista;
}

um_no* alocar_um_no() {
  um_no *novo_no;
  novo_no = NULL;

  novo_no = malloc(sizeof(um_no));

  if (novo_no != NULL) {
    novo_no -> proximo = NULL;
    novo_no -> conteudo = 42;
  }
  else {
    printf("\nOH CRAP NO LIST NODE ALLOCATED!\n");
  }
  return novo_no;
}

um_no* adicionar_no_pe(uma_lista *lista_alvo) {

  /* existe */
  if (lista_alvo != NULL) {

    /* sem pe */
    if (lista_alvo -> pe_da_lista == NULL) {
      lista_alvo -> pe_da_lista = alocar_um_no();
    }
    /* com pe, deslocando o pe */
    else {
      lista_alvo -> pe_da_lista -> proximo = alocar_um_no();
      lista_alvo -> pe_da_lista = lista_alvo -> pe_da_lista -> proximo;
    }

    /* completa informacao da cabeca se faltando */
    if (lista_alvo -> cabeca_da_lista == NULL) {
      lista_alvo -> cabeca_da_lista = lista_alvo -> pe_da_lista;
    }

    return lista_alvo -> pe_da_lista;
  }
  else {
  /* escape de emergencia*/
    printf("\nOH CRAP NO LIST HEAD TO ADD NODE!\n");
    return NULL;
  }
}

void obliterar_lista(uma_lista *lista_alvo) {
  um_no *cursor;
  cursor = NULL;

  if (lista_alvo != NULL) {
    while(lista_alvo -> cabeca_da_lista != NULL) {
      /* guarda o proximo no */
      cursor = lista_alvo -> cabeca_da_lista -> proximo;
      /* apaga o no na cabeca */
      free(lista_alvo -> cabeca_da_lista);
      lista_alvo -> cabeca_da_lista = NULL;
      /* anda pro proximo no */
      lista_alvo -> cabeca_da_lista = cursor;
    }
  }

  free(lista_alvo);
  lista_alvo = NULL;
}

int main(int argc, char **argv)
{
  uma_lista *raiz_da_lista;
  um_no *temporario;

  raiz_da_lista = preparar_minha_lista();

  temporario = adicionar_no_pe(raiz_da_lista);
  temporario -> conteudo = 20;

  temporario = adicionar_no_pe(raiz_da_lista);
  temporario -> conteudo = 404;

  temporario = adicionar_no_pe(raiz_da_lista);
  temporario -> conteudo = 1337;

  printf("\n|%i|\n", raiz_da_lista -> cabeca_da_lista -> conteudo);
  printf("\n|%i|\n", raiz_da_lista -> cabeca_da_lista -> proximo -> conteudo);
  printf("\n|%i|\n", raiz_da_lista -> pe_da_lista -> conteudo);

  obliterar_lista(raiz_da_lista);

  return 0;
}

