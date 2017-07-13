/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 10:48:40 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 18:04:21 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	begin_tricorn(t_env *env)
{
	env->frac = 5;
	env->iter_max = 100;
	env->minx = -2.2;
	env->miny = -1.3;
	env->maxx = 1.85;
	env->maxy = 1.25;
	env->help = 0;
	env->r = 35;
	env->g = 5;
	env->b = 95;
	env->zc = 0;
}

void	tricorn(t_env *e)
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
			while (e->zr * e->zr + e->zi * e->zi < 4 && e->i++ < e->iter_max)
			{
				e->tmp = e->zr;
				e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
				e->zi = -2 * e->zi * e->tmp + e->ci;
			}
			if (e->i - 1 == e->iter_max)
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0);
			else
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, color(e));
		}
	}
}
