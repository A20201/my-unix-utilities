/*
Aki Laaksonen
aki.laaksonen@student.lut.fi
Course CT30A3370
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  FILE* file = NULL;
  int counter = 0;
  char current_character = 0;
  char past_character = 0;
  /* Check if there one or more arguments. */
  if (argc > 1)
	{
	  /* Go through all files. */
	  for (int filecounter = 1; filecounter < argc; filecounter++)
		{	
		  file = fopen(argv[filecounter], "r");

		  /* Go through the file one character at a time. */
		  while ((current_character = fgetc(file)) != EOF)
			{
			  if(current_character == past_character)
				{
				  counter++;
				}
			  else
				{
				  /* Write the 4-byte integer and after it the character. */
				  fwrite(&counter, sizeof(int), 1, stdout);
				  fprintf(stdout, "%c", current_character);
				  counter = 0;
				}
			  past_character = current_character;
			}
		  fclose(file);
		}
	}
  else
	{
	  fprintf(stderr, "my-zip: file1 [file2 ...]\n");
	  exit(1);
	}
  return 0;
}
