/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:11:40 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/07 13:32:33 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*strout;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	if ((int)len > ft_strlen(str))
		len = ft_strlen(str);
	strout = (char *)malloc(len * sizeof(char) + 1);
	protec_error_pt(strout, ERR_OUT);
	while (str[i] != '\0')
	{
		if (i >= start && j < len)
		{
			strout[j] = str[i];
			j++;
		}
		i++;
	}
	strout[j] = '\0';
	return (strout);
}

static int	is_exist( char *pt, char c)
{
	int	count;

	count = 0;
	while (pt[count])
	{
		if (pt[count] == c)
			return (1);
		count++;
	}
	return (0);
}

static int	get_end( char *s1, char *set)
{
	int	len;

	len = ft_strlen(s1);
	while (--len)
	{
		if (is_exist(set, s1[len]) == 0)
			return (len);
	}
	return (0);
}

static int	get_start( char *s1, char *set)
{
	int	count;

	count = 0;
	while (s1[count])
	{
		if (is_exist(set, s1[count]) == 0)
			return (count);
		count++;
	}
	return (-1);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return ((char *)s1);
	i = get_start(s1, set);
	j = get_end(s1, set);
	if (i < 0)
		return (ft_strdup(""));
	if (!s1 || !set)
		return ((char *)s1);
	return (ft_substr(s1 + i, 0, (j - i + 1)));
}
