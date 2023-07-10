#include "main.h"

/**
 * main - Copies the content of a file to another file.
 * @argc: Argument Counter
 * @argv: Argument Vector
 *
 * Return: 0 for success.
 */
int main(int argc, char *argv[])
{
	char *file_from, *file_to, *str;
	int fp_from, fp_to, fp1_from, fp1_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	str = malloc(1024 * sizeof(char));
	if (!str)
		file_to_error(file_to, str);
	fp_from = open(file_from, O_RDONLY);
	if (fp_from == -1)
		file_from_error(file_from, str);
	fp_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fp_to == -1)
		file_to_error(file_to, str);
	fp1_from = read(fp_from, str, 1024);
	if (fp1_from == -1)
		file_from_error(file_from, str);
	do {
		fp1_to = write(fp_to, str, fp1_from);
		if (fp1_to == -1)
			file_to_error(file_to, str);
		fp1_from = read(fp_from, str, 1024);
		if (fp1_from == -1)
			file_from_error(file_from, str);
		fp_to = open(file_to, O_WRONLY | O_APPEND);
		if (fp_to == -1)
			file_to_error(file_to, str);
	} while (fp1_from > 0);
	free(str);
	close_fd(fp_from);
	close_fd(fp_to);
	return (0);
}
