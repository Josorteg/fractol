/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:06:11 by josorteg          #+#    #+#             */
/*   Updated: 2023/05/31 09:22:09 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static double	scale(int32_t win_pos, int32_t win_size,
	double pos, double size)
{
	return (((double)win_pos / (double)win_size) * size + pos);
}

int	key_hook(int keycode, t_painter *painter)
{
	if (keycode == ESC_KEY)
		painter_exit(painter);
	if (keycode == UP_KEY)
		painter->pict.pos.y -= (painter->pict.size.y / 10);
	if (keycode == DOWN_KEY)
		painter->pict.pos.y += (painter->pict.size.y / 10);
	if (keycode == RIGHT_KEY)
		painter->pict.pos.x += (painter->pict.size.x / 10);
	if (keycode == LEFT_KEY)
		painter->pict.pos.x -= (painter->pict.size.x / 10);
	if (keycode == PUP_KEY)
		painter->pict.iter_num++;
	if (keycode == PDOWN_KEY)
		painter->pict.iter_num -= (painter->pict.iter_num >= 1);
	draw_win(painter);
	return (0);
}

int	mouse_hook(int x, int y, t_painter *painter)
{
	if (painter->pict.movable && !painter->pict.mov_lock)
	{
		painter->mouse_pos.x = scale(x, painter->mlx.win_size.x,
				painter->pict.pos.x, painter->pict.size.x);
		painter->mouse_pos.y = scale(y, painter->mlx.win_size.y,
				painter->pict.pos.y, painter->pict.size.y);
		draw_win(painter);
	}
	return (0);
}

int	scroll_hook(int button, int x, int y, t_painter *painter)
{
	if (button == SCROLLUP_KEY)
	{
		zoom_out(painter, (t_vec2){x, y});
	}
	else if (button == SCROLLDOWN_KEY)
	{
		zoom_in(painter, (t_vec2){x, y});
	}
	else
	{
		if (!painter->pict.movable)
		{
			painter->pict.pos.x = scale(x, painter->mlx.win_size.x,
					painter->pict.pos.x, painter->pict.size.x)
				- painter->pict.size.x / 2;
			painter->pict.pos.y = scale(y, painter->mlx.win_size.y,
					painter->pict.pos.y, painter->pict.size.y)
				- painter->pict.size.y / 2;
		}
		else
			painter->pict.mov_lock = !painter->pict.mov_lock;
	}
	draw_win(painter);
	return (0);
}
