#include "push_swap.h"

int main(int argc, char const *argv[])
{
    int i;
    t_holder *holder;
    
    i = 0;
    if (argc < 2)
        return(0);

    holder = get_valid_holder(argc, argv);
    if(holder != NULL)
    //teste
        tester(holder);
    //fim teste
    // free_holder(holder);
}
