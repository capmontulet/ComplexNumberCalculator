/* Revision 1.1.  loadComplex() changed, to return Complex structure */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
   double real; 
   double imag; 
} Complex;

#define Exit 0
#define Load 1
#define Display 2
#define Move 3
#define Conjugate 4
#define Add 5
#define Subtract 6
#define Multiply 7
#define Divide 8

#define PROMPT_USER_TO(menuItem) printf("%d. %s complex numbers\n", menuItem, #menuItem);

int  displayMenu();
void executeMenuItem(int menuItem);
Complex loadComplex();
int chooseComplexNumberTo(char*);
void display(Complex c);
Complex subtract(Complex c1, Complex c0);
Complex add(Complex c1, Complex c0);
Complex multiply(Complex c1, Complex c0);
Complex divide(Complex c1, Complex c0);
Complex complexConjugate(Complex c);

// DO NOT CHANGE THIS FUNCTION
int main(void){   
   int choice = Exit;
   printf("Welcome to the complex number calculator\n\n");
   do{
      choice = displayMenu();
	   executeMenuItem(choice);
   } while (choice != Exit);

   printf("Program exited\n");
   exit(EXIT_SUCCESS);
}
// DO NOT CHANGE THIS FUNCTION
int displayMenu(){  
    int input = Exit;
    printf("Select one of the following:\n\n");
    PROMPT_USER_TO(Load)
    PROMPT_USER_TO(Display)
    PROMPT_USER_TO(Move)
    PROMPT_USER_TO(Conjugate)
    PROMPT_USER_TO(Add)
    PROMPT_USER_TO(Subtract)
    PROMPT_USER_TO(Multiply)
    PROMPT_USER_TO(Divide)
    printf("%d. Exit Program\n", Exit);
    scanf("%d", &input);
    return input;
}
// DO NOT CHANGE THIS FUNCTION
void executeMenuItem(int menuItem){
    Complex c = {0,0};  
    static Complex c0 = {0,0}, c1 = {0,0}, cResult = {0,0};   
    
 
    switch (menuItem) {

        case Exit: break;

        case Load:        
            if (chooseComplexNumberTo("load"))
               c1 = loadComplex();
            else
               c0 = loadComplex();
            break;

        case Display:
           c = chooseComplexNumberTo("display")?c1:c0;
           display(c); 
           break;  

        case Move: // move the cResult to c1 or c0
            if(chooseComplexNumberTo("set equal to the result")){
               c1=cResult;
               display(c1);
            }else{
               c0=cResult;
               display(c0);
            }
            break; 

        case Conjugate:
           if(chooseComplexNumberTo("conjugate")){
            c1=complexConjugate(c1);
            display(c1);
           }else{
            c0=complexConjugate(c0);
            display(c0);
           }
           
           break;

        case Add:    
           cResult = add(c1, c0); 
           display(cResult);
           break;      

        case Subtract: 
           cResult = subtract(c1, c0); 
           display(cResult);
           break;

        case Multiply: 
           cResult= multiply(c1, c0);
           display(cResult);
           break;
        case Divide:
           assert(c0.real!=0 && c0.imag!=0);
           cResult=divide(c0,c1);
           display(cResult);
           break;     
        

        default:
            printf("Bad menu value entered; ");
    }
    printf("\n");
}
// DO NOT CHANGE THIS FUNCTION
Complex loadComplex(){
   Complex cTemp;
   printf("\tEnter the real component : ");
   scanf("%lf", &cTemp.real);

   printf("\tEnter the imaginary component : ");
   scanf("%lf", &cTemp.imag);
   printf("\n");
   return cTemp;
}
// DO NOT CHANGE THIS FUNCTION
int chooseComplexNumberTo(char* operation){
    int choice = 0;
    printf("\nWhich complex number do you wish to %s? (enter 0 or 1): ", operation);
    scanf("%d", &choice);
    return choice;
}
void display(Complex c){
if(c.imag>0){   
printf("\n%.3f + %.3fi", c.real, c.imag);}
else{
printf("\n%.3f%.3fi", c.real, c.imag);}
}

Complex add(Complex c0, Complex c1){
Complex aTemp;
aTemp.real=(c0.real+c1.real);
aTemp.imag=(c0.imag+c1.imag);
return aTemp;
}
Complex subtract(Complex c0, Complex c1){
Complex sTemp;
sTemp.real=(c0.real-c1.real);
sTemp.imag=(c0.imag-c1.imag);
return sTemp;
}
Complex multiply(Complex c0, Complex c1){
Complex mTemp;
mTemp.real=((c0.real*c1.real)-(c0.imag*c1.imag));
mTemp.imag=((c0.real*c1.imag)+(c1.real*c0.imag));
return mTemp;
}
Complex complexConjugate(Complex c){
Complex cTemp;
cTemp.real=c.real;
cTemp.imag=c.imag*-1;
return cTemp;
}
Complex divide(Complex c0, Complex c1){
Complex dTempNum;
Complex dTempDen;
Complex dTemp;
dTempNum=multiply(c1,complexConjugate(c0));
dTempDen=multiply(c0,complexConjugate(c0));
dTemp.real=dTempNum.real/dTempDen.real;
dTemp.imag=dTempNum.imag/dTempDen.real;
return dTemp;
}





