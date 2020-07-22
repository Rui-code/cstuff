#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void bublesort (char *items, int len);


int main (int argc, char *argv[])
{

	if (argc != 2)
	{
		puts("uso: buble_order \"<texto>\"");
		exit(1);
	}

	bublesort(argv[1], strlen(argv[1]));
	puts(argv[1]);

	return 0;
}

void bublesort (char *items, int len)
{
	uint8_t a, b;
	char t;
	
	for (a = 1; a < len; ++a)
	{
		for (b = len - 1; b >= a; --b)
		{
			if (items[b - 1] > items[b])
			{
				t = items[b - 1];
				items[b - 1] = items[b];
				items[b] = t;
			}
		}
	}
}
