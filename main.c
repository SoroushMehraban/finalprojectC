#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#define color(a); SetConsoleTextAttribute(color, a)

struct decision {
        char context[200];
        int people;
        int court;
        int treasury;
    };
struct node{
    char problem[200];
    struct decision first;
    struct decision second;
    struct node *next;
};
struct user {
    char name[50];
    int people;
    int court;
    int treasury;
};
void ASCII_art(int num){
    HANDLE  color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    switch(num){
        case 0:
            color(14);
            printf("                    .\n"
                   "                   / \\ \n"
                   "                  _\\ /_ \n"
                   "        .     .  (,'v`.)  .     . \n"
                   "        \\)   ( )  ,' `.  ( )   (/ \n"
                   "         \\`. / `-'     `-' \\ ,'/ \n"
                   "          : '    _______    ' : \n"
                   "          |  _,-'  ,-.  `-._  | \n"
                   "          |,' ( )__`-'__( ) `.| \n"
                   "          (|,-,'-._   _.-`.-.|) \n");
            color(15);
            printf("          /  /");
            color(15);
            printf("<( o)> <( o)>");
            color(15);
            printf("\\  \\ \n          :  :     ");
            color(15);
            printf("| |     ");
            color(15);
            printf(":  : \n          |  |     ");
            color(15);
            printf("; :     ");
            color(15);
            printf("|  | \n          |  |    ");
            color(15);
            printf("(.-.)    ");
            color(15);
            printf("|  | \n          |  |  ");
            color(15);
            printf(",' ___ `.  ");
            color(15);
            printf("|  | \n          ;  |");
            color(15);
            printf(")/ ,'---'. \\(");
            color(15);
            printf("|  : \n")
            color(4);
            printf("      _,-/   ");
            color(15);
            printf("|/\\(       )/\\|   ");
            color(4);
            printf("\\-._ \n_..--'.-(    ");
            color(15);
            printf("|   `-'''-'   |    ");
            color(4);
            printf(")-.`--.._ \n         `.  ;");
            color(15);
            printf("`._________,'");
            color(4);
            printf(":  ,' \n        ,' `/               \\'`. \n             `------.------' \n                    ' \n");
            color(14);
            break;
        case 1:
            color(12);
            printf("   /\\                                                        /\\ \n"
                   "  |  |                                                      |  | \n"
                   " /----\\                    Be Careful                      /----\\ \n"
                   "[______]             Your court is at danger!!!           [______] \n"
                   " |    |         _____                        _____         |    | \n"
                   " |[]  |        [     ]                      [     ]        |  []| \n"
                   " |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    | \n"
                   " |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    | \n"
                   " |             |     |/'   ");
            color(15);
            printf(" ____..____ ");
            color(12);
            printf("   '\\|     |             | \n  \\  []        |     |    ");
            color(15);
            printf("/'    ||    '\\    ");
            color(12);
            printf("|     |        []  / \n   |      []   |     |   ");
            color(15);
            printf("|o     ||     o|   ");
            color(12);
            printf("|     |  []       | \n   |           |  _  |   ");
            color(15);
            printf("|     _||_     |   ");
            color(12);
            printf("|  _  |           | \n   |   []      | (_) |   ");
            color(15);
            printf("|    (_||_)    |   ");
            color(12);
            printf("| (_) |       []  | \n   |           |     |   ");
            color(15);
            printf("|     (||)     |   ");
            color(12);
            printf("|     |           | \n   |           |     |   ");
            color(15);
            printf("|      ||      |   ");
            color(12);
            printf("|     |           | \n /''           |     |   ");
            color(15);
            printf("|o     ||     o|   ");
            color(12);
            printf("|     |           ''\\ \n[_____________[_______]");
            color(15);
            printf("--'------''------'--");
            color(12);
            printf("[_______]_____________] \n");
            color(14);
            break;
        case 2:
            color(15);
            printf("                                                          ....... \n"
                   "      ***           @@@@@@@       #############       .:::::::::::::.  \n"
                   "    *******         @@  @@@@      ##         ##      .::'  '''''  '::. \n"
                   "   *********       @@    @@@      #  ~~   ~~  #      :::           ::: \n"
                   "/\\* ### ### */\\    @ 0  0 @@@     #  ()   ()  #      :::           ::: \n"
                   "|    @ / @    |   @@  I   @@@@    (     ^     )      :::           ::: \n"
                   "\/\\    ^    /\\/   @@      @@@@     |         |       ::'           ':: \n"
                   "   \\  ===  /      @@  ==  @@@      |  {===}  |      : : /~~~' '~~~\\ : : \n"
                   "    \\_____/        @+     @@        \       /           :(:   |   :): \n"
                   "     _|_|_         @+++  +@@       /  -----  \\      '.:     / \\     :.' \n"
                   "  *$$$$$$$$$*       @+   +@     ---  |%\ /%|  ---        ':    (. .)    :' \n"
                   "                     +88$8     /     |%%%%%|     \\       '.   .:::::.  .' \n"
                   "                                     |%/ \%|              :   <----->  :   \n"
                   "                                                       '.  ~:::~  .' \n"
                   "                                                         '.  '  .'     \n"
                   "                                                           ''''' \n"
                   "            People Are mad At you !!! pay them more attention\n");
            color(14);
            break;
        case 3:
            color(14);
            printf("******************************************************************************* \n"
                  "          |                   |                  |                     | \n"
                  " _________|________________.=""_;=.______________|_____________________|_______ \n"
                  "|                   |  ,-\"_,=\"\"     `\"=.|                  | \n"
                  "|___________________|__\"=._o`\"-._        `\"=.______________|___________________ \n"
                  "          |                `\"=._o`\"=._      _`\"=._                     | \n"
                  " _________|_____________________:=._o \"=._.\"_.-=\"'\"=.__________________|_______ \n"
                  "|                   |    __.--\" , ; `\"=._o.\" ,-\"""-._ \".   | \n"
                  "|___________________|_._\"  ,. .` ` `` ,  `\"-._\"-._   \". '__|___________________ \n"
                  "          |           |o`\"=._` , \"` `; .\". ,  \"-._\"-._; ;              | \n"
                  " _________|___________| ;`-.o`\"=._; .\" ` '`.\"\\` . \"-._ /_______________|_______ \n"
                  "|                   | |o;    `\"-.o`\"=._``  '` \" ,__.--o;   | \n"
                  "|___________________|_| ;     (#) `-.o `\"=.`_.--\"_o.-; ;___|___________________\n"
                  "____/______/______/___|o;._    \"      `\".o|o_.--\"    ;o;____/______/______/____ \n"
                  "/______/______/______/_\"=._o--._        ; | ;        ; ;/______/______/______/_ \n"
                  "____/______/______/______/__\"=._o--._   ;o|o;     _._;o;____/______/______/____ \n"
                  "/______/______/______/______/____\"=._o._; | ;_.--\"o.--\"_/______/______/______/_ \n"
                  "____/______/______/______/______/_____\"=.o|o_.--""___/______/______/______/____ \n"
                  "/______/______/______/______/______/______/______/______/______/______/ \n"
                  "******************************************************************************* \n"
                  "                        Be Careful!, Your Treasury is going to empty!\n");
            break;

    }
}
void creating_decision(){
    HANDLE  color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fpin1, *fpin2;
    int i;
    char str[100]= ".\\";
    char c[10] = {'\0'};
    mkdir("CHOICES_you_made");//creating folder if it does not exist
    strcat(str,"CHOICES_you_made\\");
    fpin1 = fopen(".\\CHOICES_you_made\\CHOICES.txt", "r+");
    if(fpin1 == NULL){
        fpin1 = fopen(".\\CHOICES_you_made\\CHOICES.txt", "w");
        if (fpin1 == NULL)
            printf("ERROR in creating CHOCES\n");
        strcat(str,"c1.txt");
        fpin2 =fopen(str,"w");
        if(fpin2 == NULL)
            printf("ERROR in creating c.txt files\n");
        fputs("c1.txt\n",fpin1);
        fclose(fpin1);
    }
    else{
        while(!feof(fpin1)) //reading ci.txt names until reaching end of file
            fscanf(fpin1, "%s", c);
        printf("%s\n",c);
        for (i = 0; i < 10 && c[i] != '\0'; i++)
            if(c[i] == '.'){
            c[i-1] +=1;
            break;
            }
        printf("%s\n",c);
        strcat(str,c);
        fpin2 = fopen(str,"w");
        fputs(c,fpin1);
        fputc('\n',fpin1);
        fclose(fpin1);
    }
    char buff[100];
    int buff_num;
    printf("Enter your problem: ");
    fflush(stdin);
    color(15);
    gets(buff);
    fputs(buff,fpin2);
    fprintf(fpin2,"\n");
    color(14);
    printf("Enter your first decision: ");
    color(15);
    gets(buff);
    fputs(buff,fpin2);
    fprintf(fpin2,"\n");
    color(14);
    printf("decision effect on people : ");
    color(15);
    scanf("%d",&buff_num);
    fprintf(fpin2,"%d\n",buff_num);
    color(14);
    printf("decision effect on court : ");
    color(15);
    scanf("%d",&buff_num);
    fprintf(fpin2,"%d\n",buff_num);
    color(14);
    printf("decision effect on treasury : ");
    color(15);
    scanf("%d",&buff_num);
    fprintf(fpin2,"%d\n",buff_num);
    color(14);
    printf("Enter your second decision: ");
    fflush(stdin);
    color(15);
    gets(buff);
    fputs(buff,fpin2);
    fprintf(fpin2,"\n");
    color(14);
    printf("decision effect on people : ");
    color(15);
    scanf("%d",&buff_num);
    fprintf(fpin2,"%d\n",buff_num);
    color(14);
    printf("decision effect on court : ");
    color(15);
    scanf("%d",&buff_num);
    fprintf(fpin2,"%d\n",buff_num);
    color(14);
    printf("decision effect on treasury : ");
    color(15);
    scanf("%d",&buff_num);
    color(14);
    fprintf(fpin2,"%d\n",buff_num);
    fclose(fpin2);
}
void bubble_sort(struct user arr[],int length){
    int i,j;
    struct user temp;
    for(i = 0; i < length; i++)
        for(j = i+1; j < length; j++){
            if(arr[i].people > arr[j].people)
                continue;
            else if(arr[i].people < arr[j].people){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if(arr[i].court > arr[j].court)
                continue;
            else if(arr[i].court < arr[j].court){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if(arr[i].treasury < arr[j].treasury){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
}
void advanced_rank(){
    HANDLE  color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fpin;
    fpin = fopen("data__rank.bin","rb");
    if (fpin != NULL){// if such file exist:
        struct user *users;
        users = (struct user*)malloc(sizeof(struct user));
        if(users == NULL){
            if(users == NULL){
                printf("Cannot allocate users array\n");
                return;
            }
        }
        int i =  1,j, check_reading, length;
        while(1){//read until reach the end of file
            if(i > 1)
                users = (struct user*)realloc(users, i * sizeof(struct user));
            if(users == NULL){
                printf("Cannot reallocate users array\n");
                return;
            }
            check_reading = fread(users + i - 1, sizeof(struct user), 1, fpin);
            if(check_reading != 1)
                break;
            i++;
        }
        length = i - 1;
        bubble_sort(users, length);
        for(j = 0; j < 10 && j < length; j++){
            color(j+2);
            printf("Rank %d: ",j+1);
            color(15);
            printf("%s\n",users[j].name);
        }
        printf("\n");
        color(14);
        free(users);
        fclose(fpin);
    }
}
void save_rank(struct user *user_info){
    FILE *fpin;
    fpin = fopen("data__rank.bin","rb+");
    if(fpin == NULL)
        fpin = fopen("data__rank.bin","wb");
    struct user temp;
    int check_reading;
    while(1){
        check_reading = fread(&temp, sizeof(struct user), 1, fpin);
        if (check_reading != 1){
            break;
        }
        if(strcmp(temp.name,user_info->name) == 0){
            fseek(fpin,-1*sizeof(struct user),SEEK_CUR);
            break;
        }
    }
    int check_writing = fwrite(user_info,sizeof(struct user),1, fpin);
    if(check_writing != 1)
        printf("An error occurred during saving rank file");
    fclose(fpin);
}
void save(int position, struct user *user_info,int chances[],int length){
    HANDLE  color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fpout;
    int check_writing;
    char inname[60] = "data_";
    strcat(inname,user_info->name);
    strcat(inname,".bin");
    fpout = fopen(inname, "wb");
    check_writing = fwrite(user_info, sizeof(struct user), 1, fpout);
    if(check_writing != 1)
        printf("An error occurred during saving the user data\n");
    check_writing = fwrite(chances, sizeof(int), length, fpout);
    if(check_writing != length)
        printf("An error occurred during saving the chances\n");
    check_writing = fwrite(&position, sizeof(int), 1, fpout);
    if(check_writing != 1)
        printf("An error occurred during saving the current position\n");
    color(2);
    printf("\nData saved!!!\n");
    color(15);
    fclose(fpout);
}
void save_middle(struct user *user_info,int chances[],int length){
    FILE *fpout;
    int check_writing;
    char inname[60] = "data__middle.bin";
    fpout = fopen(inname, "wb");
    fwrite(user_info, sizeof(struct user), 1, fpout);
    fwrite(chances, sizeof(int), length, fpout);
    fclose(fpout);
}
struct user load(FILE *fpin,int chances[], int length){
    struct user user_info;
    int check_reading;
    check_reading = fread(&user_info, sizeof(struct user), 1, fpin);
    if(check_reading != 1)
        printf("An error occurred during loading the user data\n");
    check_reading = fread(chances, sizeof(int), length, fpin);
    if(check_reading != length)
        printf("An error occurred during loading the chances\n");
    return user_info;
}
void add_front(struct node **list, struct node *new_node){
    new_node->next = *list;
    *list = new_node;
}
void add_end(struct node *list, struct node *new_node){
    struct node *curNode;
    for(curNode = list; curNode->next != NULL; curNode = curNode->next);
    curNode->next = new_node;
    new_node -> next = NULL;
}
void delete_node(struct node **list, int node_num){
    if(node_num == 0){//delete first node if it's chance become zero:
        struct node *tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
    else{
        struct node *pervNode = *list;
        struct node *curNode = (*list)->next;
        int i;
        for(i = 1; i < node_num && curNode != NULL; i++){//loop to find node location
            pervNode = curNode;
            curNode = curNode->next;
        }
        if(curNode != NULL){//deleting curNode which is at node_num location
            struct node *tmp = curNode;
            pervNode->next = curNode->next;
            free(tmp);
        }
    }
}
struct node* create_node(FILE *fp){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    fgets(newNode->problem, 201, fp);
    fgets(newNode->first.context,201, fp);
    fscanf(fp, "%d", &newNode->first.people);
    fscanf(fp, "%d", &newNode->first.court);
    fscanf(fp, "%d", &newNode->first.treasury);
    fgetc(fp);//for getting \n character in file after number
    fgets(newNode->second.context, 201, fp);
    fscanf(fp, "%d", &newNode->second.people);
    fscanf(fp, "%d", &newNode->second.court);
    fscanf(fp, "%d", &newNode->second.treasury);
    newNode->next = NULL;
    return newNode;
}
struct node* input_file(){
    FILE *fpin, *fpin2;
    struct node *list = NULL,*new_node;
    char inname[30];
    fpin = fopen("CHOICES.txt", "r");
    if(fpin == NULL){
        printf("Input file is missing\n");
        exit(-1);
    }
    while(!feof(fpin)){
        fscanf(fpin, "%s", &inname);
        fpin2 = fopen(inname, "r");
        if(fpin2 == NULL){
        printf("Input files is missing\n");
        exit(-1);
        }
        new_node = create_node(fpin2);
        if(list == NULL)
            add_front(&list,new_node);
        else
            add_end(list,new_node);
        fclose(fpin2);
    }
    fclose(fpin);
    return list;
}
int list_length(struct node* list){
    struct node *curNode = list;
    int len;
    for(len = 0; curNode != NULL; len++, curNode = curNode->next);
    return len;
}
void game_round(struct node *list, struct user *user_info, int rand_num, int chances[], int max_length){
    HANDLE  color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    struct node *curNode = list;
    int i,input;
    for(i = 0; i < rand_num; i++, curNode = curNode->next);
    color(2);
    printf("\nPeople:%d Court:%d Treasury:%d\n\n", user_info->people, user_info->court, user_info->treasury);
    color(14);
    if(curNode->problem == NULL)
        printf("ERROR(NODE is empty but we are gonna open it(why?))\n");
    printf("%s\n",curNode->problem);
    color(2);
    printf("[1] ");
    color(15);
    printf("%s\n", curNode->first.context);
    color(4);
    printf("[2] ");
    color(15);
    printf("%s\n", curNode->second.context);
    printf("> ");
    scanf("%d", &input);
    color(14);
    while(input != 1 && input != 2 && input != -1){//if user's input is wrong
        printf("Wrong input!\n");
        printf("> ");
        color(15);
        scanf("%d", &input);
        color(14);
    }
    switch (input){
        case 1:
            user_info->people += curNode->first.people;
            user_info->court += curNode->first.court;
            user_info->treasury += curNode->first.treasury;
            break;
        case 2:
            user_info->people += curNode->second.people;
            user_info->court += curNode->second.court;
            user_info->treasury += curNode->second.treasury;
            break;
        case -1:
            printf("Do you want to save the game?\n");
            color(2);
            printf("[1] ");
            color(15);
            printf("yes\n");
            color(4);
            printf("[2] ");
            color(15);
            printf("no\n>");
            int input;
            scanf("%d", &input);
            color(14);
            while(input != 1 && input != 2){
                printf("Wrong input, try another one:\n> ");
                fflush(stdin);//if input is a string instead of number we should flush the keyboard buffer
                color(15);
                scanf("%d", &input);
                color(14);
            }
            if(input == 1){
                int check;
                check = remove(".\\data__middle.bin");
                if (check != 0)
                    printf("Failed to remove middle data file\n");
                save(0,user_info,chances,max_length);
                save_rank(user_info);
            }
            else if(input == 2){
                int check;
                check = remove(".\\data__middle.bin");
                if (check != 0)
                    printf("Failed to remove middle data file\n");
                printf("Have a nice day ;)\n");
                color(15);
            }
            exit(0);
    }

}
struct user instruction(int length, int chances[],struct node **list){
    HANDLE  color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    while(1){
        printf("select one of this options:\n");
        color(2);
        printf("[1] ");
        color(15);
        printf("Create a choice\n");
        color(4);
        printf("[2] ");
        color(15);
        printf("Play game\n> ");
        int input;
        scanf("%d",&input);
        color(14);
        while(input != 1 && input != 2){
            printf("Wrong input, try another one:\n> ");
            color(15);
            fflush(stdin);//if input is a string instead of number we should flush the keyboard buffer
            scanf("%d",&input);
            color(14);
        }
        if(input == 1)
            creating_decision();
        else if (input == 2)
            break;
    }
    fflush(stdin);
    struct user user_info;
    //if we leave the game unexpectedly before:
    FILE *fpin_middle;
    fpin_middle = fopen("data__middle.bin","rb");
    if(fpin_middle != NULL){
        user_info = load(fpin_middle,chances,length);//loading previous game data
        int input, i;
        printf("You leave the game unexpectedly last time, do you want to resume game?\n")
        color(2);
        printf("[1] ");
        color(15);
        printf("Start a new game\n");
        color(4);
        printf("[2] ");
        color(15);
        printf("Resume a game\n> ");
        scanf("%d",&input);
        color(14);
        while(input != 1 && input != 2){
            printf("Wrong input, try another one:\n> ");
            color(15);
            scanf("%d",&input);
            color(14);
        }
        if(input == 1){
        user_info.people = 50;
        user_info.court = 50;
        user_info.treasury = 50;
        for(i = 0; i < length; i++)
            chances[i] = 3;
        }
        else if(input == 2) {
            for(i = 0; i < length; i++)
                if (chances[i] == 0)
                    delete_node(list,i);//deleting nodes which they chance is zero
        }
        fclose(fpin_middle);
        return user_info;
    }
    //........................................
    char user_name[50],inname[60] = "data_";//user_name is current user'name that playing game and inname is address if he/she played before
    int input, position, i;
    FILE *fpin;
    printf("Enter your name:\n> ");
    color(15);
    gets(user_name);
    color(14);
    strcat(inname,user_name);//appending user_name to inname for checking saved file
    strcat(inname,".bin");//appending file suffix
    fpin = fopen(inname,"r");
    if(fpin == NULL)//if there is no inname file, then user is a new user
        printf("Welcome to the game!!!, remember you can always leave by pressing -1\n");
    else{
        ASCII_art(0);
        printf("Welcome %s, select one of this options:\n",user_name);
        color(2);
        printf("[1] ");
        color(15);
        printf("Start a new game\n");
        color(4);
        printf("[2] ");
        color(15);
        printf("Resume a game\n> ");
        scanf("%d",&input);
        color(14);
        while(input != 1 && input != 2){
            printf("Wrong input, try another one:\n> ");
            color(15);
            scanf("%d",&input);
            color(14);
        }
    }
    fseek(fpin,-1 *sizeof(int), SEEK_END);//change file position handler to where position(integer) is in file
    fread(&position, sizeof(int), 1, fpin);
    if(fpin == NULL || input == 1 || position == 1){//if position is 1 then user is lost at previous game
        strcpy(user_info.name, user_name);
        user_info.people = 50;
        user_info.court = 50;
        user_info.treasury = 50;
        for(i = 0; i < length; i++)
            chances[i] = 3;
    }
    else{
        rewind(fpin);//changing file position handler to first of file
        user_info = load(fpin,chances,length);//loading previous game data
        for(i = 0; i < length; i++)
            if (chances[i] == 0)
                delete_node(list,i);//deleting nodes which they chance is zero
    }
    fclose(fpin);
    return user_info;
}
int main(){
    HANDLE  color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    advanced_rank();
    time_t t = time(NULL);
    srand(t);//getting random number by time
    struct node *list;
    struct user user_info;//current user info(then we get info from instruction function)
    list = input_file();//input all the nodes from file(deleting special ones in instruction function if user played before)
    int length = list_length(list);//getting length of nodes
    int max_length = length; //we need this to create a random number
    int chances[length];// all the chances of each node(then we get information in instruction function)
    user_info = instruction(length, chances, &list);
    int game_is_on = 1;//it shows when game is over
    float average;
    int i,j,counter,r,r1,r2,few_treasury = 1,few_court = 1,few_people = 1;
    while(game_is_on){
        if(length == 0){//if length become zero so we have no node and we create all of them again
            list = input_file();
            length = max_length;
            for(i = 0; i < length; i++)
                chances[i] = 3;
        }
        r = rand();//creating random variable base on time
        r1 = r % max_length;//restricting random variable to [0,max_length)
        if(chances[r1] != 0){
            counter =  0;//this counter counts how many zero chances is before chances[r1] exist.
            for(j = 0;j < r1; j++)
                if(chances[j] == 0)
                    counter++;
            r2 = (r % max_length) - counter;//this is random variable for node corresponding to r1 for chances
            game_round(list,&user_info,r2,chances,max_length);
            chances[r1] -= 1;
            if(chances[r1] == 0){
                delete_node(&list,r1);
                length -= 1;
            }
        }
        //saving in middle if something unexpectedly happened :
        save_middle(&user_info,chances,max_length);

        //ASCII CODE SHOWING :
        if(user_info.people > 30)
            few_people = 1;
        if(user_info.court > 30)
            few_court = 1;
        if(user_info.treasury > 30)
            few_treasury = 1;
        if(user_info.people <= 30 && few_people == 1){
            ASCII_art(2);
            few_people = 0;
        }
        if(user_info.court <= 30 && few_court == 1){
            ASCII_art(1);
            few_court = 0;
        }
        if(user_info.treasury <= 30 && few_treasury == 1){
            ASCII_art(3);
            few_treasury = 0;
        }

        //part of game when user lose it:
        average = user_info.people + user_info.court + user_info.treasury / 3.0;
        //if one of three parameters become less than zero we change it into zero:
        if(user_info.people < 0)
            user_info.people = 0;
        if(user_info.court < 0)
            user_info.court = 0;
        if(user_info.treasury < 0)
            user_info.treasury = 0;
        if(average < 10 || user_info.people == 0 || user_info.court == 0 || user_info.treasury == 0){// if user lose :
            color(4);
            if (average < 10)
                printf("You lose because your average of 3 parameters are less than 10\n");
            else{
                printf("\nPeople:%d Court:%d Treasury:%d\n\n", user_info.people, user_info.court, user_info.treasury);
                printf("You lose because one of the parameters above become zero\n");
            }
            color(14);
            printf("Do you want to save the game?\n");
            color(2);
            printf("[1] ");
            color(15);
            printf("yes\n");
            color(4);
            printf("[2] ");
            color(15);
            printf("no\n>");
            int input;
            scanf("%d", &input);
            color(14);
            while(input != 1 && input != 2){
                printf("Wrong input, try another one:\n> ");
                color(15);
                fflush(stdin);//if input is a string istead of number we should flush the keyboard buffer
                scanf("%d", &input);
                color(14);
            }
            if(input == 1){
                int check;
                check = remove(".\\data__middle.bin");
                if (check != 0)
                    printf("Failed to remove middle data file\n");
                save(1, &user_info,chances,max_length);
                save_rank(&user_info);
            }
            else if(input == 2){
                int check;
                check = remove(".\\data__middle.bin");
                if (check != 0)
                    printf("Failed to remove middle data file\n");
                printf("Have a nice day ;)\n");
                color(15);
            }
            game_is_on = 0;
        }
    }
    return 0;
}
