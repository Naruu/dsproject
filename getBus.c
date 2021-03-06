#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERM 200
#define MAX_LENGTH 10000
#define MAX_TEXT_LENGTH 100
#define STATION_NUMBERS 10

typedef struct{
    int stopId; //정류장 Id
    double remain_seat; //빈 좌석 수
	}Bus;

typedef struct{
    int Id; //기준 정류장의 정류장 Id
    int stationnum; //정렬할 정류장의 수
	    char *time; //시간대
    Bus gbus[MAX_TERM]; //정류장 struct
}BUS_TERM;


void FIND(Bus *gbus, Bus *range);
void insertion_sort(BUS *range);
void STRTOK(char *, BUS_TERM bus);

/*
 *getBus�뒗 �빐�떦�븯�뒗 踰꾩뒪�쓽 Id�쓽 �떆媛� �젙蹂대�� 媛�吏� �뀓�뒪�듃 �뙆�씪.
 *ID_�룊�씪_�긽�뻾.txt
 */

int main(int argc, char * argv[]){
    FILE *fp;
    char buffer[MAX_LENGTH];
    BUS_TERM  bus;
    BUS arr_bus[STATION_NUMBERS];
    
    fp = fopen(argv[1], "r");
    bus.time = argv[2];
    bus.gbus[0].stopId=argv[3]; //기준이 되는 정류장도 입력 받아야돼. 

    while(fgets(buffer, sizeof(buffer), stdin) != NULL){
        STRTOK(buffer, bus);
    }
    
    FIND(bus.gbus, arr_bus);
    insertion_sort(arr_bus);
    
    return 0;
}

//memcpy(&heap[i],&heap[i/2],sizeof(bus));

void FIND(Bus *gbus, Bus *range){
	int staitonId=gbus[0].stopId;
	int n, i=1;
	int start, end;
	
	while(stationId!=gbus[n].stopID) n++;
	if(n==1) start=n;
	else if(n==2) start=n-1;
	else start=n-2;
	
	if(n+2<=gbus[0].remain_seat) end=n+2;
	else if(n+1<=gbus[0].remain_seat) end=n+1;
	else end=n;
	
	range[0].remain_seat=end-start+1; //range[0]에는 정렬할 정류장의 수가 들어있다. 
	
	while(start<=end){
		memcpy(&range[i],&gbus[start],sizeof(BUS));
		i++;
		start++;
		}
	}

void insertion_sort(BUS *range){
	int i, j;
	BUS temp; 
	
	for(i=2;i<range[0].remain_seat+1;i++){
		memcpy(&temp, &range[i], sizeof(BUS));
		j=i-1;
		while(j>0 && range[j].remain_seat>temp.remain_seat){
			memcpy(&range[j+1], &range[j], sizeof(BUS));
			j--;
		}
		memcpy(&range[j+1], &temp, sizeof(BUS));
	}
}

void STRTOK(char *buffer, BUS_TERM bus){
    char *token;
    char *time;
    char sep[] = " ,-/";
    int n = 1, len;
    token  = strtok(buffer, sep);
    strncat(time,token,6);
    
    if(strcmp(time , bus.time) != 0)
        return;
    while(token != NULL){
        token = strtok(NULL, sep);
        len = strcspn("|", token);
        token[len] = '\0';
        bus.gbus[n].stopId = atoi(token);
        bus.gbus[n].remain_seat = atoi(token+len+1);
        printf("%d %d\n", bus.gbus[n].stopId, bus.gbus[n].remain_seat);
        n++;
        
    }
    bus.gbus[0].rmain_seat=n-1; //gbus[0]에는 찾는 정류장 Id와 노선의 총 정류장 수가 들어있다. 
}
