#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
const int STRING_LEN = 10;
unsigned char* rand_string(int length, unsigned char* charset){
    srand(time(NULL));    
    int i = 0;
    for(;i<length;i++){
        charset[i]=(unsigned char) (rand()*256);
    }
    charset[i] = 0;
    return (char*) charset;
}
struct node{
    struct node* next;
    unsigned char* cargo;
};
int print_from_node(struct node* base){
    if(base->next){         
        printf("%s%s\n",base->cargo," ==> ");
        print_from_node(base->next);
    }
    return 0;
}
int main(){
    struct node* root;
    unsigned char barset[STRING_LEN+1]; 
    root->cargo = rand_string(STRING_LEN,barset);
    struct node* last = root;
    for(int i = 0 ;i<9;i++){
        struct node* new;
        last->next = new;
        unsigned char charset[STRING_LEN+1]; 
        new->cargo = rand_string(STRING_LEN,charset);
        last = new;
    }
    last->next = NULL;
    print_from_node(root);
    return 0;
}
