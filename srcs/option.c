/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:59:06 by momoka            #+#    #+#             */
/*   Updated: 2020/12/03 23:26:16 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	ft_put_dirname(char *dirname, char *inner_dirname, t_input input)
{
	struct stat		stat_buf;
	char			*path;

	if (input.option[key('G')] != 1)
	{
		ft_printf_s("%\n", 0, inner_dirname);
		return ;
	}
	if (dirname[0] == '.' && dirname[1] != '/')
		path = ft_strdup(inner_dirname);
	else
		path = ft_strjoin3(dirname, inner_dirname);
	lstat(path, &stat_buf);
	if (S_ISDIR(stat_buf.st_mode))
		putstr_blue(inner_dirname);
	else if (S_ISLNK(stat_buf.st_mode))
		putstr_magent(inner_dirname);
	else if (stat_buf.st_mode & S_IXUSR)
		putstr_red(inner_dirname);
	else
		ft_printf_s("%\n", 0, inner_dirname);
	free(path);
}
