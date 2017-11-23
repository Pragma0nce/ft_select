/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <kcoetzee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:15:27 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/09/11 13:39:27 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strfill(char **tab, const char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			*tab++ = ft_strqdupc(&s, c);
		s++;
	}
	*tab = NULL;
}
