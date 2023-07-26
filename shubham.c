#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100
struct Node {
  char data[MAX_LENGTH];
  struct Node* next;
};
void addLine(struct Node** head,const char* line){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if(newNode == NULL){
    fprintf(stderr," Memory allocation error \n");
    exit(EXIT_FAILURE);
  }
  strcpy(newNode->data,line);
  newNode->next=NULL;
  if(*head == NULL){
    *head=newNode;
  }else{
    struct Node* temp= *head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newNode;
  }
}
void removeLine(struct Node** head){
  if(*head == NULL){
    return;
  }
  struct Node* temp = *head;
  *head=(*head)->next;
  free(temp);
}
void printLastLine(struct Node* head,int n){
  struct Node* current=head;
  int linecount=0;
  while(current !=NULL){
    linecount++;
    current=current->next;
  }
  int startLine =(linecount -n)>0?(linecount - n):0;
  current =head;
  for(int i=0;i<startLine;i++){
    current=current->next;
  }
  while(current!=NULL){
    printf("%s",current->data);
    current=current->next;
  }
}
void freeList(struct Node** head){
  while(*head !=NULL){
    struct Node* temp= *head;
    *head = (*head)->next;
    free(temp);
  }
}
int main(int argc,char* argv[]){
  if(argc !=2){
    fprintf(stderr,"Usage: %s <nuber_of_line>\n",argv[0]);
    return EXIT_FAILURE;
  }
  int n = atoi(argv[1]);
  if(n<=0){
    fprintf(stderr,"Invalid value for number of lines.\n");
    return EXIT_FAILURE;
  }
  struct Node* head=NULL;
  char buffer[MAX_LENGTH];
  while(fgets(buffer,MAX_LENGTH,stdin) !=NULL){
    addLine(&head,buffer);
    if(n > 0) {
      n--;
    }else{
      removeLine(&head);
    }
  }
  printLastLine(head,atoi(argv[1]));
  freeList(&head);
  return EXIT_SUCCESS;
}