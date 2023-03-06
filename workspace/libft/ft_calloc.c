/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/26 20:36:49 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates memory for an array of nmemb elements of size bytes
The memory is set to zero
Returns a (suitably aligned for any built-in type) pointer to the memory
Returns NULL on error
If nmemb or size is 0, returns NULL or a unique pointer value passable to free()
If the nmemb * size = integer overflow, returns an error
NULL may also be returned by a successful call with nmemb or size equal to zero

Can fail with:
ENOMEM Out of memory. Possibly, the application hit the RLIMIT_AS or RLIMIT_DATA
By default, Linux follows an optimistic memory allocation strategy =>
If malloc() returns non-NULL => no guarantee that the memory really is available
If the system is out of memory, one or more processes will be killed

Normally, malloc() allocates memory from the heap,
and adjusts the size of the heap as required, using sbrk(2)
When allocating blocks of memory larger than MMAP_THRESHOLD bytes,
the glibc malloc() allocates the memory as a private anonymous mapping using
mmap(2)
MMAP_THRESHOLD is 128 kB by default, but is adjustable using mallopt(3)

Crashes are almost always related to heap corruption, such as overflowing an
allocated chunk or freeing the same pointer twice
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory_to_return;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((unsigned int)nmemb > INT_MAX / (unsigned int)size)
		return (NULL);
	memory_to_return = (char *)malloc(nmemb * size);
	if (memory_to_return == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*((char *)memory_to_return + i) = '\0';
		i++;
	}
	return ((void *)memory_to_return);
}
