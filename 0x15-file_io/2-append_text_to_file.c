#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Pathye to file
 * @text_content: text content
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fp, fp1, fp2;

	if (!filename)
		return (-1);

	fp = open(filename, O_APPEND | O_WRONLY);
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
