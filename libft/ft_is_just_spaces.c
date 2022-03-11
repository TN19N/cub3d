/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_just_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:50:59 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 10:59:10 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_is_just_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != " " && str[i] != "\t" && str[i] != "\n" \
		&& str[i] != "\v" && str[i] != "\f" && str[i] != "\r")
			return (1);
		i++;
	}
	return (0);
}