/* stonl — Space to new line
 *
 * Author: grot
 * License: 0-clause BSD
 *
 * Additional thanks to celt for helping with code
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int getFileSize(const char *fileName)
{
    struct stat file_stat;

    stat(fileName, &file_stat);
    return file_stat.st_size;
}

int main(int argc, char* argv[])
{
	FILE *target = fopen(argv[1], "r");
	int counter;

	if(argc != 3)
	{
		printf("No arguments given.\nUsage: stonl <FILE> [NUMBER OF SPACES TO REPLACE]\n");
		return 1;
	}

	if(target == NULL)
	{
		printf("No such file.\nUsage: stonl <FILE> [NUMBER OF SPACES TO REPLACE]\n");
		return 1;
	}

	int newStringsAmount = argc == 3 ? atoi(argv[2]) : 0;

	char *fileContent = malloc(getFileSize(argv[1]));

	for(counter = 0; counter < getFileSize(argv[1]); ++counter)
		fileContent[counter] = (char)fgetc(target);

	for(counter = 0; newStringsAmount >= 1 && fileContent[counter] != 0; ++counter)
		if(fileContent[counter] == ' ')
			--newStringsAmount;

	for(; fileContent[counter] != 0; ++counter)
		if(fileContent[counter] == ' ')
			fileContent[counter] = '\n';

	printf("%s\n", fileContent);
	free(fileContent);
	fclose(target);

	return 0;
}
