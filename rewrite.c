#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>

#define basePlayerHealth 120
#define HealthMax 220
#define HealthPotCost 5
#define HealthUpgradeCost 10
#define SkellyHealth 45
#define ZomboHealth 65
#define WizardHealth 25
#define ReaperHealth 45
#define MiniBossHealth 112
#define BossHealth 250


// ^ Dictionary to store item names and their costs
struct Item {
    char name[50];
    int amount;
};

// * init the players inventory
struct Item inventory[] = {
    {"Health Potion", 3}, 
    {"Sword", 0},
    {"Knife", 1},
    {"Shield", 0},
    {"Gold", 10} // ^ Starting Gold Amount
};

// ^ Struct to measure the amount of turns made
struct Turn {
    char turnType[50];
    int turnNum;
};

struct Turn playerTurns[] = {
    {"noTurns", 0},
    {"leftTurns", 0},
    {"rightTurns", 0}
};

// ^ Initialize PlayerMaxHealth and PlayerHealth to basePlayerHealth
int playerMaxHealth = basePlayerHealth, playerHealth = basePlayerHealth;

// ^ Returns a random number between 1 and the maxNum
int randomNumberGen(int maxNum)
{
    return rand() % maxNum + 1;
}

void LEnding(char* Name);
void REnding(char* Name);
void NoEnding(char* Name);

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
    system("pause && cls");
    // TODO- add audio here
    Sleep(3000);
    //TODO - add audio here
    printf("Phew. Who Would Have Thought A Bullet Wound To That Annoying Pricks Head Would Be So Gross?\nAnyway Now That Your Here Lets Begin.\n");
    system("pause && cls");
    printf("You Really Thought You Could Play A Simple Story?\n");
    Sleep(2500);
    system("pause && cls");
    //TODO - add audio here
    Sleep(4000);
    printf("\n\n\t\tA No Name Studios Game");
    Sleep(4000);
    system("cls");
    printf("\n\n\t\tPublished By WHY IS THIS IN MY ATTIC?");
    Sleep(4000);
    system("cls");
    printf("\n\n\t\tIn Collaboration With Da Baby");
    Sleep(4000);
    system("cls");
    printf("\n\n\t\tMADE IN THE UNITY ENGINE");
    Sleep(4000);
    system("cls");
    printf("\n\n\t\tA Royalty Filled Game\n\n\tYeah No Revenue Was Made Here B^)");
    Sleep(4000);
    system("cls");
    printf("\n\n\t\tDeveloped By Nick");
    Sleep(4000);
    system("cls");
    printf("\n\n\t\tALL RIGHTS RESERVED");
    Sleep(4000);
    system("cls");
    printf("\n\n\t\tThe BrokenCrypt");
    Sleep(8);
    system("cls");
    system("cls");
    // TODO - Add audio here
    Sleep(20000);
    printf("           ^\n");
    printf("          | |\n");
    printf("          | |\n");
    printf("          | |\n");
    printf("          | |\n");
    printf("       0-------0\n");
    printf("           |\n");
    printf("           0\n");
    printf("Item Gained.");
    Sleep(4000);
    system("cls");
    return name;
}

