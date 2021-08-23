#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  FILE* file = NULL;
  char current_character = 0;
  int counter = 0;
  if (argc > 1)
	{
	  /* Go through all the files. */
	  for (int filecounter = 1; filecounter < argc; filecounter++ )
		{
		  file = fopen(argv[filecounter], "r");

		  /* Go through the file. */
		  while(feof(file) != 1)
			{
			  /* Get the four byte integer. */
			  fread(&counter, sizeof(4), 1, file);
			  /* Get the character. */
			  current_character = fgetc(file);
			  /* Print enough characters for the integer. */
			  while (counter >= 0)
				{
				  printf("%c", current_character);
				  counter--;
				}
			  counter = 0;
			}
		}
	  fclose(file);
	}
  else
	{
	  fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
	  exit(1);
	}
  return 0;
}
