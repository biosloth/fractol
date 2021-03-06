/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:23:03 by amontano          #+#    #+#             */
/*   Updated: 2018/07/29 21:22:05 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_img	*del_img(t_mlx *mlx, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(mlx->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

void	clear_img(t_img *img)
{
	ft_bzero(img->ptr, WIN_W * WIN_H * img->bpp);
}

t_img	*new_img(t_mlx *mlx)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if ((img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H)) == NULL)
		return (del_img(mlx, img));
	img->ptr = \
		mlx_get_data_addr(img->img, &img->bpp, &img->stride, &img->endian);
	img->bpp /= 8;
	return (img);
}

void	img_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	*(int *)(img->ptr + ((x + (y * WIN_W)) * img->bpp)) = color;
}
