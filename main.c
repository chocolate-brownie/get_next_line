/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:35:09 by mgodawat          #+#    #+#             */
/*   Updated: 2024/07/15 11:58:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%d -->  %s", lines++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
