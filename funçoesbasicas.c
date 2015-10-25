#include<stdlib.h>
#include<stdio.h>

struct tree{	//criamos a estrutura da arvore
	int key;	//chave de localização
	int data;	//conteudo
	struct arvore *left;//ponteiro para um galho com chave menor
	struct arvore *right; //ponteiro para um galho com chave maior
};

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
}
}

void add(struct tree* node, int newkey, int node->data){//função de adição de galho na arvore
    struct tree *p = node;//estrutura p de comparação
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

void remove(struct tree *node, int delkey){
    struct tree*p = node;
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
 
void main(){
    }
