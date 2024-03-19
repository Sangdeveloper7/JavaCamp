// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}

void printStatistics(struct st_channel* c[], int size){
	printf("> Statistics of Channels\n");
    int level_c[5];
    int average[5];
    char top_c_name[5][30];
    int top_c_num[5];
    int total_n[5];


    for(int i=0; i<size; i++){
        char level[100] = c[i]->level;
        if(level == "Graphite"){
            int level = c[i] ->level;
            level_c[0]++;
            if(top_c_num[0] < level || top_c_num[0] == 0){
                top_c_num[0] = level;
                strcpy(top_c_name[0], c[i]->name);
            }
            total_n[0] += c[i]->count;
        }
        else if(level == "Opal"){
            int level = c[i] ->level;
            level_c[1]++;
            if(top_c_num[1] < level || top_c_num[1] == 0){
                top_c_num[1] = level;
                strcpy(top_c_name[1], c[i]->name);
            }
            total_n[1] += c[i]->count;
        }
        else if(level == "Bronze"){
            int level = c[i] ->level;
            level_c[2]++;
            if(top_c_num[2] < level || top_c_num[2] == 0){
                top_c_num[2] = level;
                strcpy(top_c_name[2], c[i]->name);
            }
            total_n[2] += c[i]->count;
        }
        else if(level == "Silver"){
            int level = c[i] ->level;
            level_c[3]++;
            if(top_c_num[3] < level || top_c_num[3] == 0){
                top_c_num[3] = level;
                strcpy(top_c_name[3], c[i]->name);
            }
            total_n[3] += c[i]->count;
        }
        else if(level == "Gold"){
            int level = c[i] ->level;
            level_c[4]++;
            if(top_c_num[4] < level || top_c_num[4] == 0){
                top_c_num[4] = level;
                strcpy(top_c_name[4], c[i]->name);
            }
            total_n[4] += c[i]->count;
        }
    }
    for(int i = 0; i<5; i++){
        average[i] = total_n[i]/level_c[i];
    }




    // 결과화면
    printf("Graphite : %d channels, Average %.1f peoples, Top channel : %s (%d peoples)", level_c[0], average[0], );
    printf("Opal  : %d channels, Average %.1f peoples, Top channel : %s (%d peoples)");
    printf("Bronze : %d channels, Average %.1f peoples, Top channel : %s (%d peoples)");
    printf("Silver : %d channels, Average %.1f peoples, Top channel : %s (%d peoples)");
    printf("Gold : %d channels, Average %.1f peoples, Top channel : %s (%d peoples)");


}

void pickupRandomChannels(struct st_channel* c[], int size){
	printf("> Pick up Channels\n");
	printf("> How much channels you want to pick up? > ");




}
void searchChannel(struct st_channel* c[], int size){
	printf("> Search Channels\n");
	printf("> Choose one (1:by peoples 2:by names) > ");





}

void updateChannel(struct st_channel* c[], int size){
	printf("> Modify a new Channel\n");
	printf("> Enter a number of channel > ");


}

int deleteChannel(struct st_channel* c[], int size){
	int no, yesno;
	printf("> Delete a new Channel\n");
	printf("> Enter a number of channel > ");

	return size;
}


void makeReport(struct st_channel* c[], int size){


}