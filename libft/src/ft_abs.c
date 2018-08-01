/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 21:47:14 by amontano          #+#    #+#             */
/*   Updated: 2018/06/26 22:04:19 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_abs(int i)
{
	if (i == INT_MIN)
		return (0);
	if (i < 0)
		return (-i);
	else
		return (i);
}
