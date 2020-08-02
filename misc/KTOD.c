#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	FILE *fp;
	char ch;

	if (argc != 2)
  {
		puts("Você esqueceu de digitar o nome do arquivo.");
		exit(1);
	}

	if ((fp = fopen(argv[1], "w"))==NULL)
  {
		puts("Arquivo não pode ser aberto");
		exit(1);
	}

	do {
		ch = getchar();
		fputc(ch , fp);
	} while(ch != '$');

	fclose(fp);

	return 0;
}

