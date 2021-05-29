/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:45:59 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/05 18:46:04 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_pars(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(ft_strlen((char *)s1) + 1);
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
