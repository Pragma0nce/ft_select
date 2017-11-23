/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <kcoetzee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:25:25 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/09/11 13:27:42 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdupc(const char *s, char c)
{
	char	*str;

	str = ft_strallocc(s, c);
	if (str)
		ft_stpcpyc(str, s, c);
	return (str);
}
