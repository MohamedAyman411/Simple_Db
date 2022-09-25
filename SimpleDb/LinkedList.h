#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "DataTypes.h"
#include "node.h"

typedef struct
{
    struct node *head;

}LinkedList;

bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(struct node ** listHead,uint8 id,uint8 year,uint8* subjects,uint8* grades);
void SDB_DeleteEntry(struct node ** listHead,uint8 id);
bool SDB_ReadEntry(struct node ** listHead,uint8 id,uint8* year,uint8* subjects,uint8* grades);
void SDB_GetIdList(struct node ** listHead,uint8* count,uint8* list );
bool SDB_isIdExist(struct node ** listHead,uint8 ID);

void SDB_PrintList(struct node**listhead);


#endif // LINKEDLIST_H_INCLUDED
