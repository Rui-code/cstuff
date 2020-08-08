#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COUNT 100

void enqueue (uint8_t num);
void dequeue ();
void print_queue ();
void g_head (), g_back ();

uint8_t fila[COUNT];
uint8_t head = 0, back = 0;

void main (void)
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	print_queue();
	g_head();
	g_back();
	dequeue();
	print_queue();
	g_head();
	g_back();
	enqueue(5);
	enqueue(6);
	print_queue();
	dequeue();
	dequeue();
	g_head();
	g_back();
	print_queue();
}

void enqueue (uint8_t num)
{
	fila[back++] = num;
	
}

void print_queue (void)
{
	register uint8_t i;
	
	if (head == back)
	{
		printf("Fila Vazia.");
	}
	else
	{
		for (i = head; i < back; ++i)
		{
			printf("%d ", fila[i]);
		}
		printf("\n");
	}
}

void dequeue (void)
{
	++head;
}

void g_head ()
{
	printf("%d\n", fila[head]);
}

void g_back ()
{
	printf("%d\n", fila[back-1]);
}