void gameStart(FILE *fptr, char* name)
{
    printf("Hey %s Wake Up!\n\t\t\n", name);
    system("pause && cls");
    printf("I guess it was all just a dream....");
    Sleep(1000);
    printf("\nWell since im up I might aswell go get some breakfast.\n");
    printf("|-------------------------|\n");
    printf("|  /-/               *  0 | \n");
    printf("| /-/         ___         |\n");
    printf("|/-/       [] ' '         |\n");
    printf("|-------------------------|\n");
    system("pause && cls");
    printf("*You Walk Downstairs*\n");
    //TODO - add audio here
    Sleep(10000);
    system("cls");
    printf("*You Smell Pancakes*\n");
    system("pause && cls");
    printf("Do You Want To Go Get Breakfast?   (Y/N)\n");
    char Kitchen;
    scanf(" %c", &Kitchen);
    // & Illusion of choice
    if(tolower(Kitchen) == 'y')
    {
        system("cls");
        printf("You Walk To The Kitchen.");
    }
    else
    {
        system("cls");
        printf("You Decide To Go Back To Bed.");
    }
    printf("\nBut As You Walk You Notice The Floor Boards Creaking.\nWhen Suddenly You Hear A Snap And Begin To Fall\n");
    system("pause && cls");
    // TODO implement fall video
    
    // * File writing
    fptr = fopen("Misc\\Page 1.txt", "w");
    printf("Do You Deserve This?\n");
    Sleep(3000);
    system("cls");
    fprintf(fptr, "When %s Fell They Began To Realize The Amount Of Bad Things They Had Done\nHad They Really Deserved This?\nMaybe This Was The Best Thing For Them\nAfter All", name);
    system("pause");
    printf("Are You A Good Person?\n(Y/N)\n");
    char morality = tolower((" %c", &morality));
    // * Some goofy writing i thought was good in highschool lol
    if(morality == 'y') {fprintf(fptr," They Werent Exactly A Jackass Throughout Their Life.");}
    else {fprintf(fptr," They Were Voted The Biggest Jackass In High School.");}
    fclose(fptr);
    //TODO - add audio here
    system("pause && cls");
    //TODO - add audio here
    Sleep(2000);
    printf("%s Found Themself At A Stone Gate Deep Underground With A Sign OverHead That Read '▒▒▒▒▒' \nUnderneath A Sign In English Read 'The BrokenCrypt\n\n", name);
    printf("/-----------------------------\\\n");
    printf("|                             |\n");
    printf("|       The BrokenCrypt       |\n");
    printf("|                             |\n");
    printf("\\-----------------------------/\n");
    Sleep(2000);
    system("pause && cls");
    printf("You Decide To Enter");
    //TODO - add audio here
    for (int i = 0; i < 3; i++) {
        printf(".");
    }
    Sleep(2000);
    system("cls");
    //TODO - add audio here
    printf("%s Began To Wonder What This Place Was And How It Had\nBeen Under Their House All This Time Without Them Knowing\n", name);
    system("pause");
    // * end of intro
}

// ! Enemy Fight
void enemyFight(int enemyHealth, int enemyDamageCap, char* enemyName)
{
    bool hasPlayerRun = false;
    // TODO - add audio here
    system("cls");
    printf("A %s Has Appeared!\n", enemyName);
    system("pause && cls");
    
    do
    {
        printf("The %s Is Attacking!\n", enemyName);
        system("pause && cls");
        // * Enemy Damage
        int damageTaken = randomNumberGen(enemyDamageCap);
        if (inventory[3].amount == 1) {
            damageTaken /= 2;
        }
        playerHealth -= damageTaken;
        printf("You Took %d Damage!\nYou Now Have %d Health!\n", damageTaken, playerHealth);
        system("pause && cls");
        // * Check if player is dead
        if(playerHealth <= 0)
        {
            if (playerHealth < 0)
                playerHealth = 0;
            
            printf("You Have %d Out Of %d Health!!!\n", playerHealth, playerMaxHealth);
            system("pause && cls");
            // * Revive function
            if(inventory[0].amount >= 1)
            {
                printf("You Have %d Health Pots\n Use 1 To Revive Yourself?\n(Y/N)\n", inventory[0].amount);
                char potUse;
                scanf(" %c", &potUse);
                if(tolower(potUse) == 'y')
                {
                    inventory[0].amount--;
                    playerHealth = playerMaxHealth;
                }
                else
                {
                    printf("You Died!\n");
                    system("pause && cls");
                    exit(0);
                }
            }
            else
            {
                printf("You Died!\n");
                system("pause && cls");
                exit(0);
            }
        }
        // * Player action
        action:;
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", inventory[0].amount, playerHealth, enemyHealth);
        int choice;
        scanf(" %d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            // * Player Attack
            int pDamage;
            if(inventory[1].amount == 1)
            {
                pDamage = randomNumberGen(30);
                if (pDamage < 10)
                    pDamage = 10;
            }
            else
            {
                pDamage = 10;
            }
            enemyHealth -= pDamage;
            printf("You Dealt %d Damage\n%s Now Has %i Health\n",pDamage,enemyName, enemyHealth);
            system("pause && cls");
            break;
        case 2:
            // * Player Heal
            if(inventory[0].amount >= 1)
            {
                inventory[0].amount--;
                playerHealth = playerMaxHealth;
                printf("Your Health Is Now At Its Max!\n%i\n", playerHealth);
                system("pause && cls");
                goto action;
            }
            else
            {
                printf("You Have No Health Potions!\n");
                system("pause && cls");
            }
            break;
        case 3:
            // * Player Run
            if(!hasPlayerRun)
            {
                if(randomNumberGen(8) >= 6)
                {
                    printf("You Ran Away!\n");
                    system("pause && cls");
                    goto runAway;
                    break;
                }
                else
                {
                    printf("You Failed To Run Away!\n");
                    hasPlayerRun = true;
                    system("pause && cls");
                    break;
                }
            }
            else
            {
                printf("You Already Tried To Do This And Failed.\n");
                system("pause && cls");
                goto action;
                break;
            }
        }
    }while(enemyHealth > 0);
    runAway:;
    // * End of fight
}

