/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagecollector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:04:08 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/25 17:34:22 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "garbagecollector.h"

t_mem	*gc_new(size_t size);
t_mem	*gc_get(void *p);
void	gc_del(t_mem *p);

void	*gc_malloc(size_t size)
{
	t_mem	*p;

	p = gc_new(size);
	if (!p)
		return (NULL);
	return (p->p);
}

void	*gc_calloc(size_t nmemb, size_t size)
{
	t_mem			*p;
	unsigned char	*tmp;
	size_t			total_size;

	p = NULL;
	total_size = nmemb * size;
	if (!nmemb || !size || nmemb == total_size / size)
		p = gc_new(nmemb * size);
	if (!p)
		return (NULL);
	tmp = p->p;
	while (total_size--)
		*(tmp + total_size) = '\0';
	return (p->p);
}

void	*gc_realloc(void *ptr, size_t size)
{
	t_mem			*p;
	t_mem			*new;
	unsigned char	*p1;
	unsigned char	*p2;

	p = gc_get(ptr);
	if (!p)
		return (gc_malloc(size));
	new = gc_new(size);
	if (!new)
		return (new);
	p1 = new->p;
	p2 = ptr;
	while (p->size--)
		*(p1 + p->size) = *(p2 + p->size);
	gc_del(p);
	return (new->p);
}

void	gc_free(void *ptr)
{
	gc_del(ptr);
}
