#ifndef FT_NMAP_H
# define FT_NMAP_H

# include <stdio.h>
# include <stdlib.h>
# include <getopt.h>
# include <stdbool.h>
# include <string.h>
# include <stdarg.h>

enum
{
    INVALID_OPTION,
    ARGUMENT_REQUIRED,
    INVALID_ARGUMENT,
    INVALID_ARG_VALUE
};

enum
{
    OPT_HELP,
    OPT_PORT,
    OPT_IP  ,
    OPT_FILE,
    OPT_SPD ,
    OPT_SCAN,
    NB_OPT
};

typedef struct  nmap_data
{
    bool        options[NB_OPT];
    const char  *args_pointer[NB_OPT];
}   t_nmap_data;

void    print_help(void);
void    print_error(int code, ...);

void    parse_args(int argc, char **argv,
                    t_nmap_data *data);
void    validate_arguments(t_nmap_data *data);

void    clean_exit(int exit_code);

#endif