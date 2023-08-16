#include "givenA1.h"

int main(int argc, char *argv[])
{

    int i = 0;

    int j = 0;

    int choice;

    int n;

    char profsNCourses[NUMBER_PROFS][MAX_STR];

    char cNameFound[50];

    int courseNum;

    char cName[MAX_STR];

    int cNumFound;

    char taughtBy[NUMBER_PROFS][MAX_STR];

    struct courseStruct information[NUMBER_COURSES];
    struct profStruct prof[NUMBER_PROFS];

    // Task 1
    // calling the function
    openFileForReading(argv[1]);

    //end of function 
    printf("Task 1 completed\n");

    printf("\n");

    // Task 2
    //calling the function 
    readCourse(argv[1], information);

    //prints the names of courses and id's
    for (i = 0; i < NUMBER_COURSES; i++)
    {
        printf("%s:   %d\n", information[i].courseName, information[i].courseID);
    }

    //end of function
    printf("Task 2 completed\n");

    printf("\n");

    // Task 3
    //calling the function
    readProfAndCoursesTaught(argv[2], prof, information);

    //prints the chart of professors teaching the course (id) and if not -1
    for (i = 0; i < NUMBER_PROFS; i++)
    {
        printf("%s   ", prof[i].profName);
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            printf("%d       ", prof[i].coursesTaught[j]);
        }

        printf("\n");
    }

    //end of function
    printf("Task 3 completed\n");

    printf("\n");
    
    choice = 4;

//The following code gives the user a choice for tasks, 4-8
while (choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8) {

    printf("Here is the menu\n");
    printf("4. Enter a number to find out how many professors teach that many courses.\n");
    printf("5. Enter a course number to search for its course name.\n");
    printf("6. Enter a course name to search for its course number.\n");
    printf("7. Enter a course number to find search for the professors teching it.\n");
    printf("8. Average number of courses taught by a professor.\n");


    printf("\n");

    //user inputs a number
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (3 >= choice || choice >= 9)
    {
	//prints a message when an invalid choice is entered
        printf("Invalid Choice!\n");
        return 0;
    }
    if (choice == 4)
    {
	//user inputs a number
        printf("Enter a number: ");
        scanf("%d", &n);

	//calls the function
        int profTeach = nCourses(n, prof, profsNCourses);

        for (int i = 0; i < NUMBER_PROFS; i++)
        {
 	    //names of professors teaching the courses
            printf("Names: %s\n", profsNCourses[i]);
        }
	//number of professors teaching the course
        printf("Number of professors teaching the course: %d\n", profTeach);

	//end of function
        printf("Task 4 completed!\n");
        printf("\n");
    }
    if (choice == 5)
    {
	//user enters a course code
        printf("Enter the course code: ");
        scanf("%d", &courseNum);

	//calls the function
        getCourseName(courseNum, cNameFound, information);

        printf("Name: %s \n", cNameFound);

	//end of function
        printf("Task 5 completed!\n");
        printf("\n");
    }
    if (choice == 6)
    {
	//user enters a course name
        printf("Enter the course name: ");
        getchar();
        fgets(cName, MAX_STR, stdin);

	//for the spacing
	cName[strlen(cName)-1] = '\0'; 

	//calls the function
        getCourseNum(cName, &cNumFound, information);

        printf("The ID: %d\n", cNumFound);

	//end of function
        printf("Task 6 completed!\n");
        printf("\n");
    }
    if (choice == 7)
    {
	//user enters a course id
        printf("Enter the course ID: ");
        scanf("%d", &courseNum);

	//calls the function
        int profsT = profsTeachingCourse(courseNum, prof, taughtBy);

        for (int i = 0; i < NUMBER_PROFS; i++)
        {
	    //prits number the profs teaching the course
            printf("Names of professors teaching the course %d: %s\n", courseNum, taughtBy[i]);
        }

        printf("Number of professors teaching: %d\n", profsT);

	//end of function
        printf("Task 7 completed!\n");
        printf("\n");
    }
    if (choice == 8)
    {
	//calls the function
        avgNumCourses(prof);

	//end of function 
        printf("Task 8 completed!\n");
        printf("\n");
    }

}
}

