/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:16:09 by mgodawat          #+#    #+#             */
/*   Updated: 2024/07/16 11:05:47 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

void	test1(int fd1, int fd2)
{
	char	*line;
	int		lines1;
	int		lines2;

	lines1 = 1;
	lines2 = 1;
	line = get_next_line(fd1);
	printf("\n");
	while (line)
	{
		printf("File 1, Line %d --> %s", lines1++, line);
		free(line);
		line = get_next_line(fd1);
	}
	printf("\n");
	line = get_next_line(fd2);
	while (line)
	{
		printf("File 2, Line %d --> %s", lines2++, line);
		free(line);
		line = get_next_line(fd2);
	}
	printf("\n");
}

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("read_error.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("open read_error.txt");
		return (1);
	}
	if (fd2 == -1)
	{
		perror("open file2.txt");
		close(fd1);
		return (1);
	}
	test1(fd1, fd2);
	close(fd1);
	close(fd2);
	return (0);
}
