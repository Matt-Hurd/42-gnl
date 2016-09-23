/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 22:04:36 by kyork             #+#    #+#             */
/*   Updated: 2016/09/22 13:07:24 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int			g_alloc_count = 0;
static int	g_have_registered = 0;

static void	print_alloc_count(void)
{
	if (g_alloc_count != 0)
		printf("FAIL: %d mallocs not freed\n", g_alloc_count);
	else
		printf("[OK]: all allocations freed\n");
}

void		*malloc(size_t sz)
{
	void	*(*libc_malloc)(size_t);
	void	*addr_alloc;

	if (!g_have_registered)
	{
		atexit(print_alloc_count);
		g_have_registered = 1;
	}
	libc_malloc = dlsym(RTLD_NEXT, "malloc");
	addr_alloc = libc_malloc(sz);
	g_alloc_count++;
	printf("malloc(%ld) = %p\n", sz, addr_alloc);
	return (addr_alloc);
}

void		free(void *p)
{
	void	(*libc_free)(void*);

	libc_free = dlsym(RTLD_NEXT, "free");
	printf("free(%p)\n", p);
	libc_free(p);
	g_alloc_count--;
}
