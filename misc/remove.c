#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
	char str[80];
	if (argc != 2)
  {
		puts("uso: remove <nomearq>\n");
		exit(1);
	}

	printf("apagar %s? (S/N): ", argv[1]);
	gets(str);

	if (toupper(*str) == 'S')
  {
		if (remove(argv[1]))
    {
			puts("O arquivo não pode ser apagado.");
			exit(1);
		}
	}

	return 0;
}
