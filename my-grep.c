/*
Aki Laaksonen
aki.laaksonen@student.lut.fi
Course CT30A3370
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(char** search, char** line)
{
  for (unsigned int counter = 0; counter < strlen(*line); counter++)
	{
	  /* Checks if the current character matches the start of the search. */
	  if((*search)[0] == (*line)[counter])
		{
		  unsigned char c2 = 0;
		  /* Creates a subline that has the length of the search term. */
		  char subline[strlen(*search)];
		  /* Copies the match length of characters to the subline from the line. */
		  while (c2 < strlen(*search))
			{
			  subline[c2] = (*line)[counter+c2];
			  c2++;
			}
		  subline[c2] = '\n';
		  
		  /* Compares the search term and subline and prints the line if they match. */
		  if(strncmp(*search, subline, strlen(*search)) == 0)
			printf("%s", *line);
		}
	}
  return 0;
}

int main(int argc, char** argv)
{
  FILE* file = NULL;
  size_t len = 0;
  ssize_t nread = 0;
  char* search = argv[1];
  char* line = NULL;
  /* Checks if there are arguments. */
  if( argc > 1)
	{
	  /* Checks if the are more than one argument. */
	  if(argc > 2)
		{
		  /* Checks if there are more than two arguments. */
		  if(argc >= 3)
			{
			  /* Iterates through the files passed as arguments. */
			  for (int filecounter = 2; filecounter < argc; filecounter++)
				{
				  /* Opens a file and checks if it is opened. */
				  if((file = fopen(argv[filecounter], "r")) != NULL)
					{
					  /* Goes through the file line by line. */
					  while ((nread = getline(&line, &len, file)) != -1)
						{
						  /* Performs a checking for the match. */
						  match(&search, &line);
						}	  
					  fclose(file);
					}
				  else
					{
					  fprintf(stderr, "my-grep: cannot open file\n");
					  exit(1);
					}
				}
			}
		}
	  else
		{
		  /* Gets a line from the user. */
		  getline(&line, &len, stdin);

		  /* Performs a checking for the match. */
		  match(&search, &line);
		}
	}
  else
	{
	  fprintf(stderr, "my-grep: searchterm [file ...]\n");
	  exit(1);
	}
  free(line);
  return 0;
}
