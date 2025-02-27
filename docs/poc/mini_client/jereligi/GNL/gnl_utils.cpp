/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:53:26 by mli               #+#    #+#             */
/*   Updated: 2021/03/22 12:29:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_lstclear_gnl(t_gnl **alst)
{
	t_gnl	*tmp;

	while ((*alst)->next)
	{
		tmp = (*alst);
		*alst = (*alst)->next;
		free(tmp->tab);
		free(tmp);
	}
}

t_gnl		*ft_lstnew_gnl(int fd)
{
	t_gnl	*newNode;

	if (!(newNode = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	newNode->min = 0;
	if (!(newNode->tab = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
	{
		free(newNode);
		return (NULL);
	}
	if ((newNode->max = read(fd, newNode->tab, BUFFER_SIZE)) < 0)
	{
		free(newNode->tab);
		newNode->tab = NULL;
		free(newNode);
		return (NULL);
	}
	newNode->next = 0;
	return (newNode);
}

t_fdlst		*ft_addfront_fd(t_fdlst **astruct, int fd)
{
	t_fdlst	*newNode;

	if (!(newNode = (t_fdlst *)malloc(sizeof(*newNode))))
		return (NULL);
	newNode->fd = fd;
	if (!(newNode->list = ft_lstnew_gnl(fd)))
	{
		free(newNode);
		return (NULL);
	}
	newNode->next = *astruct;
	*astruct = newNode;
	return (newNode);
}

void		ft_total_remove_fd(t_fdlst **begin_fd, t_fdlst *to_delete_fd)
{
	t_gnl		*current;
	t_gnl		*then;
	t_fdlst		*tmp_fd;

	if (!to_delete_fd)
		return ;
	current = to_delete_fd->list;
	while (current)
	{
		then = current->next;
		free(current->tab);
		free(current);
		current = then;
	}
	to_delete_fd->list = NULL;
	if (*begin_fd == to_delete_fd)
		*begin_fd = to_delete_fd->next;
	else
	{
		tmp_fd = *begin_fd;
		while (tmp_fd->next && tmp_fd->next != to_delete_fd)
			tmp_fd = tmp_fd->next;
		tmp_fd->next = tmp_fd->next->next;
	}
	free(to_delete_fd);
}

int			get_next_line(int fd, char **line)
{
	int					return_value;
	static t_fdlst		*begin_fd = NULL;
	t_fdlst				*right_fd;

	right_fd = begin_fd;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (right_fd && right_fd->fd != fd)
		right_fd = right_fd->next;
	if (!line)
	{
		ft_total_remove_fd(&begin_fd, right_fd);
		return (-1);
	}
	if (right_fd == NULL)
	{
		if (!ft_addfront_fd(&begin_fd, fd))
			return (-1);
		right_fd = begin_fd;
	}
	return_value = ft_gnl(fd, line, &(right_fd->list));
	if (return_value == 0 || return_value == (-1))
		ft_total_remove_fd(&begin_fd, right_fd);
	return (return_value);
}
