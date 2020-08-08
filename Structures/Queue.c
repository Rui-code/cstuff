#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COUNT 6

void enqueue (uint8_t num);
void dequeue ();
void print_head ();

uint8_t fila[COUNT];
uint8_t head = 0, back = 0;

void main (void)
{
  enqueue(1);
  enqueue(2);
  enqueue(3);
  print_head();
  
  puts("");
  enqueue(4);
  enqueue(5);
  enqueue(6);
  print_head();

  dequeue();
  dequeue();
  dequeue();

  enqueue(7);
  
  puts("");
  print_head();
}

void enqueue (uint8_t num)
{
  if (back == COUNT)
  {
    back = 0;
    fila[back] = num;
    back++;
  }
  else
  {
    fila[back] = num;
    back++;
  }
}

void print_head (void)
{
  register uint8_t i;
	
  if (head == back)
  {
    printf("Fila Vazia.");
  }
  else
  {
      printf("%d ", fila[head]);
  }
    printf("\n");
}

void dequeue (void)
{
  if (head == COUNT)
  {
    head = -1;
  }
  ++head;
}
