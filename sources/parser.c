#include "ft_nmap.h"

void    parse_args(int argc, char **argv, t_nmap_data *data)
{
    int         opt;
    const char  *options = "";
    extern int  optind;

    /* Setting opterr to 0 mute getopt error messages */
    // extern int  opterr;
    // opterr = 0;

    static struct option long_options[] = {
        {"help", no_argument, NULL,  OPT_HELP },
        {"ports", required_argument, NULL,  OPT_PORT },
        {"ip", required_argument, NULL,  OPT_IP },
        {"file", required_argument, NULL,  OPT_FILE },
        {"speedup", required_argument, NULL,  OPT_SPD },
        {"scan", required_argument, NULL,  OPT_SCAN },
        {NULL,   0,           NULL,  0 }
    };

    while ((opt = getopt_long(argc, argv, options, long_options, NULL)) != -1)
    {
        switch (opt)
        {
            case OPT_HELP:
                print_help();
                break ;
            case OPT_PORT:
            case OPT_IP:
            case OPT_FILE:
            case OPT_SPD:
            case OPT_SCAN:
                data->options[opt] = true;
                data->args_pointer[opt] = optarg;
                break ;
            case ':':
                /* Missing required argument */
                break;
            case '?':
            default:
                break;
        }
    }
}
