/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <kcoetzee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:32:56 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/09/08 12:18:12 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*ret;
	size_t	start;

	ret = (char *)dst;
	start = n;
	while (*src && n--)
		*dst++ = *src++;
	if (n < start)
		ft_bzero(dst, n);
	return (ret);
}
