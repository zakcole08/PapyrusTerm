#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\e[1;1H\e[2J")

void start()
{
	int lineNum = 1;
	clear();
        printf("      Papyrus\n      ---------------\n");
        printf("      %d| ", lineNum);
        while (1)
        {
                if (getchar() == '\n')
                {
                        lineNum++;
                        
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
	}
}

int main()
{
	start();
}
