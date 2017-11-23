/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <kcoetzee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 18:00:25 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/09/26 15:22:02 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*ret;

	if (!dst || !src)
		return (dst);
	ret = dst;
	if (dst < src)
		while ((size_t)(dst - ret) < len)
			*(t_byte *)dst++ = *(t_byte *)src++;
	else
		while (len-- > 0)
			((t_byte *)dst)[len] = ((t_byte *)src)[len];
	return (ret);
}
