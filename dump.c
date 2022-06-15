#include <stdio.h>
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Using: %s <file>\n", argv[0]);
		return -1;
	}
	FILE* file = fopen(argv[1], "r");
	if (!file)
	{
		printf("File open error\n");
		return -1;
	}
	int ch;
	unsigned i = 0;
	char str[17];
	str[16] = 0;
	do
	{
		printf("%08x  ", i);
		for (int c = 0; c < 9; c += 8)
		{
			for (int j = 0; j < 8; j++)
				if ((ch = getc(file)) != EOF)
				{
					printf("%02x ", ch);
					if (ch < 32)
						ch = '.';
					str[c + j] = ch;
				}
				else
				{
					printf("   ");
					str[c + j] = ' ';
				}
			printf(" ");
		}
		printf("%s\n", str);
		i += 16;
	} while (ch != EOF);
	fclose(file);
}
