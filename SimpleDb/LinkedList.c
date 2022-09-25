#include "DataTypes.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>


int Counter=0;


bool SDB_IsFull(void)
{
    if (Counter==10)
    {
        return True;
    }
    else
    {
        return False;
    }
}


uint8 SDB_GetUsedSize(void)
{
    return Counter;
}


bool SDB_AddEntry(struct node ** listHead,uint8 id,uint8 year,uint8* subjects,uint8* grades)
{
    if (Counter==10)
    {
        printf("Database is full");
        return False;
    }

    if (grades[1]>100 && grades[1]<0 &&
        grades[2]>100 && grades[2]<0 &&
        grades[3]>100 && grades[3]<0)
    {
        printf("Grades only valid from 0 to 100");
        return False;
    }


    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data.StudentId = id;
    newNode->data.StudentYear= year;

    newNode->data.Course_1_ID = *subjects;
    ++subjects;

    newNode->data.Course_2_ID = *subjects;
    ++subjects;

    newNode->data.Course_3_ID = *subjects;
    ++subjects;

    newNode->data.Course_1_Grade = *grades;
    ++grades;

    newNode->data.Course_2_Grade = *grades;
    ++grades;

    newNode->data.Course_3_Grade = *grades;
    ++grades;

    Counter++;

    newNode -> next =*listHead;
    *listHead = newNode;

    return True;

}




void SDB_DeleteEntry(struct node ** listHead,uint8 id)
{
    struct node *curr = *listHead;
    struct node *prev = *listHead;


    if(*listHead == NULL)
    {
            printf("No data found\n");
            return;
    }

    while(curr != NULL && curr->data.StudentId != id)
    {
        prev=curr;
        curr=curr->next;

        if (curr==NULL)
        {
            break;
        }
    }

    if (curr==NULL)
    {
        printf("No such id");
        return;
    }

    if (curr->data.StudentId == id)
    {
        if((*listHead)==curr)       //delete first node
        {
            free(*listHead);
            (*listHead)=curr->next;
            Counter--;
            return;
        }
        if(curr->next ==NULL)       //delete last node
        {
            free(curr);
            prev->next=NULL;
            Counter--;
            return;
        }

        prev->next=curr->next;
        free(curr);
        Counter--;

    }
}




bool SDB_ReadEntry(struct node ** listHead,uint8 id,uint8* year,uint8* subjects,uint8* grades)
{
    struct node *curr = *listHead;


     while(curr != NULL && curr->data.StudentId != id)
    {
        curr=curr->next;

        if (curr==NULL)
        {
            break;
        }
    }

    if (curr==NULL)
    {
        printf("No data found\n");
        return False;
    }

    *year=curr->data.StudentYear;

    *grades=curr->data.Course_1_Grade;
    grades++;
    *grades=curr->data.Course_2_Grade;
    grades++;
    *grades=curr->data.Course_3_Grade;
    grades++;

    *subjects=curr->data.Course_1_ID;
    subjects++;
    *subjects=curr->data.Course_2_ID;
    subjects++;
    *subjects=curr->data.Course_3_ID;
    subjects++;
    return True;
}




void SDB_GetIdList(struct node ** listHead,uint8* count,uint8** list)
{
    *count=Counter;
    struct node *curr = *listHead;

    *list=(uint8*)malloc(Counter*sizeof(uint8));

    uint8 i;
    for (i=0;i<Counter;i++)
    {
        (*list)[i] = curr->data.StudentId;
        curr=curr->next;
    }

}



bool SDB_isIdExist(struct node ** listHead,uint8 ID)
{
    struct node *curr = *listHead;
    while (curr !=NULL)
    {
        if (ID == curr->data.StudentId)
        {
            return True;
        }
        else
        {
            curr=curr->next;
        }
    }
    return False;
}


void SDB_PrintList(struct node**listhead)
{
    struct node*curr=*listhead;
    while(curr!=NULL)
    {
        printf("Student ID: %d\n", curr->data.StudentId);
        printf("Student Year: %d\n", curr->data.StudentYear);
        printf("Course1 ID: %d\n", curr->data.Course_1_ID);
        printf("Course1 Grade: %d\n", curr->data.Course_1_Grade);
        printf("Course2 ID: %d\n", curr->data.Course_2_ID);
        printf("Course2 Grade: %d\n", curr->data.Course_2_Grade);
        printf("Course3 ID: %d\n", curr->data.Course_3_ID);
        printf("Course3 Grade: %d\n\n", curr->data.Course_3_Grade);

        curr=curr->next;

    }

}
