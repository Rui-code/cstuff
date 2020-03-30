#include <stdio.h>
#include <stdlib.h>

// Defines the structure
struct cel {
	int value;
	struct cel *next;
};

// List's head
struct cel *head;

// Adds data to the end of the list
void append(int value);

// Removes data from the end of the list
void pop();

// Adds data to the beginning of the list
void unshift(int value);

// Removes data from the beginnig of the list
void shift();

// Prints the list
void print();

int main() {
	
	int i = 1;
	while(i <= 10) {
		append(i);
		i++;
	}
	print();
	pop();
	print();
	shift();
	print();
	unshift(1);
	print();
	
	return 0;
}

void print() {
	struct cel *aux = NULL;
	aux = head;
	
	while(aux->next != NULL){
		aux = aux->next;
		printf("%d->", aux->value);
	}
	
	printf("NULL\n");
}

void append(int value) {
	struct cel *aux, *newCel;
	
	if(head == NULL) {
		
		head = (struct cel*) malloc(sizeof(struct cel));
		head->next = NULL;
		
		newCel = (struct cel*) malloc(sizeof(struct cel));
		newCel->value = value;
		newCel->next = NULL;
		
		head->next = newCel;
	} else {
		aux = head;
		
		while(aux->next != NULL) {
			aux = aux->next;
		}
		
		newCel = (struct cel*) malloc(sizeof(struct cel));
		newCel->value = value;
		newCel->next = NULL;
		
		aux->next = newCel;
	}
}

void pop() {
	struct cel *aux = NULL;
	aux = head;
	
	while(aux->next->next != NULL) {
		aux = aux->next;
	}
	
	free(aux->next);
	aux->next = NULL;
}

void shift() {
	struct cel *aux = NULL;
	aux = head->next;
	head->next = head->next->next;
	free(aux);
}

void unshift(int value) {
	struct cel *newCel = NULL;
	
	newCel = (struct cel*) malloc(sizeof(struct cel));
	newCel->value = value;
	newCel->next = head->next;
	
	head->next = newCel;
}









