/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:05:24 by eaptekar          #+#    #+#             */
/*   Updated: 2018/10/03 16:48:29 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_lstpushback(t_list **blst, void const *content, size_t content_size)
{
	t_list	*list;

	list = *blst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(content, content_size);
	}
	else
		*blst = ft_lstnew(content, content_size);
}

static void		del_node(void *item, size_t size)
{
	size = 0;
	free(item);
}

void		parse_file(char *argv)
{
	int		fd;
	char	*line;
	t_list	*list;
	t_list	*head;

	if (!(fd = open(argv, O_RDONLY)))
		ERROR(strerror(errno));
	if ((read(fd, NULL, 0)) < 0)
		ERROR(strerror(errno));
	list = NULL;
	while(get_next_line(fd, &line) == 1)
	{
		// printf("line:%s - %zu\n", line, ft_strlen(line));
		ft_lstpushback(&list, line, ft_strlen(line));
		// ft_lstadd(&list, ft_lstnew(line, ft_strlen(line)));
		// printf("list:%s\n", list->content);
		free(line);
	}
	head = list;
	while (head)
	{
		printf("%s\n", head->content);
		head = head->next;
	}
	ft_lstdel(&list, &del_node);
	system("leaks RTv1");
}
