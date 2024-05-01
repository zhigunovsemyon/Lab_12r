/*
	Одноклеточная амеба каждые три часа делится на две клетки.
	Определить, сколько клеток будет через 3, 6, 9, … 24 часа.
	Решить данную задачу с помощью рекурсии

	Тестовые данные
	Исходное число клеток	Клеток через 24 часа
	10						2560
	0						0
	-1						Должно быть положительным
*/
#define _CRT_SECURE_NO_WARNINGS
#define NOERRORS 0
#include <stdio.h>

#define CELL_DIVIDE 2
int Ameba_Unwrap(int cells, int hours, int level, int time_step, int cell_divide, int end_time);
int Ameba(int cells, int time_step, int cell_divide, int end_time);
int GetCells(void);
int GetEndTime(void);
int GetTimeStep(void);

int main(void)
{
	int endTime = GetEndTime();
	//Вывод конечного результата, запуск рекурсии
	printf("\nИТОГО: через %d часа %d клеток\n", endTime,
		Ameba(GetCells(), GetTimeStep(), CELL_DIVIDE, endTime));
	return NOERRORS;
}

/*Вычисление количества клеток cells после hours часов и level вызовов функции
с шагом time_step, посредством деления клетки на cell_divide вплоть до end_time
c выводом на экран на каждом витке рекурсии*/
int Ameba_Unwrap(int cells, int hours, int level,
	int time_step, int cell_divide, int end_time)
{
	printf("%d клеток;\t%-2d часов;\t%d уровень вложенности\n", cells, hours, level);

	return (hours >= end_time) ?//Рекурсия продолжается пока количество часов меньше end_time
		cells :					//Возврат количества клеток после end_time часов
		Ameba_Unwrap(cells * cell_divide,
			hours + time_step, level + 1,		//Повторный запуск функции с изменёнными значениями
			time_step, cell_divide, end_time);	//Значения, не меняющиеся на каждом уровне
}

/*Рекурсивное вычисление и вывод на экран количества клеток cells после деления
на cell_divide каждые time_step часов вплоть до end_time*/
int Ameba(int cells, int time_step, int cell_divide, int end_time)
{
	return Ameba_Unwrap(cells, 0, 0, time_step, cell_divide, end_time);
}

/*Полученение начального числа клеток с ввода*/
int GetCells(void)
{
	int n;
	do//Проверка ввода
	{
		printf("Исходное число клеток: ");
		scanf("%d", &n);
		if (n >= 0)
			return n;
		printf("Число должно быть положительным\n");
	} while (1);
}

/*Полученение количество часов наблюдения с ввода*/
int GetEndTime(void)
{
	int n;
	do//Проверка ввода
	{
		printf("Введите количество часов наблюдения: ");
		scanf("%d", &n);
		if (n >= 0)
			return n;
		printf("Число должно быть положительным\n");
	} while (1);
}

/*Полученение шага наблюдения с ввода*/
int GetTimeStep(void)
{
	int n;
	do//Проверка ввода
	{
		printf("Введите шаг наблюдения за клетками: ");
		scanf("%d", &n);
		if (n >= 0)
			return n;
		printf("Число должно быть положительным\n");
	} while (1);
}
