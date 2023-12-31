
    char *custom_strchr(const char *s, int c) {
        while (*s != ' ') {
            if (*s == c) {
                return (char *)s;
            }
            s++;
        }
        return NULL;
    }
    
#include "shell.h"

/**
* execute_command - Executes a command.
* @argv: array of arguments.
*/
void execute_command(char **argv)
{
pid_t pid;
int status;
char *cmd_path = NULL;

if (custom_strchr(argv[0], '/') == NULL)
{
cmd_path = find_command(argv[0]);
if (!cmd_path)
{
write(stderr, "%s: command not found\n", argv[0]);
return;
}
argv[0] = cmd_path;
}

pid = fork();
if (pid == -1)
{
perror("fork failed");
free(cmd_path);
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(argv[0], argv, environ) == -1)
{
perror("execve failed");
exit(EXIT_FAILURE);
}
}
else
{
do
{
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
free(cmd_path);
}
