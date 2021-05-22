#ifndef CELL_DATA_H_INCLUDED
#define CELL_DATA_H_INCLUDED
int cdata[20][10] ={} ; //      cell data , 0 cell is empty , 1-7 is n-1 tetromino type


void bonus (){
    for(int i=19 ; i > 0 ; i --){
        int l = 0 ;
        for(int j=0 ;j <10 ; j++){
            if(cdata[i][j]){
                l++;
            }
        }
        if(l==10){
                score  += 10 ;
            for(int i1 = i ; i1 > 1 ; i1-- ){
                    for(int j1 = 0 ; j1 < 10 ; j1 ++){
                        cdata[i1][j1] = cdata[i1-1][j1] ;
                    }
            }
        }
    }

}

#endif // CELL_DATA_H_INCLUDED
