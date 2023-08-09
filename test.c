/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:22:47 by lnambaji          #+#    #+#             */
/*   Updated: 2023/08/09 12:39:01 by lnambaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <math.h>

double	rotation_x(int x , int y, int z)
{
	return ((1 * x + 0 * x + x * 0) + (0 * y + y * cos(45) + y * -sin(45)) + (0 * z + z * sin(45) + z * cos(45)));
}

double	rotation_y(int x, int y, int z)
{
	return ((cos(45) * x + 0 * x + sin(45) * x) + (0 * y + 1 * y + 0 * y) + (-sin(45) * z + 0 * z + cos(45) * z));
}

int main(void)
{

	int num[11][20] = {
	{0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
	{0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
	{0, 0, 10, 10,  0,  0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10,  0, 0, 0},
	{0, 0, 10, 10,  0,  0, 10, 10, 0, 0, 0,  0,  0,  0,  0, 10, 10, 0, 0},
	{0, 0, 10, 10,  0,  0, 10, 10, 0, 0, 0,  0,  0,  0,  0, 10, 10, 0, 0},
	{0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0,  0, 10, 10, 10, 10,  0, 0, 0},
	{0, 0,  0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10,  0,  0,  0,  0, 0, 0},
	{0, 0,  0,  0,  0,  0, 10, 10, 0, 0, 0, 10, 10,  0,  0,  0,  0, 0, 0},
	{0, 0,  0,  0,  0,  0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
	{0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0},
	{0, 0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0,  0,  0,  0,  0,  0, 0, 0}};
	int col = 0;
	int default_x = 660;
	int y_coor = 330;
	int row = 0;
	while (row <= 10)
	{
		while (col <= 19)
		{
			if (col < 19)
				printf("(%d, %d), (%d, %d), ",
				(int)rotation_x(default_x, y_coor, num[row][col]), 
				(int)rotation_y(default_x, y_coor, num[row][col]), 
				(int)rotation_x(default_x + 70, y_coor, num[row + 1][col]), 
				(int)rotation_y(default_x, y_coor, num[row + 1][col]));//, 0xF00000);//red horizontal 
			if (row != 0)
				printf("(%d, %d), (%d, %d), ",
				(int)rotation_x(default_x, y_coor, num[row][col]), 
				(int)rotation_y(default_x, y_coor, num[row][col]),
				(int)rotation_x(default_x, y_coor, num[row][col]),
				(int)rotation_y(default_x, y_coor - 70, num[row + 1][col]));//, 0x0000FF);//blue vertical good
			//printf("%d ", num[row][col]);
			col++;
			default_x += 70;
		}
		default_x = 660;
		y_coor += 70;
		col = 0;
		row++;
		printf("\n\n\n");
	}
	return (0);
}