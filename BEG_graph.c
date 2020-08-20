#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//bilalemirgunay

void init(int array[][5]){			//initially sets the elements of the array to 0

    int i,j;
   		for(i = 0; i < 5; i++)
        	for(j = 0; j < 5; j++)
            	array[i][j] = 0;
	}

	
void addEdge(int array[][5],int i, int j){			//when the function is called, 1 will be assigned to the corresponding place of the array
     array[i][j] = 1;
	}

	
void printMatrix(int array[][5]){				// print array
     int i, j;

     for(i = 0; i < 5; i++)
     {
         for(j = 0; j < 5; j++)
         {
             printf("%d ", array[i][j]);
         }
         printf("\n");
     }
}
	
int main(){
	int number;	int row=0;	int column=0;
	int array[5][5];		
	FILE *f=fopen("number.txt","r");
	
	init(array);	// sets all elements of the array to 0

	while(fscanf(f,"%d",&number)!=EOF){
		if(number==1){
			addEdge(array,row,column);	
		}
		column++;
		
		if(column==5){		// If column is 5, reset column and move to the next row
			column=0;
			row++;	// When the column is finished go to the next row
		}		
	}
	fclose(f);
	
	printMatrix(array);
	
	
	int inputDeg=0;	int outputDeg=0;	int j;	int i;
	printf("Enter node number:");	scanf("%d",&i);
	for(j=0;j<5;j++){			//input degree
		if(array[j][i]==1)
		inputDeg++;
	}
	for(j=0;j<5;j++){			//output degree
		if(array[i][j]==1)
		outputDeg++;
	}
	printf("Input Degree : %d",inputDeg);
	printf("\nOutput Degree : %d",outputDeg);
	
	int edgeCount=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(array[i][j]==1)	// only the entry degrees or just the sum of exit degrees gives us the number of edges
			edgeCount++;
		}
		
		
	}
	
	
	printf("\nNumber of edge : %d",edgeCount);	

	getch();
}
