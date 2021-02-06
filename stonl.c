/* stonl — Space to new line
 *
 * Author: grot
 * License: 0-clause BSD
 *
 * Additional thanks to celt for helping with code
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *target = fopen(argv[1], "r");
	int counter = 0;
	char fileContent[100];

	if(target == NULL)
	{
		printf("No such file.\nUsage: stonl <FILE> [NUMBER OF SPACES]\n");

		return 1;
	}

	fgets(fileContent, 100, target);

	int newStringsAmount = argc == 3 ? atoi(argv[2]) : 0;

	for(counter = 0; newStringsAmount >= 1 && fileContent[counter] != 0; ++counter)
		if(fileContent[counter] == ' ')
			--newStringsAmount;

	for(; fileContent[counter] != 0; ++counter)
		if(fileContent[counter] == ' ')
			fileContent[counter] = '\n';

	printf("%s\n", fileContent);

	fclose(target);

	return 0;
}
