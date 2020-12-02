#include "../head.h"

int		is_directory(char *dirname, char *inner_dirname)
{
	struct stat     buf;
	char *path;

	if (dirname[0] == '.' && dirname[1] != '/')
		path = ft_strdup(inner_dirname);
	else
		path = ft_strjoin3(dirname, inner_dirname);
	if (lstat(path, &buf) != 0)
		perror("is_directory?");
	free(path);
	return (S_ISDIR(buf.st_mode));
}

int		is_regfile(char *dirname, char *inner_dirname)
{
	struct stat     buf;
	char *path;

	if (dirname[0] == '.' && dirname[1] != '/')
		path = ft_strdup(inner_dirname);
	else
		path = ft_strjoin3(dirname, inner_dirname);
	
	if (lstat(path, &buf) != 0)
		perror("is_regfile?");
	free(path);
	return (S_ISREG(buf.st_mode));
}


