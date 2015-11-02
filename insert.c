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
	struct tree *aux;
	aux = (struct tree *) malloc(sizeof(struct tree));
	aux->left=NULL;
	aux->right=NULL;
	return aux;
}

int search(struct tree *any,int n){//função para encontrar elemento na arvore
    if(any->key==n){//procura a chave na raiz e consecutivamente nos galhos restantes
        return 1;
    }
    if(n>=any->key){
        return search(any->right,n);}//procura a chave nos filho a direita da raiz, recursivamente
    if(n < any->key){
        return search(any->left,n);//procura a chave nos filhos a esquerda da raiz, recursivamente
    }
    else return 0;
}

struct tree *newNode(int key){
    struct tree *tmp =  (struct tree *)malloc(sizeof(struct tree));
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    return temp;
}

struct tree *insert(struct tree *node,int key){
    if(node==NULL){
       	struct tree *tmp;
       	tmp= (struct tree*)malloc(sizeof(struct tree));
       	tmp->key=key;
       	tmp->left= tmp->right=NULL;
       	return tmp;
    }
    if(key>node->key){
        node->right=insert(node->right,key);
    }
    else if(key<node->key){
        node->left=insert(node->left,key);
    }
    return node;
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
	printf("[%d",node->key);
	brcktng(node->left);
	brcktng(node->right);
	printf("]");
}

void main(){
	int menu=0,s,key;
	char a;
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
						int n,i;
						scanf("%d",&n);
						for(i=1;i<=n;i++){
						struct tree *node=mallocnode();
						printf("Entre a chave do no %d:",i);
						scanf("%d",&node->key);
						if(root==NULL)root=node;
						else insert(node,node->key);
						}
					break;
				
				case 2:
						printf("Entre a chave a ser deletada:\n");
						scanf("%d",&key);
						del(root,key);
						break;
					
				case 3:					
					printf("Entre a chave a ser buscada:\n");
					scanf("%d",&s);
					if(root==NULL)printf("Arvore esta vazia! Adicione elementos.");
					if(search(root,s)==0)printf("O elemento nao se encontra na arvore!");
					if(search(root,s)==1)printf("O elemento esta na arvore!");
					break;
				
				case 4:
					postorder(root);
					break;
				
				case 5:					
					inorder(root);
					break;
					
				case 6:					
					preorder(root);
					break;
				
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
	
	
    
    
    
    
    
