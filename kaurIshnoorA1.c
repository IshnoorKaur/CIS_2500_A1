#include "givenA1.h"
#include <math.h>

// Task 1: This function will take in a filename as a string and attempt to create a FILE pointer out of it
FILE *openFileForReading(char fileName[MAX_STR])
{

    FILE *fPtr;

    // opens the file in read mode
    fPtr = fopen(fileName, "r");

    if (fPtr == NULL)
    {
        // file doesn't open successfully, returns null
        return NULL;
    }
    else
    {
        // file opens successfully, returns FILE pointer
        return fPtr;
    }

}

// Task 2: This function reads the course names and ID's from a text file to populate the array of structs with course names and ID's
int readCourse(char filename[MAX_STR], struct courseStruct courseInfo[NUMBER_COURSES])
{

    int m = 0;
    int i = 0;

    char cName[MAX_STR];

    // open the file in read mode
    FILE *fPtr = fopen(filename, "r");

    if (fPtr == NULL)
    {
        // file is not read successfully, return -1
        return -1;
    }
else if (fseek(fPtr, sizeof(NUMBER_COURSES)*2, SEEK_SET) >= NUMBER_COURSES * 2){
	//fseek() has failed to it returns -1
	return -1;
}
/*else if (fseek(fPtr, sizeof(NUMBER_COURSES)*2, SEEK_SET) <= (NUMBER_COURSES)*2) {
	printf("fseek() failed again\n");
	return -1;
    }*/  
    else
    {
	fseek(fPtr,0, SEEK_SET);

        // file opens successfully
        for (m = 0; m < NUMBER_COURSES; m++)
        {
            // to get the name of the courses from the file
            fgets(cName, MAX_STR, fPtr);

            // to help with the spacing
            cName[strlen(cName) - 1] = '\0';

            // populating cName with the names of courses
            strcpy(courseInfo[m].courseName, cName);
        }

        for (i = 0; i < NUMBER_COURSES; i++)
        {
            // to scan the course ID's from the file
            fscanf(fPtr, "%d", &courseInfo[i].courseID);
        }
        // to indicate successful operation
        return 1;
    }

    // to close the file
    fclose(fPtr);
}

// Task 3: This function reads the prof names and courses from a text file
int readProfAndCoursesTaught(char filename[MAX_STR], struct profStruct profInfo[NUMBER_PROFS], struct courseStruct courseInfo[NUMBER_COURSES])
{

    int i = 0;

    // to store the names of the professors
    char namesProf[MAX_STR];

    // to store the courses taught by the professors
    char ch[NUMBER_PROFS][NUMBER_COURSES];

    // open the file in read mode
    FILE *fPtr = fopen(filename, "r");

    if (fPtr == NULL)
    {
        // file is not read successfully return -1
        return -1;
    }
    else
    {
        // the code below stores the names of prof
        for (i = 0; i < NUMBER_PROFS; i++)
        {

            // gets the names of professors from the file
            fgets(namesProf, MAX_STR, fPtr);

            // helps with the spacing
            namesProf[strlen(namesProf) - 1] = '\0';

            // populating namesProf with the prof names
            strcpy(profInfo[i].profName, namesProf);
        }

        // the code below stores the course ID's
        for (i = 0; i < NUMBER_PROFS; i++)
        {

            // scans the course ID's
            fscanf(fPtr, "%s", ch[i]);

            int j = 0;

            // to check which course is taught by prof, 'y' for yes and 'n' for no
            for (j = 0; j < NUMBER_COURSES; j++)
            {

                if (tolower(ch[i][j]) == 'y')
                {
                    // the course is taught by the prof
                    profInfo[i].coursesTaught[j] = courseInfo[j].courseID;
                }
                if (tolower(ch[i][j]) == 'n')
                {
                    // the course is not taught by the prof
                    profInfo[i].coursesTaught[j] = -1;
                }
            }
        }
        // to indicate successful operation
        return 1;
    }

    // to close the file
    fclose(fPtr);
}

// Task 4: This function populates an array with names of profs who teach n or more courses and return the number of profs who teach n or more courses
int nCourses(int n, struct profStruct profInfo[NUMBER_PROFS], char profsNCourses[NUMBER_PROFS][MAX_STR])
{

    int i = 0;
    int j = 0;
    int count = 0;
    int index = 0;
    int profCount = 0;

    // goes through all the profs
    for (i = 0; i < NUMBER_PROFS; i++)
    {
        count = 0;
        strcpy(profsNCourses[i], "");

        // goes through the courses taught
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            // the course is taught
            if (profInfo[i].coursesTaught[j] != -1)
            {
                count++;
            }
        }
        if (count >= n)
        {
            // populates a string with the names of profs who taught n number of courses
            profCount++;
            strcpy(profsNCourses[index++], profInfo[i].profName);
            
        }
    }
    // returns the count
    return profCount;
}

// Task 5: This function takes the course number and searches for its course name and store it in a string parameter
int getCourseName(int courseNum, char cNameFound[50], struct courseStruct courseInfo[NUMBER_COURSES])
{
    int i = 0;

    // this loop goes through the courses
    for (i = 0; i < NUMBER_COURSES; i++)
    {
        // if statements to find the input course ID
        if (courseNum == courseInfo[i].courseID)
        {
            // stores the course name in  the string
            strcpy(cNameFound, courseInfo[i].courseName);
           
            return 1;
        }
        
    }
    return 0;
}

// Task 6: This function takes course name as input, searches for its course number and stores it in an output int parameter
int getCourseNum(char cName[50], int *cNumFound, struct courseStruct courseInfo[NUMBER_COURSES])
{
    int i = 0;
    
    // this for loop goes through the courses
    for (i = 0; i < NUMBER_COURSES; i++)
    {
        if ((strcmp(cName,courseInfo[i].courseName)) == 0)
        {
            // stores the course ID
            *cNumFound = courseInfo[i].courseID;
            return 1;
        }
    }
   return 0;
}

// Task 7: This function takes course numbers as input, seaches all the profs teaching that course and popluates an array with those prof names. It returns the number of profs teaching the course
int profsTeachingCourse(int courseNum, struct profStruct profInfo[NUMBER_PROFS], char taughtBy[NUMBER_PROFS][MAX_STR])
{
    int i = 0;

    int j = 0;

    int num = 0;

    int howManyProf = 0; 

    // this for loop goes triught the number of profs
    for (i = 0; i < NUMBER_PROFS; i++)
    {

        strcpy(taughtBy[i], "");

        // this for loop goes trough the number of courses
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            // adds the prof names that teach the course
            if (profInfo[i].coursesTaught[j] == courseNum)
            {

                strcpy(taughtBy[num++], profInfo[i].profName);
                howManyProf++;
            }
            
            
        }
    }
    return howManyProf;
}

// Task 8: This function finds the average number of courses taught by a professor.
float avgNumCourses(struct profStruct profInfo[NUMBER_PROFS])
{

    int i = 0;
    int j = 0;

    int numCourcesTaught = 0;
    int numProfessors = 0;
    float average;

   // int round = 0; 

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        // the number of professors
        numProfessors++; 

        for (j = 0; j < NUMBER_COURSES; j++)
        {
            // finds the number of courses taught
            if (profInfo[i].coursesTaught[j] != -1)
            {
                numCourcesTaught++;
            }
        }
    }

    // to find the average number of courses taught
    average = (float)(numCourcesTaught) / (numProfessors);

    //to round the average 
 
    printf("The average number of courses taught by a prof is %.2f\n", round(average));

    return 1;
}
