#include<iostream>
#include"FUNCTIONS.h"
#include<fstream>
#include <iomanip>  
using namespace std;

void output(monuments* array, int N) { //Вывод масссива на экран
	cout << setw(8) << left << "№";
	cout << setw(15) << left << "Название";
	cout << setw(10) << left << "Год";
	cout << setw(15) << left <<"Цена";
	cout << setw(15) << left << "Реставрация";
	cout << setw(15) << left << "Высота";
	cout << "\n" << endl;
	for (int i = 0; i < N ; i++) {
		cout << setw(8) << left << i + 1;
		cout << setw(15) << left << array[i].name;
		cout << setw(10) << left << array[i].year;
		cout << setw(15) << left << array[i].price;
		cout << setw(15) << left << array[i].restavretion;
		cout << setw(15) << left << array[i].h.H;
		cout << "\n" << endl;

	}
	cin.ignore();
}


void read_txt(monuments*& array, int& N) { //чтение из файла в массив
	int number;
	
	N = 0;
	cout << "Какой файл хотите открыть? Введите 1 или 2:  ";
	cin >> number;
	if (number == 1) {
		
    ifstream fin; //создаем файл
	fin.open("text1.txt");//открываем его
	char temp[256];
    fin.getline(temp, 256);
	system("cls");
	for (int i = 0; !fin.eof(); i++) {
		N++;
		monuments* tmp = new monuments[N];
		for (int j = 0; j < N; j++)
			tmp[j] = array[j];
		array = new monuments[N];
		for (int j = 0; j < N ; j++)
			array[j] = tmp[j];
		delete[] tmp;

		fin >> array[i].name >> array[i].year >> array[i].price >> array[i].YoN >> array[i].h.H;
		if (array[i].YoN == 1) {
			array[i].restavretion = yes;

		}
		if (array[i].YoN == 0) {
			array[i].restavretion = no;

		}

	}
	cout << "Файл text1.txt считан " << endl;
	N--;
	fin.close();
	

	}
	else {
		ifstream fin2;//создаем файл
	
		fin2.open("text2.txt");//открываем его
		char temp[256];
		fin2.getline(temp, 256);
		for (int i = 0; !fin2.eof(); i++) {
			N++;
			monuments* tmp = new monuments[N - 1];
			for (int j = 0; j < N - 1; j++)
				tmp[j] = array[j];
			array = new monuments[N];
			for (int j = 0; j < N - 1; j++)
				array[j] = tmp[j];
			delete[] tmp;
			fin2 >>  array[i].name >> array[i].year >> array[i].price >> array[i].YoN >> array[i].h.H;
			if (array[i].YoN == 1) {
				array[i].restavretion = yes;
				
			}
			if (array[i].YoN == 0) {
					array[i].restavretion = no;
					
			}
			
		}
		cout << "Файл text2.txt считан " << endl << endl;
		N--;
		fin2.close();
		
	}
	cin.ignore();
	

}


void add_to_the_end(monuments*& array, int& N) {
	int n;
	cout << "Сколько строчек хотите добавить в конец массива? " << endl;
	cin >> n; 

	monuments* tempArr = new monuments[N];
	for (int i = 0; i < N; i++) {
		tempArr[i] = array[i];
	}
	
 	array = new monuments[N+n];
	for (int i = 0; i < N; i++) {
		array[i] = tempArr[i];
	}
	delete[]tempArr;
	                 
	int N1 = N;
	for (int i = N1; i < N1 + n; i++) {
		
		cout << " Введите название памятника: ";
		cin >> array[i].name;
		cout << "Введите год постройки: ";
		cin >> array[i].year;
		cout << "Введите годовую стоимось расходов: ";
		cin >> array[i].price;
		cout << "Памятник реставрировался? ";
		char choice[4];
		cout << "Введите да или нет " << endl;
		gets_s(choice);
		gets_s(choice);
		if (choice[0] == 'д' || choice[1] == 'a') {
			
			array[i].restavretion = yes;
			
		}
		else {
			if (choice[0] == 'н' || choice[1] == 'е' || choice[2] == 'т') {
				array[i].restavretion = no;
			}
		}
		
		cout << "Введите примерную высоту памятника: ";
		cin >> array[i].h.H;
		N++; 
	}
	cin.ignore();
	
}

