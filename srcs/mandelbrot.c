/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:55:25 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 12:07:26 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	begin_mandelbrot(t_env *env)
{
	env->frac = 1;
	env->iter_max = 100;
	env->minx = -2.25;
	env->miny = -1.75;
	env->maxx = 2.0;
	env->maxy = 1.75;
	env->help = 1;
	env->mx = 0;
	env->my = 0;
	env->r = 5;
	env->g = 15;
	env->b = 30;
	env->zc = 0;
}

void	mandelbrot(t_env *e)
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
				e->zi = 2 * e->zi * e->tmp + e->ci;
				e->i++;
			}
			if (e->i == e->iter_max)
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0);
			else
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, color(e));
		}
	}
}
