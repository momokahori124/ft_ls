#include "../head.h"

int		is_directory(char *dirname, char *inner_dirname)
{
	struct stat     buf;
	char *path;

	if (dirname[0] == '.' && dirname[1] == '/')
		path = ft_strjoin3(dirname, inner_dirname);
	else if (dirname[0] == '.')
		path = ft_strdup(inner_dirname);
	else
		path = ft_strjoin3(dirname, inner_dirname);
	if (lstat(path, &buf) != 0)
	{
		printf("dirname : %s\ninner_dirname : %s\npath : %s\n", dirname, inner_dirname, path);
		perror("is_directory?");
	}
	free(path);
	return (S_ISDIR(buf.st_mode));
}

int		is_regfile(char *dirname, char *inner_dirname)
{
	struct stat     buf;
	char *path;

	if (dirname[0] == '.' && dirname[1] == '/')
		path = ft_strjoin3(dirname, inner_dirname);
	else if (dirname[0] == '.')
		path = ft_strdup(inner_dirname);
	else
		path = ft_strjoin3(dirname, inner_dirname);
	
	if (lstat(path, &buf) != 0)
		perror("is_regfile?");
	free(path);
	return (S_ISREG(buf.st_mode));
}


