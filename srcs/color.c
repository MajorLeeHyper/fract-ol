/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:37:55 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/12 16:42:50 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_key_check(int key)
{
	if (key == 256 || key == 261 || key == 259 || key == 260 || key == 262 ||
			key == 269)
		return (1);
	return (0);
}

void	color_change(int key, t_env *env)
{
	if (key == KEY_L_CONTROL && env->r > 5)
		env->r -= 5;
	else if (key == KEY_L_ALT && env->g > 5)
		env->g -= 5;
	else if (key == KEY_L_COMMAND && env->b > 5)
		env->b -= 5;
	else if (key == KEY_R_COMMAND && env->r < 255)
		env->r += 5;
	else if (key == KEY_R_ALT && env->g < 255)
		env->g += 5;
	else if (key == KEY_R_CONTROL && env->b < 255)
		env->b += 5;
}

int		color(t_env *env)
{
	int		r;
	int		g;
	int		b;
	int		color;

	r = (255 / env->r);
	g = (255 / env->g);
	b = (255 / env->b);
	color = b << 16 | g << 8 | r;
	return (color * env->i);
}
