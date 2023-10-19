/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pictal_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:38:08 by josorteg          #+#    #+#             */
/*   Updated: 2023/05/29 07:37:11 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"
#include<stdio.h>

static double	ft_double_abs(double nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		return (nbr);
	}
	return (nbr);
}

int32_t	draw_julia(t_painter *painter, t_vec2 pos)
{
	t_unr		z;
	int32_t		iter;
	double		tmp;

	z = (t_unr){
		.r = pos.x
		/ (painter->mlx.win_size.x / painter->pict.size.x)
		+ painter->pict.pos.x,
		.i = pos.y
		/ (painter->mlx.win_size.y / painter->pict.size.y)
		+ painter->pict.pos.y
	};
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < painter->pict.iter_num)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + painter->mouse_pos.x;
		z.i = 2 * z.i * tmp + painter->mouse_pos.y;
		iter++;
	}
	return (iter);
}

int32_t	draw_mandelbrot(t_painter *painter, t_vec2 pos)
{
	t_unr		base_point;
	t_unr		z;
	int32_t		iter;
	double		tmp;

	base_point = (t_unr){
		.r = pos.x
		/ (painter->mlx.win_size.x / painter->pict.size.x)
		+ painter->pict.pos.x,
		.i = pos.y
		/ (painter->mlx.win_size.y / painter->pict.size.y)
		+ painter->pict.pos.y
	};
	z = base_point;
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < painter->pict.iter_num)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + base_point.r;
		z.i = 2 * z.i * tmp + base_point.i;
		iter++;
	}
	return (iter);
}

int32_t	draw_ship(t_painter *painter, t_vec2 pos)
{
	t_unr		base_point;
	t_unr		z;
	int32_t		iter;
	double		tmp;

	base_point = (t_unr){
		.r = pos.x
		/ (painter->mlx.win_size.x / painter->pict.size.x)
		+ painter->pict.pos.x,
		.i = pos.y
		/ (painter->mlx.win_size.y / painter->pict.size.y)
		+ painter->pict.pos.y
	};
	z = base_point;
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4 && iter < painter->pict.iter_num)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + base_point.r;
		z.i = ft_double_abs(2 * z.i * tmp) + base_point.i;
		iter++;
	}
	return (iter);
}
