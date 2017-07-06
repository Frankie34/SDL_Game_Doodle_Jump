
//
//  main.c
//  test
//
//  Created by Frankie Zhu on 03/07/2017.
//  Copyright © 2017 Frankie Zhu. All rights reserved.
//fps: 60


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sdl2game.h"

//set image pointer
Image* Up;
Image* Down;
Image* Left;
Image* Right;

//object parameter
int x = 72;
int y = 554;
int radius = 24;
int gravity = 2;
int moving = 5;
int y_speed = 3;
int x_speed = 3;
int tolerance = 2;
int counter = 0;

//brick color
int brick_color_R = 255;
int brick_color_G = 255;
int brick_color_B = 255;
int brick_border_color_R = 0;
int brick_border_color_G = 0;
int brick_border_color_B = 0;

//brick pseudo-random address array parameter
int bricks_address_x[4];//x axis position array
int bricks_address_y[5];//y axis position array
int bricks_address[4][6][2];// main array
int k=0;
int j=0;
int p1=0;
int p2=0;
int p3=0;
int p4=0;
int p5=0;
int p6=0;

int p7=0;
int p8=0;
int p9=0;
int p10=0;
int p11=0;
int cycle_length = 667;

//brick move parameter
int brick_speed = 0;
int brick_speed_additon = 1;

//starter parameter {0,1,2}
int start = 1;


void setup() {
    //window size
    size(375, 667);

    //image loading
    Up = loadimage("image/up.png");
    Down = loadimage("image/down.png");
    Left = loadimage("image/left.png");
    Right = loadimage("image/right.png");

}



