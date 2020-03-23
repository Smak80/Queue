#pragma once
struct man
{
	char name[50]; //Имя
	int age; //Возраст
};

struct elem
{
	//Информационные поля:
	man m;
	//Ссылочные поля:
	elem* next = nullptr;
};

struct queue
{
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t sz = 0;
};

void enqueue(queue& q, const char* name, int age);
void enqueue(queue& q, man m);
bool dequeue(queue& q, man& m);