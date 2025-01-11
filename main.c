#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int DATA;
    struct node *FORWARD;
    struct node *BACKWARD;
} Node;

#define INFO DATA
#define LINK FORWARD

// For Simple Linked List
Node* START_SIMPLE = NULL;
Node* AVAIL_SIMPLE = NULL;

// For Doubly Linked List
Node* START_DOUBLY = NULL;
Node* END_DOUBLY = NULL;
Node* AVAIL_DOUBLY = NULL;

// For Header Linked List
Node* HEAD = NULL;
Node* AVAIL_HEADER = NULL;

// For Circular Linked List
Node* START_CIRCULAR = NULL;
Node* AVAIL_CIRCULAR = NULL;

// Simple Linked List Functions..
void addToAvailOfSimple(Node* NEW){
    NEW->LINK = AVAIL_SIMPLE;
    AVAIL_SIMPLE = NEW;
}
void initSimpleAvail(int n){
    for(int i=0; i<n; i++){
        Node* NEW = (Node *)malloc(sizeof(Node));
        if(NEW == NULL)
            printf("\n\t\tMemory Allocation Failed !!\n");
        else{
            NEW->INFO = 0;
            addToAvailOfSimple(NEW);
        }
    }
}
Node* checkSimpleAvail(){
    if(AVAIL_SIMPLE == NULL){
        printf("\t\t No space is available for INSERTION\n");
        return NULL;
    }else{
        Node* NEW = AVAIL_SIMPLE;
        AVAIL_SIMPLE = AVAIL_SIMPLE->LINK;
        NEW->LINK = NULL;
        return NEW;
    }
}
// Functions of insertion for Simple Linked List..
void insertAtBeginInSimple(int data){
    Node* NEW = checkSimpleAvail();
    if(NEW == NULL){
        printf("\t\tSpace is not available!!");
    }else{
        NEW->INFO = data;
        NEW->LINK = START_SIMPLE;
        START_SIMPLE = NEW;
        printf("\t\tNew node %d is inserted at the beginning SUCCESSFULLY !!\n",data);
    }
}
void insertAtEndOfSimple(int data){
    Node *NEW = checkSimpleAvail();
    if(NEW == NULL){
        printf("\t\tSpace is not available!!\n");
    }else if(START_SIMPLE == NULL){
        NEW->INFO = data;
        NEW->LINK = NULL;
        START_SIMPLE = NEW;
        printf("\t\tNew node %d is inserted at end(as first node) SUCCESSFULLY !!\n", data);
    }else{
        NEW->INFO = data;
        NEW->LINK = NULL;
        Node* PTR = START_SIMPLE;
        while(PTR->LINK != NULL){
            PTR = PTR->LINK;
        }
        PTR->LINK = NEW;
        printf("\t\tNew node %d is inserted at the end SUCCESSFULLY !!");
    }
}
void insertAfterSpecificInSimple(int specific, int data){
    Node* PTR = START_SIMPLE;
    Node* LOC = NULL;
    while(PTR!=NULL){
        if(PTR->INFO == specific)
            LOC = PTR;
        PTR = PTR->LINK;
    }
    if(LOC == NULL){
        printf("\t\tSpecific element(node) you entered is not present in the list!!\n");
    }else{
        Node* NEW = checkSimpleAvail();
        if(NEW == NULL)
            printf("\t\tSpace is not Available!!");
        else{
            NEW->INFO = data;
            NEW->LINK = LOC->LINK;
            LOC->LINK = NEW;
            printf("\t\t New node %d is inserted after %d. SUCCESSFULLY!!\n",data,specific);
        }
    }
}
// Functions of deletion for Simple Linked List..
void deleteFirstOfSimple(){
    if(START_SIMPLE == NULL){
        printf("\t\t~~~ Unable to Delete ~~~ List is Empty ~~~\n");
    }else{
        Node* NEW = START_SIMPLE;
        START_SIMPLE = START_SIMPLE->LINK;
        NEW->INFO = 0;
        addToAvailOfSimple(NEW);
        if(START_SIMPLE == NULL)
            printf("\t\tThe only element is deleted from the List ~~~ List is now EMPTY\n");
        else
            printf("\t\tFirst element is deleted. SUCCESSFULLY!\n");
    }
}
void deleteLastOfSimple(){
    if(START_SIMPLE == NULL){
        printf("\t\t~~~ Unable to Delete ~~~ List is Empty ~~~\n");
    } else if (START_SIMPLE->LINK == NULL){
        Node* NEW = START_SIMPLE;
        START_SIMPLE = NULL;
        NEW->INFO = 0;
        addToAvailOfSimple(NEW);
        printf("\t\tThe only element is deleted.List is now EMPTY!\n");
    } else {
        Node* PTR = START_SIMPLE;
        Node* PREVIOUS = NULL;
        while(PTR->LINK != NULL){
            PREVIOUS = PTR;
            PTR = PTR->LINK;
        }
        PREVIOUS->LINK = NULL;
        addToAvailOfSimple(PTR);
        printf("\t\tLast element deleted SUCCESSFULLY !!\n");
    }
}
void deleteSpecificOfSimple(int deleteValue){
    if(START_SIMPLE == NULL){
        printf("\t\t ~~~~~ Unable to Delete ~~~ List is Empty ~~~~~\n");
    } else {
        Node* PTR = START_SIMPLE;
        Node* PREVIOUS = NULL;
        while(PTR != NULL && PTR->INFO != deleteValue){
            PREVIOUS = PTR;
            PTR = PTR->LINK;
        }
        if(PTR == NULL) {
            printf("\t\t Element %d not found in the list.\n",deleteValue);
        } else{
            if(PREVIOUS == NULL)
                START_SIMPLE = PTR->LINK;
            else
                PREVIOUS->LINK = PTR->LINK;
            PTR->INFO = 0;
            addToAvailOfSimple(PTR);
            printf("\t\t Element %d is deleted from the list\n",deleteValue);
        }
    }
}
// Searching in the simple linked list
void searchSimpleList(int search){
    int count = 0;
    int found = 0;
    if(START_SIMPLE == NULL) {
        printf("\t\t ~~~ Unable to search ~ List is EMPTY ~~~ \n");
    } else {
        Node* PTR = START_SIMPLE;
        while(PTR != NULL){
            count++;
            if(PTR->INFO == search && found == 0)
                found = count;
            PTR = PTR->LINK;
        }
        printf("\n\t\t Total number of elements in Simple List are: %d\n",count);
        if(found == 0)
            printf("\t\t Sorry, element not found\n");
        else
            printf("\t\t The element %d is found at position: %d\n",search, found);
    }
}
// free all the memory of simple linked list
void freeSimpleList(){
    Node* PTR;
    while(START_SIMPLE != NULL){
        PTR = START_SIMPLE;
        START_SIMPLE = START_SIMPLE->LINK;
        free(PTR);
    }
    while(AVAIL_SIMPLE != NULL){
        PTR = AVAIL_SIMPLE;
        AVAIL_SIMPLE = AVAIL_SIMPLE->LINK;
        free(PTR);
    }
    START_SIMPLE = AVAIL_SIMPLE = NULL;
}
// display simple linked list
void displaySimpleList(){
    Node* PTR = START_SIMPLE;
    printf("\n\t\tSimple Linked List: ");
    while(PTR != NULL){
        printf("\033[1;34m%d\033[0m -> ", PTR->INFO);
        PTR = PTR->LINK;
    }
    printf("NULL\n");
    PTR = NULL;
    PTR = AVAIL_SIMPLE;
    printf("\t\tSimple Avail List: ");
    while(PTR != NULL){
        printf("\033[1;32m%p\033[0m -> ", (void*)PTR);
        PTR = PTR->LINK;
    }
    printf("NULL\n\n");
}




