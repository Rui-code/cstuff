#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	char str[80];
	FILE *fp;


	if (argc != 2)
  {
		puts("Você não informou o nome do arquivo.");
		exit(1);
	}

	if ((fp = fopen(argv[1], "w")) == NULL)
  {
		puts("O arquivo não pode ser aberto.");
		exit(1);
	}

	do {
		puts("Digite uma string (CR para sair):");
		gets(str);
		strcat(str, "\n");
		fputs(str, fp);
	} while (*str = '\n');
}
