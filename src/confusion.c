#include <zephyr/kernel.h>
#include <math.h>
#include "confusion.h"
#include "adc.h"

/* 
  K-means algorithm should provide 6 center points with
  3 values x,y,z. Let's test measurement system with known
  center points. I.e. x,y,z are supposed to have only values
  1 = down and 2 = up
  
  CP matrix is thus the 6 center points got from K-means algoritm
  teaching process. This should actually come from include file like
  #include "KmeansCenterPoints.h"
  
  And measurements matrix is just fake matrix for testing purpose
  actual measurements are taken from ADC when accelerator is connected.
*/ 

int CP[6][3]={
	                     {1,0,0},
						 {2,0,0},
						 {0,1,0},
						 {0,2,0},
						 {0,0,1},
						 {0,0,2}
};

int measurements[6][3]={
	                     {1,0,0},
						 {2,0,0},
						 {0,1,0},
						 {0,2,0},
						 {0,0,1},
						 {0,0,2}
};

int CM[6][6]= {0};



void printConfusionMatrix(void)
{
	printk("Confusion matrix = \n");
	printk("   cp1 cp2 cp3 cp4 cp5 cp6\n");
	for(int i = 0;i<6;i++)
	{
		printk("cp%d %d   %d   %d   %d   %d   %d\n",i+1,CM[i][0],CM[i][1],CM[i][2],CM[i][3],CM[i][4],CM[i][5]);
	}
}

void makeHundredFakeClassifications(void)
{
	for(int i = 0;i<6;i++)
	{
		int x = measurements[i][0];
		int y = measurements[i][1];
		int z = measurements[i][2];
		for(int j = 0;j<100;j++)
		{
    		int winner = calculateDistanceToAllCentrePointsAndSelectWinner(x,y,z);
			CM[i][winner] = CM[i][winner]+1;
		}
	}
}

void makeOneClassificationAndUpdateConfusionMatrix(int direction)
{
   // let's initialize Center points for current ADC and
   // accelerator
   CP[0][0] = 1850;
   CP[0][1] = 1500;
   CP[0][2] = 1500;
   CP[1][0] = 1200;
   CP[1][1] = 1500;
   CP[1][2] = 1500;

   CP[2][0] = 1500;
   CP[2][1] = 1850;
   CP[2][2] = 1500;
   CP[3][0] = 1500;
   CP[3][1] = 1200;
   CP[3][2] = 1500;

   CP[4][0] = 1500;
   CP[4][1] = 1500;
   CP[4][2] = 1850;
   CP[5][0] = 1500;
   CP[5][1] = 1500;
   CP[5][2] = 1200;
   // make one measurement with ADC to get x,y,z values.
   struct Measurement m = readADCValue();
   // and then calculate that measurement result distance to all 6 centre points
   // and select shortest distance.
   int winner = calculateDistanceToAllCentrePointsAndSelectWinner(m.x,m.y,m.z);
   CM[direction][winner] = CM[direction][winner]+1;
}

int calculateDistanceToAllCentrePointsAndSelectWinner(int x,int y,int z)
{
   int minimumDistance = 10000;
   int centerPoint = 7; 
   for(int i=0;i<6;i++)
   {
	  int distance = sqrt(pow(CP[i][0]-x,2) + pow(CP[i][1]-y,2) + pow(CP[i][2]-z,2));
	  if(distance<minimumDistance)
	  {
         centerPoint = i;
		 minimumDistance = distance;
	  }
   }
   return centerPoint;
}

void resetConfusionMatrix(void)
{
	for(int i=0;i<6;i++)
	{ 
		for(int j = 0;j<6;j++)
		{
			CM[i][j]=0;
		}
	}
}

