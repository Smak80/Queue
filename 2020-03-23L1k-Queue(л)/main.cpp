#include <iostream>
#include <Windows.h>
#include <fstream>
#include "queue.h"
using namespace std;

void createQueues(const char* filename, queue& empl, queue& unempl);
void showQueue(queue& q);

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	queue employable;
	queue unemployable;
	createQueues("data.txt", employable, unemployable);
	cout << "Лица трудоспособного возраста:\n";
	showQueue(employable);
	cout << "Лица нетрудоспособного возраста:\n";
	showQueue(unemployable);
	system("pause");
}

void createQueues(const char* filename, queue& empl, queue& unempl)
{
	ifstream f(filename);
	if (f.is_open())
	{
		char* str = new char[61];
		while (!f.eof())
		{
			f.getline(str, 61); // Воронцова Ю. Е. 61
			char* name = new char[50];
			int age; 
			sscanf_s(str, "%49[^0-9] %d", name, 50, &age);
			if (age < 16 || age > 64) enqueue(unempl, name, age);
			else enqueue(empl, name, age);
			delete[] name;
		}
		delete [] str;
		f.close();
	}
}

void showQueue(queue& q)
{
	int i = 0;
	while (q.sz>0)
	{
		man m;
		if (dequeue(q, m))
		{
			cout << ++i << ".\t" << m.name;
			cout << "\t Возраст: " << m.age << "\n";
		}
	}
}