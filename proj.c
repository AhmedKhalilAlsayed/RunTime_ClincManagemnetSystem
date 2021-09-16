#include <stdio.h>
#include <stdlib.h>
#include "newTypes.h"
#pragma pack(1)


//model
typedef struct{
	u32 ID;		//should be uniqe
	u8* name;
	u8 age;
	u8 gender;	//'m' for male, 'f' for female
}Patient;


// node of linkedList
typedef struct N Node;
struct N{
	Patient data;
	Node* link;
};

//global vars
static u32 ID = 100;	//uniqe ID
static Node* patientList = NULL;
static u32 reserveArr[5] = {0};
//end global



//list's functions 

Node* newNode(Patient value){	//private function

	Node* node = (Node*) malloc(sizeof(Node));
	node->data = value;
	node->link = NULL;
	
	if(node == NULL){
		printf("\n\tError in storage !!\n");
	}
	
	return node;
}

Node* createList(Patient value){
	//1st block or node
	// return the address of list
	
	return newNode(value);
}

Node* addToList(Node* list, Patient value){	
	
	Node* ptr = list;
	while(ptr->link != NULL){	//to reach the last node
		ptr = ptr->link;
	}
	
	ptr->link = newNode(value);		//link the last node with a newwer Node
	
	return list;
}

Node* getFromList(Node* list, u32 id){
	Node* ptr = list;
	
	while ((ptr != NULL) && (ptr->data.ID != id)){
		ptr = ptr->link;
	}
	
	if(ptr == NULL){
		//Error in getFromList()
		printf("\n\t\t!Error, \"ID not found\" \n\n");
	}
	
	return ptr;
	
}

void printNode(Node* node){
	
	if(node != NULL){
	printf(">>ID : %d\n",node->data.ID);
	printf("Name : %s\n",&(node->data.name));
	printf("Age : %d\n",node->data.age);
	printf("Gender : %c\n\n",node->data.gender);
	}
	
}

//end list's functions



//main functions

u8 chooseMode(){
	u8 mode=0;
	
	printf("\n'1' for admin mode & '2' for user mode,\n please enter your mode : ");
	scanf("%d",&mode);

	if(mode == 1 || mode == 2){

		return mode;
		
	}else{
		printf("\tInvalid value, please try again!\n");

		return chooseMode();
	}
}

u8 checkAdminPass(){
	u8* pass = "1234";	//default password
	u8* tempPass ;
	
	for(u8 i=0;i<3;i++){
		
		(i==0)
		?printf("Please enter the admin PASSWORD : ")
		:printf("Wrong password, please try again : ");
		
		scanf("%s",tempPass);
		
		u8 check=0;
		for(u8 idx=0;idx<5;idx++){
			//to check all chars like(pass == tempPass)
		
			if (*(tempPass+idx) == *(pass+idx)){
				check=1;
			}else{
				check = 0;
				break;
			}
		}
		
		if(check == 1){
			return 1;
			break;
		}
	}
	
	printf(">>the system is been exit\n");
	return 0;
	
}

void scanPatient(Patient* patient){
	
	patient->ID = ID++;
	printf("Patient name : ");scanf("%s",&(patient->name));
	printf("Patient age : ");scanf("%d",&(patient->age));
	printf("Patient gender 'M' for male and 'F' for female : ");scanf(" %c",&(patient->gender));
	
	//return patient;
}

void addPatient(){
	
	Patient patient ;
	scanPatient(&patient);
	
	if(patientList == NULL){	//for 1st patient only
		
		patientList = createList(patient);
		}else{
		
		patientList = addToList(patientList, patient);
		}
		
		printf(">> Patient ID is %d\n\n",patient.ID);
		
	//return patient.ID;
}

void updatePatient(){
	u32 id;
	printf("\nPlease enter patient's ID : ");scanf("%d",&id);
	
	Node* node = getFromList(patientList, id);
	
	if(node != NULL){
		printNode(node);	//print old values
		
		printf(">Enter new values : \n");
		
		Patient patient;
		scanPatient(&patient);
		
		//add new values in node
		node->data.name = patient.name;
		node->data.age = patient.age;
		node->data.gender = patient.gender;
		
		printf("\n");
		
	}
}

