#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

#define BasePlayerHealth 100
#define HealthMax 200
#define HealthPotCost 5
#define HealthUpgradeCost 10
#define SkellyHealth 45
#define ZomboHealth 65
#define WizardHealth 25
#define ReaperHealth 45
#define MiniBossHealth 112
#define BossHealth 250

int dmgdone;
int HealthPotAmt = 3;
int Gold = 10;
int PlayerMaxHealth = BasePlayerHealth;
int PlayerHealth = BasePlayerHealth;

//RANDOM NUMBER GEN
int RandNum()
{
	int Number;
	Number = rand()%9+1;
	return Number;
}
//Casino roll check
int CasRollCheck(int num1, int num2, int num3)
{
    if(num1 == num2 && num2 != num3||num2 == num3 && num3 != num1||num3 == num1 && num1 != num2)
    {
        //give full money back plus half
        return 1;
    }
    else if(num1 == num2 && num2 == num3)
    {
        //give double back
        return 2;
    }
    else if(num1 == 10 && num2 == 10 && num3 == 10)
    {
        //Jackpot
        return 3;
    }
    else
    {
        //lost their gamble
        return 4;
    }
}
//G-RAND(GOLD RANDOM)
int EmptyGrand()
{
    int Chance;
    Chance = rand()%3+1;
    if(Chance == 1)
    {
        return 1;
    }
    if(Chance == 2)
    {
        return 2;
    }
    if(Chance == 3)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
//PLAYER DAMAGE DEALT
int PDamageDealt(int Sword)
{
    int Chance;
    int Damage = 0;
    if(Sword == 1)
    {
        Chance = rand()%29+1;
        //Player Deals More Damage
            Damage = Chance;
    }
    else
    {
        Damage = 10;
    }
    return Damage;
}
//ROLL THE RUNAWAY CHANCE FUNCTION
int RunAway()
{
    int Chance;
    Chance = rand()%4+1;
    if(Chance == 1||Chance == 2||Chance == 3||Chance == 4)
    {
        //yep
        return 2;
    }
    else if(Chance == 5);
    {
        //Nope
        return 1;
    }
}
//CHECKING IF THE PLAYER IS DEAD FUNCTION
int IsPlayerDead(int PlayerHealth)
{
    if(PlayerHealth <= 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
//THE DAMAGE FUNCTIONS FOR ALL THE ENEMIES BELOW
int ZombieDMG()
{
    int Health;
	Health = rand()%44+1;
    return Health;
}
int SkeletonDMG( int Shield)
{
    int Health;
	Health = rand()%51+1;

    if(Shield == 1)
    {
    Health /= 2;
    }
    return Health;
}
int WizardDMG(int Shield)
{
    int Health;
	Health = rand()%64+1;
	if(Shield == 1)
    {
    Health /= 2;
    }
    return Health;
}
int ReaperDMG()
{
    int Health;
	Health = rand()%47+1;
    return Health;
}
int BossDMG(int Shield)
{
    int Health;
	Health = rand()%88;
	if(Shield == 1)
    {
    Health /= 2;
    }
    return Health;
}
//GAME ENDINGS
void LEnding(char Name[50])
{
    FILE *fptr;
    system("cls");
    printf("After All Those Left Turns You Finally Left The Dungeon And Ended Up In A Even Worse Place...\n The Attic.");
    system("pause");
    fptr = fopen("Misc\\Page 3.txt", "w");
    fprintf(fptr,"Well Now You Are Stuck In The Attic With No Way Out.\n\nTO BE CONTINUED.");
    fclose(fptr);
    PlaySoundA("Audio\\Notify.wav", NULL, SND_ASYNC);
    system("cls");
}
void REnding(char Name[50])
{
    FILE *fptr;
    printf("You Took The Right Path To Freedom Or Rather Your Freedom\nYou Enslaved The Entire Dungeons Population");
    system("pause");
    fptr = fopen("Misc\\Page 4.txt", "w");
    fprintf(fptr,"All Hail Our Ruler!\n\nTO BE CONTINUED.");
    fclose(fptr);
    PlaySoundA("Audio\\Notify.wav", NULL, SND_ASYNC);
    system("cls");
}
void NoEnding(char Name[50])
{
    FILE *fptr;
    printf("You Died Alone In The Dungeon Under A Boulder.");
    system("pause");
    fptr = fopen("Misc\\Page 5.txt", "w");
    fprintf(fptr,"Day 64-\nIm Stuck Down Here I Cant Find My Way Out And Im Scared\nPlease Send Help\nI've Got To Run Before They Catc-");
    fclose(fptr);
    PlaySoundA("Audio\\Notify.wav", NULL, SND_ASYNC);
    system("cls");
}
//ALL OF THE ENEMIES FIGHTS
void ZombieFight(int PlayerHealth, int Sword, int HealthPotAmt, int PlayerMaxHealth, int Gold)
{
    int ZombieLife = ZomboHealth;
    int damagetaken = 0;
    int choice = 0;
    int dead = 0;
    char PotUse;
    int RunAway1 = 0;
    int DamageDealt;
    PlaySoundA("Audio\\megalovania.wav", NULL, SND_ASYNC);
        system("cls");
        printf("A Zombie Has Appeared!\n");
        system("pause");
        system("cls");
    do
    {
        printf("The Zombie Is Attacking!\n");
        damagetaken = ZombieDMG();
        PlayerHealth -= damagetaken;
        system("pause");
        system("cls");
        printf("You Took %d Damage!\nYou Now Have %d Health!\n", damagetaken, PlayerHealth);
        system("pause");
        dead = IsPlayerDead(PlayerHealth);
        system("cls");
        //if player health is less than or equal to 0 this triggers
        if(dead == 2)
        {
            printf("You Have %d Out Of %d Health!!!\n", PlayerHealth, PlayerMaxHealth);
            system("pause");
            system("cls");
            //revive function
            if(HealthPotAmt >= 1)
            {
                printf("You Have %d\n Use 1?\n(Y/N)\n", HealthPotAmt);
                scanf(" %c", &PotUse);
                if(PotUse == 'y'|| PotUse == 'Y')
                {
                    HealthPotAmt--;
                    PlayerHealth = PlayerMaxHealth;
                    goto action;
                }
                else
                {
                    system("cls");
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
            }
            else
            {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
            }
        }
        action:;
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", HealthPotAmt, PlayerHealth, ZombieLife);
        scanf(" %d", &choice);
        system("cls");
        if(choice == 1)
        {
            DamageDealt = PDamageDealt(Sword);
            ZombieLife -= DamageDealt;
            printf("Enemy Now Has %i Health\n", ZombieLife);
            system("pause");
            system("cls");
        }
        if(choice == 2 && HealthPotAmt >= 1)
        {
            HealthPotAmt--;
            PlayerHealth = PlayerMaxHealth;
            printf("Your Health Is Now At Its Max!\n%i\n", PlayerHealth);
            system("pause");
            system("cls");
        }
        else if(choice == 2 && HealthPotAmt == 0)
        {
            printf("You Can Not Do That!\n");
            system("pause");
            system("cls");
            goto action;
        }
        if(choice == 3)
        {
            if(RunAway1 == 1)
            {
                printf("You Already Tried To Do This And Failed.\n");
                system("pause");
                  system("cls");
                goto action;
            }
            else
            {
                RunAway1 = RunAway();
                if(RunAway1 == 1)
                {
                    printf("You Failed To Run Away But You Can Still Do Another Action.\n");
                    system("pause");
                    system("cls");
                    goto action;
                }
                else
                {
                    printf("Success!\n");
                    goto RanAway;
                }
            }
        }
    }while(ZombieLife > 0);
    RanAway:;
    PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
}
void SkeletonFight(int PlayerHealth, int Sword, int HealthPotAmt, int PlayerMaxHealth, int Gold,int Shield)
{
    int SkellyHealth1 = SkellyHealth;
    int damagetaken = 0;
    int choice = 0;
    int dead = 0;
    char PotUse;
    int RunAway1 = 0;
    int DamageDealt;
    PlaySoundA("Audio\\megalovania.wav", NULL, SND_ASYNC);
         system("cls");
        printf("A Skeleton Has Appeared!\n");
        system("pause");
        system("cls");
    do
    {
        printf("The Skeleton Is Attacking!\n");
        damagetaken = SkeletonDMG(Shield);
        PlayerHealth -= damagetaken;
        system("pause");
        system("cls");
        printf("You Took %d Damage!\nYou Now Have %d Health!\n", damagetaken, PlayerHealth);
        system("pause");
        system("cls");
        dead = IsPlayerDead(PlayerHealth);
        system("cls");
        //if player health is less than or equal to 0 this triggers
        if(dead == 2)
        {
            printf("You Have %d Out Of %d Health!!!\n", PlayerHealth, PlayerMaxHealth);
            system("pause");
            system("cls");
            //revive function
            if(HealthPotAmt >= 1)
            {
                printf("You Have %d\n Use 1?\n(Y/N)\n", HealthPotAmt);
                scanf(" %c", &PotUse);
                if(PotUse == 'y'|| PotUse == 'Y')
                {
                    HealthPotAmt--;;
                    PlayerHealth = PlayerMaxHealth;
                    goto action;
                }
                else
                {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
            }
            else
            {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
            }
        }
        action:;
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", HealthPotAmt, PlayerHealth, SkellyHealth1);
        scanf(" %d", &choice);
        system("cls");
        if(choice == 1)
        {
            DamageDealt = PDamageDealt(Sword);
            SkellyHealth1 -= DamageDealt;
            printf("Enemy Now Has %i Health\n", SkellyHealth1);
            system("pause");
            system("cls");
        }
        if(choice == 2 && HealthPotAmt >= 1)
        {
            HealthPotAmt--;
            PlayerHealth = PlayerMaxHealth;
            printf("Your Health Is Now At Its Max!\n%i\n", PlayerHealth);
            system("pause");
            system("cls");
        }
        else if(choice == 2 && HealthPotAmt == 0)
        {
            printf("You Can Not Do That!\n");
            system("pause");
            system("cls");
            goto action;
        }
        if(choice == 3)
        {
            if(RunAway1 == 1)
            {
                printf("You Already Tried To Do This And Failed.\n");
                system("pause");
                system("cls");
                goto action;
            }
            else
            {
                RunAway1 = RunAway();
                if(RunAway1 == 1)
                {
                    printf("You Failed To Run Away But You Can Still Do Another Action.\n");
                    system("pause");
                    system("cls");
                    goto action;
                }
                else
                {
                    printf("Success!\n");
                    system("pause");
                    system("cls");
                    goto RanAway;
                }
            }
        }
    }while(SkellyHealth1 > 0);
    RanAway:;
    PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
}
void WizardFight(int PlayerHealth, int Sword, int HealthPotAmt, int PlayerMaxHealth, int Gold, int Shield)
{
    int WizLife = WizardHealth;
    int damagetaken = 0;
    int choice = 0;
    int dead = 0;
    char PotUse;
    int RunAway1 = 0;
    int DamageDealt;
    PlaySoundA("Audio\\megalovania.wav", NULL, SND_ASYNC);
        system("cls");
        printf("A Wizard Has Appeared!\n");
        system("pause");
        system("cls");
    do
    {
        printf("The Wizard Is Attacking!\n");
        damagetaken = WizardDMG(Shield);
        PlayerHealth -= damagetaken;
        system("pause");
        system("cls");
        printf("You Took %d Damage!\nYou Now Have %d Health!\n", damagetaken, PlayerHealth);
        system("pause");
        dead = IsPlayerDead(PlayerHealth);
        system("cls");
        //if player health is less than or equal to 0 this triggers
        if(dead == 2)
        {
            printf("You Have %d Out Of %d Health!!!\n", PlayerHealth, PlayerMaxHealth);
            system("pause");
            system("cls");
            //revive function
            if(HealthPotAmt >= 1)
            {
                printf("You Have %d\n Use 1?\n(Y/N)\n", HealthPotAmt);
                scanf(" %c", &PotUse);
                system("cls");
                if(PotUse == 'y'|| PotUse == 'Y')
                {
                    HealthPotAmt--;
                    PlayerHealth = PlayerMaxHealth;
                }
                else
                {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
            }
            else
            {
                    printf("You Died\n!");
                    system("pause");
                    system("cls");
                    exit(0);
            }
        }
        action:;
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", HealthPotAmt, PlayerHealth, WizLife);
        scanf(" %d", &choice);
        system("cls");
        if(choice == 1)
        {
            DamageDealt = PDamageDealt(Sword);
            WizLife -= DamageDealt;
            printf("Enemy Now Has %i Health\n", WizLife);
            system("pause");
            system("cls");
        }
        if(choice == 2 && HealthPotAmt >= 1)
        {
            PlayerHealth = PlayerMaxHealth;
            HealthPotAmt--;
            printf("Your Health Is Now At Its Max!\n%i\n", PlayerHealth);
            system("pause");
            system("cls");
        }
        else if(choice == 2 && HealthPotAmt == 0)
        {
            printf("You Can Not Do That!\n");
            system("pause");
            system("cls");
            goto action;
        }
        if(choice == 3)
        {
            if(RunAway1 == 1)
            {
                printf("You Already Tried To Do This And Failed.\n");
                system("pause");
                system("cls");
                goto action;
            }
            else
            {
                RunAway1 = RunAway();
                if(RunAway1 == 1)
                {
                    printf("You Failed To Run Away But You Can Still Do Another Action.\n");
                    system("pause");
                     system("cls");
                    goto action;
                }
                else
                {
                    printf("Success!\n");
                    system("pause");
                     system("cls");
                    goto RanAway;
                }
            }
        }
    }while(WizLife > 0);
    RanAway:;
    PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
}
void ReaperFight(int PlayerHealth, int Sword, int HealthPotAmt, int PlayerMaxHealth, int Gold)
{
    int RepL = ReaperHealth;
    int damagetaken = 0;
    int choice = 0;
    int dead = 0;
    char PotUse;
    int RunAway1 = 0;
    int DamageDealt;
    PlaySoundA("Audio\\megalovania.wav", NULL, SND_ASYNC);
        system("cls");
        printf("A Reaper Has Appeared!\n");
        system("pause");
        system("cls");
    do
    {
        printf("The Reaper Is Attacking!\n");
        damagetaken = ReaperDMG();
        PlayerHealth -= damagetaken;
        system("pause");
        system("cls");
        printf("You Took %d Damage!\nYou Now Have %d Health!\n", damagetaken, PlayerHealth);
        system("pause");
        dead = IsPlayerDead(PlayerHealth);
        system("cls");
        //if player health is less than or equal to 0 this triggers
        if(dead == 2)
        {
            printf("You Have %d Out Of %d Health!!!\n", PlayerHealth, PlayerMaxHealth);
            system("pause");
            system("cls");
            //revive function
            if(HealthPotAmt >= 1)
            {
                printf("You Have %d\n Use 1?\n(Y/N)\n", HealthPotAmt);
                scanf(" %c", &PotUse);
                if(PotUse == 'y'|| PotUse == 'Y')
                {
                    PlayerHealth = PlayerMaxHealth;
                    HealthPotAmt--;
                }
                else
                {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
            }
            else
            {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
            }
        }
        action:;
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", HealthPotAmt, PlayerHealth, RepL);
        scanf(" %d", &choice);
        system("cls");
        if(choice == 1)
        {
            DamageDealt = PDamageDealt(Sword);
            RepL -= DamageDealt;
            printf("Enemy Now Has %i Health\n", RepL);
            system("pause");
            system("cls");
        }
        if(choice == 2 && HealthPotAmt >= 1)
        {
            PlayerHealth = PlayerMaxHealth;
            HealthPotAmt--;
            printf("Your Health Is Now At Its Max!\n%i\n", PlayerHealth);
            system("pause");
            system("cls");
        }
        else if(choice == 2 && HealthPotAmt == 0)
        {
            printf("You Can Not Do That!\n");
            system("pause");
            system("cls");
            goto action;
        }
        if(choice == 3)
        {
            if(RunAway1 == 1)
            {
                printf("You Already Tried To Do This And Failed.\n");
                system("pause");
                system("cls");
                goto action;
            }
            else
            {
                RunAway1 = RunAway();
                if(RunAway1 == 1)
                {
                    printf("You Failed To Run Away But You Can Still Do Another Action.\n");
                    system("pause");
                    system("cls");
                    goto action;
                }
                else
                {
                    printf("Success!\n");
                    system("pause");
                    system("cls");
                    goto RanAway;
                }
            }
        }
    }while(RepL > 0);
    RanAway:;
    PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
}
void MiniBossFight(int PlayerHealth, int Sword, int HealthPotAmt, int PlayerMaxHealth, int Gold,int Shield)
{
    int MiniBossLife = MiniBossHealth;
    int damagetaken = 0;
    int choice = 0;
    int dead = 0;
    char PotUse;
    int RunAway1 = 0;
    int DamageDealt;
    PlaySoundA("Audio\\megalovania.wav", NULL, SND_ASYNC);
        system("cls");
        printf("A Mini-Boss Has Appeared!\n");
        system("pause");
        system("cls");
    do
    {
        printf("The Mini-Boss Is Attacking!\n");
        damagetaken = BossDMG(Shield);
        PlayerHealth -= damagetaken;
        system("pause");
        system("cls");
        printf("You Took %d Damage!\nYou Now Have %d Health!\n", damagetaken, PlayerHealth);
        system("pause");
        dead = IsPlayerDead(PlayerHealth);
        system("cls");
        //if player health is less than or equal to 0 this triggers
        if(dead == 2)
        {
            printf("You Have %d Out Of %d Health!!!\n", PlayerHealth, PlayerMaxHealth);
            system("pause");
            system("cls");
            //revive function
            if(HealthPotAmt >= 1)
            {
                printf("You Have %d\n Use 1?\n(Y/N)\n", HealthPotAmt);
                scanf(" %c", &PotUse);
                if(PotUse == 'y'|| PotUse == 'Y')
                {
                    HealthPotAmt--;
                    PlayerHealth = PlayerMaxHealth;
                    goto action;
                }
                else
                {
                    system("cls");
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
            }
            else
            {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
            }
        }
        action:;
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", HealthPotAmt, PlayerHealth, MiniBossLife);
        scanf(" %d", &choice);
        system("cls");
        if(choice == 1)
        {
            DamageDealt = PDamageDealt(Sword);
            MiniBossLife -= DamageDealt;
            printf("Enemy Now Has %i Health\n", MiniBossLife);
            system("pause");
            system("cls");
        }
        if(choice == 2 && HealthPotAmt >= 1)
        {
            HealthPotAmt--;
            PlayerHealth = PlayerMaxHealth;
            printf("Your Health Is Now At Its Max!\n%i\n", PlayerHealth);
            system("pause");
            system("cls");
        }
        else if(choice == 2 && HealthPotAmt == 0)
        {
            printf("You Can Not Do That!\n");
            system("pause");
            system("cls");
            goto action;
        }
        if(choice == 3)
        {
            if(RunAway1 == 1)
            {
                printf("You Already Tried To Do This And Failed.\n");
                system("pause");
                  system("cls");
                goto action;
            }
            else
            {
                RunAway1 = RunAway();
                if(RunAway1 == 1)
                {
                    printf("You Failed To Run Away But You Can Still Do Another Action.\n");
                    system("pause");
                system("cls");
                    goto action;
                }
                else
                {
                    printf("Success!\n");
                    goto RanAway;
                }
            }
        }
    }while(MiniBossLife > 0);
    RanAway:;
    PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
}
void BossFight(int PlayerHealth, int Sword, int HealthPotAmt, int PlayerMaxHealth, int Gold,int Shield)
{
    int BossLife = BossHealth;
    int damagetaken = 0;
    int choice = 0;
    int dead = 0;
    char PotUse;
    int RunAway1 = 0;
    int DamageDealt;
    PlaySoundA("Audio\\megalovania.wav", NULL, SND_ASYNC);
        system("cls");
        printf("Mythrax Has Appeared!\n");
        system("pause");
        system("cls");
    do
    {
        printf("Mythrax Is Attacking!\n");
        damagetaken = BossDMG(Shield);
        PlayerHealth -= damagetaken;
        system("pause");
        system("cls");
        printf("You Took %d Damage!\nYou Now Have %d Health!\n", damagetaken, PlayerHealth);
        system("pause");
        dead = IsPlayerDead(PlayerHealth);
        system("cls");
        //if player health is less than or equal to 0 this triggers
        if(dead == 2)
        {
            printf("You Have %d Out Of %d Health!!!\n", PlayerHealth, PlayerMaxHealth);
            system("pause");
            system("cls");
            //revive function
            if(HealthPotAmt >= 1)
            {
                printf("You Have %d\n Use 1?\n(Y/N)\n", HealthPotAmt);
                scanf(" %c", &PotUse);
                if(PotUse == 'y'|| PotUse == 'Y')
                {
                    HealthPotAmt--;
                    PlayerHealth = PlayerMaxHealth;
                    goto action;
                }
                else
                {
                    system("cls");
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
                }
            }
            else
            {
                    printf("You Died!\n");
                    system("pause");
                    system("cls");
                    exit(0);
            }
        }
        action:;
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", HealthPotAmt, PlayerHealth, BossLife);
        scanf(" %d", &choice);
        system("cls");
        if(choice == 1)
        {
            DamageDealt = PDamageDealt(Sword);
            BossLife -= DamageDealt;
            printf("Enemy Now Has %i Health\n", BossLife);
            system("pause");
            system("cls");
        }
        if(choice == 2 && HealthPotAmt >= 1)
        {
            HealthPotAmt--;
            PlayerHealth = PlayerMaxHealth;
            printf("Your Health Is Now At Its Max!\n%i\n", PlayerHealth);
            system("pause");
            system("cls");
        }
        else if(choice == 2 && HealthPotAmt == 0)
        {
            printf("You Can Not Do That!\n");
            system("pause");
            system("cls");
            goto action;
        }
        if(choice == 3)
        {
            if(RunAway1 == 1)
            {
                printf("You Already Tried To Do This And Failed.\n");
                system("pause");
                  system("cls");
                goto action;
            }
            else
            {
                RunAway1 = RunAway();
                if(RunAway1 == 1)
                {
                    printf("You Failed To Run Away But You Can Still Do Another Action.\n");
                    system("pause");
                system("cls");
                    goto action;
                }
                else
                {
                    printf("Success!\n");
                    goto RanAway;
                }
            }
        }
    }while(BossLife > 0);
    RanAway:;
    PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
}
//THE STORE FUNCTION WHERE THE PLAYER CAN BUY A HEALTH UPGRADE OR A HEALTH POTION
int Store(int MaxPlayerHealth, int Gold, int HealthPotAmt)
{
    system("cls");
    int Purchased = 0;
    int choice;
    shop:
    system("cls");
    printf("%iG\n\n[1]Health Pot ------ 10G\n[2]Heart Crystal ------ 30G\n[3] Exit Shop\n\n If You Exit The Shop You Can Not Return\n\n", Gold);
    scanf(" %d", &choice);
    system("cls");
        if(choice == 1)
        {
            if(Gold >= 10)
            {
                Gold -= 10;
                Purchased = 1;
            }
            else
            {
                goto shop;
            }
        }
        else if(choice == 2)
        {
            if(Gold >= 30 && MaxPlayerHealth <= 200)
            {
                printf("+25 Health\n", MaxPlayerHealth);
                system("pause");
                system("cls");
                //Bought Health Upgrade
                Gold -= 30;
                Purchased = 2;
            }
            else
            {
                goto shop;
            }
        }
        else
        {
            system("cls");
        }
    system("cls");
    return Purchased;
}
int Casino(int MaxPlayerHealth, int Gold, int HealthPotAmt)
{
    
}
//PLAYER CAN GET A SWORD SHIELD OR HEALTH POTION HERE
int LootRoom(int Sword, int Shield, int HealthPotAmt)
{
    int choice = 0;
    int Item;
    if(Sword == 0)
    {
        system("cls");
        printf("[1] You Found A Sword\n");
        if(Shield == 0)
        {
            printf("[2] You Found A Shield\n");
            printf("[3] You Found A Health Pot\n\nONCE YOU CHOOSE AN ITEM YOU CANNOT COME BACK UNTIL YOU FIND ANOTHER ROOM\n\n");
            scanf(" %d", &choice);
            if(choice == 1)
            {
                Item = 1;
            }
            else if(choice == 2)
            {
                Item = 2;
            }
            else
            {
                Item = 3;
            }
        }
        else
        {
            printf("[2] You Found A Health Pot\n\nONCE YOU CHOOSE AN ITEM YOU CANNOT COME BACK UNTIL YOU FIND ANOTHER ROOM\n\n");
            scanf(" %d", &choice);
            if(choice == 1)
            {
                Item = 1;
            }
            else
            {
                Item = 3;
            }

        }
    }
    else if(Shield == 0)
    {
        printf("[1] You Found A Shield\n");
        printf("[2] You Found A Health Pot\n\nONCE YOU CHOOSE AN ITEM YOU CANNOT COME BACK UNTIL YOU FIND ANOTHER ROOM\n\n");
            scanf(" %d", &choice);
            system("cls");
            if(choice == 1)
            {
                Item = 2;
            }
            else
            {
                Item = 3;
            }
    }
    else
    {
        system("cls");
        printf("You Already Have All The Items You Can Get From A Loot Room So Heres A Health Pot!\n");
        system("pause");
        system("cls");
        Item = 3;
    }
    system("cls");
    return Item;
}
//ROLLS WHETHER OR NOT YOU GET AN ENCOUNTER
int EncounterChance(int Encounterchance)
{
    int Chance;
    Chance = rand()%11+1;

    if(Chance <= 10)
    {
        //Encounter True
        return 1;
    }

    if(Chance >= 11)
    {
        //Encounter False
        return 2;
    }
}
//WHICH ENCOUNTER ARE YOU GETTING
int EncounterRoll(int EnemyRolled)
{
    int rolled;

    rolled = rand()%7+1;
    if(rolled == 1)
    {
        //No Enemy
        return 1;
    }
    else if(rolled == 2)
    {
        // Skeleton
        return 2;
    }
    else if(rolled == 3)
    {
        //wizard
        return 3;
    }
    else if(rolled == 4)
    {
        //shop
        return 4;
    }
    else if(rolled == 5)
    {
        //reaper
        return 5;
    }
    else if(rolled == 6);
    {
        //Loot Room
        return 6;
    }
    if(rolled == 7)
    {
        //zombie
        return 7;
    }
    else if(rolled == 8)
    {
        //miniboss
        return 8;
    }


}
//creating a random amount of rooms roll
    int RollRooms()
    {
        int chance;
        chance = rand()%6+1;

        if(chance == 1)
        {
            //straight
            return 1;
        }
        if(chance == 2)
        {
            //left
            return 2;
        }
        if(chance == 3)
        {
            //right
            return 3;
        }
        if(chance == 4)
        {
            //left straight
            return 4;
        }
        if(chance == 5)
        {
            //right straight
            return 5;
        }
        if(chance == 6)
        {
            //left right
            return 6;
        }
        if(chance == 7)
        {
            //left right straight
            return 7;
        }
    }


int main()
{
    srand((unsigned)time (NULL));
    int choice = 0;
    int FirstItem = 0;
    int knife = 0;
    int EnemyRolled = 0;
    char Kitchen;
    int Kills = 0;
    int AmIDead = 0;
    char Vid1[] = "Videos\\Fall.mp4";
    char child2[BUFSIZ];
    char GoodOrBad;
    int Encounterchance;
    int Shield = 0;
    int Sword = 0;
    char FirstRoom;
    int valid = 0;
    int LTurns = 0;
    int RTurns = 0;
    int NoTurns = 0;
    int RolledRoom = 0;
    char DirectionChoice1;
    char DirectionChoice2;
    char DirectionChoice3;
    char DirectionChoice4;
    int grand;

    FILE *fptr;

    char Name[10000];

    while(choice != 2)
    {
        system("cls");
        PlaySoundA("Audio\\Theme.wav", NULL, SND_ASYNC);
    printf("/-----------------------------\\\n");
    printf("|                             |\n");
    printf("|      The BrokenCrypt        |\n");
    printf("|                             |\n");
    printf("\\-----------------------------/\n");
    printf("\n\t[1] Play \n\t\n\t[2] Quit\n\n\t[3] Skip Intro\n\n\n RATED M FOR MATURE");//PLAYER CAN HIT 3 TO HERE A JOKE I ADDED || HIT 4 TO SKIP THE WHOLE INTRO SEQUENCE
    choice = getche();
    switch(choice)
    {
    case '1':
    {
        //UNTIL LINE 1070 THIS IS JUST THE INTRO SEQUENCE TO THE GAME
        Gold = 10;
        //my line of code to play audio
        PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
        system("cls");
        //Intro Sequence
        printf("BEST EXPERIENCED WITH HEADPHONES");
        sleep(3);
        system("cls");
        printf("Welcome Traveller To BrokenLane");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        system("cls");
        printf("What Should We Call You?\n");
        gets(Name);
        system("cls");
        printf("Welcome T▒ Our W▒n▒erf▒l Wor▒d Of BrokenLane %s\n", Name);
        system("pause");
        system("cls");
        PlaySoundA("Audio\\Gungun.wav", NULL, SND_ASYNC);
        sleep(3);
        PlaySoundA("Audio\\Cough.wav", NULL, SND_ASYNC);
        printf("Phew. Who Would Have Thought A Bullet Wound To That Annoying Pricks Head Would Be So Gross?\nAnyway Now That Your Here Lets Begin.\n");
        system("pause");
        system("cls");
        printf("You Really Thought You Could Play A Simple Story?\n");
        sleep(2.5);
        system("pause");
        system("cls");
        PlaySoundA("Audio\\Intro.wav", NULL, SND_ASYNC);
        sleep(4);
        printf("\n\n\t\tA No Name Studios Game");
        sleep(4);
        system("cls");
        printf("\n\n\t\tPublished By WHY IS THIS IN MY ATTIC?");
        sleep(4);
        system("cls");
        printf("\n\n\t\tIn Collaboration With Da Baby");
        sleep(4);
        system("cls");
        printf("\n\n\t\tMADE IN THE UNITY ENGINE");
        sleep(4);
        system("cls");
        printf("\n\n\t\tA Royalty Filled Game\n\n\tYeah No Revenue Was Made Here B^)");
        sleep(4);
        system("cls");
        printf("\n\n\t\tDeveloped By Nick");
        sleep(4);
        system("cls");
        printf("\n\n\t\tALL RIGHTS RESERVED");
        sleep(4);
        system("cls");
        printf("\n\n\t\tThe BrokenCrypt");
        sleep(8);
        system("cls");
         PlaySoundA("Audio\\SpeechIntro.wav", NULL, SND_ASYNC);
         sleep(20);
         printf("           ^\n");
         printf("          | |\n");
         printf("          | |\n");
         printf("          | |\n");
         printf("          | |\n");
         printf("       0-------0\n");
         printf("           |\n");
         printf("           0\n");
         printf("Item Gained.");
         knife ++;
         sleep(4);
         system("cls");
         sleep(20);

        //Start Game.
        {
             printf("Hey %s Wake Up!\n\t\t\n", Name);
             system("Pause");
             system("cls");
             printf("I guess it was all just a dream....");
             sleep(1);
             printf("\nWell since im up I might aswell go get some breakfast.\n");
             printf("|-------------------------|\n");
             printf("|  /-/               *  0 | \n");
             printf("| /-/         ___         |\n");
             printf("|/-/       [] ' '         |\n");
             printf("|-------------------------|\n");
             system("pause");
             system("cls");
             printf("*You Walk Downstairs*\n");
             PlaySoundA("Audio\\Stepstirs.wav", NULL, SND_ASYNC);
             sleep(10);
             system("cls");
             printf("*You Smell Pancakes*\n");
             system("Pause");
             system("cls");
             printf("Do You Want To Go Get Breakfast?   (Y/N)\n");
             scanf(" %c", &Kitchen);
             //Thats right I gave the user the illusion of choice

             if(Kitchen == 'Y'|| Kitchen == 'y')
             {
                 system("cls");
                 printf("You Walk To The Kitchen.");
             }
             else
             {
                 system("cls");
                 printf("You Decide You Should Go Anyway.");
             }
             printf("\nBut As You Walk You Notice The Floor Boards Creaking.\nWhen Suddenly You Hear A Snap And Begin To Fall\n");
             system("Pause");
             system("cls");
             //fall video
             system (Vid1);
             strcpy (child2, "Videos\\Fall.mp4");
             strcat (child2, " -aparm -b");
             sleep(29);
             system("Pause");
             /* open for writing */
             fptr = fopen("Misc\\Page 1.txt", "w");
             printf("Do You Deserve This?\n");
             sleep(3);
             system("cls");
             fprintf(fptr, "When %s Fell They Began To Realize The Amount Of Bad Things They Had Done\nHad They Really Deserved This?\nMaybe This Was The Best Thing For Them\nAfter All", Name);
             system("pause");
             printf("Are You A Good Person?\n(Y/N)\n");
             scanf(" %c", &GoodOrBad);
             if(GoodOrBad == 'Y'||GoodOrBad == 'y')
             {
              fprintf(fptr," They Werent Exactly A Jackass Throughout Their Life.");
             }
             else
             {
                fprintf(fptr," They Were Voted The Biggest Jackass In High School.");
             }
             fclose(fptr);
             PlaySoundA("Audio\\Notify.wav", NULL, SND_ASYNC);
             /*closed file using me saying BOOP as a hint that a file was made in the MISC directory*/
             system("pause");
             system("cls");
             PlaySoundA("Audio\\Thump.wav", NULL, SND_ASYNC);
             sleep(2);
             printf("%s Found Themself At A Stone Gate Deep Underground With A Sign OverHead That Read '▒▒▒▒▒' \nUnderneath A Sign In English Read 'The BrokenCrypt\n\n", Name);
             printf("/-----------------------------\\\n");
             printf("|                             |\n");
             printf("|       The BrokenCrypt       |\n");
             printf("|                             |\n");
             printf("\\-----------------------------/\n");
             sleep(2);
             system("pause");
             system("cls");
             printf("You Decide To Enter");
             PlaySoundA("Audio\\Stepstirs.wav", NULL, SND_ASYNC);
             sleep(1);
             printf(".");
             sleep(1);
             printf(".");
             sleep(1);
             printf(".");
             sleep(2);
             system("cls");
             PlaySoundA("Audio\\StopSound.wav", NULL, SND_ASYNC);
             printf("%s Began To Wonder What This Place Was And How It Had\nBeen Under Their House All This Time Without Them Knowing\n", Name);
             system("pause");
        }
            skip:
            {
            sleep(2);
            system("cls");
            Encounterchance = EncounterChance(Encounterchance);

            if(Encounterchance == 1)
            {
                do
                {
                    EnemyRolled = EncounterRoll(EnemyRolled);

                } while(EnemyRolled == 7);

                //Calling Each Encounter
                if(EnemyRolled == 1)
                {
                    //rolled no enemy
                    printf("You Got Lucky!\n Although Noises Were Coming From This Room Nothing Is Here\n +7 Gold\n");
                    Gold += 7;
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 2)
                {
                    //Rolled Skeleton
                    SkeletonFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold, Shield);
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 3)
                {
                    //rolled A Wizard;
                    WizardFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold, Shield);
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 4)
                {
                    //Rolled A ZOmbie
                    ZombieFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold);
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 5)
                {
                    //Rolled A Reaper
                    ReaperFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold);
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 6)
                {
                    //Rolled Loot Room
                    FirstItem = LootRoom(Sword, Shield, HealthPotAmt);
                    //sword added
                    if(FirstItem == 1)
                    {
                        Sword = 1;
                    }
                    else if(FirstItem == 2)
                    {
                        Shield = 1;
                    }
                    else
                    {
                        HealthPotAmt ++;
                    }
                }
            }

            else if(Encounterchance == 2)
            {
                //rolled false encounter
                printf("You Found A Pouch Of Gold\nIt Has 7 Gold\n");
                system("pause");
                system("cls");
                Gold += 7;
                printf("You Have %i Gold.\n", Gold);
                system("pause");
                system("cls");
            }
            }
            fptr = fopen("Misc\\Page 2.txt", "w");
            fprintf(fptr, "When %s Entered The First Room They Realized How Little Was In It,\nThe Room Had Almost No Loot, Skeletons Chained To The Walls,\nAnd By Nothing I(The Narrator) Mean Almost No Spiders\nIN A UNDERGROUND DUNGEON!?!?\n\nPage 2", Name);
            fclose(fptr);
            PlaySoundA("Audio\\Notify.wav", NULL, SND_ASYNC);
            system("cls");
            //CHANGE THIS IF YOU WANT A LONGER  {VV}/SHORTER EXPERIENCE
            for(int TotalTurns = 0;TotalTurns <= 20; TotalTurns++)
            {
                RolledRoom = RollRooms();
                if(RolledRoom == 1)
                {
                    //straight
                    printf("There Is Only One Path Out Of This Room.\n");
                    system("pause");
                    system("cls");
                    printf("You Go Straight\n");
                    system("pause");
                    system("cls");
                    NoTurns ++;
                }
                if(RolledRoom == 2)
                {
                    //left
                    printf("There Is Only One Path Out Of This Room.\n");
                    system("pause");
                    system("cls");
                    printf("You Go Left\n");
                    system("pause");
                    system("cls");
                    LTurns ++;
                }
                if(RolledRoom == 3)
                {
                    //right
                    printf("There Is Only One Path Out Of This Room.\n");
                    system("pause");
                    system("cls");
                    printf("You Go Right\n");
                    system("pause");
                    system("cls");
                    RTurns ++;
                }
                if(RolledRoom == 4)
                {
                    //left straight
                    printf("There Are 2 Paths Out Of This Room\n (L/S)\n");
                    scanf(" %c", &DirectionChoice1);
                    system("cls");
                    switch(DirectionChoice1)
                    {
                        case 'L':
                        case 'l':
                        {
                            LTurns ++;
                        }
                        case 'S':
                        case 's':
                        {
                            NoTurns ++;
                        }
                    }
                }
                if(RolledRoom == 5)
                {
                    //right straight
                    printf("There Are 2 Paths Out Of This Room\n (R/S)\n");
                    scanf(" %c", &DirectionChoice2);
                    system("cls");
                    switch(DirectionChoice2)
                    {
                        case 'R':
                        case 'r':
                        {
                            RTurns ++;
                        }
                        case 'S':
                        case 's':
                        {
                            NoTurns ++;
                        }
                    }
                }
                if(RolledRoom == 6)
                {
                    //left right
                    printf("There Are 2 Paths Out Of This Room\n (L/R)\n");
                    scanf(" %c", &DirectionChoice3);
                    system("cls");
                    switch(DirectionChoice3)
                    {
                        case 'L':
                        case 'l':
                        {
                            LTurns ++;
                        }
                        case 'R':
                        case 'r':
                        {
                            RTurns ++;
                        }
                    }
                }
                if(RolledRoom == 7)
                {
                    //left right straight
                    printf("There Are 3 Paths Out Of This Room\n (L/R/S)\n");
                    scanf(" %c", &DirectionChoice4);
                    system("cls");
                    switch(DirectionChoice4)
                    {
                        case 'L':
                        case 'l':
                        {
                            LTurns ++;
                        }
                        case 'R':
                        case 'r':
                        {
                            RTurns ++;
                        }
                        case 'S':
                        case 's':
                        {
                            NoTurns ++;
                        }
                    }
                }
            Encounterchance = EncounterChance(Encounterchance);

            if(Encounterchance == 1)
            {

                    EnemyRolled = EncounterRoll(EnemyRolled);



                //Calling Each Encounter
                if(EnemyRolled == 1)
                {
                    //rolled no enemy
                    printf("You Got Lucky!\n Although Noises Were Coming From This Room Nothing Is Here\n +7 Gold\n");
                    Gold += 7;
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 2)
                {
                    //Rolled Skeleton
                    SkeletonFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold, Shield);
                    Gold += 10;
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 3)
                {
                    //rolled A Wizard;
                    WizardFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold, Shield);
                    Gold += 10;
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 7)
                {
                    //Rolled A ZOmbie
                    ZombieFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold);
                    Gold += 10;
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 5)
                {
                    //Rolled A Reaper
                    ReaperFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold);
                    Gold += 10;
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 6)
                {
                    //Rolled Loot Room
                    FirstItem = LootRoom(Sword, Shield, HealthPotAmt);
                    //sword added
                    if(FirstItem == 1)
                    {
                        Sword = 1;
                    }
                    else if(FirstItem == 2)
                    {
                        Shield = 1;
                    }
                    else
                    {
                        HealthPotAmt ++;
                    }

                }
                if(EnemyRolled == 8)
                {
                    //rolled A MiniBoss;
                    MiniBossFight(PlayerHealth,Sword,HealthPotAmt,PlayerMaxHealth,Gold, Shield);
                    Gold += 50;
                    printf("You Now Have %i Gold\n", Gold);
                    system("pause");
                    system("cls");
                }
                if(EnemyRolled == 4)
                {
                    //store
                    FirstItem = Store(PlayerMaxHealth, Gold, HealthPotAmt);
                    if(FirstItem == 1)
                    {
                        HealthPotAmt ++;
                        printf("You Have %i Health Potions\n", HealthPotAmt);
                        system("pause");
                        system("cls");
                    }
                    if(FirstItem == 2)
                    {
                        PlayerMaxHealth += 25;
                        PlayerHealth = PlayerMaxHealth;
                        printf("Your New Maximum Health Is %i\n", PlayerMaxHealth);
                        system("pause");
                        system("cls");
                    }
                }

            }

            else if(Encounterchance == 2)
            {
                //rolled false encounter
                grand = EmptyGrand();
                if(grand == 1)
                {
                    grand = 7;
                }
                if(grand == 2)
                {
                    grand = 8;
                }
                if(grand == 3)
                {
                    grand = 12;
                }
                if(grand == 4)
                {
                    grand == 5;
                }

                Gold += grand;
                printf("You Found A Pouch Of Gold\nIt Has %i Gold\n", grand);
                system("pause");
                system("cls");
                printf("You Have %i Gold.\n", Gold);
                system("pause");
                system("cls");
            }
            }
            skipalot:;
            system("cls");
            int Choice;
            shop:;
            system("cls");
            printf("%iG\n\n[1] Heart Crystal 30G\n\n[2] Casino\n[3] Exit Shop\n\n If You Exit The Casino You Can Not Return\n\n", Gold);
            scanf(" %d", &Choice);
            system("cls");
                if(Choice == 1)
                {
                    if(Gold >= 30 && PlayerMaxHealth <= 225)
                    {
                        printf("+25 Health\n");
                        PlayerMaxHealth += 25;
                        PlayerHealth = PlayerMaxHealth;
                        system("pause");
                        system("cls");
                        //Bought Health Upgrade
                        Gold -= 30;
                        goto shop;
                    }
                    else
                    {
                        goto shop;
                    }
                }
                else if(Choice == 2)
                {
                    int num1;
                    int num2;
                    int num3;
                    int choice;
                    int Rolled;
                    int Gamble = 0;
                    casino:;
                    Gamble = 0;
                    printf("%iG <-- Your Gold\n\nWelcome To The Casino\n\n\n[1]Gamble ------- 10G\n\n[2]Gamble ------- 20G\n\n[3]Gamble ------- 30G\n\n[4] Custom Gamble\n\n[5] EXIT\n\nJACKPOT IS 100 GOLD", Gold);
                    scanf(" %i", &choice);
                    system("cls");
                    if(choice == 1 && Gold >= 10)
                    {
                        Gamble = 10;
                    }
                    else if(choice == 2 && Gold >= 20)
                    {
                        Gamble = 20;
                    }
                    else if(choice == 3 && Gold >= 30)
                    {
                        Gamble = 30;
                    }
                    else if(choice == 4)
                    {
                        valid:;
                        printf("%iG\n\nHow Much Are You Gambling?\n", Gold);
                        scanf("%i", &Gamble);
                        if(Gamble <= Gold)
                        {
                            system("cls");
                        }
                        else
                        {
                        printf("You Cannot Enter That Much!\n");
                        goto valid;
                        }
                    }
                    else if(choice == 5)
                    {
                        goto shop;
                    }
                    else
                    {
                        system("cls");
                        goto casino;
                    }
                     num1 = RandNum();
                     printf("%i ",num1);
                     sleep(1);
                     num2 = RandNum();
                     printf("%i ",num2);
                     sleep(1);
                     num3 = RandNum();
                     printf("%i",num3);

                     Rolled = CasRollCheck(num1, num2, num3);

                     if(Rolled == 1)
                     {
                         Gamble *= 1.5;
                         printf("\nYou Got %i Back\n", Gamble);
                         system("pause");
                         system("cls");
                         Gold += Gamble;
                     }
                     else if(Rolled == 2)
                     {
                         Gamble *= 2;
                         printf("\nYou Got %i Back\n", Gamble);
                         system("pause");
                         system("cls");
                         Gold += Gamble;
                     }
                     else if(Rolled == 3)
                     {
                         Gamble *= 100;
                         printf("\nYOU GOT THE JACKPOT");
                         printf("\nYou Got %i Back\n", Gamble);
                         system("pause");
                         system("cls");
                         Gold += Gamble;
                     }
                     else
                     {
                         printf("Well GoodBye To All That Gold");
                         Gold -= Gamble;
                         system("pause");
                         system("cls");
                     }

                     goto casino;
                }
                else
                {
                    system("cls");
                }
            system("cls");
            system("pause");
            system("cls");
            BossFight(PlayerHealth,Sword, HealthPotAmt, PlayerMaxHealth,  Gold, Shield);
            system("cls");
            if(LTurns > RTurns && LTurns > NoTurns)
            {
                LEnding(Name);
            }
            else if(RTurns > LTurns && RTurns > NoTurns)
            {
                REnding(Name);
            }
            else if(NoTurns > LTurns && NoTurns > RTurns)
            {
                NoEnding(Name);
            }
            else if(NoTurns == LTurns && NoTurns == RTurns)
            {
                system("cls");
                printf("Your Lost Forever\n");
                system("pause");
                system("cls");
            }
            break;
    }

    case '2':
    {
        //THE EXIT THE GAME FUNCTION.
        system("cls");
        exit(0);
    }
    case '4':
    {
        //meme
        system("cls");
        PlaySoundA("Audio\\Death.wav", NULL, SND_ASYNC);
        sleep(3);
        break;
    }
    case '3':
    {
        //skip to the start of the fighting half of the game for testing purposes
        // i was losing my mind going through the whole game every time :)
        //DEBUG
        system("cls");
        printf("What Should We Call You?\n");
        gets(Name);
        system("cls");
        goto skip;
    }
    case '.':
    {
        //Made This To Test Out The Ending Stuff
        Gold += 2000;
        goto skipalot;
    }
    }
    }
}
/*         _
       .__(.)< (MEOW)
        \___)
 ~~~~~~~~~~~~~~~~~~~~~~~*/
