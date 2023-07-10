#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: path to file
 * @text_content: text_content.
 *
 * Return: 1 on success and -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fp, fp1, fp2;

	if (!filename)
		return (-1);

	fp = creat(filename, 0600);
	if (fp == -1)
		return (-1);

	if (text_content)
	{
		fp1 = write(fp, text_content, strlen(text_content));
		if (fp1 == -1)
			return (-1);
	}

	fp2 = close(fp);
	if (fp2 == -1)
		return (-1);

	return (1);
}
