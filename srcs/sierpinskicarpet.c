/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinskicarpet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 10:52:30 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 11:42:56 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	begin_carpet(t_env *env)
{
	env->frac = 4;
	env->iter_max = 1;
	env->minx = 0;
	env->miny = 0;
	env->maxx = 3;
	env->maxy = 3;
	env->x = 0;
	env->y = 0;
	env->help = 1;
}

int		is_filled(t_env *env, int x, int y)
{
	env->i = 0;
	while ((x > 0 || y > 0) && env->i < env->iter_max)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
		env->i++;
	}
	return (1);
}

void	sierpinski_carpet(t_env *env)
{
	int		x;
	int		y;
	int		new_x;
	int		new_y;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			new_x = x * env->maxx / WIN_X;
			new_y = y * env->maxy / WIN_Y;
			if (is_filled(env, new_x, new_y) == 1)
				mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
			else
				mlx_pixel_put(env->mlx, env->win, x, y, 0x000000);
		}
	}
}
