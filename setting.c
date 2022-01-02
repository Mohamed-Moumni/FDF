/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:44:22 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/02 17:12:52 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(int error)
{
	if (error == 1)
		write(2, "FILE ERROR.\n", 12);
	else if (error == 2)
		write(2, "Invalid Parameters.\n", 21);
	else if (error == 3)
		write(2, "Allocation Error.\n", 18);
	else if (error == 4)
		write(2, "Found wrong line length Exiting.\n", 33);
	exit(1);
}
