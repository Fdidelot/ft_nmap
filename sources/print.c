#include "ft_nmap.h"

const char help_message[] = 
"Usage:\n\
    ft_nmap [--help] [--ports [NUMBER/RANGED]] --ip IP_ADDRESS [--speedup [NUMBER]] [--scan [TYPE]]\n\
            or\n\
    ft_nmap [--help] [--ports [NUMBER/RANGED]] --file FILE [--speedup [NUMBER]] [--scan [TYPE]\n\n\
Options:\n\
    --help      Print this helper\n\
    --ports [NUMBER/RANGED]\n\
                Ports to scan (eg: 1-10 or 1,2,3 or 1,5-15), max 1024 ports\n\
    --ip IP_ADDRESS\n\
                IP address to scan\n\
    --file FILE\n\
                File name containing IP addresses to scan\n\
    --speedup NUMBER\n\
                Number of parallel threads to use (250 max)\n\
    --scan TYPE\n\
                Scan type to perform SYN/NULL/FIN/XMAS/ACK/UDP\n\
\n";

void print_help(void)
{
    printf("%s", help_message);
    clean_exit(EXIT_SUCCESS);
}