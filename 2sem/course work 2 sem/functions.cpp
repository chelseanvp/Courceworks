#include<iostream>
#include"FUNCTIONS.h"
#include<fstream>
#include <iomanip>  
using namespace std;

void output(monuments* array, int N) { //����� �������� �� �����
	cout << setw(8) << left << "�";
	cout << setw(15) << left << "��������";
	cout << setw(10) << left << "���";
	cout << setw(15) << left <<"����";
	cout << setw(15) << left << "�����������";
	cout << setw(15) << left << "������";
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


void read_txt(monuments*& array, int& N) { //������ �� ����� � ������
	int number;
	
	N = 0;
	cout << "����� ���� ������ �������? ������� 1 ��� 2:  ";
	cin >> number;
	if (number == 1) {
		
    ifstream fin; //������� ����
	fin.open("text1.txt");//��������� ���
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
	cout << "���� text1.txt ������ " << endl;
	N--;
	fin.close();
	

	}
	else {
		ifstream fin2;//������� ����
	
		fin2.open("text2.txt");//��������� ���
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
		cout << "���� text2.txt ������ " << endl << endl;
		N--;
		fin2.close();
		
	}
	cin.ignore();
	

}


void add_to_the_end(monuments*& array, int& N) {
	int n;
	cout << "������� ������� ������ �������� � ����� �������? " << endl;
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
		
		cout << " ������� �������� ���������: ";
		cin >> array[i].name;
		cout << "������� ��� ���������: ";
		cin >> array[i].year;
		cout << "������� ������� �������� ��������: ";
		cin >> array[i].price;
		cout << "�������� ���������������? ";
		char choice[4];
		cout << "������� �� ��� ��� " << endl;
		gets_s(choice);
		gets_s(choice);
		if (choice[0] == '�' || choice[1] == 'a') {
			
			array[i].restavretion = yes;
			
		}
		else {
			if (choice[0] == '�' || choice[1] == '�' || choice[2] == '�') {
				array[i].restavretion = no;
			}
		}
		
		cout << "������� ��������� ������ ���������: ";
		cin >> array[i].h.H;
		N++; 
	}
	cin.ignore();
	
}

void write_txt(monuments* array, int N) {
	ofstream fout;
	fout.open("new_file.txt");
	if (!fout) {
		cout << " ������ ��� �������� �����.\n";
	}
	fout << setw(8) << left << "�";
	fout << setw(15) << left << "��������";
	fout << setw(10) << left << "���";
	fout << setw(15) << left << "����";
	fout << setw(15) << left << "�����������";
	fout << setw(15) << left << "������";
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
	cout << "���������� ������� �������� � ����� ����! ";
	cin.ignore();
}

void chenges(monuments*& array, int N) {
	int exit1;
	do {
		cout << "��� �������: " << endl;
		output(array, N);
		cout << "������� ����� ����, � ������� ������ ��������: ";
		int choice;
		cin >> choice;
		cout << "������� �������� ����, � ������ ������ ��������: ";
		char name[12];
		gets_s(name);
		gets_s(name);

		if (name[0] == '�' && name[1] == '�' && name[2] == '�' && name[4] == '�' && name[7] == '�') {

			cout << "������� ����� �������� ���� ������: " << endl;
			cin >> array[choice - 1].name;
		}

		if (name[0] == '�' && name[1] == '�' && name[2] == '�') {
			cout << "������� ����� �������� ���� ������: " << endl;
			cin >> array[choice - 1].year;
		}


		if (name[0] == '�' && name[1] == '�' && name[2] == '�' && name[3] == '�') {
			cout << "������� ����� �������� ���� ������: " << endl;
			cin >> array[choice - 1].price;
		}

		if (name[0] == '�' && name[2] == '�' && name[4] == '�' && name[10] == '�') {
			cout << "������� ����� �������� ���� ������: " << endl;
			cout << "�������� ���������������? ������� �� ��� ���: ";
			char vibor[4];
			gets_s(vibor);
			if (vibor[0] == '�' || vibor[1] == 'a') {

				array[choice - 1].restavretion = yes;

			}
			else {
				if (vibor[0] == '�' || vibor[1] == '�' && vibor[2] == '�') {
					array[choice - 1].restavretion = no;
				}
			}

		}

		if (name[0] == '�' && name[1] == '�' && name[2] == '�' && name[4] == '�' && name[5] == '�') {
			cout << "������� ����� �������� ���� ������: " << endl;
			cin >> array[choice - 1].h.H;
		}

		cout << "������ ��������! ��� ����� �������: " << endl;;
		output(array, N);

		cout << "������ �������� ��� ���� ����? 1-�� 2 -���: ";
		cin >> exit1;
		if (exit1 == 1) {
			system("cls");
		}
	} while (exit1 == 1);

}