// ! Loot room function
void lootRoom()
{
    system("cls");
    char prompt[200];
    int promptType;
    bool finished = false;
    if(inventory[1].amount == 0)
    {
        strcpy(prompt, "[1] You Found A Sword\n");
        promptType = 1;
        if(inventory[3].amount == 0)
        {
            strcpy(prompt, "[1] You Found A Sword\n[2] You Found A Shield\n");
            promptType = 2;
        }
    }
    else if (inventory[3].amount == 0)
    {
        strcpy(prompt, "[1] You Found A Shield\n");
        promptType = 3;
    }
    else
    {
        strcpy(prompt, " ");
    }
    if(prompt == " ")
    {
        printf("You Already Have All The Items You Can Get From A Loot Room So Heres A Health Pot!\n");
        system("pause && cls");
        inventory[0].amount++;
    }
    else
    {
        int healthPotNum;
        switch (promptType)
        {
            case 1:
                healthPotNum = 2;
                break;
            case 2:
                healthPotNum = 3;
                break;
            case 3:
                healthPotNum = 2;
                break;
        }
        while(!finished)
        {
            system("cls");
            printf("%s\n[%i] You Found A Health Pot\n\nONCE YOU CHOOSE AN ITEM YOU CANNOT COME BACK UNTIL YOU FIND ANOTHER ROOM\n\n",healthPotNum);
            int choice = scanf(" %d", &choice);
            system("cls");
            switch(choice)
            {
                case 1:
                    if(promptType == 1)
                    {
                        inventory[1].amount++;
                        finished = true;
                    }
                    else if(promptType == 2)
                    {
                        inventory[1].amount++;
                        finished = true;
                    }
                    else
                    {
                        inventory[3].amount++;
                        finished = true;
                    }
                    break;
                case 2:
                    if(promptType == 2)
                    {
                        inventory[3].amount++;
                        finished = true;
                    }
                    else if(promptType == 3)
                    {
                        inventory[0].amount++;
                        finished = true;
                    }
                    break;
                case 3:
                    if(promptType == 2)
                    {
                        inventory[0].amount++;
                        finished = true;
                    }
                    else
                    {
                        printf("Invalid Choice\n");
                        system("pause && cls");
                    }
                    break;
                default:
                    printf("Invalid Choice\n");
                    system("pause && cls");
                    break;
            }
        }
    }
}

