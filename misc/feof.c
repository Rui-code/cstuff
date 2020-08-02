#include <stdio.h>
#include <stdlib.h>

void main (int argc, char *argv[])
{
	FILE *in, *out;
	char ch;

	if (argc != 3)
  {
		puts("Você esqueceu de informar o nome do arquivo.");
		exit(1);
	}

	if ((in = fopen(argv[1], "rb")) == NULL)
  {
		puts("O arquivo-fonte não pode ser aberto");
		exit(1);
	}

	if ((out = fopen(argv[2], "wb")) == NULL)
  {
		puts("O arquivo destino não pode ser aberto");
		exit(1);
	}

	while (!feof(in))
  {
		ch = fgetc(in);
		if (!feof(in)) fputc(ch, out);
	}
}
