#ifndef MOVEMENTS_H_INCLUDED
#define MOVEMENTS_H_INCLUDED


bool chk(int x1,int y1,int chk_st ){
    for(int i=0 ; i <4 ; i++){
        if(SHP[cr_shp].bp[i][chk_st].F + pos.F + x1  <  0 ) return false ;
        if(SHP[cr_shp].bp[i][chk_st].F + pos.F + x1 > 9 ) return false ;
        if(SHP[cr_shp].bp[i][chk_st].S + pos.S + y1 < 0 ) return false ;
        if(SHP[cr_shp].bp[i][chk_st].S + pos.S + y1 > 19 ) return false ;
        if(cdata[SHP[cr_shp].bp[i][chk_st].S + pos.S + y1][SHP[cr_shp].bp[i][chk_st].F + pos.F + x1] ) return false ;
    }

//    cout << SHP[x].bp[0][0].F + pos.F + x1  <<endl;
    return true ;
}

bool chkr( int chk_st ){
//    cout << "inside chk_r" \n <<endl;
    for(int i=0 ; i <4 ; i++){
        if(SHP[cr_shp].bp[i][chk_st].F + pos.F <  0 ) return false ;
        if(SHP[cr_shp].bp[i][chk_st].F + pos.F > 9 ) return false ;
        if(SHP[cr_shp].bp[i][chk_st].S + pos.S < 0 ) return false ;
        if(SHP[cr_shp].bp[i][chk_st].S + pos.S > 19 ) return false ;
        if( cdata[SHP[cr_shp].bp[i][chk_st].S + pos.S][SHP[cr_shp].bp[i][chk_st].F + pos.F] ) return false ;
    }
    //  cout << SHP[x].bp[0][0].F + pos.F + x1  <<endl;
    return true ;
}

bool to_stop(){
    bool cond = false ;
     for(int i=0 ; i <4 ; i++){
        if(SHP[cr_shp].bp[i][cr_st].S + pos.S + 1 == 20 ) { cond = true ; }
        if(cdata[SHP[cr_shp].bp[i][cr_st].S + pos.S + 1][SHP[cr_shp].bp[i][cr_st].F + pos.F ] ) {
                cond = true ;
        }
     }
    if(cond){
        for(int i=0 ; i <4 ; i++){
            cdata[SHP[cr_shp].bp[i][cr_st].S + pos.S][SHP[cr_shp].bp[i][cr_st].F + pos.F] = cr_shp + 1  ;
        }
       }

    return cond ;
}

void draw_nxt(){
 //   cout << "inside draw next funciton\n" ;
    glColor3f(SHP[nxt_shp].t_col[0]  ,SHP[nxt_shp].t_col[1],SHP[nxt_shp].t_col[2]);
    for ( int i =0 ; i < 4 ; i++){
        int x = ngx+40 + SHP[nxt_shp].bp[i][nxt_st].F*20 ;
        int y =  ngy + 40 +SHP[nxt_shp].bp[i][nxt_st].S*20  ;
        glBegin( GL_POLYGON );
        glVertex2f(x , y );

        glVertex2f( x+ 20, y);
        glVertex2f( x + 20, y+20);
        glVertex2f( x, y+20);
        glEnd();
        glFlush() ;
    }
    {
    glColor3f(1.0,1.0,1.0);
    for(int i = ngx ; i<= ngx+NGWL ; i+=20){
        glBegin(GL_LINES);
        glVertex2f(i,ngy);
        glVertex2f(i,ngy+NGWH);
        glEnd();
    }
    for(int i = ngy ; i<= ngy+NGWH ; i+=20){
        glBegin(GL_LINES);
        glVertex2f(ngx,i);
        glVertex2f(ngx+NGWL, i);
        glEnd();
    }
    glFlush();
}

    glFlush() ;
}

void ref_tetro(){
    int st =0 ;
    // cout << "inside ref tetro\n" ;
     // for ( ; st < 4 ; st ++){
            draw_window();
            for ( int i =0 ; i < 4 ; i++){
                 draw_unit(pos.F + SHP[cr_shp].bp[i][cr_st].F ,pos.S +SHP[cr_shp].bp[i][cr_st].S , cr_shp );
          //   cout <<pos.F*20+gx +SHP[x].bp[i][0].F*20 <<endl;
            }

            for(int i=0 ;i < 20 ; i++ ){
                for (int j=0 ;j < 10 ; j++ ){
                        //cout << cdata[i][j] <<" " ;
                    if( cdata[i][j] == 0 ) continue ;
                    draw_unit( j, i,cdata[i][j]-1) ;
                }
                //cout << endl ;
            }
            draw_next_window() ;
            draw_nxt() ;
            draw_mesh() ;
       // }
}

void move_left(){
    //cout << "inside left fun\n" ;
        if(chk(-1,0,cr_st)){
            pos.F-=1 ;
        }
            ref_tetro();

}

void move_up(){
    //  cout << "inside up fun \n" ;
        if(chk(0,-1,cr_st)){
            pos.S-=1 ;
        }
            ref_tetro();
}

void move_down(){
    // cout << "inside down fun\n" ;
        if(chk(0,1,cr_st)){
            pos.S+=1 ;
        }
            ref_tetro();
}

void move_right(){
    // cout << "inside right fun \n" ;
        if(chk(1,0,cr_st)){
            pos.F+=1 ;
        }
            ref_tetro();
}
void rot_tet(int i){
    int n_st = (cr_st+i+4)%4 ;

    if( chkr(n_st) ){
        cr_st = n_st ;
    }
    ref_tetro() ;
    glFlush() ;
}


void test_shapes(){

    for(int z=0 ; z < 7 ; z ++ ){ cr_shp = z ;
        for (int st =0 ; st < 4 ; st ++){
            draw_window();
            for ( int i =0 ; i < 4 ; i++){
                 draw_unit( 4+SHP[z].bp[i][st].F , 4+SHP[z].bp[i][st].S ,z );
            }
            draw_mesh();
             dela (10) ;
        }
    }

    return ;
}



#endif // MOVEMENTS_H_INCLUDED
