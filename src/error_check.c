#include "../includes/so_long.h"

int	is_right_shape(t_data *data)
{
	int	i;
	
	i = 1;
	data->map.cols = ft_strlen(data->map.tab[0]);
	if (data->map.cols == data->map.rows)
		return (0);
	while (data->map.tab[i])
	{
		if (ft_strlen(data->map.tab[i]) != data->map.cols)
			return (0);
		i++;
	}
	return (1);
}

int	is_wall_surrounded(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.tab[i])
	{
		if (data->map.tab[i][0] != WALL || data->map.tab[i][data->map.cols -1] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map.cols)
	{
		if (data->map.tab[0][i] != WALL || data->map.tab[data->map.rows - 1][i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	there_is_wrong_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (j < data->map.cols)
		{
			if (!(ft_strchr("01CEPX", data->map.tab[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}	

void	check_characters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.tab[i])
	{
		j = 0;
		while (j < data->map.cols)
		{
			if (data->map.tab[i][j] == EXIT)
				data->map.exit++;
			if (data->map.tab[i][j] == PLAYER)
			{
				data->map.player++;
				data->player.x = j;
				data->player.y = i;
			}
			if (data->map.tab[i][j] == COINS)
				data->map.coins++;
			j++;
		}
		i++;
	}
}
		
void	check_map(t_data *data)
{
	data->map.exit = 0;
	data->map.player = 0;
	data->map.coins = 0;
	if (!(is_right_shape(data)))
		print_error_and_exit("Map is not rectangular.\n", data);
	if(!(is_wall_surrounded(data)))
		print_error_and_exit("Map is not wall surrounded.\n",data);
	if (there_is_wrong_char(data))
		print_error_and_exit("Wrong char in map\n", data);
	check_characters(data);
	if (data->map.exit != 1)
		print_error_and_exit("More than one exit.\n", data);
	if (data->map.player != 1)
		print_error_and_exit("More than one player.\n", data);
	if (data->map.coins == 0)
		print_error_and_exit("Not enough coins.\n", data);
}
