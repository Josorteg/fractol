/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 07:57:15 by josorteg          #+#    #+#             */
/*   Updated: 2023/05/31 14:47:39 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	painter_exit(t_painter *painter)
{
	if (painter->mlx.mlx && painter->mlx.window)
		mlx_destroy_window(painter->mlx.mlx, painter->mlx.window);
	if (painter->mlx.mlx && painter->mlx.image)
		mlx_destroy_image(painter->mlx.mlx, painter->mlx.image);
	exit(0);
}

void	zoom_in(t_painter *painter, t_vec2 pos)
{
	painter->pict.pos.x += painter->pict.size.x / 3
		* ((double)pos.x / (double)painter->mlx.win_size.x);
	painter->pict.pos.y += painter->pict.size.y / 3
		* ((double)pos.y / (double)painter->mlx.win_size.y);
	painter->pict.size.x -= painter->pict.size.x / 3;
	painter->pict.size.y -= painter->pict.size.y / 3;
}

void	zoom_out(t_painter *painter, t_vec2 pos)
{
	painter->pict.pos.x -= painter->pict.size.x / 3
		* ((double)pos.x / (double)painter->mlx.win_size.x);
	painter->pict.pos.y -= painter->pict.size.y / 3
		* ((double)pos.y / (double)painter->mlx.win_size.y);
	painter->pict.size.x += painter->pict.size.x / 3;
	painter->pict.size.y += painter->pict.size.y / 3;
}
