#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\e[1;1H\e[2J")

char fileName[100];
FILE *file;
int lineNum = 1;

int open()
{
    clear();
        // Get the filename from the user
    printf("Enter filename to save: ");
    scanf("%s", fileName);
    getchar(); // Consume the \n so it isn't read into buffer
	// Print the initial UI
    printf("      Papyrus\n      ---------------\n");
    printf("      1| ");

    // Open the file in write mode
    file = fopen(fileName, "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
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
            printf("      %d| ", lineNum);	// Output this to terminal
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

int main()
{
    open();
    edit();
    return 0;
}

