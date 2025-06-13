/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:12:24 by fde-alme          #+#    #+#             */
/*   Updated: 2025/06/13 16:04:57 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
#include <stdlib.h>
#include <stdio.h>

void	free_area(char **area)
{
	(void)area;
}

void	dfs(char **tab, t_point size, int x, int y)
{
	if (x < 0 || y < 0 || x == size.x || y == size.y || tab[y][x] == '1')
		return ;

	tab[y][x] = '1';
	dfs(tab, size, x - 1, y);
	dfs(tab, size, x + 1, y);
	dfs(tab, size, x, y - 1);
	dfs(tab, size, x, y + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	dfs(tab, size, begin.x, begin.y);
}

char	**make_area(char **zone, t_point *size)
{
	char	**area;
	int		i;
	int		j;

	area = (char **) malloc(sizeof(char *) * size->y);
	if (!area)
		return (NULL);
	i = 0;
	while (i < size->y)
	{
		j = 0;
		area[i] = (char *) malloc(size->x + 1);
		if (!area[i])
			return (free_area(area), NULL);
		while (zone[i][j])
		{
			area[i][j] = zone[i][j];
			j++;
		}
		area[i][j] = '\0';
		i++;
	}
	return (area);
}

void	print_area(char **area, t_point size)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	char	**area;
	char	*zone[] = {
		"11111111",
		"10000001",
		"10010001",
		"1011E001",
		"11111111",
	};

	t_point	begin = {1, 3};
	t_point	size = {8, 5};

	area = make_area(zone, &size);
	print_area(area, size);
	flood_fill(area, size, begin);
	print_area(area, size);

	return (0);
}