// ! Shop function
void goShopping()
{
    while(true)
    {
        system("cls");
        printf("%iG\n\n[1]Health Pot ------ 10G\n[2]Heart Crystal ------ 30G\n[3] Exit Shop\n\n If You Exit The Shop You Can Not Return\n\n", inventory[4].amount);
        int choice = scanf(" %d", &choice);
        switch(choice)
        {
            case 1:
                if(inventory[4].amount >= 10)
                {
                    inventory[0].amount++;
                    inventory[4].amount -= 10;
                }
                else
                {
                    printf("You Do Not Have Enough Gold!\n");
                    system("pause && cls");
                }
                break;
            case 2:
                if(inventory[4].amount >= 30 && playerMaxHealth <= HealthMax)
                {
                    printf("+25 Health\nYour New Max Health Is: %i", playerMaxHealth);
                    playerMaxHealth += 25;
                    playerHealth = playerMaxHealth;
                    inventory[4].amount -= 30;
                }
                else
                {
                    printf("You Do Not Have Enough Gold Or You Are At Max Health!\n");
                    system("pause && cls");
                }
                break;
            case 3:
                system("cls");
                return;
                break;
            default:
                printf("Invalid Choice\n");
                system("pause && cls");
                break;
        }
    }
}

// ^ Actual Gameplay
void gameplay(struct Item *inventory, FILE *fptr, char* name)
{
     // !! CHANGE THIS IF YOU WANT A LONGER  {VV}/SHORTER EXPERIENCE
    for(int TotalTurns = 0;TotalTurns <= 20; TotalTurns++)
    {
        playerHealth = playerMaxHealth;
        //* Triggers an encounter + allows me to change the encounter rate
        if(randomNumberGen(11) <= 10)
        {
            int chance = randomNumberGen(10);
            switch (chance)
            {
            case 1:
                // & no enemy
                int goldAmt = randomNumberGen(12);
                printf("You Got Lucky!\n Although Noises Were Coming From This Room Nothing Is Here\n +%d Gold\n", goldAmt);
                inventory[4].amount += goldAmt;
                system("pause && cls");
                break;
            case 2:
                // & Skeleton Encounter
                enemyFight(SkellyHealth, 52, "Skeleton");
                system("cls");
                break;
            case 3:
                // & Wizard Encounter
                enemyFight(WizardHealth, 65, "Wizard");
                system("cls");
                break;
            case 4:
                // & Shop Encounter
                goShopping();
                system("cls");
                break;
            case 5:
                // & Reaper Encounter
                enemyFight(ReaperHealth, 47, "Reaper");
                system("cls");
                break;
            case 6:
                // & Loot Room Encounter
                lootRoom();
                system("cls");
                break; 
            case 7:
                // & Zombie Encounter
                enemyFight(ZomboHealth, 44, "Zombie");
                system("cls");
                break;
            case 8:
                if (TotalTurns <= 5)
                {
                    // & Zombie Encounter
                    enemyFight(ZomboHealth, 24, "Zombie");
                }
                else
                {
                    // & MiniBoss Encounter
                    enemyFight(MiniBossHealth, 30, "MiniBoss");
                    system("cls");  
                }
                break;
            default:
                break;
            }
        }
        // * Player dodges an encounter
        else
        {
            //rolled false encounter
            int goldAmt = randomNumberGen(12);
            printf("You Found A Pouch Of Gold\nIt Has %i Gold\n", goldAmt);
            system("pause && cls");
            inventory[4].amount += goldAmt;
            printf("You Have %i Gold.\n", inventory[4].amount);
            system("pause && cls");
        }
        // & if its the first encounter write up some lore
        if(TotalTurns == 0)
        {
            fptr = fopen("Misc\\Page 2.txt", "w");
            fprintf(fptr, "When %s Entered The First Room They Realized How Little Was In It,\nThe Room Had Almost No Loot, Skeletons Chained To The Walls,\nAnd By Nothing I(The Narrator) Mean Almost No Spiders\nIN A UNDERGROUND DUNGEON!?!?\n\nPage 2", name);
            fclose(fptr);
        }
        char choice;
        switch(randomNumberGen(7))
        {
            case 1:
                // & straight
                    printf("There Is Only One Path Out Of This Room.\n");
                    system("pause && cls");
                    printf("You Go Straight\n");
                    system("pause && cls");
                    playerTurns[0].turnNum++;
                break;
            case 2:
                // & left
                    printf("There Is Only One Path Out Of This Room.\n");
                    system("pause && cls");
                    printf("You Go Left\n");
                    system("pause && cls");
                    playerTurns[1].turnNum++;
                break;
            case 3:
                // & right
                    printf("There Is Only One Path Out Of This Room.\n");
                    system("pause && cls");
                    printf("You Go Right\n");
                    system("pause && cls");
                    playerTurns[2].turnNum++;
                break;
            case 4:
                //& left straight
                    printf("There Are 2 Paths Out Of This Room\n (L/S)\n");
                    choice = tolower(scanf(" %c", &choice));
                    system("cls");
                    switch(choice)
                    {
                        case 'l':
                        {
                            playerTurns[1].turnNum ++;
                        }
                        case 's':
                        {
                            playerTurns[0].turnNum ++;
                        }
                    }
                break;
            case 5:
                //& right straight
                    printf("There Are 2 Paths Out Of This Room\n (R/S)\n");
                    choice = tolower(scanf(" %c", &choice));
                    system("cls");
                    switch(choice)
                    {
                        case 'r':
                        {
                            playerTurns[2].turnNum ++;
                        }
                        case 's':
                        {
                            playerTurns[0].turnNum ++;
                        }
                    }
                break;
            case 6:
                //& left right
                    printf("There Are 2 Paths Out Of This Room\n (L/R)\n");
                    choice = tolower(scanf(" %c", &choice));
                    system("cls");
                    switch(choice)
                    {
                        case 'l':
                        {
                            playerTurns[1].turnNum ++;
                        }
                        case 'r':
                        {
                            playerTurns[2].turnNum ++;
                        }
                    }
                break;
            case 7:
                //& left right straight
                    printf("There Are 3 Paths Out Of This Room\n (L/R/S)\n");
                    choice = tolower(scanf(" %c", &choice));
                    system("cls");
                    switch(choice)
                    {
                        case 'l':
                        {
                            playerTurns[1].turnNum ++;
                        }
                        case 'r':
                        {
                            playerTurns[2].turnNum ++;
                        }
                        case 's':
                        {
                            playerTurns[0].turnNum ++;
                        }
                    }
                break;
        }
    }
    //!! PRE-Bossfight section
    int casino();
    goShopping();
    //!! Bossfight section
    char* bossNames[] = {
        "The Great Wizard", "The Reaper", "The Skeleton King", "The Dark Sorcerer", 
        "The Undead Knight", "The Cursed Pharaoh", "The Fallen Angel", "The Demon Lord", 
        "The Shadow Assassin", "The Ancient Dragon", "The Lich King", "The Vampire Lord", 
        "The Warlock", "The Necromancer", "The Dark Paladin", "The Infernal Beast", 
        "The Ghostly Wraith", "The Bloodthirsty Beast", "The Soul Reaper", "The Death Bringer"
    };
    char* bossName = bossNames[randomNumberGen(20) - 1];
    enemyFight(BossHealth, 88, bossName);
    if (playerTurns[1].turnNum > playerTurns[2].turnNum && playerTurns[1].turnNum > playerTurns[0].turnNum) {
        LEnding(name);
    } else if (playerTurns[2].turnNum > playerTurns[1].turnNum && playerTurns[2].turnNum > playerTurns[0].turnNum) {
        REnding(name);
    } else if (playerTurns[0].turnNum > playerTurns[1].turnNum && playerTurns[0].turnNum > playerTurns[2].turnNum) {
        NoEnding(name);
    } else {
        system("cls");
        printf("You're Lost Forever\n");
        system("pause && cls");
    }
}

