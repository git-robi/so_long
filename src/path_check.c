#include "../includes/so_long.h"

void	flood_fill_algorithm(t_data, t_copy *map_copy, int y, int x)
{
	
	if (x < 0 || y < 0 || x >= data->map->rows || y >= data->map->cols
		|| map_copy->tab[y][x] == '1')
		return ;
	else if (map_copy->tab[y][x] == 'E')
	{
		map_copy->enemies += 1;
		map_copy->tab[y][x] = '1';
		return ;
	}
	else if (map_copy->tab[y][x] == 'C')
		map_copy->coins += 1;
	map_copy->tab[y][x] = '1';
	if (y + 1 < data->map->cols && (map_copy->tab[y + 1][x] != 1
		|| map_copy->tab[y + 1][x] != 'X'))
		flood_fill_algorithm(data, map_copy, y + 1, x);
	if (y - 1 >= 0 && (map_copy->tab[y - 1][x] != 1
		|| map_copy->tab[y - 1][x] != 'X'))
		flood_fill_algorithm(data, map_copy, y - 1, x);
	if (x + 1 < data->map->rows && (map_copy_tab[y][x - 1] != 1
		|| map_copy->tab[y][x - 1] != 'X'))
		flood_fill_algorithm(data, map_copy, y, x - 1);
	if (x - 1 >= 0 && (map_copy->tab[y][x + 1] != 1
		|| map_copy->tab[y][x + 1] != 'X'))
		flood_fill_algorithm(data, map_copy, y, x + 1);
}

void	init_map_copy(t_data *data, t_copy *map_copy)
{
	int	i;

	i = 0;
	map_copy->enemies = 0;
	map_copy->coins = 0;
	map_copy->tab = (char **)ft_malloc(data->map->cols + 1, sizeof(char *)); //consider changing with calloc
	if (!map_copy->tab)
		return ;
	while (i < data->map->cols)
	{
		map_copy->tab[i] = ft_strdup(data->map->tab[i]);
		if (!map_copy->tab[i])
		{
			while (i >= 0)
			{
				free(map_copy->tab[i]);
				i--;
			}
			free(map_copy->tab);
			map_copy->tab = NULL;
			return ;
		}
		i++;
	}
}

int	path_check(t_data *data)
{
	t_copy	map_copy;

	init_map_copy(data, &map_copy);
	if (map_copy.tab == NULL)
		print_error_and_exit("memory allocation failed.\n", data);
	flood_fill_algorithm(data, &map_copy, data->player->y, data->player->x);
	free_map(map_copy.tab);
	if (map_copy.coins != data->map->coins || map_copy.enemies != 1)
		return (1);
	return (0);
}