void new_line(monuments*& array, int N) {

	cout << "��� �������: " << endl;
	output(array, N);
	cout << "������� ����� ����, ������� ������ ��������: ";
	int choice;
	cin >> choice;

	cout << "������� �������� ���������: ";
	cin >> array[choice-1].name;
	cout << "������� ��� ���������: ";
	cin >> array[choice - 1].year;
	cout << "������� ������� �������� ��������: ";
	cin >> array[choice - 1].price;
	cout << "�������� ���������������? ";
	cout << "������� �� ��� ��� " << endl;
	char vibor[4];
	gets_s(vibor);
	gets_s(vibor);
	if (vibor[0] == '�' || vibor[1] == 'a') {
		array[choice-1].restavretion = yes;

	}
	else {
		if (vibor[0] == '�' || vibor[1] == '�' || vibor[2] == '�') {
			array[choice-1].restavretion = no;
		}
	}
    
	cout << "������� ��������� ������ ���������: ";
	cin >> array[choice-1].h.H;
	cout << "���� ���������������! ";
	cin.ignore();

}

void deleted(monuments* array, int& N) {
	cout << "��� �������: " << endl;
	output(array, N);
	int choice;
	cout << "������� ����� ������, ������� ������ �������: ";
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
	cout << "��� �������: " << endl;
	output(array, N);
	int choice;
	cout << "������� ������� �� ������� ������ �������� �����: ";
	cin >> choice;
	monuments* tempArr = new monuments[N];
	for (int i = 0; i < N; i++) {
		tempArr[i] = array[i];
		
	}
	
	
	array = new monuments[N+1];
	for (int i = 0; i <= choice - 1; i++) {
		if (i == choice - 1) {
			cout << "������� �������� ���������: ";
			cin >> array[i].name;
			cout << "������� ��� ���������: ";
			cin >> array[i].year;
			cout << "������� ������� �������� ��������: ";
			cin >> array[i].price;
			cout << "�������� ���������������? ";
			char choice[4];
			cout << "������� �� ��� ��� " << endl;
			gets_s(choice);
			gets_s(choice);
			if (choice[0] == '�' || choice[1] == 'a') {

				array[i].restavretion = yes;

			}
			else {
				if (choice[0] == '�' || choice[1] == '�' || choice[2] == '�') {
					array[i].restavretion = no;
				}
			}

			cout << "������� ��������� ������ ���������: ";
			cin >> array[i].h.H;
			cout << "������ ��������! " << endl;
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
	cout << "��� �������: " << endl;
	output(array, N);
	int choice;
	cout << "������� ������� ����� ������� ������ �������� �����: ";
	cin >> choice;
	monuments* tempArr = new monuments[N];
	for (int i = 0; i < N; i++) {
		tempArr[i] = array[i];

	}


	array = new monuments[N + 1];
	for (int i = 0; i <= choice; i++) {
		if (i == choice) {
			cout << "������� �������� ���������: ";
			cin >> array[i].name;
			cout << "������� ��� ���������: ";
			cin >> array[i].year;
			cout << "������� ������� �������� ��������: ";
			cin >> array[i].price;
			cout << "�������� ���������������? ";
			char choice[4];
			cout << "������� �� ��� ��� " << endl;
			gets_s(choice);
			gets_s(choice);
			if (choice[0] == '�' || choice[1] == 'a') {

				array[i].restavretion = yes;

			}
			else {
				if (choice[0] == '�' || choice[1] == '�' || choice[2] == '�') {
					array[i].restavretion = no;
				}
			}

			cout << "������� ��������� ������ ���������: ";
			cin >> array[i].h.H;
			cout << "������ ��������! " << endl;
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
	cout << "��� �������: " << endl;
	output(array, N);
	cout << "�������� ���������  �� ����" << endl;
	cout << "������ �������� ������� ������ ��� ������ ? ";
	char vibor[7];
	gets_s(vibor);
	cout << "������� �������� �� �������� ������ ������� ��������: ";
	int choice;
	cin >> choice;

	if (vibor[0] == '�' && vibor[1] == '�' && vibor[2] == '�' && vibor[5] == '�') {
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

	if (vibor[0] == '�' && vibor[1] == '�' && vibor[2] == '�' && vibor[3] == '�') {
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
	cout << "��� ����������� ������: " << endl;
	output(array, N);
	cin.ignore();
}

void sort(monuments* array, int& N) {

	cout << "��� �������: " << endl;
	output(array, N);
	cout << "�������� �� ������ ���� ������ ����������: " << endl;
	cout << "��������� ����: ���/����/������ ";
	char choice[7];
	gets_s(choice);
	if (choice[0] == '�' && choice[1] == '�' && choice[2] == '�') {
		for (int i = 0; i < N - 1; i++) {
			for (int j = i; j < N; j++) {
				if (array[j].year < array[i].year) {
					swap(array[i], array[j]);
				}
			}
		}
	}

	if (choice[0] == '�' && choice[1] == '�' && choice[3] == '�') {
		for (int i = 0; i < N - 1; i++) {
			for (int j = i; j < N; j++) {
				if (array[j].price< array[i].price) {
							swap(array[i], array[j]);
				}
			}
		}
	}
			
			
	if (choice[0] == '�' && choice[1] == '�' && choice[2] == '�' && choice[3] == '�') {
		for (int i = 0; i < N - 1; i++) {
			for (int j = i; j < N; j++) {
				if (array[j].h.H < array[i].h.H) {
							swap(array[i], array[j]);
				}
			}
		}
	}

	cout << "��� ��������������� �������: " << endl;
	output(array, N);
	cin.ignore();
}

void deleted_since_choice(monuments* array, int& N) {
	cout << "��� �������: " << endl;
	output(array, N);
	cout << "������� � ������ �������� ������ ������� ��������: ";
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
	cout << "��� ����� �������:" << endl;
	output(array, N);
	cin.ignore();
}

void middle(monuments* array, int N) {
	cout << "��� �������: " << endl;
	output(array, N);

	cout << "������� ��������, �� ������� ������ ��������� ������� ��������:" << endl;;
	int up;
	int down;
	cout << "������� ��������: ";
	cin >> up;
	cout << "������  ��������: ";
	cin >> down;

	cout << "������� ������ ����: ���/���� ";
    char choice[7];
	gets_s(choice);
	gets_s(choice);
	if (choice[0] == '�' && choice[1] == '�' && choice[2] == '�') {
		for (int i = up,m=1,sum=0; i <= down; i++,m++) {
			
			sum += array[i-1].year;
			if (i == down) {
				int middle;
				middle = sum / m;
				cout << "������� ��������������: " << middle << endl;
			}

		}
		
	}

	if (choice[0] == '�' && choice[1] == '�' && choice[3] == '�') {
		for (int i = up, m = 1, sum = 0; i <= down; i++, m++) {
			
			sum += array[i - 1].price;
			
			if (i == down) {
				int middle;
				middle = sum / m;
				cout << "������� ��������������: " << middle << endl;
			}
		}
	}

	
	cin.ignore();
}

void min_max(monuments* array, int N) {
	cout << "��� �������: " << endl;
	output(array, N);
	cout << "������� ��������, �� ������� ������ ��������� ������� ��������:" << endl;;
	int up;
	int down;
	cout << "������� ��������: ";
	cin >> up;
	cout << "������  ��������: ";
	cin >> down;
	
	cout << "������� ������ ����: ���/���� ";
	char choice[7];
	gets_s(choice);
	gets_s(choice);

	if (choice[0] == '�' && choice[1] == '�' && choice[2] == '�') {
		int min = up - 1;
		int max = up - 1;
		for (int i = up - 1; i < down; i++) {
			if (array[i].year < array[min].year)
				min = i;
			if (array[i].year > array[max].year)
				max = i;
		}

		cout << "���������� �������� � �������� ��������� - " << array[max].year << " � �������� � �������� " << max << endl;
		cout << "���������� �������� � �������� ��������� - " << array[min].year << " � �������� � �������� " << min << endl;
	}

	

	if (choice[0] == '�' && choice[1] == '�' && choice[3] == '�') {
		int min = up - 1;
		int max = up - 1;
		for (int i = up - 1; i < down; i++) {
			if (array[i].price < array[min].price)
				min = i;
			if (array[i].price > array[max].price)
				max = i;
		}

		cout << "���������� �������� � �������� ��������� - " << array[max].price << " � �������� � �������� " << max << endl;
		cout << "���������� �������� � �������� ��������� - " << array[min].price << " � �������� � �������� " << min << endl;
	}

	cin.ignore();
}
