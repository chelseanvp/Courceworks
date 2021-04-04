
#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

enum restavretion { no, yes };
union height { double H; };

struct monuments {
	int YoN;
	int year;
	char name[14];
	long int price;
	restavretion restavretion;
	height h;
};

//функции по варианту:
void output(monuments* array, int N); //Вывод массива структур
void read_txt(monuments*& array, int& N); // Чтение из файла в массив структур
void add_to_the_end(monuments*& array, int &N); //Добавление структуры в конец массива
void write_txt(monuments* array, int N); //Запись из массива в файл
void chenges(monuments*& array, int N); //Замена одной, выбранной структуры
void new_line(monuments*& array, int N); //Замена всех структур элемента массива
void deleted(monuments* array, int& N); //Удаление структуры
void new_before(monuments*& array, int& N); //Добавление элемента перед выбранным
void new_after(monuments*& array, int& N); //Добавление после перед выбранного

//оставшиеся функции:
void delete_for_choice(monuments* array, int& N); //удаление по выбору
void sort(monuments* array, int& N); //сортировка по числовому полю
void deleted_since_choice(monuments* array, int& N); // удаляет от выбранного элемента 
void middle(monuments* array, int N); // поиск среднего на заданном диапазоне 
void min_max(monuments* array, int N); //поиск минимального  и максимального значения
#endif
