#include "in.h"

void help(){
    printf ("ft_nmap [OPTIONS]\n" 
        "--help Print this help screen\n"
        "--ports [1024 max] ports to scan (eg: 1-10 or 1,2,3 or 1,5-15), default (1-1024)\n"
        "--ip ip addresses to scan in dot format\n"
        "--file File name containing IP addresses to scan\n"
        "--speedup [250 max] number of parallel threads to use\n"
        "--scan SYN/NULL/FIN/XMAS/ACK/UDP, all by default\n"
    );
}
