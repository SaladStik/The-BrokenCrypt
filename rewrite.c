#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>

#define basePlayerHealth 100
#define HealthMax 200
#define HealthPotCost 5
#define HealthUpgradeCost 10
#define SkellyHealth 45
#define ZomboHealth 65
#define WizardHealth 25
#define ReaperHealth 45
#define MiniBossHealth 112
#define BossHealth 250

// ^ Initialize PlayerMaxHealth and PlayerHealth to basePlayerHealth
int playerMaxHealth = basePlayerHealth, playerHealth = basePlayerHealth;

// ^ Returns a random number between 1 and the maxNum
int randomNumberGen(int maxNum)
{
    return rand() % maxNum + 1;
}

char* playIntro()
{
    static char name[200];
    printf("Welcome Traveller To BrokenLane");
    for (int i = 0; i < 3; i++) 
    {
        Sleep(1000); printf("."); 
    }
    system("cls");
    printf("What Should We Call You?\n");
    int i = 0;
    char ch;
    while ((ch = getche()) != '\r' && i < 199) {
        name[i++] = ch;
    }
    name[i] = '\0';
    system("cls");
    printf("Welcome T▒ Our W▒n▒erf▒l Wor▒d Of BrokenLane %s\n", name);
    system("pause");
    system("cls");
    // TODO- add audio here
    Sleep(3);
    //TODO - add audio here
    printf("Phew. Who Would Have Thought A Bullet Wound To That Annoying Pricks Head Would Be So Gross?\nAnyway Now That Your Here Lets Begin.\n");
    system("pause");
    system("cls");
    printf("You Really Thought You Could Play A Simple Story?\n");
    Sleep(2.5);
    system("pause");
    system("cls");
    //TODO - add audio here
    Sleep(4);
    printf("\n\n\t\tA No Name Studios Game");
    Sleep(4);
    system("cls");
    printf("\n\n\t\tPublished By WHY IS THIS IN MY ATTIC?");
    Sleep(4);
    system("cls");
    printf("\n\n\t\tIn Collaboration With Da Baby");
    Sleep(4);
    system("cls");
    printf("\n\n\t\tMADE IN THE UNITY ENGINE");
    Sleep(4);
    system("cls");
    printf("\n\n\t\tA Royalty Filled Game\n\n\tYeah No Revenue Was Made Here B^)");
    Sleep(4);
    system("cls");
    printf("\n\n\t\tDeveloped By Nick");
    Sleep(4);
    system("cls");
    printf("\n\n\t\tALL RIGHTS RESERVED");
    Sleep(4);
    system("cls");
    printf("\n\n\t\tThe BrokenCrypt");
    Sleep(8);
    system("cls");
    system("cls");
    // TODO - Add audio here
    Sleep(20);
    printf("           ^\n");
    printf("          | |\n");
    printf("          | |\n");
    printf("          | |\n");
    printf("          | |\n");
    printf("       0-------0\n");
    printf("           |\n");
    printf("           0\n");
    printf("Item Gained.");
    Sleep(4);
    system("cls");
    return name;
}



// ^ Main function
int main()
{
    // ^ Seed the random number generator
    srand((unsigned)time (NULL));
    int choice = 0;
    // ^ Dictionary to store item names and their costs
    struct Item {
        char name[50];
        int amount;
    };
    // * The players inventory
    struct Item inventory[] = {
        {"Health Potion", 3}, 
        {"Sword", 0},
        {"Knife", 0},
        {"Shield", 0},
        {"Gold", 10} // ^ Starting Gold Amount
        };

    // ^ Main game loop
    while(1 == 1)
    {
        system("cls");
        //TODO - add music here
        printf("/-----------------------------\\\n");
        printf("|                             |\n");
        printf("|      The BrokenCrypt        |\n");
        printf("|                             |\n");
        printf("\\-----------------------------/\n");
        printf("\n\t[1] Play \n\t\n\t[2] Quit\n\n\t[3] Skip Intro\n");//PLAYER CAN HIT 3 TO HERE A JOKE I ADDED || HIT 4 TO SKIP THE WHOLE INTRO SEQUENCE
        // * Take in user input
        choice = getche();
        system("cls");

        // ^ Switch to user choice
        switch(choice)
        {
            case '1': // ^ Start the game
                char* name = playIntro();
                inventory[2].amount = 1;
                for (int i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
                    printf("%s: %d\n", inventory[i].name, inventory[i].amount);
                }
                printf("Welcome, %s!\n", name); // Display player's name
                system("pause");
                break;
            default:
                // ^ Invalid choice
                break;
        }

    }
}
