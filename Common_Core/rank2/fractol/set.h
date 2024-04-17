/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:23 by tialbert          #+#    #+#             */
/*   Updated: 2024/04/12 21:47:52 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H

#define SET_H

typedef struct s_mlx {
	void		*mlx;
	void		*window;
	int			win_height;
	int			win_length;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	int			x;
	int			y;
	long double	c_real;
	long double	c_ima;
	int			zoom;
	int			backgr;
	int			foregr;
	int			color1;
	int			color2;
	int			color3;
}				t_mlx;

int		mandel_render_hook(t_mlx *mlx, int x, int y);
void	check_set(t_mlx *mlx, long double x, long double y);
void	mandel(char **argv, int argc);
int		zoom_press(int keysym, t_mlx *mlx);
int		xpress(int buttonsym, t_mlx *mlx);
int		keypress(int keysym, t_mlx *mlx);
void	get_c(char **argv, int argc, t_mlx *mlx);

#endif
