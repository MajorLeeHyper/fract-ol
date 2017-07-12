/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 10:48:40 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 16:49:20 by dnelson          ###   ########.fr       */
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

void	tricorn(t_env *env)
{
	env->x = -1;
	while (++env->x < WIN_X)
	{
		env->y = -1;
		while (++env->y < WIN_Y)
		{
			env->cr = env->minx + ((double)env->x * (env->maxx - env->minx)
					/ WIN_X);
			env->ci = env->miny + ((double)env->y * (env->maxy - env->miny)
					/ WIN_Y);
			env->zr = 0;
			env->zi = 0;
			env->i = 0;
			while (env->zr * env->zr + env->zi * env->zi < 4 && env->i++ <
					env->iter_max)
			{
				env->tmp = env->zr;
				env->zr = env->zr * env->zr - env->zi * env->zi + env->cr;
				env->zi = -2 * env->zi * env->tmp + env->ci;
			}
			if (env->i - 1 == env->iter_max)
				mlx_pixel_put(env->mlx, env->win, env->x, env->y, 0);
			else
				mlx_pixel_put(env->mlx, env->win, env->x, env->y, color(env));
		}
	}
}
