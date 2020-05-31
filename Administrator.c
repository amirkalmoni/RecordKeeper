#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define MAX_TEXT 512

struct my_msg_st{
	long int my_msg_type;
	char info[MAX_TEXT];
};


int main(){
	int running =1;;
	struct my_msg_st some_data;
	int msgid;
	char data[BUFSIZ], choice[BUFSIZ];
	
	msgid = msgget((key_t)2234, 0666 | IPC_CREAT);
	
	if(msgid == -1){
		fprintf(stderr, " failed with error %d\n", errno);
		exit(EXIT_FAILURE);		
	}
	else{
	printf(" msgid is %d\n",msgid);
	}

	
	while(running) {
		//User is prompted to input a command
		printf("Your Input: ");
		fgets(choice, BUFSIZ, stdin);
		if(strncmp(choice,"End",3) == 0){ 
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			running = 0;
			}


 		//User chooses to insert a new employee
		else if(strncmp(choice, "Insert",6) == 0){
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			int i;
			for(i = 0; i < 4; i++){ 
				if(i == 0){
					printf("Enter the name: ");	
					fgets(data, BUFSIZ, stdin);
					some_data.my_msg_type =1;
					strcpy(some_data.info, data);
					if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}	 
				}
				else if(i == 1){
					printf("Enter the department name: ");	
					fgets(data, BUFSIZ, stdin);
					some_data.my_msg_type =1;
					strcpy(some_data.info, data);
					if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
				}
				else if(i == 2){
					printf("Enter the employee number: ");	
					fgets(data, BUFSIZ, stdin);
					some_data.my_msg_type =1;
					strcpy(some_data.info, data);
					if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
				}
				else if(i == 3){
					printf("Enter the salary: ");	
					fgets(data, BUFSIZ, stdin);
					some_data.my_msg_type =1;
					strcpy(some_data.info, data);
					if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
				}

			}
		}// end of Insert operation 


		//User chooses to check name by number
		else if(strncmp(choice,"Check_name", 10) == 0){ 
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			printf("Please enter the number you want to check: ");
			fgets(data,BUFSIZ,stdin);
			some_data.my_msg_type = 1;
			strcpy(some_data.info, data);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
		}//end of when user chose to check name by number 
		
		
		//User chooses to check depart by number		
		else if(strncmp(choice,"Check_department", 16) == 0){ 
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			printf("Please enter the number you want to check: ");
			fgets(data,BUFSIZ,stdin);
			some_data.my_msg_type = 1;
			strcpy(some_data.info, data);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
		}//end of when user chose to check depart by number
		

		//User chooses to check salary by number 		
		else if(strncmp(choice,"Check_salary", 12) == 0){ 
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			printf("Please enter the number you want to check: ");
			fgets(data,BUFSIZ,stdin);
			some_data.my_msg_type = 1;
			strcpy(some_data.info, data);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
		}//end of when user choose to check salary by number


		//User chooses to delete by number 		
		else if(strncmp(choice,"Delete", 6) == 0){ 
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			printf("Please enter the number of the employee you want to delete: ");
			fgets(data,BUFSIZ,stdin);
			some_data.my_msg_type = 1;
			strcpy(some_data.info, data);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
		}//end of when user choose to delete by number 
	
		//User chooses to check number by name 		
		else if(strncmp(choice,"Check_employee_number", 21) == 0){ 
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			printf("Please enter the name you want to check: ");
			fgets(data,BUFSIZ,stdin);
			some_data.my_msg_type = 1;
			strcpy(some_data.info, data);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
		}//end of when user choose to check number by name 
		

		//User chooses to check all number in a depart		
		else if(strncmp(choice,"Check ", 6) == 0){ 
			some_data.my_msg_type =1;
			strcpy(some_data.info, choice);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
				fprintf(stderr, "msgsnd failed\n");
				exit(EXIT_FAILURE);}
			printf("Please enter the dapart you want to check: ");
			fgets(data,BUFSIZ,stdin);
			some_data.my_msg_type = 1;
			strcpy(some_data.info, data);
			if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0) == -1){
					fprintf(stderr, "msgsnd failed\n");
					exit(EXIT_FAILURE);
					}
		}//end of when user choose to check all number in a depart
		

		
		
		
		else{printf("Wrong input, please enter a valid command.\n");}
			
	}
	exit(EXIT_SUCCESS);
}