//& GAME ENDINGS
void LEnding(char* Name)
{
    FILE *fptr;
    system("cls");
    printf("After All Those Left Turns You Finally Left The Dungeon And Ended Up In A Even Worse Place...\n The Attic.");
    system("pause");
    fptr = fopen("Misc\\Page 3.txt", "w");
    fprintf(fptr,"Well Now You Are Stuck In The Attic With No Way Out.\n\nTO BE CONTINUED.");
    fclose(fptr);
    //TODO - add audio here
    system("cls");
}
void REnding(char* Name)
{
    FILE *fptr;
    printf("You Took The Right Path To Freedom Or Rather Your Freedom\nYou Enslaved The Entire Dungeons Population");
    system("pause");
    fptr = fopen("Misc\\Page 4.txt", "w");
    fprintf(fptr,"All Hail Our Ruler!\n\nTO BE CONTINUED.");
    fclose(fptr);
    //TODO - add audio here
    system("cls");
}
void NoEnding(char* Name)
{
    FILE *fptr;
    printf("You Died Alone In The Dungeon Under A Boulder.");
    system("pause");
    fptr = fopen("Misc\\Page 5.txt", "w");
    fprintf(fptr,"Day 64-\nIm Stuck Down Here I Cant Find My Way Out And Im Scared\nPlease Send Help\nI've Got To Run Before They Catc-");
    fclose(fptr);
    //TODO - add audio here
    system("cls");
}

