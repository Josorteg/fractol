/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:47:35 by josorteg          #+#    #+#             */
/*   Updated: 2023/10/19 10:55:12 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	init_mandelbrot(t_painter *painter)
{
	painter->pict.name = "mandelbrot";
	painter->pict.size.x = 4;
	painter->pict.size.y = 4;
	painter->pict.pos.x = -2;
	painter->pict.pos.y = -2;
	painter->pict.iter_num = 3;
	painter->pict.movable = false;
}

void	init_julia(t_painter *painter)
{
	painter->pict.name = "Julia";
	painter->pict.size.x = 4.0;
	painter->pict.size.y = 4.0;
	painter->pict.pos.x = -2.0;
	painter->pict.pos.y = -2.0;
	painter->pict.iter_num = 3;
	painter->pict.movable = true;
	painter->pict.mov_lock = false;
}

void	init_ship(t_painter *painter)
{
	painter->pict.name = "ship";
	painter->pict.size.x = 3.0;
	painter->pict.size.y = 3.0;
	painter->pict.pos.x = -2.0;
	painter->pict.pos.y = -2.0;
	painter->pict.iter_num = 3;
	painter->pict.movable = false;
}

void	init_fract(const char *frac, t_painter *painter)
{
	if (!ft_strncmp("mandelbrot", frac, 10))
		init_mandelbrot(painter);
	else if (!ft_strncmp("Julia", frac, 5))
		init_julia(painter);
	else if (!ft_strncmp("ship", frac, 4))
		init_ship(painter);
}

int	main(int ac, char **arg)
{
	t_painter	painter;

	ft_bzero(&painter, sizeof(t_painter));
	if (ac == 2 && check_frac(arg[1]))
	{
		ft_bzero(&painter, sizeof(t_painter));
		init_fract(arg[1], &painter);
		init(&painter);
		if (display_mlx_win(&painter) == 0)
			return (0);
	}
	else
		ft_mensaje();
	return (0);
}
