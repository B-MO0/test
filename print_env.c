
    // Custom implementations of strcpy, strlen, and snprintf
    // Placeholders for actual implementations
    
#include "shell.h"

/**
* print_env - Prints all the environment variables.
* @env: the environment.
*/
void print_env(void)
{
int i = 0;
while (environ[i])
{
write(STDOUT_FILENO, environ[i], custom_strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
}
