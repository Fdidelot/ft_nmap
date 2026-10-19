#include "ft_nmap.h"

static void    is_valid_opt(const char *arg, const char *option)
{
    if (strncmp(arg + 2, option, strlen(option) + 1) != 0)
        print_error(INVALID_OPTION, arg);
}

static bool    no_short_option(const char *option, struct option *long_options)
{
    size_t len = strlen(option) + 1;

    for (;long_options->name ;long_options++)
    {
        if (strncmp(option + 2, long_options->name, len) == 0)
            return 1;
    }
    return 0;
}

void    parse_args(int argc, char **argv, t_nmap_data *data)
{
    int         opt, index;
    const char  *options = ":";
    extern int  optind;

    extern int  opterr;
    opterr = 0;

    static struct option long_options[] = {
        {"help", no_argument, NULL,  OPT_HELP },
        {"ports", required_argument, NULL,  OPT_PORT },
        {"ip", required_argument, NULL,  OPT_IP },
        {"file", required_argument, NULL,  OPT_FILE },
        {"speedup", required_argument, NULL,  OPT_SPD },
        {"scan", required_argument, NULL,  OPT_SCAN },
        {NULL,   0,           NULL,  0 }
    };
    

    while (1)
    {
        if ((opt = getopt_long(argc, argv, options, long_options, &index)) == -1)
            break;

        const char *raw_option = argv[optind] ? argv[optind]: argv[optind - 1];
        if (optarg && optind >= 2 && optarg == argv[optind - 1])
            raw_option = argv[optind - 2];

        switch (opt)
        {            
            case OPT_HELP:
            case OPT_PORT:
            case OPT_IP:
            case OPT_FILE:
            case OPT_SPD:
            case OPT_SCAN:
                is_valid_opt(raw_option, long_options[index].name);
                data->options[opt] = true;
                if (optarg)
                    data->args_pointer[opt] = optarg;
                break ;
            case ':':
                if (no_short_option(raw_option, long_options))
                    print_error(ARGUMENT_REQUIRED, raw_option);
                print_error(INVALID_OPTION, raw_option);
                break;
            case '?':
            default:
                print_error(INVALID_OPTION, raw_option);
                break;
        }
    }
    if (optind != argc)
        print_error(INVALID_ARGUMENT, argv[optind]);
}