// ! Casino
int casino()
{
    while(true)
    {
        int totalGamble = 0;
        printf("%iG <-- Your Gold\n\nWelcome To The Casino\n\n\n[1]Gamble ------- 10G\n\n[2]Gamble ------- 20G\n\n[3]Gamble ------- 30G\n\n[4] Custom Gamble\n\n[5] EXIT\n\nJACKPOT IS 100 GOLD", inventory[4].amount);
        int choice = scanf(" %i", &choice);
        system("cls");
        if(choice == 1 && inventory[4].amount >= 10) {totalGamble = 10;}
        else if(choice == 2 && inventory[4].amount >= 20) {totalGamble = 20;}
        else if(choice == 3 && inventory[4].amount >= 30) {totalGamble = 30;}
        else if(choice == 4)
        {
            while(true)
            {
                printf("%iG\n\nHow Much Are You Gambling?\n", inventory[4].amount);
                scanf("%i", &totalGamble);
                if(totalGamble <= inventory[4].amount)
                {
                    system("cls");
                    break;
                }
                else
                {
                printf("You Cannot Enter That Much!\n");
                system("pause && cls");
                }
            }
        }
        else if(choice == 5) {return 0;}
        else
        {
            printf("Invalid Choice!\n");
            system("pause && cls");
        }
        inventory[4].amount -= totalGamble;
        int num1 = randomNumberGen(10);
        printf("%i ",num1);
        Sleep(1000);
        int num2 = randomNumberGen(10);
        printf("%i ",num2);
        Sleep(3000);
        int num3 = randomNumberGen(10);
        printf("%i",num3);

        if(num1 == num2 && num2 == num3) {
            totalGamble *= (num1 == 10) ? 100 : 2;
            printf("\n%s", (num1 == 10) ? "YOU GOT THE JACKPOT" : "You Got a Match");
        } else if(num1 == num2 || num2 == num3 || num3 == num1) {
            totalGamble *= 1.5;
            printf("\nYou Got a Partial Match");
        } else {
            printf("Well GoodBye To All That Gold");
            totalGamble = 0;
        }
        printf("\nYou Got %i Back\n", totalGamble);
        system("pause && cls");
        inventory[4].amount += totalGamble;
    }
    return 0;
}


// ^ Main function
int main()
{
    // ^ Seed the random number generator
    srand((unsigned)time (NULL));
    int choice = 0;
    FILE *fptr;

    // ^ Main game loop
    while(true)
    {
        
        system("cls");
        //TODO - add music here
        printf("/-----------------------------\\\n");
        printf("|                             |\n");
        printf("|      The BrokenCrypt        |\n");
        printf("|                             |\n");
        printf("\\-----------------------------/\n");
        printf("\n\t[1] Play \n\t\n\t[2] Quit\n\n\t[3] Skip Intro\n");
        // * Take in user input
        choice = getche();
        system("cls");
        char* name = NULL;
        // ^ Switch to user choice
        switch(choice)
        {
            case '1': // ^ Start the game
                name = playIntro();
                gameStart(fptr, name);
                gameplay(inventory, fptr, name);
                break;
            case '2': // ^ Quit the game
                exit(0);
                break;
            case '3': // ^ Skip the intro
                name = "Player";
                gameplay(inventory, fptr, name);
                break;
            default:
                // ^ Invalid choice
                break;
        }

    }
}
