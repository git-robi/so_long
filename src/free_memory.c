#include "../includes/so_long.h"

void	destroy_assets(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->background.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->wall.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->coins.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->enemy.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_one.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_two.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_three.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_four.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->player_five.xpm_ptr);
        mlx_destroy_image(data->mlx_ptr, data->player_six.xpm_ptr);
        mlx_destroy_image(data->mlx_ptr, data->player_seven.xpm_ptr);
        mlx_destroy_image(data->mlx_ptr, data->player_eight.xpm_ptr);
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
