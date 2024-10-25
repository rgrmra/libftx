/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagecollector.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:24:33 by rde-mour          #+#    #+#             */
/*   Updated: 2024/10/25 17:31:32 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGECOLLECTOR_H
# define GARBAGECOLLECTOR_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_mem
{
	size_t	size;
	void	*p;
	void	*next;
}	t_mem;

void	gc_flush(void);
void	*gc_malloc(size_t size);
void	*gc_calloc(size_t nmemb, size_t size);
void	*gc_realloc(void *ptr, size_t size);
void	gc_free(void *ptr);

#endif
