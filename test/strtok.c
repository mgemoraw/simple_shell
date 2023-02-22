#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "This is the way.";
	char d[] = " ";

	char *portion1 = strtok(s, d);

	while (portion1 != NULL)
	{
		printf("%s\n", portion1);
		portion1 = strtok(NULL, d);
	}
	const char *ss = "What is happening to this computer?";

	ss = "sizeof operator";

	printf("%s\n", ss);
	return (0);
}
