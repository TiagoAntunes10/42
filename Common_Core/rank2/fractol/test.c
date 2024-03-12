#include "fractol.h"
#include <X11/X.h>

int	render_next_frame(t_mlx *mlx)
{
	int	y;

	if (mlx->window == NULL)
		mlx_loop_end(mlx->mlx);
	push_img(mlx);
	y = mlx->y;
	while (y < mlx->win_height - 1)
	{
		my_mlx_pixel_put(mlx, mlx->x, y, mlx->color);
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (1);
}

int	handle_keypress(int keysym, int x, int y, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		mlx->window = NULL;
	}
	return (0);
}

int	handle_buttonpress(int buttonsym, t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx->window = NULL;
	return (0);
}

int	main(void)
{
	t_mlx	*mlx;
	
	mlx = open_window();
	mlx->y = mlx->win_height / 2;
	mlx->x = mlx->win_length / 2;
	mlx->color = 0x00FF0000;
	mlx_loop_hook(mlx->mlx, &render_next_frame, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &handle_keypress, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &handle_buttonpress, mlx);
	mlx_loop(mlx->mlx);
	if (mlx->window == NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx);
}
