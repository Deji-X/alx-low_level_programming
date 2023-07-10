#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the
 *			POSIX standard output.
 * @filename: path to file
 * @letters: Number of characters to print
 *
 * Return: The number of letters it should read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp, fp1, fp2, fp3;
	char *str;

	if (!filename)
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1)
		return (0);

	str = malloc(sizeof(char) * letters);
	if (!str)
		return (0);

	fp1 = read(fp, str, letters);
	if (fp1 == -1)
	{
		free(str);
		return (0);
	}

	fp2 = write(STDOUT_FILENO, str, fp1);
	if (fp2 == -1 || fp1 != fp2)
	{
		free(str);
		return (0);
	}

	fp3 = close(fp);
	if (fp3 == -1)
	{
		free(str);
		return (0);
	}
	free(str);
	return (fp2);
}
