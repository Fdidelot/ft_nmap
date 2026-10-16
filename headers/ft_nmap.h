#ifndef FT_NMAP_H
# define FT_NMAP_H

# include <stdio.h>
# include <stdlib.h>
# include <getopt.h>
# include <stdbool.h>

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

void    parse_args(int argc, char **argv,
                    t_nmap_data *data);

void    clean_exit(int exit_code);

#endif