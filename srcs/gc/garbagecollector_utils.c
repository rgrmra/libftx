/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagecollector_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:31:50 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/25 17:33:18 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "garbagecollector.h"

static t_mem	*gc(void *p)
{
	static t_mem	*list;

	if (p)
		list = p;
	return (list);
}

t_mem	*gc_new(size_t size)
{
	t_mem	*p;

	p = (t_mem *) malloc(sizeof(t_mem));
	if (!p)
		return (NULL);
	p->p = (void *) malloc(size);
	if (!p->p)
	{
		free(p);
		return (NULL);
	}
	p->size = size;
	p->next = gc(NULL);
	gc(p);
	return (p);
}

t_mem	*gc_get(void *p)
{
	t_mem	*list;

	list = gc(NULL);
	while (list)
	{
		if (list->p == p)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	gc_del(t_mem *p)
{
	t_mem	*list;
	t_mem	*tmp;

	list = gc(NULL);
	tmp = NULL;
	while (list)
	{
		if (list->p == p)
		{
			if (tmp == NULL)
				tmp = list->next;
			else
				tmp->next = list->next;
			free(p->p);
			free(p);
		}
		tmp = list;
		list = list->next;
	}
}

void	gc_flush(void)
{
	t_mem	*list;
	t_mem	*tmp;

	list = gc(NULL);
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->p);
		free(tmp);
	}
}
