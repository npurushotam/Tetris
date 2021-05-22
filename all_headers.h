#ifndef ALL_HEADERS_H_INCLUDED
#define ALL_HEADERS_H_INCLUDED

#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include <ctime>
#include<bits/stdc++.h>
using namespace std ;
#define F first
#define S second
#define PB push_back

#define WH  500         //          window height
#define WL  400         //          window length
#define GWH  400         //          game window height
#define GWL  200         //          game window length
#define NGWH 120        //          next shape window height
#define NGWL 100        //          next shape window length
#define SGWH 120        //          score window height
#define SGWL 100        //          score window length

int N = 1 , bla = 0 ;
int gx = 180 , gy = 50 , ngx = 10 , ngy = 50 , sgx = 10 , sgy = 300 ;

// para meteres determining shape , position and state of current tetromino ;
pair <int,int> pos ;
int cr_st = 0 ;
int cr_shp = 0 ;
int nxt_st = 0 ;
int nxt_shp = 1 ;
int speed = 500 ;
int score = 0 ;

void drawString(float x, float y, float z, string s) {
    glRasterPos3f(x, y, z);

  for (int i =0 ; i< s.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
  }
  glFlush() ;
}

void dela (long long int n){
    int k =0;
    for(long long int i=0 ; i < n*1e7 ; i++){ k++ ; k--; }
}

void instruction (){

    glClearColor(255.0/255.0,0.0/255.0,0.0/255.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    drawString( 50 , 20 , 0 , " User Manual : " );
    drawString( 10 , 40 , 0 , " Arrow up key - rotate clockwise  " );
    drawString( 10 , 60 , 0 , " Arrow down key - rotate anti-clockwise  " );
    drawString( 10 , 80 , 0 , " Arrow left key - move left  " );
    drawString( 10 , 100 , 0 , " Arrow right key - move right " );
    drawString( 10 , 120 , 0 , " '+' : increase the speed " );
    drawString( 10 , 140 , 0 , " '-' : decrease the speed " );
    dela ( (long long int)100) ;
    glClearColor(82.0/255.0,233.0/255.0,10.0/255.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    drawString( 120 , 200 , 0 , " *** START *** " );
    dela ( (long long int)50) ;

    glClearColor(1.0,0.5,1.0,0.0);      //      game background
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

}

#endif // ALL_HEADERS_H_INCLUDED



