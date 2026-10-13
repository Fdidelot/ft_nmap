#include "in.h"


int main(int agrc ,char **agrv)
{
    if (agrc == 1)
    {
        help();
    }

    if (agrc > 1){
        
        if(strcmp(agrv[1],"--help") == 0)
        {
            help();
            return 0;
        }
        int i;
        for(i = 0; agrv[i];i++) 
        {
            if(strcmp(agrv[i],"--ports") == 0)
            {
                if(agrv[i+1])
                {
                    ports(agrv[i+1]);
                }
                else
                {
                    return 1;
                }
            }
        }

    }
    return 0;
}
