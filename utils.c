#include "pipex.h"

/* Showing error */
int	ft_error(char *error)
{
	ft_putendl_fd(error, 2);
	return (1);
}

/* Cleaning 2d array */
void	ft_clear_2d(char **array)
{
	int		i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

/* Validate and open arguments(files) */
int 	ft_isvalid(char *file1, char *file2, int *fd)
{
	fd[0] = open(file1, O_RDONLY);
	if (fd[0] == -1)
		return (0);
	fd[1] = open(file2, O_RDWR | O_TRUNC | O_CREAT | 0755);
	if (fd[1] == -1)
	{
		close(fd[0]);
		return (0);
	}
	return (1);
}
