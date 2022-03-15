/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:38:30 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:21:47 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
	{
		*ptr1 = *ptr2;
		ptr2++;
		ptr1++;
	}
	return (dst);
}
