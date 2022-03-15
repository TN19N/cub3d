/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:21:22 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:22:17 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	ptr = malloc((i + 1) * sizeof(*ptr));
	i = 0;
	if (ptr == NULL)
		ft_error("malloc failed :(");
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
