#include"MENU.h"
#include"FUNCTIONS.h"
#include<iostream> 
using namespace std;
int menu() {
	int choice;
	int N = 0;
	monuments* Array = new monuments[N];
	do {
		cout << "МЕНЮ: " << endl;;
		cout << "Выберите операцию: " << endl;
		cout << "#1 Ввод информации из текстового файла в массив \n   указателей на записи. Нажмите-1" << endl;
		cout << "#2 Добавление новых элементов в конец массива. Нажмите-2" << endl;
		cout << "#3 Просмотр всех элементов массива. Нажмите-3" << endl;
		cout << "#4 Вывод информации из массива в текстовый файл. Нажмите-4" << endl;
		cout << "#5 Корректировка полей выбранного элемента. Нажмите-5" << endl;
		cout << "#6 Удаление выбранного элемента. Нажмите-6 " << endl;
		cout << "#7 Вставка нового элемента перед выбранным элементом. Нажмите-7" << endl;
		cout << "#8 Вставка нового элемента после выбранного элемента. Нажмите-8" << endl;
		cout << "#9 Замена выбранного элемента. Нажмите-9" << endl;
		cout << "#10 Выход. Нажмите-10" << endl;
		cout << "_____________________________________________________________________________" << endl;
		cout << "Дополнительные функции вне варианта: " << endl;
		cout << "#11 Удаление элементов по условию \n    (поле <или> заданного значения). Нажмите-11" << endl;
		cout << "#12 Сортировка массива по числовому полю. Нажмите-12" << endl;
		cout << "#13 Удаление элементов, начиная от выбранного. Нажмите-13" << endl;
		cout << "#14 Просмотр элементов и вычисление среднего на множестве тех элементов"<<endl;
		cout << "    которые попадают в заданный диапазон по заданному полю Нажмите-14." << endl;
		cout << "#15 Просмотр элементов и вычисление минимума и максимума на множестве" << endl;
		cout << "    тех элементов, которые попадают в заданный диапазон" << endl;
		cout << "    по заданному полю Нажмите-15" << endl;



		     
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			read_txt(Array, N);
			break;

		case 2:
			system("cls");
			add_to_the_end(Array, N);
			break;
		case 3:
			system("cls");
			output(Array, N);
			break;
		case 4:
			system("cls");
			write_txt(Array, N);
			break;
		case 5:
			system("cls");
			new_line(Array, N);
			break;
		case 6:
			system("cls");
			deleted(Array, N);
			break;

		case 7:
			system("cls");
			new_before(Array, N);
			break;

		case 8:
			system("cls");
			new_after(Array, N);
			break;

		case 9:
			system("cls");
			chenges(Array, N);
			break;
		case 10:
			return 0;

		case 11:
			system("cls");
			delete_for_choice(Array, N);
			break;
		case 12:
			system("cls");
			sort(Array, N);
			break;
		case 13:
			system("cls");
			deleted_since_choice(Array, N);
			break;
		case 14:
			system("cls");
			middle(Array, N);
			break;
		case 15:
			system("cls");
			min_max(Array, N);
			break;
		}
		

		
		cin.ignore();
		system("cls");

	} while (true);

	delete []Array;
}