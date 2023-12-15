
    int custom_strcmp(const char *s1, const char *s2) {
        // Custom implementation of strcmp
        // Placeholder for actual implementation
        return 0;
    }
    
#include "shell.h"

/**
* run_shell - shell infinite loop.
* Return: status
*/
int run_shell(void)
{
char *line = NULL;
char *argv[MAX_ARGS];

while (1)
{
display_prompt();
read_command(&line);

if (!parse_command(line, argv))
{
free(line);
line = NULL;
continue;
}

if (custom_strcmp(argv[0], "exit") == 0)
{
free(line);
return (0);
}

if (custom_strcmp(argv[0], "env") == 0)
{
print_env();
free(line);
line = NULL;
continue;
}

execute_command(argv);
free(line);
line = NULL;
}
}

/**
* main - run the shell
* Return: status
*/
int main(void)
{
return (run_shell());
}
