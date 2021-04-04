#include"MENU.h"
#include"FUNCTIONS.h"
#include<iostream> 
using namespace std;
int menu() {
	int choice;
	int N = 0;
	monuments* Array = new monuments[N];
	do {
		cout << "����: " << endl;;
		cout << "�������� ��������: " << endl;
		cout << "#1 ���� ���������� �� ���������� ����� � ������ \n   ���������� �� ������. �������-1" << endl;
		cout << "#2 ���������� ����� ��������� � ����� �������. �������-2" << endl;
		cout << "#3 �������� ���� ��������� �������. �������-3" << endl;
		cout << "#4 ����� ���������� �� ������� � ��������� ����. �������-4" << endl;
		cout << "#5 ������������� ����� ���������� ��������. �������-5" << endl;
		cout << "#6 �������� ���������� ��������. �������-6 " << endl;
		cout << "#7 ������� ������ �������� ����� ��������� ���������. �������-7" << endl;
		cout << "#8 ������� ������ �������� ����� ���������� ��������. �������-8" << endl;
		cout << "#9 ������ ���������� ��������. �������-9" << endl;
		cout << "#10 �����. �������-10" << endl;
		cout << "_____________________________________________________________________________" << endl;
		cout << "�������������� ������� ��� ��������: " << endl;
		cout << "#11 �������� ��������� �� ������� \n    (���� <���> ��������� ��������). �������-11" << endl;
		cout << "#12 ���������� ������� �� ��������� ����. �������-12" << endl;
		cout << "#13 �������� ���������, ������� �� ����������. �������-13" << endl;
		cout << "#14 �������� ��������� � ���������� �������� �� ��������� ��� ���������"<<endl;
		cout << "    ������� �������� � �������� �������� �� ��������� ���� �������-14." << endl;
		cout << "#15 �������� ��������� � ���������� �������� � ��������� �� ���������" << endl;
		cout << "    ��� ���������, ������� �������� � �������� ��������" << endl;
		cout << "    �� ��������� ���� �������-15" << endl;



		     
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