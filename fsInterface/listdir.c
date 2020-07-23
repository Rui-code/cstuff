#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define DIR_NAME_SIZE 256

int main(int argc, char * argv[])
{

	if (argc != 2) 
	{
		puts("Argumento necessario");
		exit(1);
	}

	DIR * dir_destino;
	struct dirent * dir_content;

	dir_destino = opendir(argv[1]);

	if (dir_destino != NULL)
	{
		while (dir_content = readdir(dir_destino))
			puts(dir_content->d_name);

		(void) closedir(dir_destino);
	} else
		puts("Erro ao listar o diretorio");
	
	return 0;
}