// Doubly Linked List Functions...
void addToAvailOfDoubly(Node* NEW){
    NEW->FORWARD = AVAIL_DOUBLY;
    AVAIL_DOUBLY = NEW;
}
void initAvailOfDoubly(int n){
    if(n <= 0){
        printf("\n\t Please enter valid size \n");
    }else{
        for(int i=0; i<n; i++){
            Node* NEW = (Node *)malloc(sizeof(Node));
            if(NEW == NULL){
                printf("Memory Allocation Failed!!\n");
            }else{
                NEW->DATA = 0;
                addToAvailOfDoubly(NEW);
            }
        }
    }
}
Node* checkAvailOfDoubly(){
   if(AVAIL_DOUBLY == NULL){
    printf("~~ No space available for insertion ~~\n");
    return NULL;
   }
   Node* NEW = AVAIL_DOUBLY;
   AVAIL_DOUBLY = AVAIL_DOUBLY->FORWARD;
   NEW->FORWARD = NULL;
   NEW->BACKWARD = NULL;
   return NEW;
}
// doubly list insertion programs
void insertAtBeginInDoubly(int data){
    Node* NEW = checkAvailOfDoubly();
    if(NEW == NULL)
        printf("\t\t~~ Space not available ~~\n");
    else{
        if(START_DOUBLY == NULL && END_DOUBLY == NULL){
            NEW->FORWARD = NULL;
            NEW->BACKWARD = NULL;
            NEW->DATA = data;
            START_DOUBLY = NEW;
            END_DOUBLY = NEW;
            printf("\t\tNew node %d is inserted as first(also last) node\n",data);
        }else {
            NEW->DATA = data;
            NEW->FORWARD = START_DOUBLY;
            NEW->BACKWARD = NULL;
            START_DOUBLY->BACKWARD = NEW;
            START_DOUBLY = NEW;
            printf("\t\tNew node %d is inserted at the begin.\n",data);
        }
    }
}
void insertAtEndInDoubly(int data){
    Node* NEW = checkAvailOfDoubly();
    if(NEW == NULL)
        printf("\t\t~~~ Space not available ~~~\n");
    else{
        if(END_DOUBLY == NULL && START_DOUBLY == NULL){
            NEW->DATA = data;
            NEW->FORWARD = NULL;
            NEW->BACKWARD = NULL;
            END_DOUBLY = NEW;
            START_DOUBLY = NEW;
            printf("\t\tNew node %d is inserted as the last(also first) node\n",data);
        }else {
            NEW->DATA = data;
            NEW->FORWARD = NULL;
            NEW->BACKWARD = END_DOUBLY;
            END_DOUBLY->FORWARD = NEW;
            END_DOUBLY = NEW;
            printf("\t\tNew node %d is inserted at the end of list.\n",data);
        }
    }
}
void insertAfterSpecificInDoubly(int specific, int data){
    Node* PTR = START_DOUBLY;
    Node* LOC = NULL;
    while(PTR != NULL){
        if(PTR->DATA == specific && LOC == NULL)
            LOC = PTR;
        PTR = PTR->FORWARD;
    }
    if(LOC == NULL){
        printf("\t\tSpecific element you enter is not present, Sorry\n");
    }else {
        Node* NEW = checkAvailOfDoubly();
        if(NEW == NULL){
            printf("\t\tSpace is not available\n");
        }else{
            NEW->DATA = data;
            NEW->FORWARD = LOC->FORWARD;
            NEW->BACKWARD = LOC;
            LOC->FORWARD = NEW;
            if(NEW->FORWARD != NULL)
                NEW->FORWARD->BACKWARD = NEW;
            else
                END_DOUBLY = NEW;
        }
        printf("\t\t %d element is inserted after %d Successfully !!\n",data,specific);
    }
}
void insertBeforeSpecfic(int specific, int data){
    Node* PTR = END_DOUBLY;
    Node* LOC = NULL;
    while(PTR != NULL){
        if(PTR->DATA == specific && LOC == NULL) // for first occurence of that specific location
            LOC = PTR;
        PTR = PTR->BACKWARD;
    }
    if(LOC == NULL){
        printf("\t\tSpecific element you enter is not present, Sorry\n");
    }else {
        Node* NEW = checkAvailOfDoubly();
        if(NEW == NULL){
            printf("\t\tSpace is not available\n");
        }else{
            NEW->DATA = data;
            NEW->FORWARD = LOC;
            NEW->BACKWARD = LOC->BACKWARD;
            LOC->BACKWARD = NEW;
            if(NEW->BACKWARD != NULL)
                NEW->BACKWARD->FORWARD = NEW;
            else
                START_DOUBLY = NEW;
        }
        printf("\t\t %d element is inserted before %d Successfully!\n",data,specific);
    }
}
// Fucntions of deletion in doubly linked list..
void deleteFirstOfDoubly(){
    if(START_DOUBLY == NULL){
        printf("\t\t ~~ Unable to delete ~ UNDERFLOW ~~\n");
    } else if (START_DOUBLY->FORWARD == NULL){
        Node* NEW = START_DOUBLY;
        START_DOUBLY = NULL;
        END_DOUBLY = NULL;
        NEW->DATA = 0;
        addToAvailOfDoubly(NEW);
        printf("\t\tThe only element of list is deleted ~ List is Empty\n");
    } else {
        Node* NEW = START_DOUBLY;
        START_DOUBLY = START_DOUBLY->FORWARD;
        START_DOUBLY->BACKWARD = NULL;
        NEW->DATA = 0;
        addToAvailOfDoubly(NEW);
        printf("\t\t First element is deleted Successfully.\n");
    }
}
void deleteLastOfDoubly(){
    if(END_DOUBLY == NULL){
        printf("\t\t ~~ Unable to delete ~ UNDERFLOW ~~\n");
    } else if(END_DOUBLY->BACKWARD == NULL){
        Node* NEW = END_DOUBLY;
        END_DOUBLY = NULL;
        START_DOUBLY = NULL;
        NEW->DATA = 0;
        addToAvailOfDoubly(NEW);
        printf("\t\tThe only element of list is deleted ~ List is Empty\n");
    } else {
        Node* NEW = END_DOUBLY;
        END_DOUBLY = END_DOUBLY->BACKWARD;
        END_DOUBLY->FORWARD = NULL;
        NEW->DATA = 0;
        addToAvailOfDoubly(NEW);
        printf("\t\tLast element deleted Successfully.\n");
    }
}
void deleteSpecificOfDoubly(int deleteValue){
    if(START_DOUBLY == NULL){
        printf("\t\t ~~ Unable to delete ~ UNDERFLOW ~~\n");
    } else if(START_DOUBLY->DATA == deleteValue){
        Node* NEW = START_DOUBLY;
        START_DOUBLY = START_DOUBLY->FORWARD;
        START_DOUBLY->BACKWARD = NULL;
        NEW->DATA = 0;
        addToAvailOfDoubly(NEW);
        printf("\t\tElement %d is deleted from the beginning of the list\n",deleteValue);
    } else {
        Node* PTR = START_DOUBLY;
        Node* PREVIOUS = NULL;
        while(PTR != NULL && PTR->DATA != deleteValue){
            PREVIOUS = PTR;
            PTR = PTR->FORWARD;
        }
        if(PTR == NULL)
            printf("\t\tElement %d is not found in the list.\n",deleteValue);
        else{
            PREVIOUS->FORWARD = PTR->FORWARD;
            if(PTR->FORWARD != NULL)
                PTR->FORWARD->BACKWARD = PREVIOUS;
            else
                END_DOUBLY = PREVIOUS;
            addToAvailOfDoubly(PTR);
            printf("\t\tElement %d is deleted Successfully\n",deleteValue);
        }
    }
}
// seaching functions...
void searchFromStart(int search){
    int count = 0;
    int found = 0;
    if(START_DOUBLY == NULL){
        printf("\t\t~~ Unable to search ~~ List is EMPTY ~~\n");
    }else {
        Node* PTR = START_DOUBLY;
        while(PTR != NULL){
            count++;
            if(PTR->DATA == search && found == 0)
                found = count;
            PTR = PTR->FORWARD;
        }
        printf("\t\tTotal number of elements in the list are: %d",count);
        if(found == 0)
            printf("\t\tSorry, element not found.\n");
        else
            printf("\t\tThe element %d is found at position: %d\n",search,found);
    }
}
void searchFromEnd(int search){
    int count = 0;
    int found = 0;
    if(END_DOUBLY == NULL)
        printf("\t\t~~ Unable to search ~~ List is EMPTY ~~\n");
    else{
        Node* PTR = END_DOUBLY;
        while(PTR != NULL){
            count++;
            if(PTR->DATA == search && found == 0)
                found = count;
            PTR = PTR->BACKWARD;
        }
        printf("\t\tTotal number of elements in the list are: %d",count);
        if(found == 0)
            printf("\t\tSorry, element not found.\n");
        else
            printf("\t\tThe element %d is found at position: %d",search,found);
    }
}
// display function
void displayDoublyListWithStart(){
    Node* PTR = START_DOUBLY;
    printf("\t\t Doubly Linked List: START -> ");
    while(PTR != NULL){
        printf("\033[1;34m%d\033[0m -> ", PTR->DATA);
        PTR = PTR->FORWARD;
    }
    printf("NULL\n");
    PTR = NULL;
    PTR = AVAIL_DOUBLY;
    printf("\t\tAVAIL LIST: ");
    while(PTR != NULL){
        printf("\033[1;32m%p\033[0m -> ", (void*)PTR);
        PTR = PTR->FORWARD;
    }
    printf("NULL\n");
}
void displayDoublyListWithEnd(){
    Node* PTR = END_DOUBLY;
    printf(" \t\t Doubly Linked List: END -> ");
    while(PTR != NULL){
        printf("\033[1;34m%d\033[0m -> ", PTR->DATA);
        PTR = PTR->BACKWARD;
    }
    printf("NULL\n");
    PTR = NULL;
    PTR = AVAIL_DOUBLY;
    printf("\t\t AVAIL LIST: ");
    while(PTR != NULL){
        printf("\033[1;32m%p\033[0m -> ", (void*)PTR);
        PTR = PTR->FORWARD;
    }
    printf("NULL\n");
}
// free doubly list
void freeDoublyList(){
    Node* PTR;
    while(START_DOUBLY != NULL){
        PTR = START_DOUBLY;
        START_DOUBLY = START_DOUBLY->FORWARD;
        free(PTR);
    }
    while(END_DOUBLY != NULL){
        PTR = END_DOUBLY;
        END_DOUBLY = END_DOUBLY->BACKWARD;
        free(PTR);
    }
    while(AVAIL_DOUBLY != NULL){
        PTR = AVAIL_DOUBLY;
        AVAIL_DOUBLY = AVAIL_DOUBLY->FORWARD;
        free(PTR);
    }
    START_DOUBLY = END_DOUBLY = AVAIL_DOUBLY = NULL;
}




