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

// ^ Main function
int main()
{
    // ^ Seed the random number generator
    srand((unsigned)time (NULL));
    int choice = 0;
    // ^ Dictionary to store item names and their costs
    struct Item {
        char name[20];
        int cost;
    };
    // * The players inventory
    struct Item invetory[] = {
        {"Health Potion", 3}, 
        {"Sword", 0},
        {"Knife", 0},
        {"Shield", 0},
        {"Gold", 10} // ^ Starting Gold Amount
        };
    
    char name[50];

}