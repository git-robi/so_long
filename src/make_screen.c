
#include "../includes/so_long.h"

void	player_view(t_data *data, int i, int j)
{
	if (data->player.dir == RIGHT)
	{
		if (data->player.pos == ONE)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_one.xpm_ptr, j * PX, i * PX);
		else if (data->player.pos == TWO)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_two.xpm_ptr, j * PX, i * PX);
		else if (data->player.pos == THREE)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_three.xpm_ptr, j * PX, i * PX);
		else if (data->player.pos == FOUR)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_four.xpm_ptr, j * PX, i * PX);
	}
	else if (data->player.dir == LEFT)
	{
		if (data->player.pos == ONE)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_five.xpm_ptr, j * PX, i * PX);
		else if	(data->player.pos == TWO)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_six.xpm_ptr, j * PX, i * PX);
		else if (data->player.pos == THREE)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_seven.xpm_ptr, j * PX, i * PX);
		else if (data->player.pos == FOUR)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->player_eight.xpm_ptr, j * PX, i * PX);
	}
}

void	put_assets_on_screen(t_data *data, int i, int j)
{
	if (data->map.tab[i][j] == EMPTY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->background.xpm_ptr, j *PX, i * PX);
	else if (data->map.tab[i][j] == WALL)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall.xpm_ptr, j * PX, i * PX);
	else if (data->map.tab[i][j] == COINS)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->coins.xpm_ptr, j * PX, i * PX);
	else if (data->map.tab[i][j] == EXIT && data->map.coins > 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_c.xpm_ptr, j * PX, i * PX);
	else if (data->map.tab[i][j] == EXIT && data->map.coins <= 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_o.xpm_ptr, j * PX, i * PX);
	else if (data->map.tab[i][j] == ENEMY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->enemy.xpm_ptr, j * PX, i * PX);
	else if (data->map.tab[i][j] == PLAYER)
		player_view(data, i, j);
}

int	make_screen(t_data *data)
{
	int	i;;
	int	j;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols - 1)
		{
			put_assets_on_screen(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
