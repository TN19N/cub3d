/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:16:09 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:21:52 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (len-- > 0)
	{
		*ptr = c;
		ptr++;
	}
	return (s);
}
