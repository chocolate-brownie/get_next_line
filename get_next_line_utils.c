/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:11:20 by mgodawat          #+#    #+#             */
/*   Updated: 2024/07/11 19:03:31 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_nodes(t_list **list, t_list *clean_node, char *buff)
{
	t_list *current = *list;
	while (current != NULL)
	{
		t_list *temp = current->next;
		free(current->str_buf);
		free(current);
		current = temp;
	}
	// handle the clean node
	if (clean_node->str_buf[0] != '\0')
		*list = clean_node;
	else
	{
		free(buff);
		free(clean_node);
		*list = NULL;	
	}
}
int	found_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	counter;
	char			search;

	counter = 0;
	search = (char)c;
	while (s[counter] != '\0')
	{
		if (s[counter] == search)
			return ((char *)&s[counter]);
		counter++;
	}
	if (s[counter] == search)
		return ((char *)&s[counter]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

void	copy_string(t_list *src, char *dest)
{
	printf("\t\t\tI am inside the copy_string function\n");
	int list_i; // var to traverse the linked list
	int dest_j; // var to increment the *dest and copy content from the src
	dest_j = 0;
	if (!src)
		return ;
	// traverse the nodes
	while (src)
	{
		list_i = 0;
		// traverse the str_buf until NULL
		while (src->str_buf[list_i])
		{
			/* copy the content from src to dest but if you find the \n
			add the position of \n(1 byte) and the '\0'(1 byte) accordingly */
			if (src->str_buf[list_i] == '\n')
			{
				dest[dest_j++] = '\n';
				dest[dest_j] = '\0';
				return ;
			}
			dest[dest_j++] = src->str_buf[list_i++];
		}
		// else travel to the next node and keep copying
		src = src->next;
	}
	// null terminate the dest string
	dest[dest_j] = '\0';
	printf("\t\tCopy string function executed\n");
}

t_list	*find_last_node(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

