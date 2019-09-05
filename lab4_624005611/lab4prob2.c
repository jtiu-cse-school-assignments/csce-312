
#include <stdio.h>
#include <stdlib.h>

void writeToRAM(int ram[],int pos, int inp)
{
	ram[pos] = inp;
}

void readRAM(int ram[],int pos)
{
	printf("\nPosition %i has the value %i\n",pos,ram[pos]);
}

void readROM(int rom[], int pos)
{
	printf("\nPosition %i has the value %i\n",pos,rom[pos]);
}

int main()
{
		int RAM[256]; 
		int ROM[256];
		int counter;
		for(counter = 0;counter<256;counter++)
		{
			ROM[counter] = counter;
		}

		RAM[7] = 5;
		ROM[7] = 9;
		int answer = 0;
		
		for(;;)
		{
			printf("\n Would you like to:\n 1-> Read RAM?\n 2-> Read ROM?\n 3-> Write to RAM?\n Enter a Number. ");
			scanf("%i", &answer);
			if(answer == 1)
			{
				int position;
				do
				{
					printf("Where do you want to read from in RAM? (Enter number from 0-255) ");
					scanf("%i", &position);
				}while(position < 0 || position > 255);
				readRAM(RAM,position);
			}
			else if(answer == 2)
			{
				int position;
				do
				{
					printf("Where do you want to read from in ROM? (Enter number from 0-255) ");
					scanf("%i", &position);
				}while(position < 0 || position > 255);
				
				readROM(ROM,position);
			}
			else if(answer == 3)
			{
				int position,value;
				do
				{
					printf("Where do you want to write to in RAM? (Enter number from 0-255) ");
					scanf("%i", &position);
				}while(position < 0 || position > 255);
				do
				{
					printf("What do you want to write into RAM? (Enter number from 0 - 255) ");
					scanf("%i", &value);
				}while(value < 0 || value > 256);
				
				writeToRAM(RAM,position,value);
			}
		}
			
}