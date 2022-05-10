#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct staff{
    char name[50];
    char lib_name[50];
    int staff_num;

    struct staff *next;
}STAFF;

void help_msg();
STAFF *insert_node(STAFF *head, STAFF tmp);
void print_node(STAFF *head);

int main(){
    help_msg();
    STAFF *head = NULL;
    char cmd[10] = {0};
    while(1){
        printf("Please enter a command : ");scanf("%s",cmd);
        if(0 == strcmp(cmd,"help")){
            help_msg();
        }
        else if(0 == strcmp(cmd,"insert")){
            STAFF tmp;
            printf("Please enter name, library name, staff number : \n");
            printf("for example : name libx 1\n");
            scanf("%s %s %d",tmp.name, tmp.lib_name, &tmp.staff_num);
            head = insert_node(head,tmp);

        }
        else if(0 == strcmp(cmd,"print")){
            print_node(head);
        }
        else if(0 == strcmp(cmd,"search")){
            printf("---search---\n");
        }
        else if(0 == strcmp(cmd,"del")){
            printf("---del---\n");
        }
        else if(0 == strcmp(cmd,"free")){
            printf("---free---\n");
        }
        else if(0 == strcmp(cmd,"quit")){
            break;
        }
        else{
            printf("incorrect command\n");
        }
    }
    return 0;
}

void help_msg(){
    printf("#########################################################\n");
    printf("# command list                                          #\n");
    printf("# help : help message                                   #\n");
    printf("# insert : insert node                                  #\n");
    printf("# print : print all node                                #\n");
    printf("# search : search node                                  #\n");
    printf("# del : delete node                                     #\n");
    printf("# free : free node                                      #\n");
    printf("# quit : quit                                           #\n");
    printf("#########################################################\n");
}

STAFF *insert_node(STAFF *head, STAFF tmp){

    STAFF *p = (STAFF *)calloc(1,sizeof(STAFF));
    if(NULL == p){  //  >>> Situation : calloc failed <<<
        perror("calloc");
        return head;
    }

    if(NULL != p){  //  >>> Situation : calloc succeed <<<
        *p = tmp;
        p->next = NULL;

        if(NULL == head){   //  >> Situation : No node exist <<
            head = p;
            return head;
        }
        if(NULL != head){   //  >> Situation : Some nodes exist <<
            STAFF *pb = head, *pf = head;
            while( ((pb->staff_num) < (p->staff_num)) && (pb->next != NULL) ){  // > find place to insert <
                pf = pb;
                pb = pb->next;
            }
            if( (pb->staff_num) >= (p->staff_num) ){    //  > (pb->staff_num) larger than (p->staff_num) <
                if(pb == head){ //  >| p insert in the beginning of nodes |<
                    p->next = pb;
                    head = p;
                    return head;
                }
                else{   //  >| p inserts in middle place of nodes |<
                    pf->next = p;
                    p->next = pb;
                    return head;
                }
            }
            else{   //  > p inserts in the end of nodes <
                pf->next = p;
                return head;
            }
        }
    }
}

void print_node(STAFF *head){
    if(NULL == head){
        printf("No node exist\n");
    }
    if(NULL != head){
        STAFF *pb = head;
        while(pb != NULL){
            printf("Name : %s, Library name : %s, Staff number : %d\n",pb->name, pb->lib_name, pb->staff_num);
            pb = pb->next;
        }

    }
}
