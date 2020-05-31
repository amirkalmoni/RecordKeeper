Amir Kalmoni


1.open two xTerm/terminal windows in the same directory you have saved Administrator.c and RecordKeeper.c
2.type gcc Administrator.c -o sender   in first xTerm window
3.type gcc RecordKeeper.c -o receiver	in second xTerm window
4.type ./send in first xTerm window
5.type ./receive in second xTerm window 
6.type your command in first xTerm window, valid commands are 
	1)Insert
	2)Check_name
	3)Check_department
	4)Check_salary
	5)Check_employee_number
	6)Check (notice there is a space followed by this command!)
	7)Delete 
	8)End
7.1 If you choose Insert: xTerm will ask for employee name, department name, employee number, and salary line by line. Please follow the instruction and input the information line by line.
7.2 If you choose Check_name: This function ask for employee number and returns relevant employee name. 
7.3 If you choose Check_department: This function ask for employee number and returns relevant department name. 
7.4 If you choose Check_salary: This function ask for employee number and returns relevant employee salary.
7.5 If you choose Check_employee_number: This function ask for employee name and returns relevant employee number.
7.6 If you choose Check : This function ask for department name and returns relevant employee number.   
7.7 If you choose Delete: This function ask for employee number and delete relevant information of this number.
8.type End to end both programs
