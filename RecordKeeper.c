#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include <malloc.h>

struct my_msg_st{
	long int my_msg_type;
	char info[BUFSIZ];
};

struct database{
	char name[BUFSIZ];
	char depart[BUFSIZ];
	char number[BUFSIZ];
	char salary[BUFSIZ];
};

struct company 
{ 
  struct database emp; 
  struct company *next; 
}; 

int main(){
	
	
	int running = 1;
	int msgid;
	struct my_msg_st some_data;
	struct database db;
	long int msg_to_receive = 0;
	struct company *head;
	struct company *tail; //added 
	struct company *check;
	int employcount = 0; //count of employees in the system
	

	msgid = msgget((key_t)2234, 0666 | IPC_CREAT);
	
	if(msgid == -1){
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}else{
	printf(" msg id is %d\n",msgid);
	}
	
	while(running){
		if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
			fprintf(stderr, "msgrcv failed with error: %d\n", errno);
			exit(EXIT_FAILURE);}
		//Start of Check
		if(strncmp(some_data.info,"Check ",6) == 0){
			if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);
			}
			check = head;
			while(check != NULL){
				if( strcmp((*check).emp.depart, some_data.info) == 0){
					printf("Department name: %s Employee id: %s",some_data.info,(*check).emp.number);
				}
				check = (*check).next;
			}			
		}//End of Check
		

		//Start of Delete  
		else if(strncmp(some_data.info,"Delete",6) == 0){
           		 if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
                       		 fprintf(stderr, "msgrcv failed with error: %d\n", errno);
                       		 exit(EXIT_FAILURE);
          		  }
           		 int deleted = 0;
            		check = head;

            
              	  while(check != NULL){
                    	if( strcmp((*head).emp.number, some_data.info) == 0){
                   	 if((*head).next == NULL){
                     	   head = NULL;
                      	  employcount = 0;
                      	  deleted = 1;
                      	  break;
		            }
		            head = (*head).next;
		            check = head;
		            deleted = 1;
		        }
		        
		            struct company *next = (*check).next;
		            if(next == NULL){
		                break;
		            }
		            if( strcmp((*next).emp.number, some_data.info) == 0){
		                (*check).next = (*next).next;
		                check = head;
		                deleted = 1;

		            }else{
		            check = (*check).next;}
		        }    
		        if(deleted == 0){
		            printf("-1 \nEmployee not found");
		        }else{
		            printf("0\n");
		        }        
		}//end of Delete

		else if(strncmp(some_data.info,"Check_employee_number",21) == 0){
			if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);
			}		 
			check = head;
			while(check != NULL){
				if( strcmp((*check).emp.name, some_data.info) == 0){
					printf("employee name: %s Employee id: %s",some_data.info,(*check).emp.number);
				}
				check = (*check).next;
			}
		 			
		}//end of check employee number

		
		//Start of Check_salary
		else if(strncmp(some_data.info,"Check_salary",12) == 0){
			if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);
			}
			check = head;
			while(check != NULL){
				if( strcmp((*check).emp.number, some_data.info) == 0){
					printf("Employee id: %sEmployee salary: %s",some_data.info,(*check).emp.salary);
				}
				check = (*check).next;
			}			
		}//End of Check_salary

		//Start of Check_department
		else if(strncmp(some_data.info,"Check_department",16) == 0){
			if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);
			}
			check = head;
			while(check != NULL){
				if( strcmp((*check).emp.number, some_data.info) == 0){
					printf("Employee id: %sDepartment name: %s",some_data.info,(*check).emp.depart);
				}
				check = (*check).next;
			}			
		}//end of Check_department

		//Start of Check_name
		else if(strncmp(some_data.info,"Check_name", 10) == 0){
			if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);
			}
			check = head;
			while(check != NULL){
				if( strcmp((*check).emp.number, some_data.info) == 0){
					printf("Employee id: %sEmployee name: %s",(*check).emp.number,(*check).emp.name);
				}
				check = (*check).next;
			}			
		}//end of Check_name
		
		//Start of Insert	
		else if(strncmp(some_data.info, "Insert",6) == 0){ //if user choose to insert
			int i;
			for(i = 0; i < 4; i++){ 
				if(i == 0){
					if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);}
					strcpy(db.name, some_data.info);
					}
				if(i == 1){
					if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);}
					strcpy(db.depart, some_data.info);
					}
				if(i == 2){
					if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);}
					strcpy(db.number, some_data.info);
					}
				if(i == 3){
					if(msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0) == -1){
						fprintf(stderr, "msgrcv failed with error: %d\n", errno);
						exit(EXIT_FAILURE);}
					strcpy(db.salary, some_data.info);
					}
			}
	
			struct company* node = NULL;
			node  = (struct company*)malloc(sizeof(struct company));
			node->emp = db;
			node->next = NULL;
			if(employcount == 0){
				head = node;
				tail= node;
			}else{
				(*tail).next = node;
				tail = node;
			}
			employcount++; 
		}//end of Insert 	
		
		
		
		if(strncmp(some_data.info, "End",3) == 0){
			struct company *check = head;
			while(check != NULL){
				printf("\nname : %s\n",(*check).emp.name);
				printf("department : %s\n", (*check).emp.depart);
				printf("number : %s\n", (*check).emp.number);
				printf("salary : %s\n", (*check).emp.salary);
				check = (*check).next;
			}
		running = 0;}
	}
	
	if(msgctl(msgid, IPC_RMID, 0) == -1){
		fprintf(stderr, "msgctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}		
	
	exit(EXIT_SUCCESS);
}



















