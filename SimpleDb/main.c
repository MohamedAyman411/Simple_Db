#include <stdio.h>
#include <stdlib.h>

#include "DataTypes.h"
#include "Data.h"
#include "node.h"
#include "LinkedList.h"




int main()
{
    LinkedList L1;      //create linked list
    L1.head=NULL;       //Initializing linked list

    //Declarations
    bool DbFull;
    bool EntryExist;
    bool EntryAdd;
    bool ReadEntry;
    uint8 size;


    //Creating Samples
    uint8 id_1=10;
    uint8 year_1=18;
    uint8 subjects_1[]={14,15,16};
    uint8 grades_1[]={11,12,13};

    uint8 id_2=11;
    uint8 year_2=19;
    uint8 subjects_2[]={24,25,26};
    uint8 grades_2[]={21,22,23};

    uint8 id_3=12;
    uint8 year_3=20;
    uint8 subjects_3[]={34,35,36};
    uint8 grades_3[]={31,32,33};


    //Functions

    EntryAdd = SDB_AddEntry(&(L1.head),id_1,year_1,subjects_1,grades_1);
    EntryAdd = SDB_AddEntry(&(L1.head),id_2,year_2,subjects_2,grades_2);
    EntryAdd = SDB_AddEntry(&(L1.head),id_3,year_3,subjects_3,grades_3);

    DbFull=SDB_IsFull();

    SDB_DeleteEntry(&(L1.head),12);

    size=SDB_GetUsedSize();

    EntryExist=SDB_isIdExist((&L1.head),11);


    uint8 readYear=0;
    uint8 readSubjects[3]={0,0,0};
    uint8 readGrades[3]={0,0,0};
    ReadEntry=SDB_ReadEntry((&L1.head),11,&readYear,readSubjects,readGrades);



    uint8 count;
    uint8* IdList;
    SDB_GetIdList(&(L1.head),&count,&IdList);



    //Output

    SDB_PrintList(&(L1.head));

    printf("-----------------------------\n");
    printf("Id list\n");

    uint8 i;
    for(i=0;i<count;i++)
    {
        printf("%d\n",*IdList);
        IdList++;
    }
    printf("-----------------------------\n");





    if(ReadEntry==True)
    {
        printf("Read Entry: \n");
        printf("Student year %d\n",readYear);

        uint8 i;
        for(i=0;i<3;i++)
        {
            printf("Subject ID=%d , Grade=%d\n",readSubjects[i],readGrades[i]);
        }
    }
    printf("-----------------------------\n");

    printf("1 for True,0 for false\n");
    printf("Entry exist:%d\n",EntryExist);
    printf("database full: %d\n",DbFull);
    printf("Size Used=%d\n",size);

    return 0;
}

