#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#ifdef _WIN32
    #include<windows.h>
#else
    #include<unistd.h>
#endif


#define RESET   "\033[0m"  
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

void print_list();
void print_choice_of_user(int);
void print_choice_of_random(int);
void clear_screen();

int main()
{    
    clear_screen();
    int choice_by_user, choice_by_random;
    int user_score = 0, bot_score = 0, draws = 0;
    while(1){
        srand(time(0));
        choice_by_random=(rand()%3)+1;
    
        print_list();
        int valid=scanf("%d",&choice_by_user);
        
        if(valid!=1 || choice_by_user<1 || choice_by_user>3){
            printf("\n Invalid Input !! Retry :)");
            printf("\n___________________________________________________");
            while(getchar() != '\n');
            
        }else{
              print_choice_of_user(choice_by_user);
              printf("\n Revealing the bot's move");
              for (int i = 0; i < 3; i++) {
                    printf(" .");
                    fflush(stdout);
                    #ifdef _WIN32
                        Sleep(1000);
                    #else
                        sleep(1);
                    #endif

              }
              printf("\n Bot Chooses : ");
              print_choice_of_random(choice_by_random);
              
              
                  if (choice_by_user == choice_by_random) {
                    printf(YELLOW"\n\n It's a Draw!"RESET);
                    draws++;
                  }else if 
                    ((choice_by_user == 1 && choice_by_random == 3) || 
                    (choice_by_user == 2 && choice_by_random == 1) || 
                    (choice_by_user == 3 && choice_by_random == 2)) {
                
                        printf(GREEN"\n\n Bingo You Win!"RESET);
                        user_score++;
                    } else {
                        printf(RED"\n\n You Lose!"RESET);
                        bot_score++;
                    }
                    
                    
                    printf(CYAN"\n\n Scores"RESET": You - %d | Bot - %d | Draws - %d", user_score, bot_score, draws);
                    
              char play_again;
              printf("\n\n Press (e/E) to exit the game : ");
              while (getchar() != '\n');
              scanf(" %c", &play_again);

             if (play_again == 'e' || play_again == 'E') {
                printf(YELLOW"\n Thanks for playing"RESET"!"CYAN" Goodbye!"RESET);
                printf("\n Developed by @"RED"Dipayan\n"RESET);
                break; 
             }else{
                clear_screen();
                printf(CYAN"\n\n Scores"RESET": You - %d | Bot - %d | Draws - %d", user_score, bot_score, draws);
             }
                    
        }
        
    }
    
    return 0;
}

void print_list(){
    printf(CYAN"\n\n\n \t \tWELCOME"RESET);
    printf("\n \t \t  TO");
    printf(MAGENTA"\n\t  ROCK"YELLOW" PAPER"RED" SCISSOR"RESET);
    printf(BLUE"\n \n \n Choose Your Move "WHITE"\n FOR"MAGENTA" ROCK(1) "WHITE"\n FOR "YELLOW"PAPER(2) "WHITE"\n FOR "RED"SCISSOR(3) "WHITE"\n \nENTER YOUR MOVE : "RESET);
}

void print_choice_of_user(int choice_by_user){
    
    if(choice_by_user==1)
    printf("\n \n Your Choice : "MAGENTA"ROCK"RESET);
    else if(choice_by_user==2)
    printf("\n \n Your Choice : "YELLOW"PAPER"RESET);
    else if(choice_by_user==3)
    printf("\n \n Your Choice : "RED"SCISSOR"RESET);
}

void print_choice_of_random(int choice_by_random){

    if(choice_by_random==1){
    #ifdef _WIN32
        Sleep(1000);
    #else
        sleep(1);
    #endif

    printf(MAGENTA"ROCK"RESET);}
    else if(choice_by_random==2){
    #ifdef _WIN32
        Sleep(1000);
    #else
        sleep(1);
    #endif

    printf(YELLOW"PAPER"RESET);}
    else if(choice_by_random==3){
    #ifdef _WIN32
    Sleep(1000);
#else
    sleep(1);
#endif

    printf(RED"SCISSOR"RESET);}
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
