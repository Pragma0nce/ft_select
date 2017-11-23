/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <kcoetzee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:58:20 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/09/07 15:41:34 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	while (n--)
	{
		*(t_byte *)dst++ = *(t_byte *)src;
		if (*(t_byte *)src++ == (t_byte)c)
			return ((t_byte *)dst);
	}
	return (NULL);
}
