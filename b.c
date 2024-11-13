int ZombieFight(int PlayerHealth, int Sword, int HealthPots, int PlayerMaxHealth, int Gold)
{
    int ZombieLife = ZomboHealth;
    int damagetaken = 0;
    int choice = 0;
    int dead = 0;
    char PotUse;
    int RunAway1;
    PlaySoundA("Audio\\megalovania.wav", NULL, SND_ASYNC);
    
    do
    {
        system("cls");
        printf("A Zombie Has Appeared!");
        system("pause");
        system("cls");
        printf("The Zombie Is Attacking!\n");
        damagetaken = PlayerHealthDamageRoll(damagetaken);
        PlayerHealth = PlayerHealth - damagetaken;
        system("pause");
        printf("You Took %d Damage!\nYou Now Have %d Health!", damagetaken, PlayerHealth);
        dead = IsPlayerDead(PlayerHealth);
        system("cls");
        //if player health is less than or equal to 0 this triggers
        if(dead == 1)
        {
            printf("You Have %d Out Of %d Health!!!\n", PlayerHealth, PlayerMaxHealth);
            //revive function
            if(HealthPots >= 1)
            {
                printf("You Have %d\n Use 1?\n(Y/N)\n", HealthPots);
                scanf(" %c", PotUse);
                if(PotUse == 'y'|| PotUse == 'Y')
                {
                    PlayerHealth = PlayerMaxHealth;
                }
                else
                {
                    printf("You Died!");
                    system("pause");
                    system("cls");
                    exit(0);
                }
            }
            else
            {
                    printf("You Died!");
                    system("pause");
                    system("cls");
                    exit(0);
            }
        }
        action:
        {
        system("pause");
        system("cls");
        printf("[1]Attack!\n[2]Heal! %d Remaining\n[3]Run Away You Coward!\nYour Health %d\n Their Health %d\n\n", HealthPots, PlayerHealth, ZombieLife);
        scanf(" %d", &choice);
        system("cls");
        }
        if(choice == 1)
        {
            //checking what weapon player has
            if(Sword == 1)
            {
                
            }
            else
            {
                
            }
        }
        if(choice == 2 && HealthPots >= 1)
        {
            PlayerHealth = PlayerMaxHealth;
            printf("Your Health Is Now At Its Max!\n%i", PlayerHealth);
        }
        else if(choice == 2 && HealthPots == 0)
        {
            printf("You Can Not Do That!");
            goto action;
        }
        if(choice == 3)
        {
            if(RunAway1 == 1)
            {
                printf("You Already Tried To Do This And Failed.");
                goto action;
            }
            else
            {
                RunAway1 = RunAway();
                if(RunAway1 == 1)
                {
                    printf("You Failed To Run Away But You Can Still Do Another Action.");
                    goto action;
                }
                else
                {
                    printf("Success!");
                    goto RanAway;
                }
            }
        }   
    }while(ZombieLife > 0);
    RanAway:
    {
        Gold = Gold + 10;
    }
    return Gold;
}