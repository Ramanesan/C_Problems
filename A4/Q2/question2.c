#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DMY_MonthDY(char *buffer, const char *str);
void MonthDY_DMY(char *buffer, const char *str);

void DMY_MonthDY(char *buffer, const char *str){
    int i =0; int j=0; int len = 0; char *token = " " ; char* month = " "; char *day = " "; char *year = " "; char string[11] = " "; char* nmonth = " ";
    strcpy(string,str);
    day =strtok(string,"/");
    month = strtok(NULL,"/");
    year = strtok(NULL,"/");
    char *ptr;
    long val = 0 ;long val1 = 0;  long val2 = 0;
    val = strtol(month, &ptr, 10);
    val1 = strtol(day, &ptr, 10);
    val2 =strtol(year, &ptr, 10);
    
    if (val == 1 ){
        nmonth = "January";
        
        sprintf(buffer, "%s   %2d, %4d", nmonth,val1,val2 ) ;
    }
    else if (val == 2 ){
        nmonth = "February";
        
        sprintf(buffer, "%s  %2d, %4d", nmonth,val1,val2 )  ;
    }
    else if (val == 3 ){
        nmonth = "March";
        
        sprintf(buffer, "%s     %2d, %4d", nmonth,val1,val2 ); 
    }
    else if (val == 4 ){
        nmonth ="April";
        
        sprintf(buffer, "%s     %2d, %4d", nmonth,val1,val2 ) ;
    }
    else if (val == 5 ){
        nmonth = "May";
        
       sprintf(buffer, "%s       %2d, %4d", nmonth,val1,val2 ) ;
        
    }
    else if (val == 6 ){
        nmonth = "June";
        
        sprintf(buffer, "%s      %2d, %4d", nmonth,val1,val2 ) ;
        
    }
    else if (val== 7 ){
        nmonth = "July";
        
        sprintf(buffer, "%s      %2d, %4d", nmonth,val1,val2 ); 
       
    }
    else if (val == 8 ){
        nmonth = "August";
        
       sprintf(buffer, "%s    %2d, %4d", nmonth,val1,val2 ) ;
      
    }
    else if (val == 9){
        nmonth = "September";
        
        sprintf(buffer,"%s %2d, %4d",nmonth,val1,val2 ) ;
    
    }
    else if (val == 10 ){
        nmonth ="October";
         
      sprintf(buffer, "%s   %2d, %4d", nmonth,val1,val2 ) ;
    
    }
    else if (val == 11 ){
        nmonth = "November";
        
       sprintf(buffer, "%s  %2d, %4d", nmonth,val1,val2 ) ;
    
    }
    else if (val== 12 ){
        nmonth =  "December";
        
      sprintf(buffer, "%s  %2d, %4d", nmonth,val1,val2 ) ;
     
    }


}

void MonthDY_DMY(char *buffer, const char *str){
    int i =0; int j=0; int len = 0; char *token = " " ; char* month = " "; char *day = " "; char *year = " "; char string[20] = " "; int nmonth = 0;
    strcpy(string,str);
    month = strtok(string," ");
    day =strtok(NULL,",");
    year = strtok(NULL," ");
    char *ptr;
    long val1 = strtol(day, &ptr, 10);
    long val2 =strtol(year, &ptr, 10);

    if (strcmp(month,"January") == 0 ){
        nmonth = 1;
        
        sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 ) ;
    }
    else if (strcmp(month,"February") == 0 ){
        nmonth = 2;
        
        sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 )  ;
    }
    else if (strcmp(month,"March") == 0 ){
        nmonth = 3;
        
        sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 ); 
    }
    else if (strcmp(month,"April") == 0 ){
        nmonth =4;
        
        sprintf(buffer, "%02d/%02d/%04d",val1,nmonth,val2 ) ;
    }
    else if (strcmp(month,"May") == 0 ){
        nmonth = 5;
        
       sprintf(buffer, "%02d/%02d/%04d",val1,nmonth,val2 ) ;
        
    }
    else if ( strcmp(month,"June") == 0 ){
        nmonth = 6;
        
        sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 ) ;
        
    }
    else if (strcmp(month,"July") == 0 ){
        nmonth = 7;
        
        sprintf(buffer, "%02d/%02d/%04d",val1,nmonth,val2 ); 
       
    }
    else if (strcmp(month,"August") == 0 ){
        nmonth = 8;
        
       sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 ) ;
      
    }
    else if (strcmp(month,"September") == 0){
        nmonth = 9;
        
        sprintf(buffer,"%02d/%02d/%04d",val1,nmonth,val2 ) ;
    
    }
    else if (strcmp(month,"October") == 0 ){
        nmonth =10;
        
      sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 ) ;
    
    }
    else if ( strcmp(month,"November") == 0 ){
        nmonth = 11;
        
       sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 ) ;
    
    }
    else if (strcmp(month,"December") == 0 ){
        nmonth =  12;
        
      sprintf(buffer, "%02d/%02d/%04d", val1,nmonth,val2 ) ;
     
    }





}


int main(){
char format1[12][11] = { "01/01/1970"
                       , "10/02/1763"
                       , "15/03/0044"
                       , "18/04/1982"
                       , "05/05/1789"
                       , "06/06/1944"
                       , "01/07/1867"
                       , "03/08/1492"
                       , "02/09/1945"
                       , "24/10/1917"
                       , "11/11/1918"
                       , "08/12/1980"
                       };
char format2[12][19] = { "January    1, 1970" // First Day of History (according to computers)
                       , "February  10, 1763" // France cedes Canada to England
                       , "March     15,   44" // Assassination of Julius Caesar
                       , "April     18, 1982" // Canada Achieves Sovereignty 
                       , "May        5, 1789" // French Revolution
                       , "June       6, 1944" // D-Day Landings of WWII
                       , "July       1, 1867" // Confederation of Canada
                       , "August     3, 1492" // Christopher Columbus Sets Sail for the Americas
                       , "September  2, 1945" // WWII Surrender of Japan
                       , "October   24, 1917" // October Revolution (Julian Calendar)
                       , "November  11, 1918" // WWI Armistice
                       , "December   8, 1980" // Murder of John Lennon
                       };
    
    char buffer1[12][11];
    char buffer2[12][19];
    
    printf ("-- DD\\MM\\YY to Month DD, YYYY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format1[i]);
        DMY_MonthDY(buffer2[i], format1[i]);
        printf("-> \"%s\"\n", buffer2[i]);
    }
    
    
    printf ("\n\n-- Month DD, YYYY to DD\\MM\\YY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format2[i]);
        MonthDY_DMY(buffer1[i], format2[i]);
        printf("-> \"%s\"\n", buffer1[i]);
    }
}