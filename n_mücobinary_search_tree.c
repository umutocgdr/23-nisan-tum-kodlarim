#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

struct node{
  int key;
  struct node *left;
  struct node *right;
};

struct node *dugumOlustur(int key){
  struct node *yeni = (struct node*)malloc(sizeof(node));
  yeni -> key = key;
  yeni -> left = yeni -> right =  NULL;
  return yeni;
}

void inorder(struct node *root){
  if(root != NULL){
    inorder(root->left);
    printf(" %d ",root->key);
  //  printf("a");
    inorder(root->right);
  }
}

struct node *ekle(struct node *root,int key){
  if(root == NULL) return dugumOlustur(key);
  if(key < root -> key){
    root -> left = ekle(root->left,key);
  }else if (key > root -> key){
    root -> right = ekle(root -> right,key);
  }
  return root;
}

int minimum(struct node *root){
  if(root == NULL){
    return 0;
  }while(root -> left != NULL){
    root = root -> left;
  }
  return root -> key;
}

int yukseklik(struct node *root){
  if(root == NULL) return -1;
  else{
    int sol,sag;
    sol = yukseklik(root->left);
    sag = yukseklik(root->right);

    if(sag > sol){
      return sag+1;
    }else{
      return sol+1;
    }
  }
}

int size(struct node *root){
  if(root == NULL) return 0;
  else{
    int a = size(root->left) + 1 + size(root->right);
    return a;
  }
}

struct node *bul(struct node *root,int key){
  if(root == NULL || root -> key == key){
    return root;
  }
  if(root->key < key){
    return bul(root->right,key);
  }else{
    return bul(root->left,key);
  }
}

int total(struct node *root){
  int toplam = 0;
  if(root == NULL){
    return toplam;
  }
  else{
    if(root -> left == NULL && root -> right == NULL){
      toplam += root -> key;
    }else{
      if(root->left != NULL){
        total(root->left);
        toplam += root->key;
      }
      if(root->right != NULL){
        toplam += root -> key;
        total(root->right);
      }
    }
  }
  return toplam;
}




int main(int argc, char const *argv[]) {
  struct node *root = NULL;
  root = ekle(root,1);
  ekle(root,2);
  ekle(root,3);
  ekle(root,4);
  ekle(root,5);
  inorder(root);
  int c = minimum(root);
  int b = yukseklik(root);
  int a = size(root);
  int top = total(root);
  printf("\ndugum sayisi %d\n",a);
  printf("minumun dugum : %d\n",c);
  printf("yukseklik :%d\n",b);
  printf("%d \n",top);

  return 0;
}
