#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int getch();

int main() {
	
    stack s;
    int choice,n;
    
    while(1){
    	system("cls");
    	printf("-----------Stack operations-------------\n");
    	printf("1.Init stack\n");
        printf("2.Push onto stack\n");
        printf("3.Pop from stack\n");
        printf("4.Empty or not\n");
        printf("5.Top element\n");
        printf("6.Size of stack\n");
        printf("7.Clear stack\n");
        printf("8.Print stack\n");
		printf("9.Exit\n");
    	printf("----------------------------------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: init(&s);
                    break;
                        
			case 2: printf("enter an element to push onto the stack:");
					scanf("%d",&n);
					push(&s,n);
                    break;
                
            case 3: printf("The poped element is: %d\n",pop(&s));
                    break;
                
            case 4: if(is_empty(&s) == 1){
                		printf("stack is empty\n");
					}else{
						printf("stack is not empty\n");
					}
                    break;
                
            case 5: printf("The element at the top is: %d\n",top(&s));
                    break;
                
            case 6: printf("The size of the stack is: %d\n",size(&s));
                    break;
                
            case 7: clear(&s);
                    break;
                
            case 8: printStack(&s);
                    break;
                
			case 9: exit(0);
                    break;
						   
            default: printf("Wrong Choice\n");
                    break;
        }
		
		getch();
    
	}

   
    return 0;
}

