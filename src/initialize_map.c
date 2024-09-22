/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:09:10 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/22 14:16:12 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_argv(int argc, char **argv, t_data *data)
{
	int	string_start;

	if (argc == 1)
		print_error_and_exit("Map is missing.\n", data);
	if (argc > 2)
		print_error_and_exit("Too many arguments.\n", data);
	if (ft_strlen(argv[1]) < 5)
		print_error_and_exit("Map is not .ber file.\n", data);
	string_start = ft_strlen(argv[1]) - 4;
	if (ft_strcmp(&argv[1][string_start], ".ber") != 0)
		print_error_and_exit("Map is not .ber file.\n", data);
}

int	get_rows_count(char *map, t_data *data)
{
	int		fd;
	int		rows;
	char	buffer;
	int		read_bytes;

	rows = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error_and_exit("Map file could not be opened.\n", data);
	read_bytes = read(fd, &buffer, 1);
	while (read_bytes > 0)
	{
		if (buffer == '\n')
			rows++;
		read_bytes = read(fd, &buffer, 1);
	}
	if (read_bytes == -1)
		print_error_and_exit("Error reading the file.\n", data);
	close(fd);
	if (buffer != '\n')
		rows++;
	return (rows);
}

void	store_map(char **argv, t_data *data)
{
	int	i;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error_and_exit("Map file could not be opened.\n", data);
	i = 0;
	data->map.rows = get_rows_count(argv[1], data);
	data->map.tab = malloc((data->map.rows + 1) * sizeof(char *));
	if (data->map.tab == NULL)
		print_error_and_exit("Allocation of map failed.\n", data);
	data->is_map_alloc = 1;
	while (1)
	{
		data->map.tab[i] = get_next_line(fd);
		if (data->map.tab[i] == NULL)
			break ;
		i++;
	}
	if (i != data->map.rows)
		print_error_and_exit("Allocation of map failed.\n", data);
	data->map.tab[i] = NULL;
	close(fd);
}

void	initialize_map(int argc, char **argv, t_data *data)
{
	data->is_map_alloc = 0;
	check_argv(argc, argv, data);
	store_map(argv, data);
	check_map(data);
	if (path_check(data))
		print_error_and_exit("path not found.\n", data);
}