// Header Linked List Functions...
void initHeader(){
    Node* NEW = (Node *)malloc(sizeof(Node));
    if(NEW == NULL){
        printf("\t\tUnable to initalizate Header .\n");
    }else{
        NEW->INFO = 0;
        NEW->LINK = NULL;
        HEAD = NEW;
    }
}
void updateHeader(char x[]){
    if(HEAD == NULL){
        printf("\t\t Unable to update the Header.\n");
        return;
    }
    if (strcmp(x, "increment") == 0 || strcmp(x, "Increment") == 0) {
        HEAD->INFO++;
    } else if (strcmp(x, "decrement") == 0 || strcmp(x, "Decrement") == 0) {
        HEAD->INFO--;
    } else {
        printf("\t\t Invalid operation. Use 'increment' or 'decrement'.\n");
    }
}
void addToAvailOfHeader(Node* NEW){
    NEW->LINK = AVAIL_HEADER;
    AVAIL_HEADER = NEW;
}
void initAvailOfHeader(int n){
    for(int i=0; i<n; i++){
        Node* NEW = (Node *)malloc(sizeof(Node));
        if(NEW == NULL){
            printf("\t\tMemory Allocation Failed!!\n");
        }else{
            NEW->INFO = 0;
            addToAvailOfHeader(NEW);
        }
    }
}
Node* checkAvailOfHeader(){
    if(AVAIL_HEADER == NULL){
        printf("\t\tNo space available for Insertion!\n");
        return NULL;
    }
    Node* NEW = AVAIL_HEADER;
    AVAIL_HEADER = AVAIL_HEADER->LINK;
    NEW->LINK = NULL;
    return NEW;
}
// Insertion in Header List
void insertAtBeginInHeader(int data){
    if(HEAD == NULL){
        printf("\t\t Initialize Header node first. \n");
    } else{
        Node* NEW = checkAvailOfHeader();
        if(NEW == NULL){
            printf("\t\tSpace not available!\n");
        }else{
            NEW->INFO = data;
            NEW->LINK = HEAD->LINK;
            HEAD->LINK = NEW;
            printf("\t\tNew node %d is inserted at the beginning of the list.\n",data);
            updateHeader("increment");
        }
    }
}
void insertAtEndInHeader(int data){
    if(HEAD == NULL){
        printf("\t\t Initialize header node first.\n");
    }else{
        Node* NEW = checkAvailOfHeader();
        if(NEW == NULL){
            printf("\t\tSpace not available!\n");
        }
        else{
            NEW->INFO = data;
            NEW->LINK = NULL;
            if(HEAD->LINK == NULL){
                HEAD->LINK = NEW;
                printf("\t\tNew node %d is inserted at end as first node.\n",data);
            } else{
                Node* PTR = HEAD->LINK;
                while(PTR->LINK != NULL)
                    PTR = PTR->LINK;
                PTR->LINK = NEW;
                printf("\t\tNew node %d is inserted at the End of the list.\n",data);
            }
            updateHeader("Increment");
        }
    }
}
void insertAfterSpecificInHeader(int specific, int data){
    if(HEAD == NULL){
        printf("\t\t Initilaize Header Node First.\n");
    } else{
        Node* PTR = HEAD->LINK;
        Node* LOC = NULL;
        while(PTR != NULL){
            if(PTR->INFO == specific && LOC == NULL)
                LOC = PTR;
            PTR = PTR->LINK;
        }
        if(LOC == NULL){
            printf("\t\tSpecific element(node) is not found in the list!.\n");
        } else{
            Node* NEW = checkAvailOfHeader();
            if(NEW == NULL){
                printf("\t\tSpace is not available!\n");
            }else{
                NEW->INFO = data;
                NEW->LINK = LOC->LINK;
                LOC->LINK = NEW;
                printf("\t\tNew node %d is inserted after %d Successfully.\n",data,specific);
                updateHeader("Increment");
            }
        }
    }
}
// deletion in header list..
void deleteFirstOfHeader(){
    if(HEAD == NULL){
        printf("\t\t Initialize Header Node First\n");
    }else if(HEAD->LINK == NULL){
        printf("\t\t ~~~~~ Unable to Delete ~~~ List is EMPTY! ~~~~~\n");
    }else{
        Node* NEW = HEAD->LINK;
        HEAD->LINK = HEAD->LINK->LINK;
        NEW->INFO = 0;
        addToAvailOfHeader(NEW);
        updateHeader("decrement");
        if(HEAD->LINK == NULL)
            printf("\t\t The only element is deleted from the List ~~~ List is EMPTY Now\n");
        else
            printf("\t\t First element is deleted. SUCCESSFULLY!\n");
    }
}
void deleteLastOfHeader(){
    if(HEAD == NULL){
        printf("\t\tInitialize Header Node First\n");
    }else{
        if(HEAD->LINK == NULL){
            printf("\t\t ~~~~~ Unable to Delete ~~~ List is Empty ~~~~~\n");
        }else if (HEAD->LINK->LINK == NULL){
            Node* NEW = HEAD->LINK;
            HEAD->LINK = NULL;
            NEW->INFO = 0;
            addToAvailOfHeader(NEW);
            updateHeader("decrement");
            printf("\t\tThe only element is deleted.List is now EMPTY!\n");
        } else {
            Node* PTR = HEAD->LINK;
            Node* PREVIOUS = NULL;
            while(PTR->LINK != NULL){
                PREVIOUS = PTR;
                PTR = PTR->LINK;
            }
            PREVIOUS->LINK = NULL;
            addToAvailOfHeader(PTR);
            updateHeader("decrement");
            printf("\t\t Last element deleted SUCCESSFULLY !!\n");
        }
    }
}
void deleteSpecificOfHeader(int deleteValue){
    if(HEAD == NULL){
        printf("\t\tInitialize Header Node First!\n\n");
    }else{
        if(HEAD->LINK == NULL){
            printf("\t\t ~~~ Unable to Delete ~~~ List is Empty ~~~\n");
        }else if(HEAD->LINK->INFO == deleteValue){
            Node* NEW = HEAD->LINK;
            HEAD->LINK = HEAD->LINK->LINK;
            NEW->INFO = 0;
            addToAvailOfHeader(NEW);
            updateHeader("Decrement");
            printf("\t\t Element %d is deleted Successfully.\n",deleteValue);
        }else {
            Node* PTR = HEAD->LINK;
            Node* PREVIOUS = NULL;
            while(PTR != NULL && PTR->INFO != deleteValue){
                PREVIOUS = PTR;
                PTR = PTR->LINK;
            }
            if(PTR == NULL) {
                printf("\t\t Element %d not found in the list.\n",deleteValue);
            } else{
                PREVIOUS->LINK = PTR->LINK;
                PTR->INFO = 0;
                addToAvailOfHeader(PTR);
                updateHeader("Decrement");
                printf("\t\t Element %d is deleted from the list\n",deleteValue);
            }
        }
    }
}
// searching in header list..
void searchInHeader(int search){
    if(HEAD == NULL){
        printf("\t\tInitialize Header Node First\n");
    }else{
        int count = 0;
        int found = 0;
        if(HEAD->LINK == NULL) {
            printf("\t\t ~~~ Unable to search ~ List is EMPTY ~~~ \n");
        } else {
            Node* PTR = HEAD->LINK;
            while(PTR != NULL){
                count++;
                if(PTR->INFO == search && found == 0)
                    found = count;
                PTR = PTR->LINK;
            }
            printf("\t\t Total number of elements in Header List are: %d\n",count);
            if(found == 0)
                printf("\t\t Sorry, element not found\n");
            else
                printf("\t\t The element %d is found at position: %d\n",search, found);
        }
    }
}
void displayHeaderList(){
    if(HEAD == NULL){
        printf("\t\tInitialize Header Node First\n");
    }else{
        printf("\n\t\tHeader Linked List: START -> \033[1;34mHEAD[Total: %d]\033[0m -> ",HEAD->INFO);
        Node* PTR = HEAD->LINK;
        while(PTR != NULL){
            printf("\033[1;34m%d\033[0m -> ", PTR->INFO);
            PTR = PTR->LINK;
        }
        printf("NULL\n");
        PTR = NULL;

        Node* PTR2 = AVAIL_HEADER;
        printf("\t\t Header Avail List: ");
        while(PTR2 != NULL){
            printf("\033[1;32m%p\033[0m -> ", (void*)PTR2);
            PTR2 = PTR2->LINK;
        }
        printf("NULL\n\n");
    }
}
void freeHeaderList(){
    Node* PTR;
    while(HEAD != NULL){
        PTR = HEAD;
        HEAD = HEAD->LINK;
        free(PTR);
    }
    while(AVAIL_HEADER != NULL){
        PTR = AVAIL_HEADER;
        AVAIL_HEADER = AVAIL_HEADER->LINK;
        free(PTR);
    }
    HEAD = AVAIL_HEADER = NULL;
}




