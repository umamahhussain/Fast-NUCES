#include <stdio.h>
#include <string.h>

int main()
{
FILE* f;
f = fopen("f.txt", "r");
char str[500];
fgets(str, 500, f);
printf("%s", str);

char word[10];
printf("\nEnter Word :");
scanf("%s", word);
printf("%s", word);
int len = strlen(str);
int flag = 0;
int wordlen = strlen(word);
int count = 0;

for (int i = 0; i < len; i++)
{
if (str[i] == word[0])
{
for (int j = 0; j < wordlen; j++)
{
if (str[i] == word[j])
{
i++;
flag = 1;
}
else
{
flag = 0;
break;
}
}

if (flag == 1)
{
count++;
}
}
}

printf("\nThe value of count is: %d", count);
}
