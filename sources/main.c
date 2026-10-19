#include "ft_nmap.h"

int main(int argc, char **argv)
{

    t_nmap_data data = {0};
    parse_args(argc, argv, &data);

    if (argc == 1 || data.options[OPT_HELP])
        print_help();


    // DEBUG
    const char *options[] =
    {
        "Help", "Port", "IP", "File", "Speed", "Scan"
    };
    printf("\n\n");
    for (int i = OPT_PORT; i < NB_OPT; i += 1)
    {
        printf("%7s = %s\n", options[i], data.args_pointer[i]);
    }
    printf("\n\n");
    for (int i = 0; i < NB_OPT; i++)
    {
        printf("%7s : %s\n", options[i], data.options[i] ? "True": "False");
    }
    // END DEBUG

    validate_arguments(&data);
    return 0;
}