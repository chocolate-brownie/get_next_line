/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:15:09 by mgodawat          #+#    #+#             */
/*   Updated: 2024/07/15 16:34:54 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	strlen_newline(t_list *list)
{
	int	length;
	int	curr_pos;

	length = 0;
	if (!list)
		return (0);
	while (list)
	{
		curr_pos = 0;
		while (list->str_buf[curr_pos])
		{
			if (list->str_buf[curr_pos] == '\n')
				return (length + 1);
			curr_pos++;
			length++;
		}
		list = list->next;
	}
	return (length);
}

void	free_nodes(t_list **list, t_list *clean_node, char *buff)
{
	t_list	*current;
	t_list	*temp;

	current = *list;
	while (current != NULL)
	{
		temp = current->next;
		free(current->str_buf);
		free(current);
		current = temp;
	}
	if (clean_node && clean_node->str_buf[0] != '\0')
		*list = clean_node;
	else
	{
		if (buff)
			free(buff);
		if (clean_node)
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
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	copy_string(t_list *src, char *dest)
{
	int	list_i;
	int	dest_j;

	dest_j = 0;
	if (!src)
		return ;
	while (src)
	{
		list_i = 0;
		while (src->str_buf[list_i])
		{
			if (src->str_buf[list_i] == '\n')
			{
				dest[dest_j++] = '\n';
				dest[dest_j] = '\0';
				return ;
			}
			dest[dest_j++] = src->str_buf[list_i++];
		}
		src = src->next;
	}
	dest[dest_j] = '\0';
}

t_list	*find_last_node(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