void write_txt(monuments* array, int N) {
	ofstream fout;
	fout.open("new_file.txt");
	if (!fout) {
		cout << " Ошибка при открытии файла.\n";
	}
	fout << setw(8) << left << "№";
	fout << setw(15) << left << "Название";
	fout << setw(10) << left << "Год";
	fout << setw(15) << left << "Цена";
	fout << setw(15) << left << "Реставрация";
	fout << setw(15) << left << "Высота";
	fout << "\n" << endl;
	for (int i = 0; i < N; i++) {
		fout << setw(8) << left << i + 1;
		fout << setw(15) << left << array[i].name;
		fout << setw(10) << left << array[i].year;
		fout << setw(15) << left << array[i].price;
		fout << setw(15) << left << array[i].restavretion;
		fout << setw(15) << left << array[i].h.H;
		fout << "\n" << endl;
	}
	fout.close();
	cout << "Информация успешна записана в новый файл! ";
	cin.ignore();
}

void chenges(monuments*& array, int N) {
	int exit1;
	do {
		cout << "Вот таблица: " << endl;
		output(array, N);
		cout << "Введите номер поля, с которым хотите работать: ";
		int choice;
		cin >> choice;
		cout << "Введите название поля, с кторым хотите работать: ";
		char name[12];
		gets_s(name);
		gets_s(name);

		if (name[0] == 'н' && name[1] == 'а' && name[2] == 'з' && name[4] == 'а' && name[7] == 'е') {

			cout << "Введите новое значение этой ячейки: " << endl;
			cin >> array[choice - 1].name;
		}

		if (name[0] == 'г' && name[1] == 'о' && name[2] == 'д') {
			cout << "Введите новое значение этой ячейки: " << endl;
			cin >> array[choice - 1].year;
		}


		if (name[0] == 'ц' && name[1] == 'е' && name[2] == 'н' && name[3] == 'а') {
			cout << "Введите новое значение этой ячейки: " << endl;
			cin >> array[choice - 1].price;
		}

		if (name[0] == 'р' && name[2] == 'с' && name[4] == 'а' && name[10] == 'я') {
			cout << "Введите новое значение этой ячейки: " << endl;
			cout << "Памятник реставрировался? Введите да или нет: ";
			char vibor[4];
			gets_s(vibor);
			if (vibor[0] == 'д' || vibor[1] == 'a') {

				array[choice - 1].restavretion = yes;

			}
			else {
				if (vibor[0] == 'н' || vibor[1] == 'е' && vibor[2] == 'т') {
					array[choice - 1].restavretion = no;
				}
			}

		}

		if (name[0] == 'в' && name[1] == 'ы' && name[2] == 'с' && name[4] == 'т' && name[5] == 'а') {
			cout << "Введите новое значение этой ячейки: " << endl;
			cin >> array[choice - 1].h.H;
		}

		cout << "Данные изменины! Вот новая таблица: " << endl;;
		output(array, N);

		cout << "Хотите изменить еще одно поле? 1-да 2 -нет: ";
		cin >> exit1;
		if (exit1 == 1) {
			system("cls");
		}
	} while (exit1 == 1);

}

void new_line(monuments*& array, int N) {

	cout << "Вот таблица: " << endl;
	output(array, N);
	cout << "Введите номер поля, который хотите изменить: ";
	int choice;
	cin >> choice;

	cout << "Введите название памятника: ";
	cin >> array[choice-1].name;
	cout << "Введите год постройки: ";
	cin >> array[choice - 1].year;
	cout << "Введите годовую стоимось расходов: ";
	cin >> array[choice - 1].price;
	cout << "Памятник реставрировался? ";
	cout << "Введите да или нет " << endl;
	char vibor[4];
	gets_s(vibor);
	gets_s(vibor);
	if (vibor[0] == 'д' || vibor[1] == 'a') {
		array[choice-1].restavretion = yes;

	}
	else {
		if (vibor[0] == 'н' || vibor[1] == 'е' || vibor[2] == 'т') {
			array[choice-1].restavretion = no;
		}
	}
    
	cout << "Введите примерную высоту памятника: ";
	cin >> array[choice-1].h.H;
	cout << "Поле отредактировано! ";
	cin.ignore();

}

void deleted(monuments* array, int& N) {
	cout << "Вот таблица: " << endl;
	output(array, N);
	int choice;
	cout << "Введите номер строки, который хотите удалить: ";
	cin >> choice;	
	
	for (int i=0,m = 0; i < N; i++,m++) {
		
		if (m == choice-1) {
			N--;
			for (int j = i; j < N; j++)
				array[j] = array[j + 1];
			i--;
		}
	
	}
	monuments* tempArr = new monuments[N];
	for (int i = 0; i < N; i++)
		tempArr[i] = array[i];
	array = new monuments[N];
	for (int i = 0; i < N; i++)
		array[i] = tempArr[i];
	delete[]tempArr;
	system(" cls");
	output(array, N);

}

