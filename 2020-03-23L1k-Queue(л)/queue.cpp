#include "queue.h"
#include <string.h>

void enqueue(queue& q, const char* name, int age)
{
	man m;
	m.age = age;
	strcpy_s(m.name, name);
	enqueue(q, m);
}

void enqueue(queue& q, man m)
{
	elem* newel = new elem;
	newel->m = m;
	if (!q.head)
	{
		q.head = q.tail = newel;
	} else
	{
		q.tail->next = newel;
		q.tail = newel;
	}
	q.sz++;
}

bool dequeue(queue& q, man& m)
{
	if (q.head)
	{
		m = q.head->m;
		elem* rem = q.head;
		q.head = q.head->next;
		delete rem;
		q.sz--;
		if (!q.head) q.tail = nullptr;
		return true;
	}
	return false;
}
