#include "ft_nmap.h"

void    print_error(int code, ...)
{
    static const char *error_message[] =
    {
        [INVALID_OPTION]    = "Invalid option: '%s'\n",
        [ARGUMENT_REQUIRED] = "Option: '%s' require an argument.\n",
        [INVALID_ARGUMENT]  = "Invalid argument: '%s'\n",
        [INVALID_ARG_VALUE] = "Invalid argument: '%s' to option '--%s'\n"
    };

    va_list args;
    va_start(args, code);
    vfprintf(stderr, error_message[code], args);
    va_end(args);
    clean_exit(EXIT_FAILURE);
}