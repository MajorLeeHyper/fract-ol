/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 00:10:01 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 16:48:50 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		begin_burning_ship(t_env *env)
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

void	burning_ship(t_env *env)
{
	env->x = -1;
	while (++env->x < WIN_X)
	{
		env->y = -1;
		while(++env->y < WIN_Y)
		{
			env->cr = env->minx + ((double)env->x * (env->maxx - env->minx)
					/ WIN_X);
			env->ci = env->miny + ((double)env->y * (env->maxy - env->miny)
					/ WIN_Y);
			env->zr = 0;
			env->zi = 0;
			env->i = 0;
			while (env->zr * env->zr +env->zi * env->zi < 4 && env-> i <
					env->iter_max)
			{
				env->tmp = env->zr;
				env->zr = env->zr * env->zr - env->zi * env->zi + env->cr;
				env->zi = 2 * fabs(env->zi * env->tmp) + env->ci;
				env->i++;
			}
			if (env->i == env->iter_max)
				mlx_pixel_put(env->mlx, env->win, env->x, env->y, 0);
			else
				mlx_pixel_put(env->mlx, env->win, env->x, env->y, color(env));
		}
	}
}
