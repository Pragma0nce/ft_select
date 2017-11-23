/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <kcoetzee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:04:51 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/09/26 16:35:38 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sleft;

	sleft = size;
	while (*dst && sleft > 0 && sleft--)
		dst++;
	while (*src && sleft > 1 && sleft--)
		*dst++ = *src++;
	if (sleft == 1)
		*dst = '\0';
	return (size - sleft);
}
