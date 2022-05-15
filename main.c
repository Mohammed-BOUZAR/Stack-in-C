#include <stdio.h>
#include <stdlib.h>

struct LIST{
    int *data;
    int top;
    int size;
};
typedef struct LIST STACK;

void initialize_STACK(STACK *S)
{
    printf("Stack size : ");
    scanf("%d",&S->size);
    S->data = malloc(S->size * sizeof(int));
    S->top = -1;
}

int is_Full(STACK *S)
{
    return (S->top == S->size-1);
}

int is_Empty(STACK *S)
{
    return S->top == -1;
}

void push(STACK *S, int new_data)
{
    if(is_Full(S))
        printf("the stack is full.\n");
    else
        S->data[++S->top] = new_data;

}

int pop(STACK *S)
{
    int data;
    if(is_Empty(S))
        printf("the stach is empty.\n");
    else
        data = S->data[S->top--];
    return data;
}

void print_Stack(STACK *S)
{
    if(is_Empty(S))
        printf("the stack is empty.\n");
    else{
        int i;
        printf(" ==> ");
        for(i=0; i<=S->top; i++){
            printf("%d  ",S->data[i]);
        }
        printf("\n");
    }
}

void remove_Negative(STACK *S)
{
    STACK *help;
    int i;
    help = malloc(sizeof(STACK));
    help->top = -1;
    help->size = S->top+1;
    help->data = malloc(S->size * sizeof(int));

    for(i=S->top; i>=0; i--){
        if(S->data[i]<0){
            pop(S);
        }
        else{
            push(help,pop(S));
        }
    }
    for(i=help->top ;i>=0; i--){
        push(S,pop(help));
    }

    free(help->data);
    free(help);
}

int main()
{
    STACK *s;
    int data,menu,size;
        while(1){
            printf("1- Initialize.\n");
            printf("2- Print stack.\n");
            printf("3- push.\n");
            printf("4- pop.\n");
            printf("5- Remove negative data.\n");
            printf("6- Quit.\n");
            scanf("%d",&menu);
            switch(menu){
            case 1:
                s = malloc(sizeof(STACK));
                initialize_STACK(s);
                break;
            case 2:
                print_Stack(s);
                break;
            case 3:
                printf("Data : ");
                scanf("%d",&data);
                push(s,data);
                break;
            case 4:
                pop(s);
                break;
            case 5:
                remove_Negative(s);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Error.\n");
                break;
            }
        }
    free(s->data);
    free(s);
    return 0;
}

