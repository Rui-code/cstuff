#include <stdio.h>
#include <stdlib.h>

void main (int argc, char * argv[])
{
	
	FILE *fp;
	char ch;

	if (argc > 3 || argc < 2)
  {
		puts("Você esqueceu de digitar o nome do arquivo.");
		exit(1);
	}

	if (argv[2] = "-b")
  {
		if ((fp = fopen(argv[1], "rb")) == NULL)
    {
			puts("O arquivo não pode ser aberto");
			exit(1);
		}
	} else if ((fp = fopen(argv[1], "r")) == NULL)
  {
		puts("O arquivo não pode ser aberto.");
		exit(1);
	}

	ch = fgetc(fp);

	while (ch != EOF)
  {
		putchar(ch);
		ch = fgetc(fp);
	}

	puts("");

	fclose(fp);
}
