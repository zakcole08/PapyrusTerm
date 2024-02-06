#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\e[1;1H\e[2J")

char fileName[100];
FILE *file;
int lineNum = 1;

void print_lineNum()
{
	if (lineNum < 10)
	{
		printf("      %d| ", lineNum);
	}
	if (lineNum >= 10 && lineNum < 100)
	{
		printf("     %d| ", lineNum);
	}
	if (lineNum >= 100 && lineNum < 1000)
	{
		printf("    %d| ", lineNum);
	}
	if (lineNum >= 1000 && lineNum < 10000)
	{
		printf("   %d| ", lineNum);
	}
	if (lineNum >= 10000 && lineNum < 100000)
	{
		printf("  %d| ", lineNum);
	}
	if (lineNum >= 100000 && lineNum < 1000000)
	{
		printf(" %d| ", lineNum);
	}
	if (lineNum >= 1000000 && lineNum < 10000000)
	{
		printf("%d| ", lineNum);
	}
}

int open(char *fileName)
{
	// Print the initial UI
    	clear();
    	printf("       _______\n");
    	printf("      |Papyrus|\n");
    	printf("      |==============================================\n");
    	printf("      | Use Ctrl-D to save and exit or Ctrl-C to exit|\n");
    	printf("       ----------------------------------------------\n");
    	printf("      1| ");
	
    	// Open the file in write mode
    	file = fopen(fileName, "r+");
	
    	if (file == NULL)
    	{
		clear();
		printf("Error opening file.\n");
		exit(1);
    	}
    	return 0;
}

void edit()
{
    	while (1)
    	{
    	    int ch = getchar();
	
	        if (ch == EOF || ch == 4) // EOF or Ctrl-D to exit the loop
	        {
			printf("\n---File saved---\n\n");
	       		break;
	        }
	        else if (ch == '\n')
        	{
        		lineNum++;
        		fprintf(file, "\n");		// Output this to file
        		print_lineNum();
		}
        	else
        	{
        		// Write the character to the file
        		fputc(ch, file);
        	}	
	}
	// Close the file when done
        fclose(file);
}

int main(int argc, char *argv[])
{
	if (argc != 2 || argv == NULL)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
    	open(argv[1]);
    	edit();
    	return 0;
}

