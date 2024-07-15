/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:05:59 by mgodawat          #+#    #+#             */
/*   Updated: 2024/07/15 12:58:34 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				free_nodes(t_list **list, t_list *clean_node, char *buff);
t_list				*find_last_node(t_list *list);
int					strlen_newline(t_list *list);
int					found_newline(t_list *list);
void				copy_string(t_list *src, char *dest);

#endif
