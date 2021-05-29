/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:45:59 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/05 14:37:53 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(ft_strlen_gnl(s1) + 1);
	if (res)
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = s1[i];
		return (res);
	}
	return (NULL);
}
