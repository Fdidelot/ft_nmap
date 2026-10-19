#include "ft_nmap.h"

static bool speedup_check(const char *speedup){
    if (speedup[strspn(speedup, "0123456789")] != '\0')
        return false;
    if (atoi(speedup) > 250)
        return false;
    return true;
}

static bool ports_check(const char *ports){
    if (ports[strspn(ports, ",-0123456789")] != '\0')
        return false;
    int i;
    i = strlen(ports);
    if (ports[0] == ',' || ports[0] == '-' || ports[i] == '-' || ports[i] == ',')
        return false;
    return true;
}

static bool ip_check(const char *ip)
{
    (void)ip;
    return true;
}

static bool file_check(const char *file)
{
    (void)file;
    return true;
}

static bool scan_check(const char *scan)
{
    (void)scan;
    return true;
}

/* Todo 

    Remplacer atoi par strtol dans speedup_check, de souvenir atoi c'est deprecated,
    et apres test il a pas l'air de marcher avec des nombres trop grand

    Implementer ip_check, file_check, scan_check

    Est ce qu'on stock les valeurs directement dans les fonctions de check ?
    Par exemple speedup vu qu'on fait direct le atoi/strtol on a la valeur donc
    on pourrais, mais est ce que ce sera aussi pratique pour toute ?
    Si oui, je pense qu'il faut rajouter data en arguments aux fonctions,
    et je pense juste rajouter des fields direct dans la structure pour l'instant,
    si besoin on creera des sous structures pour que ce soit mieux organiser et on
    reviendra modifier.

    Peut etre changer le scope de option_name, si on en a besoin autre part
*/

void    validate_arguments(t_nmap_data *data)
{
    static const char *option_name[] =
    {
        [OPT_PORT]  = "ports",
        [OPT_IP]    = "ip",
        [OPT_FILE]  = "file",
        [OPT_SPD]   = "speedup",
        [OPT_SCAN]  = "scan"
    };

    static bool (*const check_functions[])(const char *) =
    {
        [OPT_PORT]  = ports_check,
        [OPT_IP]    = ip_check,
        [OPT_FILE]  = file_check,
        [OPT_SPD]   = speedup_check,
        [OPT_SCAN]  = scan_check
    };

    for (int opt = OPT_PORT; opt < NB_OPT; opt++)
    {
        if (data->options[opt] &&
            check_functions[opt](data->args_pointer[opt]) == false)
            print_error(INVALID_ARG_VALUE, data->args_pointer[opt],
                        option_name[opt]);
   }
}