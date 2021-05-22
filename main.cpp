//                 Tetris main file - Project made by : Vaibhav Dixit  and N Purushotam Kumar  of COMP A, AIT PUNE
// A single player Tetris game. It includes a scoreboard and a window to display hints of the next tetromino.
// Instructions to play the game are provided on the main window.

#include "all_headers.h"
#include "cell_data.h"
#include "Tetromino.h"
#include "game_window.h"
#include "movements.h"
#include "keyboard_funcions.h"
#include "main_driver.h"

void init()
{
	glClearColor(1.0,0.5,1.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,WL, WH, 0) ;
	glEnable(GL_LINE_SMOOTH);
 //   glLineWidth(1.0);
	glFlush() ;
    pos = {4,1} ;
    state0() ;
    state1() ;
    state2() ;
    state3() ;
    dig_in() ;
//    t_box() ;
     srand(time(NULL)); //                  for random values every time
    cr_shp = (rand() % 100)%7 ;
    nxt_shp = (rand() % 100)%7 ;
   // nxt_shp = 1 ;
   // cr_shp = 3 ;


}


void display(){

    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(1);
    if(bla==0)    {
            bla ++ ;
        cout <<" User Manual : \n" ;
        cout <<" Arrow up key - rotate clockwise \n";
        cout <<" Arrow down key - rotate anti-clockwise \n";
        cout <<" Arrow left key - move left \n";
        cout <<" Arrow right key - move right \n";
        cout << " '+' : increase the speed \n" ;
        cout << " '-' : decrease the speed \n" ;
        instruction () ;
    }
 // test_shapes() ;

    draw_next_window();
    draw_window();
    draw_nxt() ;
    draw_mesh();
    draw_score_window() ;
    up_score() ;
    glFlush() ;
    return ;
}
int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(WL,WH);
	glutInitWindowPosition(800,150);
	glutCreateWindow(" Tetris ");
    init();
    glutKeyboardFunc(keyb) ;
    glutSpecialFunc(SpecialInput);
	glutDisplayFunc(display);
    glutTimerFunc(speed  ,driver,0);
	glutMainLoop();

	return 0;

}
