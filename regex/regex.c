#include "regex.h"
/**
 * regex_match - Checks a given pattern matches with a given string
 * @str: Given string
 * @pattern: Given pattern
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t.
 */
int regex_match(char const *str, char const *pattern)
{
	int j = 0;
	int asterisk = 0;

	if (!str || !pattern)
		return (0);

	j = *str && (*str == *pattern || *pattern == '.');
	asterisk = *(pattern + 1) == '*';

	if (!*str && !asterisk)
		return (*pattern ? 0 : 1);
	else if (j && asterisk)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (j && !asterisk)
		return (regex_match(str + 1, pattern + 1));
	else if (asterisk)
		return (regex_match(str, pattern + 2));
	return (0);
}
