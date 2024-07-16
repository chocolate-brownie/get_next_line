/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:14:40 by mgodawat          #+#    #+#             */
/*   Updated: 2024/07/16 10:44:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	update_and_clean(t_list **list)
{
	t_list	*clean_node;
	t_list	*last_node;
	char	*new_buffer;
	int		i;
	int		k;

	clean_node = malloc(sizeof(t_list));
	new_buffer = malloc(BUFFER_SIZE + 1);
	if (!clean_node || !new_buffer)
		return ;
	last_node = find_last_node(*list);
	if (!last_node || !last_node->str_buf)
		return ;
	i = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		new_buffer[k++] = last_node->str_buf[i];
	new_buffer[k] = '\0';
	clean_node->str_buf = new_buffer;
	clean_node->next = NULL;
	free_nodes(list, clean_node, new_buffer);
}

char	*get_line_from_list(t_list *list)
{
	char	*next_line;
	int		len_to_newline;

	if (!list)
		return (NULL);
	len_to_newline = strlen_newline(list);
	next_line = malloc(len_to_newline + 1);
	if (!next_line)
		return (NULL);
	copy_string(list, next_line);
	return (next_line);
}

void	append_node(t_list **list, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buf);
		return ;
	}
	last_node = find_last_node(list[fd]);
	if (!last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!found_newline(list[fd]))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			if (char_read < 0)
			{
				free_nodes(list, NULL, NULL);
				return ;
			}
			break ;
		}
		buffer[char_read] = '\0';
		append_node(list, buffer, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[1024];
	char			*next_line;
	t_list			*temp;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		if (list[fd])
		{
			while (list[fd] != NULL)
			{
				temp = list[fd]->next;
				free(list[fd]->str_buf);
				free(list[fd]);
				list[fd] = temp;
			}
		}
		return (NULL);
	}
	create_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_line_from_list(list[fd]);
	update_and_clean(&list[fd]);
	return (next_line);
}