void reserve(){
	
	s8 check = 0;
	u8 idx;
	u32 id=0;
	
	while(id<100){	//ids will start from 100 as standard
	
	printf("Enter this ID : ");
	scanf("%d",&id);
	
	}
	
	for(u8 i=0;i<5;i++){
		
		if (reserveArr[i] == id) {
			check = -1;
			break;
		}
		
		if(reserveArr[i] == 0 ){
			check++;
			
			if(check==1) printf("\n>>The available slots : \n");
			
			switch(i){
				case 0:
				idx = i+1;
				printf("%d->2pm to 2:30pm\n",idx);
				break;
				
				case 1:
				idx = i+1;
				printf("%d->2:30pm to 3pm\n",idx);
				break;
				
				case 2:
				idx = i+1;
				printf("%d->3pm to 3:30pm\n",idx);
				break;
				
				case 3:
				idx = i+1;
				printf("%d->4pm to 4:30pm\n",idx);
				break;
				
				case 4:
				idx = i+1;
				printf("%d->4:30pm to 5pm\n",idx);
				break;
			}
			
			
		}
	}
	
	if (check == -1){
		printf(">>ID is already exists\n\n");
		
	}else if(check == 0){
		printf(">>No available slots : \n");
		
	}else if (check == 1){
		printf("Enter id in only available slot (%d) : ",idx);
		//scanf("%d",&id);
		idx--;
		
		if(reserveArr[idx] == 0){
		reserveArr[idx] = id;
		printf(">DONE\n\n");
		}else{
			printf(">!ERROR in index\n\n");
		}
		
	}else{
		printf("Enter the num of available slot : ");
		scanf("%d",&idx);
		//printf("Enter ID : ");scanf("%d",&id);
		idx--;
		
		if(reserveArr[idx] == 0){
		reserveArr[idx] = id;
		printf(">DONE\n\n");
		}else{
			printf(">!ERROR in index\n\n");
		}
		
	}
	
}

void cancelReserve(){
	
	u32 id;
	
	printf("Enter this ID : ");
	scanf("%d",&id);
	
	u32* ptr = reserveArr;
	
	for(u8 i=0;i<5;i++){
		if(ptr[i] == id){
			ptr[i] = 0;
			break;
		}
	}
	
	printf(">DONE\n\n");
}

//end main functions



//modes

void adminMode(){
	printf("\n\t>>>Admin mode is opened<<<\n\n");
	
	static u8 option = 0 ;
	
	while(option!=5){
	printf("*******************Admin*******************\n");
	
	printf("Options :\n1) Add a new patient\t\t\t2) Update patient's data\n3) Reserve a slot with the doctor\t4) Cancel reservation\n5) return\n");
	printf("Enter your option : ");
	scanf("%d",&option);
	
	switch(option){
		case 1://Add a new patient
		
		addPatient();		
		
		break;
		
		case 2://Update patient's data
		
		updatePatient();
		
		break;
		
		case 3://Reserve a slot with the doctor
		
		reserve();
		
		break;
		
		case 4://Cancel reservation
		
		cancelReserve();
		
		break;
		
		
	}//end switch

	
//printf("testtest option %d \n",option);// why 'option' without static, can't be seen here !!

 }//end while

option = 0;
  
}

void userMode(){
	printf("\n\t>>>User mode is opened<<<\n\n");
	
	static u8 option = 0;
	
	while(option!=3){
	printf("*******************User*******************\n");
	
	printf("Options :\n1)View patient record\t2)View today's reservation\n3)return\n\n");
	printf("Please enter your option : ");scanf("%d",&option);
	
	u32 id = 0;
	u8 checkEmpty = 0;
	switch(option){
		case 1:	//View patient record
		
		printf("Please enter ID you want to show : ");
		scanf("%d",&id);
		
		printNode( getFromList(patientList, id) );
		break;
		
		case 2:	//View today's reservation
		
		for(u8 i=0;i<5;i++){
			if(reserveArr[i] != 0){
				
				checkEmpty++;
				if(checkEmpty == 1) printf("\n>>The available slots : \n");
				
				switch(i){
					case 0:
					printf("ID (%d) : At 2pm to 2:30pm\n",reserveArr[i]);
					break;
					
					case 1:
					printf("ID (%d) : At 2:30pm to 3pm\n",reserveArr[i]);
					break;
					
					case 2:
					printf("ID (%d) : At 3pm to 3:30pm\n",reserveArr[i]);
					break;
					
					case 3:
					printf("ID (%d) : At 4pm to 4:30pm\n",reserveArr[i]);
					break;
					
					case 4:
					printf("ID (%d) : At 4:30pm to 5pm\n",reserveArr[i]);
					break;
				}
			}
		}
		
		if(checkEmpty==0) printf(">>All are free\n");
		
		break;
	}
	printf("\n");
	}
option = 0;
		
}

//end modes


int main(){
	
	printf("\n\t\t>>>Clinc Managemnet System\n\n");
	
	
	//u8 mode = chooseMode();
	
	while(1){
		
		switch( chooseMode() ){
		
		case 1:	//admin mode 
		 
		 if (checkAdminPass()){
			 
			 adminMode();
			 
		 }else
			 return 1;
		 
		break;
		
		case 2:	//user mode
		
		userMode();
		
		break;
	    }	
		
	}
	
	return 0;
		
}

