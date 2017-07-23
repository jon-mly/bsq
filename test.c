#include "convert.h"
#include "data.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>

int main(int ac, char **av)
{
	int		fd;
	int		i;

	t_list	**begin_list;
	t_list	*current_object;
	char	**tab;

	int x = 0;
	int y = 0;

	i = 0;
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			write(1, "map_error\n", 10);
		begin_list = init_chained(fd);
		delete_first_line(begin_list);
		current_object = *begin_list;
		int x_max = get_x_max(begin_list);
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