void draw(float stateTime) {
    //x axis position array init
    for(k=0;k<=3;k++)
    {
        bricks_address_x[k]=k*75;
    }

    //y axis position array init
    for(k=0;k<=4;k++)
    {
        bricks_address_y[k]=48+10+130*k;
    }

        bricks_address_y[5]=48+10-130;

    //main position array init
    for(k=0;k<=3;k++)
    {
       for(j=0;j<=5;j++)
       {
        bricks_address[k][j][0] = bricks_address_x[k];
        bricks_address[k][j][1] = bricks_address_y[j];
       }
    }


    // starter
    if(start == 1){
        srand( (unsigned)time( NULL ) );
        start = 0;
    }else if(start == 2){
        brick_speed+= brick_speed_additon;
        //if(bricks_address[p1][0][1]+brick_speed == 100){}
    }

    //start-brick
    coloredfillrect(0, 578+brick_speed , 150, 30, brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);

    //brick-array
    if(p1 == 0)
    {
        p1 = rand()%100;
        p1 = p1%4;
    }
    coloredfillrect(bricks_address[p1][0][0], bricks_address[p1][0][1]+brick_speed, 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p2 == 0)
    {
        p2 = rand()%100;
        p2 = p2%4;
    }
    coloredfillrect(bricks_address[p2][1][0], bricks_address[p2][1][1]+brick_speed , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p3 == 0)
    {
        p3 = rand()%100;
        p3 = p3%4;
    }
    coloredfillrect(bricks_address[p3][2][0], bricks_address[p3][2][1]+brick_speed , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p4 == 0)
    {
        p4 = rand()%100;
        p4 = p4%4;
    }
    coloredfillrect(bricks_address[p4][3][0], bricks_address[p4][3][1]+brick_speed , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p6 == 0)
    {
        p6 = rand()%100;
        p6 = p6%4;
    }
    coloredfillrect(bricks_address[p6][5][0], bricks_address[p6][5][1]+brick_speed , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);

    /*##################################################
    ##################################################
    ##################################################*/

    if(p7 == 0)
    {
        p7 = rand()%100;
        p7 = p7%4;
    }
    coloredfillrect(bricks_address[p7][0][0], bricks_address[p7][0][1]+brick_speed- cycle_length, 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p8 == 0)
    {
        p8 = rand()%100;
        p8 = p8%4;
    }
    coloredfillrect(bricks_address[p8][1][0], bricks_address[p8][1][1]+brick_speed- cycle_length , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p9 == 0)
    {
        p9 = rand()%100;
        p9 = p9%4;
    }
    coloredfillrect(bricks_address[p9][2][0], bricks_address[p9][2][1]+brick_speed- cycle_length , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p10 == 0)
    {
        p10 = rand()%100;
        p10 = p10%4;
    }
    coloredfillrect(bricks_address[p10][3][0], bricks_address[p10][3][1]+brick_speed- cycle_length , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);
    if(p11 == 0)
    {
        p11 = rand()%100;
        p11 = p11%4;
    }
    coloredfillrect(bricks_address[p11][5][0], bricks_address[p11][5][1]+brick_speed- cycle_length , 150, 30,  brick_border_color_R, brick_border_color_G,brick_border_color_B, brick_color_R, brick_color_G , brick_color_B);

    /*##################################################
    ##################################################
    ##################################################*/
coloredcircle(x, y, radius,0,0,0);
     //BOOM adjust
    if (y>=554-tolerance+brick_speed&&y<=554+tolerance+brick_speed&&x>=0&&x<=0+150+24){
        moving = 0;
    }

    if (y>=bricks_address[p6][5][1]-radius-tolerance+brick_speed&&y<=bricks_address[p6][5][1]-radius+tolerance+brick_speed&&x>=bricks_address[p1][5][0]&&x<=bricks_address[p1][5][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p4][3][1]-radius-tolerance+brick_speed&&y<=bricks_address[p4][3][1]-radius+tolerance+brick_speed&&x>=bricks_address[p4][3][0]&&x<=bricks_address[p4][3][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p3][2][1]-radius-tolerance+brick_speed&&y<=bricks_address[p3][2][1]-radius+tolerance+brick_speed&&x>=bricks_address[p3][2][0]&&x<=bricks_address[p3][2][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p2][1][1]-radius-tolerance+brick_speed&&y<=bricks_address[p2][1][1]-radius+tolerance+brick_speed&&x>=bricks_address[p2][1][0]&&x<=bricks_address[p2][1][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p1][0][1]-radius-tolerance+brick_speed&&y<=bricks_address[p1][0][1]-radius+tolerance+brick_speed&&x>=bricks_address[p1][0][0]&&x<=bricks_address[p1][0][0]+150+24)
    {
        moving = 0;
    }

    /*##################################################
    ##################################################
    ##################################################*/

    if (y>=bricks_address[p11][5][1]-radius-tolerance+brick_speed- cycle_length&&y<=bricks_address[p11][5][1]-radius+tolerance+brick_speed- cycle_length&&x>=bricks_address[p1][5][0]&&x<=bricks_address[p1][5][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p10][3][1]-radius-tolerance+brick_speed- cycle_length&&y<=bricks_address[p10][3][1]-radius+tolerance+brick_speed- cycle_length&&x>=bricks_address[p4][3][0]&&x<=bricks_address[p4][3][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p9][2][1]-radius-tolerance+brick_speed- cycle_length&&y<=bricks_address[p9][2][1]-radius+tolerance+brick_speed- cycle_length&&x>=bricks_address[p3][2][0]&&x<=bricks_address[p3][2][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p8][1][1]-radius-tolerance+brick_speed- cycle_length&&y<=bricks_address[p8][1][1]-radius+tolerance+brick_speed- cycle_length&&x>=bricks_address[p2][1][0]&&x<=bricks_address[p2][1][0]+150+24)
    {
        moving = 0;
    }
    if (y>=bricks_address[p7][0][1]-radius-tolerance+brick_speed- cycle_length&&y<=bricks_address[p7][0][1]-radius+tolerance+brick_speed- cycle_length&&x>=bricks_address[p1][0][0]&&x<=bricks_address[p1][0][0]+150+24)
    {
        moving = 0;
    }

    /*##################################################
    ##################################################
    ##################################################*/


    //y axis movement adjust
    if(moving == 0)
    {
        y = y+brick_speed;
    }
    else if(moving == 1)
    {image(Up, x-radius, y-radius);}
    else if(moving == 2)
    {image(Down, x-radius, y-radius);}
    else if(moving)
    {
        y = y+gravity;
    }


    //x axis movement adjust
    if(moving == 3)
    {image(Left, x-radius, y-radius);}
    else if(moving == 4)
    {image(Right, x-radius, y-radius);}

}

//
void mousePress() {
}
void mouseMove() {
}
void mouseRelease() {
}

//
void keyDown() {
	//y axis movement parameter adjust
    if(key == KEY_W){
    	start = 2;
        moving = 1;
    	y = y-y_speed;
    }
	if(key == KEY_S&&moving != 0){
	   moving = 2;
	   y = y+y_speed;
	}

    //x axis movement parameter adjust
    if(key == KEY_A){
        moving = 3;
        x = x-x_speed;
	}
	if(key == KEY_D){
	   moving = 4;
	   x = x+x_speed;
	}
}
void keyUp() {
    //y axis movement parameter init
    if(key == KEY_W){
        moving = 5;
	}
	if(key == KEY_A){
        moving = 5;
	}

    //x axis movement parameter init
    if(key == KEY_S){
        moving = 5;
	}
	if(key == KEY_D){
        moving = 5;
	}

}

//
void close() {
	unloadimage(Down);
	unloadimage(Up);
	unloadimage(Left);
	unloadimage(Right);
}

