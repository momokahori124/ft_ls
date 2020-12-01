#include "../head.h"

int     cmp_by_alpha(char *s, char *t)
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

int		cmp_by_mtime(char *s, char *t)
{
	struct stat     buf1;	
	struct stat     buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_mtime : ");
		exit(0);
	}
	return (-(buf1.st_mtime - buf2.st_mtime));
}

int		cmp_by_atime(char *s, char *t)
{
	struct stat     buf1;	
	struct stat     buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_atime : ");
		exit(0);
	}
	return (-(buf1.st_atime - buf2.st_atime));
}

int		cmp_by_ctime(char *s, char *t)
{
	struct stat     buf1;	
	struct stat     buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_ctime : ");
		exit(0);
	}
	return (-(buf1.st_ctime - buf2.st_ctime));
}

int		cmp_by_filesize(char *s, char *t)
{
	struct stat     buf1;	
	struct stat     buf2;

	if (lstat(s, &buf1) != 0 || lstat(t, &buf2) != 0)
	{
		perror("cmp_by_ctime : ");
		exit(0);
	}	
	return (buf1.st_size - buf2.st_size);
}
