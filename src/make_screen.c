
#include "../includes/so_long.h"

void	player_view(t_data *data, int i, int j)
{
	if (data->player->pos == DOWN)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->player_f->xpm_ptr, i * PX, j * PX);
	if (data->player->pos == UP)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->player_b->xpm_ptr, i * PX, j * PX);
	if (data->player_pos == LEFT)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->player_l->xpm_ptr, i * PX, j * PX);
	if (data->player->pos == RIGHT)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->player_r->xpm_ptr, i * PX, j * PX);
}

void	put_assets_on_screen(t_data *data, int i, int j)
{
	if (data->map->tab[i][j] == EMPTY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->background->xpm_ptr, j * PX, i * PX);
	else if (data->map[i][j] == WALL)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall->xpm_ptr, j * PX, i * PX);
	else if (data->map[i][j] == COINS)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->coins->xpm_ptr, j * PX, i * PX);
	else if (data->map[i][j] == EXIT && data->map->coins > 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_c->xpm_ptr, j * PX, i * PX);
	else if (data->map[i][j] == EXIT && data->map->coins <= 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->exit_o->xpm_ptr, j * PX, i * PX);
	else if (data->map[i][j] == ENEMY)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->enemy->xpm_ptr, j * PX, i * PX);
	else if (data->map[i][j] == PLAYER)
		player_view(data, i, j);
}

int	make_screen(t_data *data)
{
	int	i;;
	int	j;

	i = 0;
	while (data->map->tab[y])
	{
		j = 0;
		while (data->map->tab[i][j])
		{
			put_assets_on_screen(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
