#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "data.h"

struct node
{
    struct_Data_t data;
    struct node *next;
};


#endif // NODE_H_INCLUDED
