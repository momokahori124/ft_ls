/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:09:12 by momoka            #+#    #+#             */
/*   Updated: 2020/12/04 03:35:16 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

int			cmp_by_alpha(char *s, char *t)
{
	int i;

	i = 0;
	while (s[i] && t[i])
	{
		if (s[i] != t[i])
			return (s[i] - t[i]);
		i++;
	}
	return (s[i] - t[i]);
}

int			cmp_by_mtime(char *s, char *t)
{
	struct stat		buf1;
	struct stat		buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_mtime : ");
		exit(0);
	}
	if (buf1.st_mtime != buf2.st_mtime)
		return (-(buf1.st_mtime - buf2.st_mtime));
	else if (buf1.st_mtimespec.tv_nsec != buf2.st_mtimespec.tv_nsec)
		return (-(buf1.st_mtimespec.tv_nsec - buf2.st_mtimespec.tv_nsec));
	else
		return (cmp_by_alpha(s, t));
}

int			cmp_by_atime(char *s, char *t)
{
	struct stat		buf1;
	struct stat		buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_atime : ");
		exit(0);
	}
	if (buf1.st_atime != buf2.st_atime)
		return (-(buf1.st_atime - buf2.st_atime));
	else if (buf1.st_atimespec.tv_nsec != buf2.st_atimespec.tv_nsec)
		return (-(buf1.st_atimespec.tv_nsec - buf2.st_atimespec.tv_nsec));
	else
		return (cmp_by_alpha(s, t));
}

int			cmp_by_ctime(char *s, char *t)
{
	struct stat		buf1;
	struct stat		buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_ctime : ");
		exit(0);
	}
	if (buf1.st_birthtimespec.tv_sec != buf2.st_birthtimespec.tv_sec)
		return (-(buf1.st_birthtimespec.tv_sec - buf2.st_birthtimespec.tv_sec));
	else if (buf1.st_birthtimespec.tv_nsec != buf2.st_birthtimespec.tv_nsec)
		return (-(buf1.st_birthtimespec.tv_nsec - \
		buf2.st_birthtimespec.tv_nsec));
	else
		return (cmp_by_alpha(s, t));
}

int			cmp_by_filesize(char *s, char *t)
{
	struct stat		buf1;
	struct stat		buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_filesize : ");
		exit(0);
	}
	if (buf1.st_size != buf2.st_size)
		return (-(buf1.st_size - buf2.st_size));
	else
		return (cmp_by_alpha(s, t));
}
