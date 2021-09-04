#define _CRT_SECURE_NO_WARNINGS#include <stdio.h>

#include <string.h>

#include <locale.h>

#include <ctype.h>

int main() {
  setlocale(LC_ALL, "rus");
  int j, len_str;
  char d[4];
  printf("Введите 3 цифры без пробелов");
  scanf("%s", d);
  len_str = strlen(d);
  if (len_str != 3) {
    fprintf(stderr, "Неверная длина строки : (\n");
    return 1;
  }
  for (j = 0; j < len_str; j++) {
    if (!isdigit(d[j])) {
      fprintf(stderr, "Не число!\n");
      return 1;
    }
  }
  printf(" %s становится", d);
  __asm {
    mov al, d[0];
    mov dl, al;
    mov ah, 0;
    sub ax, '0';
    mov bl, 5;
    div bl;
    al - частное, ah - остаток
    mov bl, d[1];
    mov bh, 0;
    sub bx, '0';
    cmp bl, al;
    jne fin
    mov bl, d[2];
    mov bh, 0;
    sub bx, '0';
    cmp bl, ah;
    jne fin
    cmp dl, '0';
    je quit
    sub dl, 1;
    mov d[0], dl;
    jmp quit
    fin:
      mov d[1], dl;
    mov d[2], dl;
    quit:
      nop
  }
  printf("%s\n", d);
  return 0;
}
