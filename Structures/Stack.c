#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX 100

void pop(), print_stack(), push(uint8_t value);

uint8_t stack[MAX]; 
uint8_t top = 0, bottom = 0;

int main (void)
{
	push(1);	
	push(2);	
	push(3);	
	push(4);	
	print_stack();
	puts("");
	pop();
	pop();
	puts("");
	print_stack();
}

void push (uint8_t value)
{
	if (top == MAX)
	{
		printf("Pilha cheia.");
		return;
	}

	stack[top++] = value;
}

void pop ()
{
	if (top == bottom)
	{
		printf("Pilha vazia.");
		return;
	}

	printf("%d\n", stack[top-1]);
	--top;
}

void print_stack ()
{
	uint8_t i;
	
	if (top == bottom)
	{
		printf("Pilha vazia.");
		return;
	}
	
	for (i = bottom; i < top; i++)
	{
		printf("%d\n", stack[i]);
	}
}
