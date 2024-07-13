/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:11:30 by mgodawat          #+#    #+#             */
/*   Updated: 2024/07/13 17:57:29 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

// update and clean the nodes
void	update_and_clean(t_list **list)
{
	t_list	*clean_node;
	t_list	*last_node;
	char	*new_buffer;

	// malloc for the clean_node and the buffer
	clean_node = malloc(sizeof(t_list));
	new_buffer = malloc(BUFFER_SIZE + 1);
	if (!clean_node || !new_buffer)
		return;
	// find the last_node
	last_node = find_last_node(*list);	
	// find the current /n position
	int i = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	/* count from the current \n position upuntil the null to detect remaining
	data and copy it to the new buffer */
	int k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
			new_buffer[k++] = last_node->str_buf[i];
	// create the clean node
	clean_node->str_buf = new_buffer;
	clean_node->next = NULL;
	// clean all the nodes and memory leaks
	free_nodes(list, clean_node, new_buffer);
}

// extract the line from the linked list
char	*get_line(t_list *list)
{
	size_t	str_len;
	t_list	*temp;
	char	*newline_pos;
	char	*next_str;

	printf("\tEntering the get_line function\n");
	str_len = 0;
	if (!list)
		return (NULL);
	temp = list;
	while (temp)
	{
		// find the newline position
		newline_pos = strchr(temp->str_buf, '\n');
		/* if find the \n position count the len from the start of the buff
		to upuntil \n position including the \n char */
		if (newline_pos)
		{
			str_len += newline_pos - temp->str_buf + 1;
			break ;
		}
		/* else count the whole str_bufs len and return it to the str_len*/
		str_len += strlen(temp->str_buf);
		// go the next node
		temp = temp->next;
	}
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	// copy the str_buf from the node to the dest variable
	printf("\t\tEntering the copy string function inside getline function\n");
	copy_string(list, next_str);
	return (next_str);
	printf("Exiting the getline function");
}

void	append_node(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	printf("\t\tEntering append node function\n");
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	last_node = find_last_node(*list);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
	printf("\t\tappend node function excecuted\n");
}

// read the fd until you encounter \n
void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	printf("\tI am inside create lists function\n");
	while (!found_newline(*list))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		// add a new node to the static linked list
		append_node(list, buffer);
	}
	printf("\tcreate line executed\n");
}

// main function to read the next line from the file descriptor
char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	printf("\n\nStep 1:	Creating next line\n");
	create_list(&list, fd);
	if (!list)
		return (NULL);
	printf("\n\nStep 2:	trying to get line\n");
	next_line = get_line(list);
	update_and_clean(&list);
	return (next_line);
}
