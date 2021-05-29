/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:15:09 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/05 14:38:02 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	res = (char*)malloc(i);
	i = 0;
	j = 0;
	if (res)
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			res[i++] = s2[j++];
		res[i] = '\0';
		free(s1);
		return (res);
	}
	free(s1);
	return (NULL);
}
