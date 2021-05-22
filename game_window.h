#ifndef GAME_WINDOW_H_INCLUDED
#define GAME_WINDOW_H_INCLUDED
//                                     rows * col = 20 * 10
void draw_window(){
    glColor3f(0.0,0.0,0.0);
    drawString( gx+40 ,  gy -10  , 0 , "**GAME : TETRIS**" );  glFlush() ;
    glColor3f(1.0,0.0,0.0);
    glBegin( GL_POLYGON );
    glVertex2f(gx , gy );
    glVertex2f(gx+ GWL, gy);
    glVertex2f(gx + GWL, gy+GWH);
    glVertex2f(gx, gy+GWH);
    glEnd();
}
void draw_next_window(){
    glColor3f(0.0,0.0,0.0);
    drawString( ngx+10 , ngy -10  , 0 , "**NEXT**" );  glFlush() ;
    glColor3f(1.0,0.0,0.0);
    glBegin( GL_POLYGON );
    glVertex2f(ngx , ngy );
    glVertex2f(ngx+ NGWL, ngy);
    glVertex2f(ngx + NGWL, ngy+NGWH);
    glVertex2f(ngx, ngy+NGWH);
    glEnd();
}
void draw_score_window(){
    glColor3f(0.0,0.0,0.0);
    drawString( sgx+10 , sgy -10  , 0 , "**SCORE**" );  glFlush() ;
    glColor3f(1.0,0.0,0.0);
    glBegin( GL_POLYGON );
    glVertex2f(sgx , sgy );
    glVertex2f(sgx+ SGWL, sgy);
    glVertex2f(sgx + SGWL, sgy+SGWH);
    glVertex2f(sgx, sgy+SGWH);
    glEnd();

}

void draw_unit(int x , int y , int k ){
    glColor3f( SHP[k].t_col[0]  ,SHP[k].t_col[1],SHP[k].t_col[2]);
    x = gx + 20 * x ;
    y = gy + 20 * y ;
    glBegin( GL_POLYGON );
    glVertex2f(x , y );
    glVertex2f( x+ 20, y);
    glVertex2f( x + 20, y+20);
    glVertex2f( x, y+20);

    glEnd();
    glFlush() ;
}



void draw_mesh(){
    glColor3f(0.0,0.0,0.0);
    drawString( gx-35 , gy+60, 0 , "FULL" );  glFlush() ;

    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2f(gx,gy+60);
        glVertex2f(gx+GWL,gy+60);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    for(int i = gx ; i<= gx+GWL ; i+=20){
        glBegin(GL_LINES);
        glVertex2f(i,gy);
        glVertex2f(i,gy+GWH);
        glEnd();
    }
    for(int i = gy ; i<= gy+GWH ; i+=20){
        if(i==gy+60) continue ;
        glBegin(GL_LINES);
        glVertex2f(gx,i);
        glVertex2f(gx+GWL, i);
        glEnd();
    }

    glFlush();
}


void draw_scr(int x1,int y1, int d){

    glColor3f(1.0,1.0,1.0);
    if(dig[d][0]){
            glBegin(GL_LINES); glVertex2f(x1,y1); glVertex2f(x1+20, y1); glEnd();
    }
     if(dig[d][1]){
            glBegin(GL_LINES); glVertex2f(x1,y1); glVertex2f(x1, y1+20); glEnd();
    }
     if(dig[d][2]){
            glBegin(GL_LINES); glVertex2f(x1,y1+20); glVertex2f(x1+20, y1+20); glEnd();
    }
     if(dig[d][3]){
            glBegin(GL_LINES); glVertex2f(x1+20,y1); glVertex2f(x1+20, y1+20); glEnd();
    }
     if(dig[d][4]){
            glBegin(GL_LINES); glVertex2f(x1,y1+20); glVertex2f(x1, y1+40); glEnd();
    }
     if(dig[d][5]){
            glBegin(GL_LINES); glVertex2f(x1,y1+40); glVertex2f(x1+20, y1+40); glEnd();
    }
     if(dig[d][6]){
            glBegin(GL_LINES); glVertex2f(x1+20,y1+40); glVertex2f(x1+20, y1+20); glEnd();
    }

}

void up_score(){
    int scr[3] = {} ;
    int ps = score ;
    for(int i=0 ;i < 3 ; i ++){
        scr[2-i] = ps % 10 ; ps /= 10 ;
    }
    int x1 = sgx + 10 , y1 = sgy  + 20 ;
    draw_scr(x1,y1,scr[0]) ;
    x1 = sgx + 10 +20 +10 ;
    draw_scr(x1,y1,scr[1]) ;
    x1 = sgx + 10 +20 +10 +20 + 10 ;
    draw_scr(x1,y1,scr[2]) ;

}

void game_over(){
    glClearColor(1,0,0,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    drawString( 140 , 210 , 0 , "***GAME OVER***" );
    string sc ="" ;
    sc += (char)(48+score%10) ; score/=10 ;
    sc += (char)(48+score%10) ; score/=10 ;
    sc += (char)(48+score%10) ; score/=10 ;
    reverse(sc.begin(),sc.end()) ;
    drawString( 140 , 240 , 0 , "YOUR SCORE : "+sc );
    glFlush() ;
    dela(40) ;

}



#endif // GAME_WINDOW_H_INCLUDED