// Circular Linked list Functions..
void addToAvailOfCircular(Node* NEW){   
    NEW->LINK = AVAIL_CIRCULAR;
    AVAIL_CIRCULAR = NEW;
}
void initAvailOfCircular(int n){
    for(int i=0; i<n; i++){
        Node* NEW = (Node *)malloc(sizeof(Node));
        if(NEW == NULL){
            printf("\t\t Memory Allocation Failed!!\n");
        }else{
            NEW->INFO = 0;
            addToAvailOfCircular(NEW);
        }
    }
}
Node* checkAvailOfCircular(){
    if(AVAIL_CIRCULAR == NULL){
        printf("\t\tNo space available for INSERTION!!\n");
        return NULL;
    }
    Node* NEW = AVAIL_CIRCULAR;
    AVAIL_CIRCULAR = AVAIL_CIRCULAR->LINK;
    NEW->LINK = NULL;
    return NEW;
}
// Insertion functions of Circular Lists..
void insertAtBeginInCircular(int data){
    Node* NEW = checkAvailOfCircular();
    if(NEW == NULL){
        printf("\t\t Space is not available!\n");
    }else{
        if(START_CIRCULAR == NULL){
            NEW->INFO = data;
            NEW->LINK = NEW;
            START_CIRCULAR = NEW;
            printf("\t\t%d is inserted as first(also last) node Successfully!!\n",data);
        } else {
            NEW->INFO = data;
            NEW->LINK = START_CIRCULAR;
            Node* PTR = START_CIRCULAR;
            while(PTR->LINK != START_CIRCULAR){
                PTR = PTR->LINK;
            }
            PTR->LINK = NEW;
            START_CIRCULAR = NEW;
            printf("\t\t%d is inserted at the beginning\n",data);
        }
    }
}
void insertAtEndInCircluar(int data){
    Node* NEW = checkAvailOfCircular();
    if(NEW == NULL){
        printf("\t\tSpace is not available!\n");
    } else{
        if(START_CIRCULAR == NULL){
            NEW->INFO = data;
            NEW->LINK = NEW;
            START_CIRCULAR = NEW;
            printf("\t\t%d is inserted as first(also last) node in the list.\n",data);
        } else {
            NEW->INFO = data;
            Node* PTR = START_CIRCULAR;
            while(PTR->LINK != START_CIRCULAR)
                PTR = PTR->LINK;
            PTR->LINK = NEW;
            NEW->LINK = START_CIRCULAR;
            printf("\t\t%d is inserted at the last of the list.\n",data);
        }
    }
}
void insertAfterSpecificInCirclar(int specific, int data){
    Node* PTR = START_CIRCULAR;
    Node* LOC = NULL;
    while(PTR->LINK != START_CIRCULAR){
        if(PTR->INFO == specific && LOC == NULL){
            LOC = PTR;
            break;
        }
        PTR = PTR->LINK;
    }
    if(LOC == NULL){
        printf("\t\t %d node is not present in the list.\n",specific);
    } else {
        Node* NEW = checkAvailOfCircular();
        if(NEW == NULL){
            printf("\t\t Space is not available.\n");
        }else{
            NEW->INFO = data;
            NEW->LINK = LOC->LINK;
            LOC->LINK = NEW;
            printf("\t\t %d is inserted after %d Successfully/\n",data,specific);
        }
    }
}
// Deletion functions of Circular List..
void deleteFirstOfCircular(){
    if(START_CIRCULAR == NULL){
        printf("\t\t ~~ Unable to delete ~~ UNDERFLOW ~~\n");
    } else if(START_CIRCULAR->LINK == START_CIRCULAR){
        Node* NEW = START_CIRCULAR;
        START_CIRCULAR = NULL;
        addToAvailOfCircular(NEW);
        printf("\t\t Now the list is EMPTY.\n");
    } else {
        Node* NEW = START_CIRCULAR;
        Node* PTR = START_CIRCULAR;
        while(PTR->LINK != START_CIRCULAR)
            PTR = PTR->LINK;
        PTR->LINK = START_CIRCULAR->LINK;
        START_CIRCULAR = START_CIRCULAR->LINK;
        addToAvailOfCircular(NEW);
        printf("\t\t First element deleted SUCCESSFULLTY.\n");
    }
}
void deleteLastOfCircular(){
    if(START_CIRCULAR == NULL){
        printf("\t\t ~~ Unable to delete ~~ UNDERFLOW ~~\n");
    } else if(START_CIRCULAR->LINK == START_CIRCULAR){
        Node* NEW = START_CIRCULAR;
        START_CIRCULAR = NULL;
        addToAvailOfCircular(NEW);
        printf("\t\t Now the list is EMPTY.\n");
    } else {
        Node* PTR = START_CIRCULAR;
        Node* PREVIOUS = NULL;
        while(PTR->LINK != START_CIRCULAR){
            PREVIOUS = PTR;
            PTR = PTR->LINK;
        }
        PREVIOUS->LINK = START_CIRCULAR;
        addToAvailOfCircular(PTR);
        printf("\t\t ~~ Last element deleted SUCCESSFULLY ~~\n");
    }
}
void deleteSpecificInCircular(int deleteValue){
    if(START_CIRCULAR == NULL){
        printf("\t\t ~~ Unable to delete ~~ UNDERFLOW ~~\n");
    } else if (START_CIRCULAR->INFO == deleteValue){
        Node* NEW = START_CIRCULAR;
        if(START_CIRCULAR->LINK == START_CIRCULAR){ // matlab sirf ek node..
            START_CIRCULAR = NULL;
            printf("\t\t Now list is EMPTY\n");
        }else{                                    // matlab ek se jyada node..
            Node* PTR = START_CIRCULAR;
            while(PTR->LINK != START_CIRCULAR)
                PTR = PTR->LINK;
            PTR->LINK = START_CIRCULAR->LINK;
            START_CIRCULAR = START_CIRCULAR->LINK;
        }
        addToAvailOfCircular(NEW);
        printf("\t\t Element %d is deleted SUCCESSFULLY.\n",deleteValue);
    } else {
        Node* PTR = START_CIRCULAR->LINK;       // pehli se agli node ko point kr rha h
        Node* PREVIOUS = START_CIRCULAR;        //pehli node ko point kr rha h..
        while(PTR != START_CIRCULAR && PTR->INFO != deleteValue){
            PREVIOUS = PTR;
            PTR = PTR->LINK;
        }
        if(PTR == START_CIRCULAR)       // element not found
            printf("Element %d is not found in the list.\n",deleteValue);
        else{
            PREVIOUS->LINK = PTR->LINK;
            addToAvailOfCircular(PTR);
            printf("Element %d is deleted from the list.\n",deleteValue);
        }
    }
}
// search function of Circular List
void searchCircularList(int search){
    int count = 0;
    int found = 0;
    if(START_CIRCULAR == NULL){
        printf("\t\t ~~ Unable to search ~~ List is EMPTY ~~.\n");
    } else {
        Node* PTR = START_CIRCULAR;
        do{
            count++;
            if(PTR->INFO == search){
                found = count;
                break;
            }
            PTR = PTR->LINK;
        }while(PTR != START_CIRCULAR);
        printf("\t\t Total number of elements in the list are: %d\n",count);
        if(found == 0)
            printf("\t\t SORRY, element not found.\n");
        else
            printf("\t\t The element %d is found at position: %d\n",search,found);
    }
}
void displayCircularList(){
    if(START_CIRCULAR == NULL){
        printf("\t\t CIRCULAR LINKED LIST: NULL\n");
    }else{
        Node* PTR = START_CIRCULAR;
        printf("\t\tCIRCULAR LINKED LIST: ");
        do {
            printf("\033[1;34m%d\033[0m -> ", PTR->INFO);
            PTR = PTR->LINK;
            //special case
            if(PTR == NULL){
                printf("\n\t\t ERROR: Circular Link Broken (NULL Encountered).\n");
                return;
            }
        } while (PTR != START_CIRCULAR); // Loop back to START to complete the circle
        printf("\033[1;34m[Circular Link Back to %d]\033[0m\n", START_CIRCULAR->INFO); // Indicate circular nature of the list
    }

    if(AVAIL_CIRCULAR == NULL){
        printf("\t\t AVAIL LIST: NULL");
    }else{
        Node* PTR = AVAIL_CIRCULAR;
        printf("\t\t AVAIL LIST: ");
        while(PTR != NULL){
            printf("\033[1;32m%p\033[0m -> ", (void*)PTR);
            PTR = PTR->LINK;
        }
        printf("NULL\n");
    }
}
void freeCircularList(){
    if(START_CIRCULAR != NULL){
        Node* PTR = START_CIRCULAR;
        Node* TEMP;
        do{
            TEMP = PTR;
            PTR = PTR->LINK;
            free(TEMP);
        }while(PTR != START_CIRCULAR);
        START_CIRCULAR = NULL;
        printf("Circular linked list memory freed.\n");
    }

    while (AVAIL_CIRCULAR != NULL){
        Node* TEMP = AVAIL_CIRCULAR;
        AVAIL_CIRCULAR = AVAIL_CIRCULAR->LINK;
        free(TEMP);
    }
    AVAIL_CIRCULAR = NULL;
    printf("Avail list memory freed.\n");
}




