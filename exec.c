#include "pipex.h"

/* Search path to script */
static	char	*ft_search_cmd(char *cmd, char *path, char **script)
{
	int		i;
	char	*tmp;
	char	**paths;

	i = -1;
	cmd = ft_strjoin("/", cmd);
	paths = ft_split(path, ':');
	while (paths[++i] && !*script)
	{
		tmp = ft_strjoin(paths[i], cmd);
		if (!access(tmp, 0) && !access(tmp, 1))
			*script = tmp;
		else
			free(tmp);
	}
	free(cmd);
	ft_clear_2d(paths);
	return (*script);
}

/* Execute command function */
void	ft_exec_cmd(char **cmd, char **env)
{
	int		i;
	char	*path;
	char	*script;

	i = -1;
	path = NULL;
	script = NULL;
	while (env[++i] && !path)
		if (!ft_strncmp(env[i], "PATH=", 5))
			path = ft_strchr(env[i], '=');
	if (!ft_search_cmd(cmd[0], ++path, &script))
		ft_error(RED"Er.: Command not found!"RESET);
	else
		execve(script, cmd, env);
	free(script);
	ft_clear_2d(cmd);
}
