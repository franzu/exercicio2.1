#include<stdlib.h>
#include<stdio.h>

struct tree{	//criamos a estrutura da arvore
	int key;	//chave de localização
	struct tree *left;//ponteiro para um galho com chave menor
	struct tree *right; //ponteiro para um galho com chave maior
};

struct tree *root=NULL;
struct tree *temp=NULL;

struct tree *mallocnode(){
   struct tree *tmp;
   tmp = (struct tree *) malloc(sizeof(struct tree));
   tmp->left = NULL;
   tmp->right = NULL;
   return tmp;
}

void search(int n,struct tree *node){
    if(node==NULL) printf("\nVish!Elemento nao esta na arvore.");
    else if(node->key==n) printf("\nAe!Elemento esta na arvore.");
    else if(n>node->key) search(n,node->right);
    else search(n,node->left);
    }

void insert(struct tree *root,struct tree *newnode) {
	if(newnode->key<root->key){
      if(root->left==NULL)root->left=newnode;
      else insert(root->left,newnode);
	}
	if(newnode->key>root->key){
      if (root->right==NULL)root->right=newnode;
      else insert(root->right,newnode);
	}
}

struct tree *minimum(struct tree* node){
    struct tree *tmp = node;
    while (tmp->left != NULL)
        tmp = tmp->left;
 	return tmp;
}

struct tree *del(struct tree *root, int n){
	if(root==NULL)return;
	if (n < root->key)
        root->left = del(root->left, n);
    if (n > root->key)
        root->right = del(root->right, n);
    else {
		if (root->left == NULL){
            struct tree *node = root->right;
            free(root);
            return node;
         }
        else 
		if(root->right == NULL){
            struct tree *node = root->left;
            free(root);
            return node;
        }
        if (root->right == NULL){
            struct tree *node = root->left;
            free(root);
            return;
        }
    struct tree *tmp=minimum(root->right);
    root->key = tmp->key;
    root->right = del(root->right, tmp->key);
	}
	return;
}

void inorder(struct tree *node){
	if(node!=NULL){
		inorder(node->left);
		printf("%d ",node->key);
		inorder(node->right);
	}
}

void preorder(struct tree *node){
	if(node!=NULL){
		printf("%d ",node->key);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(struct tree *node){
	if(node!=NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->key);
	}
}

void brcktng(struct tree *node){
	printf("[");
	if(node!=NULL){
	printf("%d",node->key);
	brcktng(node->left);
	brcktng(node->right);
	}
	printf("]");
}

void main(){
	int menu=0,s,key,n,i;
	char a;
	struct tree *newnode, *tmp=NULL;
	printf("--Programa de ARVORE BINARIA DE BUSCA Inicializado--");
	printf("\nMENU:");
	printf("\n1.Inserir elemento.");
	printf("\n2.Deletar elemento.");
	printf("\n3.Buscar elemento.");
	printf("\n4.Impressao em posordem.");
	printf("\n5.Impressao em ordem.");
	printf("\n6.Impressao em preordem.");
	printf("\n7.Impressao em colchetes rotulados.");
	printf("\n8.Sair.");	
	printf("\nEscolha alguma das opcoes com seu respectivo numero:");
	while(menu!=8){
		scanf("%d",&menu);
			switch(menu){
				case 1:
					printf("Quantos elementos deseja adicionar?  ");
					scanf("%d",&n);
					for(i=1;i<=n;i++){
					newnode=mallocnode();
					printf("Entre a chave do no %d:",i);
					scanf("%d",&newnode->key);
					if(root==NULL)root=newnode;
					else insert(root,newnode);
					}
					break;
				
				case 2:
					printf("Entre a chave a ser deletada:\n");
					scanf("%d",&key);
					del(root,key);
					break;
					
				case 3:	
					printf("Escolha o valor a ser buscado:");
					scanf("%d",&s);
					search(s,root);
					break;
				
				case 4:
					if(root!=NULL){
					postorder(root);
					break;
					}
					else break;
				
				case 5:					
					if(root!=NULL){inorder(root);
					break;
					}
					else break;
					
				case 6:					
					if(root!=NULL){preorder(root);
					break;
					}
					else break;
				
				case 7:
					brcktng(root);
					break;
				
				case 8:
					printf("Tchau.");
					return;
				
				default:
					printf("Entrada errada, escolha dentre os numeros!!");
					break;
			}
		printf("\nEscolha novamente:");
	}
	return;
}
	
	
    
    
    
    
    
