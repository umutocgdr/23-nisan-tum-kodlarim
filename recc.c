
#include <stdio.h>
#include "stdlib.h"
struct n{
    int data;
    struct n * next;
};

typedef struct n node;
node * root=NULL;
node * temp=NULL;
node * nr =NULL;
void nodeolusvesonaekle(node * root,int deger){
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->next=NULL;
        root->data=deger;
        temp=root;
    }
    else if(deger<root->data){
        nr=(node*)malloc(sizeof(node));
        nr->next=root;
        nr->data=deger;
        root=nr;
    }
    else if(deger>root->data){
        
    }
}

void kacelemanvar(){
int sayac=0;
    while(temp->next != NULL){
        sayac++;
        temp=temp->next ;
   }
    printf("%d",sayac);
}
void listele(){
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    
    }
    
}
void istenencikar(){
    int a ;
      scanf("%d",&a);
    
    
}
int main(){
nodeolusvesonaekle(root,3);
    nodeolusvesonaekle(root,5);
     nodeolusvesonaekle(root,4);
    nodeolusvesonaekle(root,8);
    listele();
//listele();
//    kacelemanvar();
    return 0;
}
