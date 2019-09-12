#include <stdio.h>

const int MAX = 110;

struct Tree{
  int root;
  int left;
  int right;
};

Tree tree[MAX];

void preorder(int x){
  //루트를 x로 하는 전위순회
  if(tree[x].left==-1 && tree[x].right==-1){
    printf("%d ", x);  
  }else{
    //Root --> Left --> Right
    printf("%d ", x);
    if(tree[x].left!=-1) preorder(tree[x].left);
    if(tree[x].right!=-1) preorder(tree[x].right);
  }
}


void inorder(int x){
  //루트를 x로 하는 중위순회
  if(tree[x].left==-1 && tree[x].right==-1){
    printf("%d ", x);
  }else{
    //Left --> Root --> Right
    if(tree[x].left!=-1) inorder(tree[x].left);
    printf("%d ", x);
    if(tree[x].right!=-1) inorder(tree[x].right);
  }
}

void postorder(int x){
  //루트를 x로 하는 후위순회
  if(tree[x].left==-1 && tree[x].right==-1) {
    printf("%d ", x);
  }else{
    //Left--> Right --> Root
    if(tree[x].left!=-1) postorder(tree[x].left);
    if(tree[x].right!=-1) postorder(tree[x].right);
    printf("%d ", x);
  }
}





int main() {
  
  int n,a,b,c;
  scanf("%d", &n);
  
  for(int i=0;i<n;i++){
    scanf("%d %d %d", &a, &b,&c);
    
    tree[a].left=b;
    tree[a].right=c;
  }
  
  preorder(0);
  printf("\n");
  inorder(0);
  printf("\n");
  postorder(0);

  return 0;
}