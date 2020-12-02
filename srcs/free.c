#include "../head.h"


void	save_2D(char ***tmp, char **s)
{
	int i;

	while (s[i])
		i++;
	*tmp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (s[i])
	{
		(*tmp)[i] = ft_strdup(s[i]);
		i++;
	}
	(*tmp)[i] = NULL;
}

void	free_2D(char ***s)
{
	int i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
		i++;
	}
	free((*s));
	(*s) = NULL;
}
