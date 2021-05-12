/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppunzo <ppunzo@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:21:00 by mfarnia           #+#    #+#             */
/*   Updated: 2021/05/12 16:21:01 by mfarnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (str[j] == '\0')
		j++;
	i = j;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i - j);
}

int	ft_iscinstr(char c, char const *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*ret;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] == '\0')
		j++;
	while (s2[j] && s2[j] != '\n')
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}