// MAIN FUNCTION...
int main(){
    int choice,space,data,specific,searchElement;

    while(1){
        Main_Menu:printf("\n<--- Choose a list from following --->\n");
        printf(" 1: For Simple Linked List\n");
        printf(" 2: For Doubly Linked List\n");
        printf(" 3: For Header Linked List\n");
        printf(" 4: For Circular Linked List\n");
        printf(" 5: To EXIT \n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:

                Simple:printf("\n\t<--- SIMPLE LINKED LIST --->\n\n");
                printf("\t0: For Initiate/Assign some space\n");
                printf("\t1: For Insertion\n");
                printf("\t2: For Deletion\n");
                printf("\t3: For Searching\n");
                printf("\t4: To Display Lists\n");
                printf("\t5: RETURN TO MAIN-MENU\n");
                printf("\t6: EXITING THE PROGRAM\n");
                printf("\tEnter Choice: ");
                scanf("%d",&choice);
 
                switch(choice){
                    case 0:
                        printf("\tEnter the space you want to initiate: ");
                        scanf("%d",&space);
                        initSimpleAvail(space);
                        printf("\t\033[1;32m~~~ Space Initalized Successfully ~~~\033[0m -> ");
                        break;

                    case 1:
                        Insert_Operation_In_Simple:printf("\t\t*** Where do you want to insert ? ***\n");
                        printf("\t\t 1: Insert at Beginning.\n");
                        printf("\t\t 2: Insert after a specific node.\n");
                        printf("\t\t 3: Insert at End.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of insertion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1:
                                printf("\n\t\t Enter the element you want to insert(at begin): ");
                                scanf("%d",&data);
                                insertAtBeginInSimple(data);
                                break;

                            case 2:
                                printf("\n\t\t Enter the specific node after which you want to insert: ");
                                scanf("%d",&specific);
                                printf("\t\t Enter the element you want to insert(after %d): ",specific);
                                scanf("%d", &data);
                                insertAfterSpecificInSimple(specific, data);
                                break;

                            case 3:
                                printf("\n\t\t Enter the element you want to insert(at end): ");
                                scanf("%d",&data);
                                insertAtEndOfSimple(data);
                                break;

                            case 4:
                                goto Simple;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n\n");
                                goto Insert_Operation_In_Simple;
                                break;
                        }
                        break;

                    case 2:
                        Delete_Operation_In_Simple:printf("\t\t*** Which one you want to delete ? ***\n");
                        printf("\t\t 1: Delete first element.\n");
                        printf("\t\t 2: Delete a specific node.\n");
                        printf("\t\t 3: Delete last element.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of deletion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1: 
                                deleteFirstOfSimple();
                                break;

                            case 2:
                                printf("\n\t\t Enter the value of that specific node: ");
                                scanf("%d",&data);
                                deleteSpecificOfSimple(data);
                                break;

                            case 3:
                                deleteLastOfSimple();
                                break;

                            case 4:
                                goto Simple;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n\n");
                                goto Delete_Operation_In_Simple;
                                break;
                        }
                        break;

                    case 3:
                        printf("\t\tEnter the elemnet you want to search: ");
                        scanf("%d",&searchElement);
                        searchSimpleList(searchElement);
                        break;

                    case 4:
                        displaySimpleList();
                        break;

                    case 5:
                        goto Main_Menu;
                        break;

                    case 6:
                        freeSimpleList();
                        return 1;
                        break;

                    default:
                        printf("\n\t\t~~~ Invalid Entry ~~~\n");
                        goto Simple;
                        break;                    
                }
                goto Simple;
                break;

            case 2:
                Doubly:printf("\n\t<--- DOUBLY LINKED LIST --->\n");
                printf("\t 0: For Initiate/Assign some space\n");
                printf("\t 1: For Insertion\n");
                printf("\t 2: For Deletion\n");
                printf("\t 3: For Searching\n");
                printf("\t 4: To Display Lists\n");
                printf("\t 5: RETURN TO MAIN-MENU\n");
                printf("\t 6: EXITING THE PROGRAM\n");
                printf("\t Enter Choice: ");
                scanf("%d",&choice);

                switch(choice){
                    case 0:
                        printf("\tEnter the space you want to initiate: ");
                        scanf("%d",&space);
                        initAvailOfDoubly(space);
                        printf("\t\033[1;32m~~~ Space Initalized Successfully ~~~\033[0m -> ");
                        break;

                    case 1:
                        Insert_Operation_In_Doubly:printf("\t\t*** Where do you want to insert ? ***\n");
                        printf("\t\t 1: Insert at Beginning.\n");
                        printf("\t\t 2: Insert after a specific node.\n");
                        printf("\t\t 3: Insert at End.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of insertion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1:
                                printf("\n\t\t Enter the element you want to insert(at begin): ");
                                scanf("%d",&data);
                                insertAtBeginInDoubly(data);
                                break;

                            case 2:
                                printf("\n\t\t Enter the specific node after which you want to insert: ");
                                scanf("%d",&specific);
                                printf("\t\t Enter the element you want to insert(after %d): ",specific);
                                scanf("%d", &data);
                                insertAfterSpecificInDoubly(specific, data);
                                break;

                            case 3:
                                printf("\n\t\t Enter the element you want to insert(at end): ");
                                scanf("%d",&data);
                                insertAtEndInDoubly(data);
                                break;

                            case 4:
                                goto Doubly;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n\n");
                                goto Insert_Operation_In_Doubly;
                                break;
                        }
                        break;

                    case 2:
                        Delete_Operation_In_Doubly:printf("\t\t*** Which one you want to delete ? ***\n");
                        printf("\t\t 1: Delete first element.\n");
                        printf("\t\t 2: Delete a specific node.\n");
                        printf("\t\t 3: Delete last element.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of deletion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1: 
                                deleteFirstOfDoubly();
                                break;

                            case 2:
                                printf("\n\t\t Enter the value of that specific node: ");
                                scanf("%d",&data);
                                deleteSpecificOfDoubly(data);
                                break;

                            case 3:
                                deleteLastOfDoubly();
                                break;

                            case 4:
                                goto Doubly;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n\n");
                                goto Delete_Operation_In_Doubly;
                                break;
                        }
                        break;

                    case 3:
                        Searching_Operation_In_Doubly:printf("\t\t*** From where you want to search? ***\n");
                        printf("\t\t 1: From START.\n");
                        printf("\t\t 2: From END.\n");
                        printf("\t\t 3: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice for searching: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1:
                                printf("\t\t Enter the number you want to search from START: ");
                                scanf("%d",&searchElement);
                                searchFromStart(searchElement);
                                break;

                            case 2:
                                printf("\t\t Enter the number you want to search from END: ");
                                scanf("%d",&searchElement);
                                searchFromEnd(searchElement);
                                break;

                            case 3:
                                goto Doubly;
                                break;

                            default:
                                printf("\t\t ~~ INVALID ENTRY ~~\n");
                                goto Searching_Operation_In_Doubly;
                                break;
                        }
                        break;

                    case 4:
                        Display_Doubly_List:printf("\t\t 1: To display list from START.\n");
                        printf("\t\t 2: To display list from END.\n");
                        printf("\t\t 3: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice: ");
                        scanf("%d",&choice);
                        switch (choice)
                        {
                        case 1:
                            displayDoublyListWithStart();
                            break;

                        default:
                            displayDoublyListWithEnd();
                            break;
                        }
                        break;

                    case 5:
                        goto Main_Menu;
                        break;

                    case 6:
                        freeDoublyList();
                        return 1;
                        break;

                    default:
                        printf("\n\t\t~~~ Invalid Entry ~~~\n");
                        goto Doubly;
                        break; 
                }
                goto Doubly;
                break;

            case 3:
                
                Header:printf("\n\t<--- HEADER LINKED LIST --->\n");
                printf("\t -1: ~~~ TO INITIATE HEAD NODE ~~~ \n");
                printf("\t 0: For Initiate/Assign some space\n");
                printf("\t 1: For Insertion\n");
                printf("\t 2: For Deletion\n");
                printf("\t 3: For Searching\n");
                printf("\t 4: To Display Lists\n");
                printf("\t 5: RETURN TO MAIN-MENU\n");
                printf("\t 6: EXITING THE PROGRAM\n");
                printf("\t Enter Choice: ");
                scanf("%d",&choice);
                // initializing header
                switch(choice){
                    case -1:
                        initHeader();
                        printf("\t\033[1;32m~~~ HEAD NODE INITIALIZED ~~~\033[0m");
                        break;

                    case 0:
                        printf("\tEnter the space you want to initiate: ");
                        scanf("%d",&space);
                        initAvailOfHeader(space);
                        printf("\t\033[1;32m~~~ Space Initalized Successfully ~~~\033[0m ");
                        break;

                    case 1:
                        Insert_Operation_In_Header:printf("\t\t*** Where do you want to insert ? ***\n");
                        printf("\t\t 1: Insert at Beginning.\n");
                        printf("\t\t 2: Insert after a specific node.\n");
                        printf("\t\t 3: Insert at End.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of insertion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1:
                                printf("\n\t\t Enter the element you want to insert(at begin): ");
                                scanf("%d",&data);
                                insertAtBeginInHeader(data);
                                break;

                            case 2:
                                printf("\n\t\t Enter the specific node after which you want to insert: ");
                                scanf("%d",&specific);
                                printf("\t\t Enter the element you want to insert(after %d): ",specific);
                                scanf("%d", &data);
                                insertAfterSpecificInHeader(specific, data);
                                break;

                            case 3:
                                printf("\n\t\t Enter the element you want to insert(at end): ");
                                scanf("%d",&data);
                                insertAtEndInHeader(data);
                                break;

                            case 4:
                                goto Header;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n\n");
                                goto Insert_Operation_In_Header;
                                break;
                        }
                        break;

                    case 2:
                        Delete_Operation_In_Header:printf("\t\t*** Which one you want to delete ? ***\n");
                        printf("\t\t 1: Delete first element.\n");
                        printf("\t\t 2: Delete a specific node.\n");
                        printf("\t\t 3: Delete last element.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of deletion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1: 
                                deleteFirstOfHeader();
                                break;

                            case 2:
                                printf("\n\t\t Enter the value of that specific node: ");
                                scanf("%d",&data);
                                deleteSpecificOfHeader(data);
                                break;

                            case 3:
                                deleteLastOfHeader();
                                break;

                            case 4:
                                goto Header;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n\n");
                                goto Delete_Operation_In_Header;
                                break;
                        }
                        break;

                    case 3:
                        printf("\t\tEnter the elemnet you want to search: ");
                        scanf("%d",&searchElement);
                        searchInHeader(searchElement);
                        break;

                    case 4:
                        displayHeaderList();
                        break;

                    case 5:
                        goto Main_Menu;
                        break;

                    case 6:
                        freeHeaderList();
                        return 1;
                        break;

                    default:
                        printf("\n\t\t~~~ Invalid Entry ~~~\n");
                        goto Header;
                        break;                    
                }
                goto Header;
                break;

            case 4:
                Circular:printf("\n\t<--- CIRCULAR LINKED LIST --->\n");
                printf("\t 0: For Initiate/Assign some space\n");
                printf("\t 1: For Insertion\n");
                printf("\t 2: For Deletion\n");
                printf("\t 3: For Searching\n");
                printf("\t 4: To Display Lists\n");
                printf("\t 5: RETURN TO MAIN-MENU\n");
                printf("\t 6: EXITING THE PROGRAM\n");
                printf("\t Enter Choice: ");
                scanf("%d",&choice);

                switch(choice){
                    case 0:
                        printf("\tEnter the space you want to initiate: ");
                        scanf("%d",&space);
                        initAvailOfCircular(space);
                        printf("\t\033[1;32m~~~ Space Initalized Successfully ~~~\033[0m -> ");
                        break;

                    case 1:
                        Insert_Operation_In_Circular:printf("\t\t*** Where do you want to insert ? ***\n");
                        printf("\t\t 1: Insert at Beginning.\n");
                        printf("\t\t 2: Insert after a specific node.\n");
                        printf("\t\t 3: Insert at End.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of insertion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1:
                                printf("\n\t\t Enter the element you want to insert(at begin): ");
                                scanf("%d",&data);
                                insertAtBeginInCircular(data);
                                break;

                            case 2:
                                printf("\n\t\t Enter the specific node after which you want to insert: ");
                                scanf("%d",&specific);
                                printf("\t\t Enter the element you want to insert(after %d): ",specific);
                                scanf("%d", &data);
                                insertAfterSpecificInCirclar(specific, data);
                                break;

                            case 3:
                                printf("\n\t\t Enter the element you want to insert(at end): ");
                                scanf("%d",&data);
                                insertAtEndInCircluar(data);
                                break;

                            case 4:
                                goto Circular;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n\n");
                                goto Insert_Operation_In_Circular;
                                break;
                        }
                        break;

                    case 2:
                        Delete_Operation_In_Circular:printf("\t\t*** Which one you want to delete ? ***\n");
                        printf("\t\t 1: Delete first element.\n");
                        printf("\t\t 2: Delete a specific node.\n");
                        printf("\t\t 3: Delete last element.\n");
                        printf("\t\t 4: Return to SUB-MENU.\n");
                        printf("\t\t Enter choice of deletion: ");
                        scanf("%d",&choice);

                        switch(choice){
                            case 1: 
                                deleteFirstOfCircular();
                                break;

                            case 2:
                                printf("\n\t\t Enter the value of that specific node: ");
                                scanf("%d",&data);
                                deleteSpecificInCircular(data);
                                break;

                            case 3:
                                deleteLastOfCircular();
                                break;

                            case 4:
                                goto Circular;
                                break;

                            default:
                                printf("\n\t\t INVALID ENTRY ~ Please re-enter\n");
                                goto Delete_Operation_In_Circular;
                                break;
                        }
                        break;

                    case 3:
                        printf("\t\tEnter the elemnet you want to search: ");
                        scanf("%d",&searchElement);
                        searchCircularList(searchElement);
                        break;

                    case 4:
                        displayCircularList();
                        break;

                    case 5:
                        goto Main_Menu;
                        break;

                    case 6:
                        freeCircularList();
                        return 1;
                        break;

                    default:
                        printf("\n\t\t~~~ Invalid Entry ~~~\n");
                        goto Circular;
                        break;                    
                }
                goto Circular;
                break;

            case 5:
                printf("\t<--- EXITING THE PROGRAM --->\n");
                return 1;
                break;

            default:
                printf("\t<--- Invalid Entry | Please re-enter --->\n\n");
                goto Main_Menu;
                break;
        }
    }
    return 0;
}