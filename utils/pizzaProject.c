//
// Created by Kaloyan Petkov on 10.07.24.
//

#include <stdio.h>
#include <stdlib.h>

char *dough1() { return "Dough1";}
char *dough2() { return "Dough2";}

char *tomatoSauce() { return "Tomato sause";}
char *pestoSause() { return "Pesto sause";}

char *mozzarellaCheese() { return "Mozzarella cheese";}
char *cheddarCheese() { return "Cheddar cheese";}

void createPizza(char *(*doughFunc)(), char *(*sauceFunc)(), char *(*cheeseFunc)() ) {
    printf("Pizza ingredients:\n");
    printf("Dough - %s\n", doughFunc());
    printf("Sauce - %s\n", sauceFunc());
    printf("Cheese - %s\n", cheeseFunc());
}

int testPizzaProject() {
    int doughType;
    char *(*doughFunc)();
    printf("Enter dough type:\n1. Dough1\n2. Dough2\n");
    scanf("%d", &doughType);
    switch (doughType) {
        case 1:
            doughFunc = dough1;
            break;
        case 2:
            doughFunc = dough2;
            break;
        default:
            printf("Entered dough type is invalid!");
            exit(1);
    }

    int sauceType;
    char *(*sauceFunc)();
    printf("Enter sauce type:\n1. Tomato\n2. Pesto\n");
    scanf("%d", &sauceType);
    switch (sauceType) {
        case 1:
            sauceFunc = tomatoSauce;
            break;
        case 2:
            sauceFunc = pestoSause;
            break;
        default:
            printf("Entered sauce type is invalid!");
            exit(1);
    }

    int cheeseType;
    char *(*cheeseFunc)();
    printf("Enter cheese type:\n1. Mozzarella\n2. Cheddar\n");
    scanf("%d", &cheeseType);
    switch (cheeseType) {
        case 1:
            cheeseFunc = mozzarellaCheese;
            break;
        case 2:
            cheeseFunc = cheddarCheese;
            break;
        default:
            printf("Entered sauce type is invalid!");
            exit(1);
    }

    createPizza(doughFunc, sauceFunc, cheeseFunc);
    return 0;
}