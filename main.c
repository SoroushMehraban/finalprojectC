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
    int chance;
    struct node *next;
};
struct user {
    char name[50];
    int people;
    int court;
    int treasury;
};
void save(int position, struct user *user_info,int chances[]){
    FILE *fpout;
    int check_writing;
    char inname[60] = "data_";
    strcat(inname,user_info->name);
    strcat(inname,".bin");
    fpout = fopen(inname, "wb");
    check_writing = fwrite(user_info, sizeof(struct user), 1, fpout);
    if(check_writing != 1)
        printf("An error occurred during saving the user data\n");
    check_writing = (chances, sizeof(chances), 1, fpout);
    if(check_writing != 1)
        printf("An error occurred during saving the chances\n");
    check_writing = (position, sizeof(int), 1, fpout);
    if(check_writing != 1)
        printf("An error occurred during saving the current position\n");
}
struct user load(FILE *fpin,int chances[]){
    struct user user_info;
    int check_reading;
    check_reading = fread(&user_info, sizeof(struct user), 1, fpin);
    if(check_reading != 1)
        printf("An error occurred during loading the user data\n");
    check_reading = (chances, sizeof(chances), 1, fpin);
    if(check_reading != 1)
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
    fgets(newNode->second.context, 201, fp);
    fscanf(fp, "%d", &newNode->second.people);
    fscanf(fp, "%d", &newNode->second.court);
    fscanf(fp, "%d", &newNode->second.treasury);
    newNode->chance = 3;
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
void game_round(struct node *list, struct user *user_info, int rand_num){
    struct node *curNode = list;
    int i,input;
    for(i = 0; i < rand_num; i++, curNode = curNode->next);
    printf("People:%d Court:%d Treasury:%d\n", user_info.people, user_info.court, user_info.treasury);
    printf("%s",list->problem);
    printf("[1] %s\n", list->first.context);
    printf("[2] %s\n", list->second.context);
    printf("> ");
    scanf("%d", &input);
    while(input != 1 && input != 2 && input != -1){
        printf("Wrong input!\n");
        printf("> ");
        scanf("%d", &input);
    }
    switch (input){
        case 1:
            user_info->people += list->first.people;
            user_info->court += list->first.court;
            user_info->treasury += list->first.treasury;
            break;
        case 2:
            user_info->people += list->second.people;
            user_info->court += list->second.court;
            user_info->treasury += list->second.treasury;
            break;
        case 3:
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
        printf("Welcome to the game!!,remember you can always leave by pressing -1\n");
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
    fscanf(fpin, "%d", &position);
    if(fpin == NULL || input == 1 || position == 1){//if position is 1 then user is lost at previous game
        strcpy(user_info.name, user_name);
        user_info.people = 50;
        user_info.court = 50;
        user_info.treasury = 50;
        for(i = 0; i < length; i++)
            chances[i] = 3;
    }
    else{
        user_info = load(fpin,chances);//loading previous game data
        for(i = 0; i < length; i++)
            if (chances[i] == 0)
                delete_node(list,i);//deleting nodes which they chance is zero
    }
    fclose(fpin);
    return user_info;
}
int main(){
    time_t t = time(NULL);
    srand(t);//getting random number by time
    struct node *list;
    struct user user_info;//current user info(then we get info from instruction function)
    list = input_file();//input all the nodes from file(deleting special ones in instruction function if user played before)
    int length = list_length(list);//getting length of nodes
    int chances[length];// all the chances of each node(then we get information in instruction function)
    user_info = instruction(length, chances, &list);
    int game_is_on = 1;//it shows when game is over
    while(game_is_on){
        int r = rand()%(length + 1);
        game_round(list,&user_info,r);
    }
    return 0;
}
