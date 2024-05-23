#include <stdio.h>

void hello(char name[10]){
    printf("%s%s%s\n", "hello ", name, "!");
}

void exit(){
    printf("Exiting the program ...\n");
    exit(0);
}

void options(){
    printf("0. Exit the program\n");
    printf("1. Calculate Addition\n");
    printf("2. Calculate Product\n");
    printf("3. Calculate Division\n");
    printf("4. Calculate Subtraction\n");
}

void perform(int choice){
    int num1, num2;
    float result;

    switch (choice)
    {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("The sum is: %f\n", result);
            break;

        case 2:
            printf("Enter two numbers to multiply: ");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("The product is: %f\n", result);
            break;

        case 3:
            printf("Enter two numbers to divide: ");
            scanf("%d %d", &num1, &num2);
            if(num2 != 0)
                result = (float)num1 / num2;
            else
                printf("Error: Division by zero is not allowed.\n");
            printf("The quotient is: %f\n", result);
            break;

        case 4:
            printf("Enter two numbers to subtract: ");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("The difference is: %f\n", result);
            break;

        default:
            printf("Invalid choice. Please choose a valid option.\n");
            break;
    }
}

int main() {
    printf("Enter your name: ");
    char name[10];
    int choice;
    scanf("%s", name);
    hello(name);
    printf("What would you like to do today?\n");
    options();
    while(1){
        printf("Please enter desired choice... : ");
        scanf("%d", &choice);
        if(choice == 0){
            exit();
            break;
        }else{
            perform(choice);
        }
    }
    return 0;
}