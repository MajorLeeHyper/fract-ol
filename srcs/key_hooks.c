/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:06:59 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 16:41:15 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_zoom(t_env *env, int zoom)
{
	double	dx;
	double	dy;

	dx = env->maxx - env->minx;
	dy = env->maxy - env->miny;
	env->mx = ((double)(WIN_X / 2) / WIN_X * dx) - dx / 2 + env->mx;
	env->my = ((double)(WIN_Y / 2) / WIN_Y * dy) - dy / 2 + env->my;
	if (zoom == 1 && env->zc < 50)
	{
		env->minx = env->mx - (dx / 1.5) / 2;
		env->maxx = env->mx + (dx / 1.5) / 2;
		env->miny = env->my - (dy / 1.5) / 2;
		env->maxy = env->my + (dy / 1.5) / 2;
		env->zc++;
	}
	else if (zoom == -1 && env->zc > -5)
	{
		env->minx = env->mx - (dx * 1.5) / 2;
		env->maxx = env->mx + (dx * 1.5) / 2;
		env->miny = env->my - (dy * 1.5) / 2;
		env->maxy = env->my + (dy * 1.5) / 2;
		env->zc--;
	}
	draw(env);
}

int		help_window_checks(int keycode, t_env *env)
{
	if (keycode == KEY_H && env->help == 0)
	{
		show_help_window(env);
		env->help = 1;
	}
	else if (keycode == KEY_H && env->help == 1)
	{
		env->help = 0;
		draw(env);
	}
	return (0);
}

int		even_more_keys(int keycode, t_env *env)
{
	if (keycode == KEY_PAGE_UP && env->frac == 4)
		increase_carpet(env);
	else if (keycode == KEY_PAGE_DOWN && env->frac == 4)
		decrease_carpet(env);
	else if (keycode == KEY_SPACE && env->frac == 2)
	{
		if (env->mouse == 0)
			env->mouse = 1;
		else
			env->mouse = 0;
	}
	else if (color_key_check(keycode))
	{
		color_change(keycode, env);
		draw(env);
	}
	else
		help_window_checks(keycode, env);
	return (0);
}

int		more_keys(int keycode, t_env *env)
{
	if (keycode == KEY_PAGE_UP && env->frac != 4)
	{
		if (env->iter_max < 500)
		{
			if (env->iter_max >= 50)
				env->iter_max += 10;
			else
				env->iter_max += 1;
			draw(env);
		}
	}
	else if (keycode == KEY_PAGE_DOWN && env->frac != 4)
	{
		if (env->iter_max > 0)
		{
			if (env->iter_max <= 50)
				env->iter_max -= 10;
			else
				env->iter_max -= 1;
			draw(env);
		}
	}
	else
		even_more_keys(keycode, env);
	return (0);
}

int		key_press_hook(int keycode, t_env *env)
{
	if (keycode >= KEY_1 && keycode <= KEY_5)
	{
		relaunch_fract(keycode - 17, env);
		draw(env);
	}
	else if (keycode == KEY_R)
	{
		relaunch_fract(env->frac, env);
		draw(env);
	}
	else if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_PLUS)
		key_zoom(env, 1);
	else if (keycode == KEY_MINUS)
		key_zoom(env, -1);
	else
		more_keys(keycode, env);
	return (0);
}