void new_before(monuments*& array, int& N) {
	cout << "Вот таблица: " << endl;
	output(array, N);
	int choice;
	cout << "Введите элемент до которго хотите добавить новый: ";
	cin >> choice;
	monuments* tempArr = new monuments[N];
	for (int i = 0; i < N; i++) {
		tempArr[i] = array[i];
		
	}
	
	
	array = new monuments[N+1];
	for (int i = 0; i <= choice - 1; i++) {
		if (i == choice - 1) {
			cout << "Введите название памятника: ";
			cin >> array[i].name;
			cout << "Введите год постройки: ";
			cin >> array[i].year;
			cout << "Введите годовую стоимось расходов: ";
			cin >> array[i].price;
			cout << "Памятник реставрировался? ";
			char choice[4];
			cout << "Введите да или нет " << endl;
			gets_s(choice);
			gets_s(choice);
			if (choice[0] == 'д' || choice[1] == 'a') {

				array[i].restavretion = yes;

			}
			else {
				if (choice[0] == 'н' || choice[1] == 'е' || choice[2] == 'т') {
					array[i].restavretion = no;
				}
			}

			cout << "Введите примерную высоту памятника: ";
			cin >> array[i].h.H;
			cout << "Строка записана! " << endl;
			break;
		}
		
		array[i]=tempArr[i];

	}
	
	for (int i = choice ; i < N+1; i++) {
	array[i] = tempArr[i-1];
	}
	N++;

	
	
	output(array, N);
	cin.ignore();
}

void new_after(monuments*& array, int& N) {
	cout << "Вот таблица: " << endl;
	output(array, N);
	int choice;
	cout << "Введите элемент после которго хотите добавить новый: ";
	cin >> choice;
	monuments* tempArr = new monuments[N];
	for (int i = 0; i < N; i++) {
		tempArr[i] = array[i];

	}


	array = new monuments[N + 1];
	for (int i = 0; i <= choice; i++) {
		if (i == choice) {
			cout << "Введите название памятника: ";
			cin >> array[i].name;
			cout << "Введите год постройки: ";
			cin >> array[i].year;
			cout << "Введите годовую стоимось расходов: ";
			cin >> array[i].price;
			cout << "Памятник реставрировался? ";
			char choice[4];
			cout << "Введите да или нет " << endl;
			gets_s(choice);
			gets_s(choice);
			if (choice[0] == 'д' || choice[1] == 'a') {

				array[i].restavretion = yes;

			}
			else {
				if (choice[0] == 'н' || choice[1] == 'е' || choice[2] == 'т') {
					array[i].restavretion = no;
				}
			}

			cout << "Введите примерную высоту памятника: ";
			cin >> array[i].h.H;
			cout << "Строка записана! " << endl;
			break;
		}

		array[i] = tempArr[i];

	}

	for (int i = choice+1; i < N + 1; i++) {
		array[i] = tempArr[i-1];
	}
	N++;



	output(array, N);
	cin.ignore();
}

void delete_for_choice(monuments* array, int& N) {
	cout << "Вот таблица: " << endl;
	output(array, N);
	cout << "Удаление элементов  по цене" << endl;
	cout << "Убрать элементы которые больше или меньше ? ";
	char vibor[7];
	gets_s(vibor);
	cout << "Введите значение по которому хотите удалить элементы: ";
	int choice;
	cin >> choice;

	if (vibor[0] == 'б' && vibor[1] == 'о' && vibor[2] == 'л' && vibor[5] == 'е') {
		for (int i = 0; i < N; i++) {
			if (array[i].price > choice) {
				N--;
				for (int j = i; j < N; j++)
					array[j] = array[j + 1];
				i--;
			}
		}
		monuments* tempArr = new monuments[N];
		for (int i = 0; i < N; i++)
			tempArr[i] = array[i];
		array = new monuments[N];
		for (int i = 0; i < N; i++)
			array[i] = tempArr[i];
		delete[]tempArr;
	}

	if (vibor[0] == 'м' && vibor[1] == 'е' && vibor[2] == 'н' && vibor[3] == 'ь') {
		for (int i = 0; i < N; i++) {
			if (array[i].price < choice) {
				N--;
				for (int j = i; j < N; j++)
					array[j] = array[j + 1];
				i--;
			}
		}
		monuments* tempArr = new monuments[N];
		for (int i = 0; i < N; i++)
			tempArr[i] = array[i];
		array = new monuments[N];
		for (int i = 0; i < N; i++)
			array[i] = tempArr[i];
		delete[]tempArr;
	}

	system("cls");
	cout << "Вот запрошенные данные: " << endl;
	output(array, N);
	cin.ignore();
}

