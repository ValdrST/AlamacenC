#include <stdio.h>
#include <ctype.h>

char opcion()
{
    char op;
    int r;
    do
    {
        printf("Opcion?");
        r=scanf("%c",&op);
        fflush(stdin);
        op=tolower(op);
        if((r!=1)||(op<'a')||(op>'f'))
        {
            printf("Te equivocaste, lero lero!\n");
            printf("intente Nuevamente\n");
        }
    }
    while((r!=1)||(op<'a')||(op>'f'));
    return op;
}
