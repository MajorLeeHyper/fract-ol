/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:17:55 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/10 18:02:43 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		begin_julia(t_env *env)
{
	env->frac = 2;
	env->iter_max = 100;
	env->minx = -2.0;
	env->miny = -2.0;
	env->maxx = 2.0;
	env->maxy = 2.0;
	env->cr = 0.0;
	env->ci = 0.72;
	env->help = 1;
	env->mouse = 1;
	env->r = 13;
	env->g = 22;
	env->b = 19;
	env->zc = 0;
}

void		julia(t_env *env)
{
	env->x = -1;
	while (++env->x < WIN_X)
	{
		env->y = -1;
		while (++env->y < WIN_Y)
		{
			env->zr = env->minx + ((double)env->x * (env->maxx - env->minx) /
					WIN_X);
			env->zi = env->miny + ((double)env->y * (env->maxy - env->miny) /
					WIN_Y);
			env->i = 0;
			while (env->zr * env->zr + env->zi * env->zi < 4 &&
				env->i < env->iter_max)
			{
				env->tmp = env->zr;
				env->zr = env->zr * env->zr - env->zi * env->zi + env->cr;
				env->zi = 2 * env->zi * env->tmp + env->ci;
				env->i++;
			}
			if (env->i == env->iter_max)
				mlx_pixel_put(env->mlx, env->win, env->x, env->y, 0);
			else
				mlx_pixel_put(env->mlx, env->win, env->x, env->y, color(env));
		}
	}
}