void sort(monuments* array, int& N) {

	cout << "Вот таблица: " << endl;
	output(array, N);
	cout << "Выберите по какому полю делать сортировку: " << endl;
	cout << "Доступные поля: Год/Цена/Высота ";
	char choice[7];
	gets_s(choice);
	if (choice[0] == 'г' && choice[1] == 'о' && choice[2] == 'д') {
		for (int i = 0; i < N - 1; i++) {
			for (int j = i; j < N; j++) {
				if (array[j].year < array[i].year) {
					swap(array[i], array[j]);
				}
			}
		}
	}

	if (choice[0] == 'ц' && choice[1] == 'е' && choice[3] == 'а') {
		for (int i = 0; i < N - 1; i++) {
			for (int j = i; j < N; j++) {
				if (array[j].price< array[i].price) {
							swap(array[i], array[j]);
				}
			}
		}
	}
			
			
	if (choice[0] == 'в' && choice[1] == 'ы' && choice[2] == 'с' && choice[3] == 'о') {
		for (int i = 0; i < N - 1; i++) {
			for (int j = i; j < N; j++) {
				if (array[j].h.H < array[i].h.H) {
							swap(array[i], array[j]);
				}
			}
		}
	}

	cout << "Вот отсортированная таблица: " << endl;
	output(array, N);
	cin.ignore();
}

void deleted_since_choice(monuments* array, int& N) {
	cout << "Вот таблица: " << endl;
	output(array, N);
	cout << "Введите с какого элемента хотите удалить элементы: ";
	int choice;
	cin >> choice;

	monuments* tempArr = new monuments[N];
	for (int i = 0; i < choice; i++) {
		tempArr[i] = array[i];
	}
	
	int N1 = N;
	for (int i = choice; i < N1; i++) {
		N--;
	}
	
	array = new monuments[choice];
	for (int i = 0; i < choice; i++) {
		array[i]=tempArr[i];
	}
	
	
	system("cls");
	cout << "Вот новая таблица:" << endl;
	output(array, N);
	cin.ignore();
}

void middle(monuments* array, int N) {
	cout << "Вот таблица: " << endl;
	output(array, N);

	cout << "Введите диапазон, на котором хотите вычислить среднее значение:" << endl;;
	int up;
	int down;
	cout << "Верхний диапазон: ";
	cin >> up;
	cout << "нижний  диапазон: ";
	cin >> down;

	cout << "Введите нужное поле: год/цена ";
    char choice[7];
	gets_s(choice);
	gets_s(choice);
	if (choice[0] == 'г' && choice[1] == 'о' && choice[2] == 'д') {
		for (int i = up,m=1,sum=0; i <= down; i++,m++) {
			
			sum += array[i-1].year;
			if (i == down) {
				int middle;
				middle = sum / m;
				cout << "Среднее арифметическое: " << middle << endl;
			}

		}
		
	}

	if (choice[0] == 'ц' && choice[1] == 'е' && choice[3] == 'а') {
		for (int i = up, m = 1, sum = 0; i <= down; i++, m++) {
			
			sum += array[i - 1].price;
			
			if (i == down) {
				int middle;
				middle = sum / m;
				cout << "Среднее арифметическое: " << middle << endl;
			}
		}
	}

	
	cin.ignore();
}

void min_max(monuments* array, int N) {
	cout << "Вот таблица: " << endl;
	output(array, N);
	cout << "Введите диапазон, на котором хотите вычислить среднее значение:" << endl;;
	int up;
	int down;
	cout << "Верхний диапазон: ";
	cin >> up;
	cout << "нижний  диапазон: ";
	cin >> down;
	
	cout << "Введите нужное поле: год/цена ";
	char choice[7];
	gets_s(choice);
	gets_s(choice);

	if (choice[0] == 'г' && choice[1] == 'о' && choice[2] == 'д') {
		int min = up - 1;
		int max = up - 1;
		for (int i = up - 1; i < down; i++) {
			if (array[i].year < array[min].year)
				min = i;
			if (array[i].year > array[max].year)
				max = i;
		}

		cout << "Наибольшее значение в заданном диапазоне - " << array[max].year << " у элемента с индексом " << max << endl;
		cout << "Наименьшее значение в заданном диапазоне - " << array[min].year << " у элемента с индексом " << min << endl;
	}

	

	if (choice[0] == 'ц' && choice[1] == 'е' && choice[3] == 'а') {
		int min = up - 1;
		int max = up - 1;
		for (int i = up - 1; i < down; i++) {
			if (array[i].price < array[min].price)
				min = i;
			if (array[i].price > array[max].price)
				max = i;
		}

		cout << "Наибольшее значение в заданном диапазоне - " << array[max].price << " у элемента с индексом " << max << endl;
		cout << "Наименьшее значение в заданном диапазоне - " << array[min].price << " у элемента с индексом " << min << endl;
	}

	cin.ignore();
}
