/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_pars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillett <dwillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:34:07 by dwillett          #+#    #+#             */
/*   Updated: 2021/02/05 18:35:59 by dwillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim_pars(char *s1, char const *set)
{
	char	*res;
	int		i;
	int		begin;
	int		end;

	begin = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_find(set, s1[begin]) && s1[begin + 1] != '\0')
		begin++;
	end = ft_strlen(s1) - 1;
	while (ft_find(set, s1[end]) && end > begin)
		end--;
	if (begin == end && ft_find(set, s1[end]))
		begin++;
	i = 0;
	if ((res = (char*)malloc(end - begin + 2)))
	{
		while (begin <= end)
			res[i++] = s1[begin++];
		res[i] = '\0';
	}
	free(s1);
	return (res);
}
