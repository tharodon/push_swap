/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:35:22 by tharodon          #+#    #+#             */
/*   Updated: 2021/04/23 19:41:48 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	*ft_calloc (size_t n, size_t len)
{
	char	*r;

	r = (char *)malloc(len * n);
	if (r == NULL)
		return (NULL);
	ft_bzero(r, len * n);
	return (r);
}
