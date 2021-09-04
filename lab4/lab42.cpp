#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <cstdlib>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	setlocale(LC_NUMERIC, "en");
	unsigned int res;
	short a[16] = {-1000, -2000, -3000, -4, -6, -
		7, 0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000
	};
	short b[16] = {-3000, -2000, -1000, 0, -1, -
		2, 3, 1000, 1000, 2000, 2000, 6000, 6000, 8000, 8000, 9000
	};
	unsigned int c[16];
	printf("Исходные массивы:\n");
	for (unsigned int i = 0; i < 16; i++)
	{
		printf("A.%.2d=%d\tB.%.2d=%d\n", i, (int) a[i], i, (int) b[i]);
	}
	_asm
	{
		lea esi, a	// esi - указатель на элементы массива a
		lea edi, b	// edi - указатель на элементы массива b
		xor ebx, ebx	// ebx - счетчик элементов в массиве c
		xor ecx, ecx	// ecx = 0, номер элемента массива число
		элементов массивов
		m2:
			mov ax, [esi]	// Берем очередной элемент массива a
		cmp ax, [edi]	// Сравниваем с очередным элементом
		массива b
		jle m1	// Меньше или равно, ничего делать
		не надо
		// a > b
		mov c[ebx *4], esi	// Если надо сохранять абсолютный адрес массива a
		// mov byte ptr c[ebx *4], cl	// Заносим смещение
		элементов относительно начала массива в массив c
		inc ebx	// ebx++ - следующий элемент
		массива c
		mov dx, [edi]	// меняем местами элементы массивов a и b
		mov[edi], ax
		mov[esi], dx
		m1:
			add esi, 2	// esi+=2 следующий элемент массива a
		add edi, 2	// edi+=2 следующий элемент массива b
		add ecx, 2	// ecx+=2 увеличение счетчика
		cmp cl, 32	// cl = 32?
		jnz m2	// Нет. Следующая итерация
		mov res, ebx	// res = число обменов
	}
	printf("Результат:\nЧисло обменов: %d\n", res);
	for (unsigned int i = 0; i < 16; i++)
	{
		printf("A.%.2d=%d\tB.%.2d=%d\n", i, (int) a[i], i, (int) b[i]);
	}
	for (unsigned int i = 0; i < res; i++)
	{
		printf("C.%.2d=%X\n", i, c[i]);
	}
	system("pause");
}