#ifndef _SORTLINES
#define _SORTLINES

#include <string.h>
#include <stdio.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

void writelines(char *lineptr[], int nlines);
int  readlines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right
	   int (*comp)(void *, void *));
int  numcmp(char *, char*);

#define MAXLEN 1000

char *alloc(int);
int   getl(char *, int);

#define ALLOCSIZE 10000

static char  allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int);

#endif
