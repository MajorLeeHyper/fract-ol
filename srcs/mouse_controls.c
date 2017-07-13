/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 00:57:19 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 18:01:34 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_zoom_cont(int b, int x, int y, t_env *env)
{
	if ((b == 2 || b == 5) && x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y &&
			env->zc > -5)
	{
		env->minx = env->mx - (env->dx * 1.5) / 2;
		env->maxx = env->mx + (env->dx * 1.5) / 2;
		env->miny = env->my - (env->dy * 1.5) / 2;
		env->maxy = env->my + (env->dy * 1.5) / 2;
		env->zc--;
	}
	return (0);
}

int		mouse_zoom(int b, int x, int y, t_env *env)
{
	if (env->frac != 4)
	{
		env->dx = env->maxx - env->minx;
		env->dy = env->maxy - env->miny;
		env->mx = ((double)(x) / WIN_X * env->dx) - env->dx / 2 + env->mx;
		env->my = (double)(y) / WIN_Y * env->dy - env->dy / 2 + env->my;
		if ((b == 1 || b == 4) && x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y
			&& env->zc < 50)
		{
			env->minx = env->mx - (env->dx / 1.5) / 2;
			env->maxx = env->mx + (env->dx / 1.5) / 2;
			env->miny = env->my - (env->dy / 1.5) / 2;
			env->maxy = env->my + (env->dy / 1.5) / 2;
			env->zc++;
		}
		else
			mouse_zoom_cont(b, x, y, env);
		draw(env);
	}
	return (0);
}

int		julia_mouse(int x, int y, t_env *env)
{
	if (env->frac == 2 && x >= 0 && y >= 0 && x <= WIN_X && y < WIN_Y &&
			env->mouse == 1)
	{
		env->cr = (double)x / (double)WIN_X * 4 - 2;
		env->ci = (double)y / (double)WIN_Y * 4 - 2;
		draw(env);
	}
	return (0);
}
