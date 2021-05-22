#ifndef MAIN_DRIVER_H_INCLUDED
#define MAIN_DRIVER_H_INCLUDED


void driver(int value){
    glutKeyboardFunc(keyb) ;
    glutSpecialFunc(SpecialInput);

	move_down() ;
    if(to_stop()){
        cr_shp = nxt_shp ;
        nxt_shp = rand() % 7 ;
        pos.F = 4 ; pos.S = 1 ;
    }
    for(int i=0 ; i < 10 ; i++){
        if(cdata[1][i]){
                game_over() ;
                 exit(0) ;
            return ;
        }
    }
    bonus() ;
    draw_score_window() ;
    up_score() ;

    glutTimerFunc(speed,driver,0);
}


#endif // MAIN_DRIVER_H_INCLUDED
