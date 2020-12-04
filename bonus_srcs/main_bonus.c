/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:58:58 by momoka            #+#    #+#             */
/*   Updated: 2020/12/04 20:10:37 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	count_and_malloc_dirname(char *av[], t_input *input)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	while (av[i])
	{
		if (av[i][0] != '-')
		{
			flag = 1;
			input->dirnum++;
		}
		else if (flag == 1)
			input->dirnum++;
		i++;
	}
	input->dirname = (char **)malloc(sizeof(char *) * (input->dirnum + 2));
}

int		main(int ac, char *av[])
{
	t_input		input;

	if (is_error(ac, av))
	{
		write(2, "Error.\n", 7);
		return (1);
	}
	input = (t_input){0};
	input_option(&input, ac, av);
	count_and_malloc_dirname(av, &input);
	input_dirname(av, &input);
	each_do_ls(input);
	free_2d(&input.dirname);
	return (0);
}
