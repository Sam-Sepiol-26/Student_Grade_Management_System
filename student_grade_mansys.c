#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count;

typedef struct{
	char name[50];
	int ID;
	float cgpa;
	char grade;
} Student;


void display(){
	printf("\nWelcome to the Student Grade Management System");
	printf("\n                         ----- Made By 0x00S30")
;
	printf("\n----------------------------------------------");
}

void display_menu(){
	printf("\n\nMENU: \n1.ADD STUDENT DETAILS \n2.DISPLAY STUDENT DETAILS \n3.EXIT");
}

void calculate_grade(Student *student){
	if(student->cgpa > 8.0){
		student->grade = 'A';
	}
	else if(student->cgpa > 6.0){
		student->grade = 'B';
	}
	else if(student->cgpa > 4.0){
		student->grade = 'C';
	}
	else if(student->cgpa > 2.0){
		student->grade = 'D';
	}
	else{
		student->grade = 'U';
	}
}


void display_details(Student student_array){
	printf("-------------------------------");
	printf("\nName: %s", student_array.name);
	printf("\nID: %d", student_array.ID);
	printf("\nCGPA: %.2f", student_array.cgpa);
	printf("\nGRADE: %c", student_array.grade);
	printf("\n-------------------------------\n");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_students(Student student_array[]){

	printf("\nADDING STUDENT DETAILS");
	printf("\nEnter total number of students: ");
	scanf("%d", &count);
	clear_input_buffer();

	if(count < 1 || count > 100){
		printf("\nInvalid number of students");
		return;
	}

	for(int i = 0; i < count; i++){

	
		printf("\n\nEnter details for Student %d", i + 1);
		
		printf("\n\nName: ");
		fgets(student_array[i].name, 50, stdin);
		student_array[i].name[strcspn(student_array[i].name, "\n")] = '\0';


		printf("ID: ");
		scanf("%d", &student_array[i].ID);
		clear_input_buffer();


		printf("CGPA: ");
		scanf("%f", &student_array[i].cgpa);
		clear_input_buffer();
		

		calculate_grade(&student_array[i]);
		
	}
}

void disp_tot_details(Student student_array[]){
	for(int i = 0; i < count; i++){
		printf("\n\n\nDetails of student[%d]: \n", i + 1);

		display_details(student_array[i]);
	}
}

int main(){


	int choice;
	int counter = 0;

	display();

	display_menu();

	Student student_array[100];
	
	while(1){
		
		printf("\n\nOption: ");
		scanf("%d", &choice);
		clear_input_buffer();

		switch(choice){
			case 1:
				add_students(student_array);
				printf("\nStudent Data Added successfully into the Database");
				break;
			case 2:
				if(counter == 0){
					printf("No Data to Show");
					printf("\nAdd some data first!");
					char s_opt;
					printf("\nWant to add data? (y/n): ");
					scanf(" %c", &s_opt);
					clear_input_buffer();
					
					if(s_opt == 'y' || s_opt == 'Y'){
						add_students(student_array);
						break;
					}
					else if(s_opt == 'n' || s_opt == 'N'){
						printf("\nNo available data. \nExiting Display Operation.....");
						break;

					}
				}
				disp_tot_details(student_array);
				break;

			case 3:
				printf("----------Thank you for using our service----------");
				printf("\nExiting......");
				exit(0);
			default:
				printf("\nInvalid Choice");
				break;
		}
		counter++;
	}
	return 0;
}
	
