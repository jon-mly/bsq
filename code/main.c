#include "convert.h"
#include "data.h"
#include "grid_error.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>

extern char		g_empty;
extern char		g_obstacle;
extern char		g_filled;

int main(int ac, char **av)
{
	int		fd;
	int		i;
	int y_max;
	int x_max;

	t_list	**begin_list;
	t_list	*current_object;
	char	**tab;

	int x = 0;
	int y = 0;

	i = 0;


	if (ac < 2)
	{
		begin_list = init_chained(0);
		get_chars(begin_list);
		x_max = get_x_max(begin_list);
		delete_first_line(begin_list);
		if (grid_is_correct(begin_list, x_max))
			write(1, "OK\n", 3);
		y_max = get_y_max(begin_list);
		tab = convert_chained(begin_list, x_max, y_max);

		while (y < y_max)
		{
			x = 0;
			while (x < x_max + 1)
			{
				write(1, &tab[y][x], 1);
				x++;
			}
			y++;
		}
		return (0);
	}

	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			write(1, "map_error\n", 10);
		begin_list = init_chained(fd);
		get_chars(begin_list);
		delete_first_line(begin_list);
		x_max = get_x_max(begin_list);
		delete_first_line(begin_list);
		if (grid_is_correct(begin_list, x_max))
			write(1, "OK\n", 3);
		int y_max = get_y_max(begin_list);
		tab = convert_chained(begin_list, x_max, y_max);

		while (y < y_max)
		{
			x = 0;
			while (x < x_max + 1)
			{
				write(1, &tab[y][x], 1);
				x++;
			}
			y++;
		}

	}
	return (0);
}
