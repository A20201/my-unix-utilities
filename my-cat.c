#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
  FILE* file = NULL;
  int counter = 1;
  /* Checks if the program has one or more arguments. */
  if( argc > 1)
	{
	  /* Goes through the arguments. */
	  while (counter < argc)
		{
		  /* Checks if the program has two or more arguments */
		  if (argc >= 2)
			{
			  /* Opens a file corresponding to argument at counter position. */
			  file = fopen(argv[counter], "r");
			}
		  
		  /* Checks if file could be opened. */
		  if (file)
			{
			  char c = 0;
			  
			  /* Prints the all characters in the file one by one. */
			  while((c = fgetc(file)) != EOF)
				{
				  fprintf(stdout, "%c", c);
				}
			  
			  fclose(file);
			}
		  else
			{
			  fprintf(stderr, "my-cat: cannot open file\n");
			  exit(1);
			}
		  counter++;
		}
	}
  return 0;
}
