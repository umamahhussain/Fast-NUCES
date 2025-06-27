#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	float result1 = 0;
	float result2 = 0;
	float avg = 0;
	int count = 0;
	int output = 0;
	
	while(1)
	{
		FILE *read = fopen("/proc/stat", "r");
		char buff[100];
		fgets(buff, 100, read);
		printf("%s\n", buff);
		fclose(read);
		
		int i = 0;
		while(buff[i] != ' ')
			i++;
		i += 2;
		
		float sum = 0;
		float res3 = 0;
		float sum2 = 0;
		
		int counter = 3;
		while(counter > 0)
		{
			float res2 = 0;
			while(buff[i] != ' ')
			{
				char res1 = buff[i];
				res2 = res2 * 10;
				res2 = (float)res1 + res2;
				i++;
			}
			
			sum = sum + res2;
			counter = counter - 1;
			i++;
		}
		
		counter = 2;
		while(counter > 0)
		{
			float res2 = 0;
			while(buff[i] != ' ')
			{
				char res1 = buff[i];
				res2 = res2 * 10;
				res2 = (float)res1 + res2;
				i++;
			}
			
			res3 = res3 + res2;
			counter = counter - 1;
			i++;
		}
		
		counter = 2;
		while(counter > 0)
		{
			float res2 = 0;
			while(buff[i] != ' ')
			{
				char res1 = buff[i];
				res2 = res2 * 10;
				res2 = (float)res1 + res2;
				i++;
			}
			
			sum2 = sum2 + res2;
			counter = counter - 1;
			i++;
		}
		
		if (count == 0) 
		{
			result1 = sum/(res3 + sum2 + sum);
			count++;
		}
		else
		{
			result2 = sum/(res3 + sum2 + sum);
			count = 0;
			output = 1;
		}
		
		if (output)
		{
			avg = ((result1 + result2)/2) * 100;
			printf("%f\n", avg);
			avg = 0;
			result1 = 0;
			result2 = 0;
			output = 0;
		}

		sleep(1);
	}

	return 0;
}

