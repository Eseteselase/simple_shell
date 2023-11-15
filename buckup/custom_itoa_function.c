#include "shell.h"

void custom_itoa(int value, char *str)
{
	int i = 0;
	int temp = value;
	int j;

	while (temp)
	{
		temp /= 10;
		i++;
	}
	if (value == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	j = i - 1;
	while (value)
	{
		str[j--] = '0' + (value % 10);
		value /= 10;
	}
	str[i] = '\0';
}
