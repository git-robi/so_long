#include "../includes/so_long.h"

void	destroy_assets(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->background.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->wall.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->coins.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->enemy.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_f.xpm_ptr);;
	mlx_destroy_image(data->mlx_ptr, data->player_b.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_l.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_r.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->exit_c.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->exit_o.xpm_ptr);
}

void	free_map(char	**map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
