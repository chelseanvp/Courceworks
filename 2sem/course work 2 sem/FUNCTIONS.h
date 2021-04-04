
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

//������� �� ��������:
void output(monuments* array, int N); //����� ������� ��������
void read_txt(monuments*& array, int& N); // ������ �� ����� � ������ ��������
void add_to_the_end(monuments*& array, int &N); //���������� ��������� � ����� �������
void write_txt(monuments* array, int N); //������ �� ������� � ����
void chenges(monuments*& array, int N); //������ �����, ��������� ���������
void new_line(monuments*& array, int N); //������ ���� �������� �������� �������
void deleted(monuments* array, int& N); //�������� ���������
void new_before(monuments*& array, int& N); //���������� �������� ����� ���������
void new_after(monuments*& array, int& N); //���������� ����� ����� ����������

//���������� �������:
void delete_for_choice(monuments* array, int& N); //�������� �� ������
void sort(monuments* array, int& N); //���������� �� ��������� ����
void deleted_since_choice(monuments* array, int& N); // ������� �� ���������� �������� 
void middle(monuments* array, int N); // ����� �������� �� �������� ��������� 
void min_max(monuments* array, int N); //����� ������������  � ������������� ��������
#endif
