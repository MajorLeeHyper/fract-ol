/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 00:10:01 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 18:14:01 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	begin_burning_ship(t_env *env)
{
	env->frac = 3;
	env->iter_max = 100;
	env->minx = -2.6;
	env->miny = -2.67;
	env->maxx = 1.99;
	env->maxy = 1.88;
	env->help = 0;
	env->r = 25;
	env->g = 15;
	env->b = 255;
	env->zc = 0;
}

void	burning_ship(t_env *e)
{
	e->x = -1;
	while (++e->x < WIN_X)
	{
		e->y = -1;
		while (++e->y < WIN_Y)
		{
			e->cr = e->minx + ((double)e->x * (e->maxx - e->minx) / WIN_X);
			e->ci = e->miny + ((double)e->y * (e->maxy - e->miny) / WIN_Y);
			e->zr = 0;
			e->zi = 0;
			e->i = 0;
			while (e->zr * e->zr + e->zi * e->zi < 4 && e->i < e->iter_max)
			{
				e->tmp = e->zr;
				e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
				e->zi = 2 * fabs(e->zi * e->tmp) + e->ci;
				e->i++;
			}
			if (e->i == e->iter_max)
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0);
			else
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, color(e));
		}
	}
}
