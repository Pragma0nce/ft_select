/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <kcoetzee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:26:19 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/09/11 13:08:53 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char			**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (tab)
		ft_strfill(tab, s, c);
	return (tab);
}
