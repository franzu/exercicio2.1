#include<stdlib.h>
#include<stdio.h>

struct tree{	//criamos a estrutura da arvore
	int key;	//chave de localização
	struct arvore *left;//ponteiro para um galho com chave menor
	struct arvore *right; //ponteiro para um galho com chave maior
}root=NULL;

struct tree *mallocnode(){
	struct tree *aux;
	aux = (struct tree *) malloc(sizeof(struct tree));
	aux->left=NULL;
	aux->right=NULL;
	return aux;
}

struct tree *search(struct tree *root;int n){//função para encontrar elemento na arvore
	 if(root==NULL){return NULL;}//arvore vazia
    if(root->key==n){//procura a chave na raiz
        return root;
    }
    if(key>=root->key){
        return search(root->right, n);}//procura a chave nos filho a direita da raiz recursivamente
    if(n < root->key){
        return busca(root->left, n);//procura a chave nos filhos a esquerda da raiz recursivamente
    }
    else return
}
}

void add(struct tree* node, int newkey){//função de adição de galho na arvore
    struct tree *p = node;//pseudo-galho auxiliar
    struct tree *dad = NULL;
     
    while(p != NULL) {
        dad = p;
        if (p->key >= newkey) {//se a chave do elemento em adição for maior q a comparação,colocamo-o a esquerda
            p = p->left;
        } else {
            p= p->right;//se a chave do elemento em adição for menor que a comparação,colocamo-o a direita
        }
    }
 
    struct tree *NEW= (struct tree*)malloc(sizeof(struct tree));//cria o novo galho
    NEW->key = newkey;		//configuramos o novo galho
    NEW->data = node->data;
    NEW->left = NULL;
    NEW->right = NULL;
     
    if(dad->key >= NEW->key){//localiza o novo galho em relação ao pai, se chave for maior, fica a esquerda 
        dad->left=NEW;
    }   
    else{//se a chave for menor, a direita
        dad->right=NEW;
        }
} 

void remove(struct tree *node, int delkey){//funcao de remocao de elementos da arvore
    struct tree*p = node;//pseudo-galho auxiliar da funcao
    struct tree *dad = NULL;
     
    while(p != NULL && p->key != delkey) {
        dad = p;
        if (p->key >= delkey) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
        if(p == NULL){
                 return;
    }
    struct tree *m = p->right;
    while(m != NULL && m->left != NULL){
            m = m->left;
    }
    struct tree *n;
        if(m != NULL){
        m -> left = p -> left;
        n = p->right;
    } else {
        n = p->left;
    }
        if(dad->key < key) {
        dad->right = n;
    } else {
        dad->left = n;
    }
    free(p);
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

void main(){
	int menu=0;
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
						printf("Quantos elementos deseja adicionar?");
						int n,i;
						scanf("%d",%n);
						for(i=1,i<=n,i++){
						struct tree node=mallocnode();
						printf("Entre a chave do no %d:\n",i);
						scanf("%d",&node->key);
						if(root==NULL)root=node;
						else add(node,node->key);}
					break;
				
				case 2:	
					do{
						struct tree node=mallocnode();
						printf("Entre a chave a ser deletada:\n");
						scanf("%d",&node->key);
						remove(node,node->key);
						char *a;
						printf("Deletar mais um elemento?(sim/nao)");
						a=gets();
					}
					while(a=='sim'||a=='SIM');
					break;
					
				case 3:
					int s;
					printf("Entre a chave a ser buscada:\n");
					scanf("%d",&s);
					if(root==NULL)printf("Arvore esta vazia! Adicione elementos.");
					if(search(root,s)==NULL)printf("O elemento nao se encontra na arvore!");
					else printf("O elemento esta na arvore!");
				
				case 4:
					struct tree node=mallocnode();
					printf("Entre a chave a partir da qual quer a impressao:\n");
					scanf("%d",&node->key);
					postorder(node);
				
				case 5:
					struct tree node=mallocnode();
					printf("Entre a chave a partir da qual quer a impressao:\n");
					scanf("%d",&node->key);
					inorder(node);
					
				case 6:
					struct tree node=mallocnode();
					printf("Entre a chave a partir da qual quer a impressao:\n");
					scanf("%d",&node->key);
					preorder(node);
				
				case 7:
					
					}
				}
	
	
	
    
    
    
    
    
