#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//Welcomes the user
void Welcome(void);

// Displays the menu choices
char menu();

//Adds points
double FunctionAdd(double points, int currentID);

//Calculates the average
void FunctionCalculate(double points, int count, int currentID);


int main()
{
char MenuSelection;
int studentID;
double points = 0;
int count = 0;

   Welcome();
   
    //prompts user to enter the student's id
   printf("\nEnter student ID: ");
   scanf("%d", &studentID);
   
   MenuSelection = menu();
   printf("\nThe character entered was %c\n", MenuSelection);
   
   
   //If the user enters 'Q' or 'q' it will not loop
    while (MenuSelection != 'Q' && MenuSelection != 'q') 
    {
        
        if (MenuSelection == 'N' || MenuSelection == 'n')
        {
            printf("\nResetting the counts and points to 0\n");
            points = 0.0;
            count = 0;
            printf("Enter new student ID: "); //asks and gets the current student ID of the next student
            scanf("%d", &studentID);
        }
        else if(MenuSelection == 'A' || MenuSelection == 'a')
        {
            printf("\nAdd points\n");
            //Calls the function with parameters
            points = FunctionAdd(points, studentID);
            count = count + 1;
        }
        else if(MenuSelection == 'C' || MenuSelection == 'c')
        {
            printf("\nCalculate the current average\n");
            //Call FunctionCalculate with parameters
            FunctionCalculate(points, count, studentID);
        }
        else
        {
            printf("\nERROR Please enter a letter from the selection provided\n");
        }
        //Displays count to keep track of it 
        printf("\n - - - count is %d - - -\n", count);
        
        //Displays the MenuSelection
        MenuSelection = menu();
        }
    

    return 0;
    } //end of while loop
 
//function definition
void Welcome(void)
{
    printf("Welcome to the grade calculator\n");
    
    printf("\t--All assessments must have a minimum of 0 and a maximum of 100 point value\n");
    printf("\t--All assessments have the same weight\n");
    
    printf("****************************************************");
    

}

//function definition
char menu()
{
    char MenuSelection;
    printf("Select 'A' to enter points\n");
    printf("Select 'C' to display the current average\n");
    printf("Select 'N' to begin/start over with a NEW student\n");
    printf("Select 'Q' to QUIT the program.\n");
    scanf(" %c", &MenuSelection);
    return MenuSelection;
}

//function definition
double FunctionAdd(double points, int currentID)
{
    double addpoints;
    do {
        printf("Add the points for %d student: ", currentID);
        scanf("%lf", &addpoints);
    } while (addpoints < 0 || addpoints>100);
    return points + addpoints;
}

//function definition
void FunctionCalculate(double points, int count, int currentID)
{
    if (count == 0)
    {
        printf("You have not added points yes, please select 'A' and add points before this step.");
    }
    else
    {
        double average = points / count;
        printf("Average points for student %d: %.2lf\n", currentID, average);
    }
    
}
