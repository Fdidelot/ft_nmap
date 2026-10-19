#include "ft_nmap.h"

bool speedup_check(char *speedup){
    if (speedup[strspn(speedup, "0123456789")] != '\0')
        return false;
    if (atoi(speedup) > 250)
        return false;
    return true;
}

int ports_check(char *ports){
    if (ports[strspn(ports, ",-0123456789")] != '\0')
        return 1;
    int i;
    i = strlen(ports);
    if (ports[0] == ',' || ports[0] == '-' || ports[i] == '-' || ports[i] == ',')
        return 2;
    return 0;
}

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
                const char *option_arg;
                option_arg = argv[optind - 2];
                if (strcmp(option_arg, "--help") != 0){
                    fprintf(stderr, "Option invalide : utilisez --help\n");
                    return;
                }
                print_help();
                break ;
            case OPT_PORT:
                option_arg = argv[optind - 2];
                if (strcmp(option_arg, "--ports") != 0){
                    fprintf(stderr, "Option invalide : utilisez --ports\n");
                    return;
                }
                if (ports_check(optarg) != 0)
                {

                }
                data->options[opt] = true;
                data->args_pointer[opt] = optarg;
                break ;
            case OPT_IP:
                 option_arg = argv[optind - 2];
                if (strcmp(option_arg, "--ip") != 0){
                    fprintf(stderr, "Option invalide : utilisez --ip\n");
                    return;
                }
                data->options[opt] = true;
                data->args_pointer[opt] = optarg;
                break ;
            case OPT_FILE:
                
                option_arg = argv[optind - 2];
                if (strcmp(option_arg, "--file") != 0){
                    fprintf(stderr, "Option invalide : utilisez --file\n");
                    return;
                }
                data->options[opt] = true;
                data->args_pointer[opt] = optarg;
                break ;
            case OPT_SPD:
                option_arg = argv[optind - 2];
                if (strcmp(option_arg, "--speedup") != 0){
                    fprintf(stderr, "Option invalide : utilisez --speedup\n");
                    return;
                }
                if (speedup_check(optarg) == false){
                    fprintf(stderr, "Valeur speedup invalide : min 0 max 250\n");
                    break;
                }
                data->options[opt] = true;
                data->args_pointer[opt] = optarg;
                break ;
            case OPT_SCAN:
                option_arg = argv[optind - 2];
                if (strcmp(option_arg, "--scan") != 0){
                    fprintf(stderr, "Option invalide : utilisez --scan\n");
                    return;
                }
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


