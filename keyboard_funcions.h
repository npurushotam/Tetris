#ifndef KEYBOARD_FUNCIONS_H_INCLUDED
#define KEYBOARD_FUNCIONS_H_INCLUDED

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
//            cout << "up\n" ;
            rot_tet(+1);
            //move_up() ;
            break;
        case GLUT_KEY_DOWN:
//            cout << "down\n" ;
            rot_tet(-1) ;
            //move_down();
            break;
        case GLUT_KEY_LEFT:
            move_left() ;
//            cout << "left\n" ;
            break;
        case GLUT_KEY_RIGHT:
//            cout << "right\n" ;
            move_right() ;
            break;

    }

}
void    keyb( unsigned char key , int x , int y  ){
    if(key==27)      //                 escape
    {
         exit(0) ;
    }
    else if(key==43)      //                + to inc speed
    {
         speed -= 100 ;
    }
    else if(key==45)      //                 - to dec speed
    {
          speed  += 100 ;
    }

}


#endif // KEYBOARD_FUNCIONS_H_INCLUDED
