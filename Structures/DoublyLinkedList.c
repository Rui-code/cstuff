#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *next;
  struct node *prior;
};

struct node *head = NULL;
struct node *back = NULL;

void append(int info)
{
  struct node *newCel = (struct node *) malloc(sizeof(struct node));
  newCel->info = info;
  
  if (head == NULL) {
    head = (struct node *) malloc(sizeof(struct node));
    back = (struct node *) malloc(sizeof(struct node));
    head->prior = NULL;
    head->next = newCel;
    newCel->prior = head;
    newCel->next = back;
    back->prior = newCel;
    back->next = NULL;
  } else {
    struct node *aux = (struct node *) malloc(sizeof(struct node));
    aux->next = head;

    while (aux->next != back->prior) {
      aux->next = aux->next->next;
    }

    back->prior = newCel;
    aux->next->next = newCel;

    newCel->next = back;
    newCel->prior = aux->next;

  }
}

void fprintl()
{
  struct node *aux = (struct node *) malloc(sizeof(struct node));
  aux->next = head->next;

  if (head == NULL || head->next == back) {
    printf("Empty List!\n");
  } else {

    while (aux->next != back) {
      printf("%d\t",aux->next->info);
      aux->next = aux->next->next;
    }

    printf("\n");
  }
}

void bprintl()
{
  struct node *aux = (struct node *) malloc(sizeof(struct node));
  aux->prior = back->prior;

  if (back == NULL || back->prior == head) {
    printf("Empty List!\n");
  } else {

    while (aux->prior != head) {
      printf("%d\t", aux->prior->info);
      aux->prior = aux->prior->prior;
    }

    printf("\n");
  }
}

void unshift(int info)
{
  struct node *newCel = (struct node *) malloc(sizeof(struct node));
  
  if (head == NULL) {
    free(newCel);
    append(info);
  } else {
    newCel->info = info;

    newCel->prior = head;
    newCel->next = head->next;

    head->next->prior = newCel;
    head->next = newCel;
  }
}

void shift()
{
  struct node *aux = (struct node *) malloc(sizeof(struct node));
  
  if (head == NULL || head->next == back) {
    printf("Empty List!\n");
  } else {
    aux->next = head->next;
    
    head->next->next->prior = head;
    head->next = head->next->next;
    
    free(aux->next);
    free(aux);
  }
}

void lremove(int value)
{
  struct node *aux = (struct node *) malloc(sizeof(struct node));
  aux->next = head->next;

  while (aux->next->info != value) {
    aux->next = aux->next->next;
  }

  if (aux->next == back) {
    printf("Value not in list!\n");
  } else {
    aux->next->prior->next = aux->next->next;
    aux->next->next->prior = aux->next->prior;

    free(aux->next);
    free(aux);
  }
}

void pop()
{
  struct node *aux = (struct node *) malloc(sizeof(struct node));
  
  if (back == NULL || back->prior == head) {
    printf("Empty List!\n");
  } else {
    aux->next = back->prior;
    
    back->prior->prior->next = back;
    back->prior = back->prior->prior;
    
    free(aux->next);
    free(aux);
  }
}

int main(void)
{
  append(1);  
  append(2);  
  append(3);  
  append(4);  
  append(5);  
  append(6);  

  fprintl();
  bprintl();

  unshift(7);

  fprintl();
  bprintl();

  shift();

  fprintl();
  bprintl();

  lremove(3);

  fprintl();
  bprintl();

  pop();

  fprintl();
  bprintl();
  
  return 0;
}
