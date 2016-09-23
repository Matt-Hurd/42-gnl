/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 01:40:15 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/22 01:50:54 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if ((ret = (t_list *)ft_memalloc(sizeof(t_list *))))
	{
		ret->content = ft_memalloc(content_size);
		ret->content = ft_memcpy(ret->content, content, content_size);
		ret->content_size = content ? content_size : 0;
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}
