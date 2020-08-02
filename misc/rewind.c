#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char str[80];
	FILE *fp;

	if((fp = fopen("Test", "w+")) == NULL)
  {
		puts("O arquivo não pode ser aberto");
		exit(1);
	}

	do {
		puts("Digite uma string (CR para sair):\n");
		gets(str);
		strcat(str, "\n");
		fputs(str, fp);
	} while (*str != '\n');

	rewind(fp);

	while (!feof(fp))
  {
		fgets(str, 79, fp);
		printf(str);
	}
}
