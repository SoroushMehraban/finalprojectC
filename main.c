#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
void bubble_sort(struct user arr[],int length){
    int i,j;
    struct user temp;
    for(i = 0; i < length - 1; i++)
        for(j = i+1; j < length; j++){
            if(arr[i].people < arr[j].people){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
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
    FILE *fpin;
    fpin = fopen("data__rank.bin","rb");
    if (fpin != NULL){// if such file exist:
        struct user *users;
        int i =  1,j, check_reading, length;
        while(1){//read until reach the end of file
            users = (struct user*)realloc(users, i * sizeof(struct user));
            if(users == NULL){
                printf("Cannot allocate users array");
                return;
            }
            check_reading = fread(users + i - 1, sizeof(struct user), 1, fpin);
            if(check_reading != 1)
                break;
            i++;
        }
        length = i;
        bubble_sort(users, length);
        for(j = 0; j < 10 && j < length - 1; j++){
            printf("Rank %d: %s\n",j+1,users[j].name);
        }
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
    printf("Data saved!!!\n");
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
    struct node *curNode = list;
    int i,input;
    for(i = 0; i < rand_num; i++, curNode = curNode->next);
    printf("\nPeople:%d Court:%d Treasury:%d\n\n", user_info->people, user_info->court, user_info->treasury);
    if(curNode->problem == NULL)
        printf("ERROR(NODE is empty but we are gonna open it(why?))\n");
    printf("%s\n",curNode->problem);
    printf("[1] %s\n", curNode->first.context);
    printf("[2] %s\n", curNode->second.context);
    printf("> ");
    scanf("%d", &input);
    while(input != 1 && input != 2 && input != -1){//if user's input is wrong
        printf("Wrong input!\n");
        printf("> ");
        scanf("%d", &input);
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
            printf("Do you want to save the game?\n"
               "[1] yes\n"
               "[2] no\n> ");
            int input;
            scanf("%d", &input);
            while(input != 1 && input != 2){
                printf("Wrong input, try another one:\n> ");
                scanf("%d", &input);
            }
            if(input == 1){
                save(0,user_info,chances,max_length);
                save_rank(user_info);
            }
            else if(input == 2)
                printf("Have a nice day ;)\n");
            exit(0);
    }

}
struct user instruction(int length, int chances[],struct node **list){
    struct user user_info;
    char user_name[50],inname[60] = "data_";//user_name is current user'name that playing game and inname is address if he/she played before
    int input, position, i;
    FILE *fpin;
    printf("Enter your name:\n> ");
    gets(user_name);
    strcat(inname,user_name);//appending user_name to inname for checking saved file
    strcat(inname,".bin");//appending file suffix
    fpin = fopen(inname,"r");
    if(fpin == NULL)//if there is no inname file, then user is a new user
        printf("Welcome to the game!!!, remember you can always leave by pressing -1\n");
    else{
        printf("Welcome %s, select one of this options:\n"
               "[1] Start a new game\n"
               "[2] Resume a game\n> ",user_name);
        scanf("%d",&input);
        while(input != 1 && input != 2){
            printf("Wrong input, try another one:\n> ");
            scanf("%d",&input);
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
    int i,j,counter,r,r1,r2;
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
        average = user_info.people + user_info.court + user_info.treasury / 3.0;
        //if one of three parameters become less than zero we change it into zero:
        if(user_info.people < 0)
            user_info.people = 0;
        if(user_info.court < 0)
            user_info.court = 0;
        if(user_info.treasury < 0)
            user_info.treasury = 0;
        if(average < 10 || user_info.people == 0 || user_info.court == 0 || user_info.treasury == 0){// if user lose :
            if (average < 10)
                printf("You lose because your average of 3 parameters are less than 10\n");
            else{
                printf("\nPeople:%d Court:%d Treasury:%d\n\n", user_info.people, user_info.court, user_info.treasury);
                printf("You lose because one of the parameters above become zero");
            }
            printf("Do you want to save the game?\n"
               "[1] yes\n"
               "[2] no\n> ");
            int input;
            scanf("%d", &input);
            while(input != 1 && input != 2){
                printf("Wrong input, try another one:\n> ");
                scanf("%d", &input);
            }
            if(input == 1){
                save(1, &user_info,chances,max_length);
                save_rank(&user_info);
            }
            else if(input == 2)
                printf("Have a nice day ;)\n");
            game_is_on = 0;
        }
    }
    return 0;
}
