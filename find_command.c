
    // Custom implementations of strcpy, strlen, and snprintf
    // Placeholders for actual implementations
    

    char *custom_getenv(const char *name) {
        // Custom implementation of getenv
        // Placeholder for actual implementation
        return NULL;
    }
    
#include "shell.h"

/**
* find_command - Searches for the command in the directories.
* @cmd: command.
*
* Return: Path to the command if found, if not NULL.
*/
#include "shell.h"

char *find_command(char *cmd)
{
char *path = custom_getenv("PATH");
char *path_copy, *full_path, *dir;

if (!path)
{
return (NULL);
}

path_copy = malloc(custom_strlen(path) + 1);
if (!path_copy)
{
perror("malloc");
return (NULL);
}
custom_strcpy(path_copy, path);

full_path = malloc(MAX_LINE);
if (!full_path)
{
perror("malloc");
free(path_copy);
return (NULL);
}

dir = strtok(path_copy, ":");
while (dir != NULL)
{
custom_snprintf(full_path, MAX_LINE, "%s/%s", dir, cmd);
if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (full_path);
}
dir = strtok(NULL, ":");
}

free(path_copy);
free(full_path);
return (NULL);
}
