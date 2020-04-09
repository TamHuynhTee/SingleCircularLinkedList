#include<stdio.h>
#include<conio.h>

int nodeCount = 0;

struct Node
{
	int data;
	struct Node* next;
};

typedef struct Node node;

struct List
{
	node* head;
	node* tail;
};

void Initualize(List &l)
{
	l.head = NULL;
	l.tail = NULL;
}

bool checkEmpty(List l)
{
	if (l.head != NULL)
		return true;
	return false;
}

void Display(List l)
{
	node* p = l.head;
	int run = nodeCount+1;
	while (run>1)
	{
		printf("%d ", p->data);
		p = p->next;
		run--;
	}
	printf("\nNumber of nodes: %d", nodeCount);
}

node* newNode(int x)
{
	node* p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}

void AddHead(List &l, int x)//Bug
{
	node* new_element = newNode(x);
	if (new_element == NULL)
	{
		return;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = new_element;
		l.tail->next = new_element;
		nodeCount++;
	}
	else
		if (l.head != NULL)
		{
			new_element->next = l.head;
			l.head = new_element;
			nodeCount++;
		}
}

void main()
{
	List l;
	AddHead(l, 50);
	AddHead(l, 40);
	AddHead(l, 30);
	AddHead(l, 10);
	Display(l);
	_getch();
}