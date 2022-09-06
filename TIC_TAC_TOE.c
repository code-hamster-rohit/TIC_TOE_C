#include <stdio.h>
#include <stdlib.h>
int pts_1=0,pts_2=0,ban_h[3]={10,21,20},ban_v[3]={10,111,11},ban_dpcount=0,ban_dscount=0;
void grid(char arr_g[3][3]){
    printf(" %c |",arr_g[0][0]);printf(" %c |",arr_g[0][1]);printf(" %c ",arr_g[0][2]);printf("\n");
    printf(" __ ");printf(" __ ");printf(" __ ");printf("\n");
    printf(" %c |",arr_g[1][0]);printf(" %c |",arr_g[1][1]);printf(" %c ",arr_g[1][2]);printf("\n");
    printf(" __ ");printf(" __ ");printf(" __ ");printf("\n");
    printf(" %c |",arr_g[2][0]);printf(" %c |",arr_g[2][1]);printf(" %c ",arr_g[2][2]);printf("\n");
}
void player_1(char arr_1[3][3],char pc1){
    char row_coloumn_1[10];
    printf("ENTER ROW AND COLOUMN AS row,coloumn : ");
    fgets(row_coloumn_1,sizeof(row_coloumn_1),stdin);
    arr_1[(row_coloumn_1[0]-'0')-1][(row_coloumn_1[2]-'0')-1]=pc1;
}
void player_2(char arr_2[3][3],char pc2){
    char row_coloumn_2[10];
    printf("ENTER ROW AND COLOUMN AS row,coloumn : ");
    fgets(row_coloumn_2,sizeof(row_coloumn_2),stdin);
    arr_2[(row_coloumn_2[0]-'0')-1][(row_coloumn_2[2]-'0')-1]=pc2;
}
int player_scorer(char arr_s[3][3],int fchance){
    int count_hx=0,count_ho=0,count_vx=0,count_vo=0,signal=0,diag_px=0,diag_po=0,diag_sx=0,diag_so=0;
    for(int p=0;p<3;p++){
        for(int q=0;q<3;q++){
            if(arr_s[p][q]=='x'&&ban_h[p]!=p){
                count_hx++;
            }
            else if(arr_s[p][q]=='o'&&ban_h[p]!=p){
                count_ho++;
            }
        }
        if(count_hx==3&&count_ho==0){
            if(fchance==0){
            printf("PLAYER 1 IS WINNER !\n");
            pts_1=pts_1+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if(count_hx==2&&count_ho==1){
            if(fchance==1){
            printf("PLAYER 2 GETS 1 PT !\n");
            pts_2++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if(count_ho==2&&count_hx==1){
            if(fchance==0){
            printf("PLAYER 1 SCORES 1 PT !\n");
            pts_1++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if(count_ho==3&&count_hx==0){
            if(fchance==1){
            printf("PLAYER 2 IS WINNER !\n");
            pts_2=pts_2+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }

        if((count_hx+count_ho)>=3){
            ban_h[p]=p;
        }
        count_hx=0;count_ho=0;
    }
    for(int r=0;r<3;r++){
        for(int s=0;s<3;s++){
            if(arr_s[s][r]=='x' && ban_v[r]!=r){
                count_vx++;
            }
            else if(arr_s[s][r]=='o'  && ban_v[r]!=r){
                count_vo++;
            }
        }
        if(count_vx==3&&count_vo==0){
            if(fchance==0){
            printf("PLAYER 1 IS WINNER !\n");
            pts_1=pts_1+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if(count_vx==2&&count_vo==1){
            if(fchance==1){
            printf("PLAYER 2 GETS 1 PT !\n");
            pts_2++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if(count_vo==2&&count_vx==1){
            if(fchance==0){
            printf("PLAYER 1 SCORES 1 PT !\n");
            pts_1++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if(count_vo==3&&count_vx==0){
            if(fchance==1){
            printf("PLAYER 2 IS WINNER !\n");
            pts_2=pts_2+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if((count_vx+count_vo)>=3){
            ban_v[r]=r;
        }
        count_vx=0;count_vo=0;
    }
    for(int d=0;d<3;d++){
        if(arr_s[d][d]=='x'&&ban_dpcount==0){
            diag_px++;
        }
        else if(arr_s[d][d]=='o'&&ban_dpcount==0){
            diag_po++;
        }
    }
    if(diag_px==3&&diag_po==0){
            if(fchance==0){
            printf("PLAYER 1 IS WINNER !\n");
            pts_1=pts_1+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            signal++;
            }
        }
        else if(diag_px==2&&diag_po==1){
            if(fchance==1){
            printf("PLAYER 2 HAS SCORED 1 PT !\n");
            pts_2++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        else if(diag_po==2&&diag_px==1){
            if(fchance==0){
            printf("PLAYER 1 HAS SCORED 1 PT !\n");
            pts_1++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        else if(diag_po==3&&diag_px==0){
            if(fchance==1){
            printf("PLAYER 2 IS WINNER !\n");
            pts_2=pts_2+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if((diag_px+diag_po)>=3)
            ban_dpcount++;
    for(int e=0;e<3;e++){
        if(arr_s[e][2-e]=='x'&& ban_dscount==0){
            diag_sx++;
        }
        else if(arr_s[e][2-e]=='o'&& ban_dscount==0){
            diag_so++;
        }
    }


        if(diag_sx==3&&diag_so==0){
            if(fchance==0){
            printf("PLAYER 1 IS WINNER !\n");
            pts_1=pts_1+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        else if(diag_sx==2&&diag_so==1){
            if(fchance==1){
            printf("PLAYER 2 HAS SCORED 1 PT !\n");
            pts_2++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        else if(diag_so==2&&diag_sx==1){
            if(fchance==0){
            printf("PLAYER 1 HAS SCORED 1 PT !\n");
            pts_1++;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        else if(diag_so==3&&diag_sx==0){
            if(fchance==1){
            printf("PLAYER 2 IS WINNER !\n");
            pts_2=pts_2+3;
            printf("PLAYER 1 : %d\n",pts_1);
            printf("PLAYER 2 : %d\n",pts_2);
            }
        }
        if((diag_sx+diag_so)>=3)
                ban_dscount++;
return signal;
}

int main(){
    char arr_o[3][3]={{'_','_','_'},
                      {'_','_','_'},
                      {'_','_','_'}};
    char player_choice[10];int sig;
    printf("CHOOSE AMONG X and O WHICHEVER YOU LIKE choose for player 1 first and then for player 2 as p1,p2\n");
    fgets(player_choice,sizeof(player_choice),stdin);
    for(int k=0;k<9;k++){
        if(k%2==0){
            printf("CHANCE FOR PLAYER 1 :)\n");
            player_1(arr_o,player_choice[0]);
            grid(arr_o);
            sig=player_scorer(arr_o,0);
        }
        else{
            printf("CHANCE FOR PLAYER 2 :)\n");
            player_2(arr_o,player_choice[2]);
            grid(arr_o);
            sig=player_scorer(arr_o,1);
        }
    }
    printf("MATCH SUMMARY :-\n");
    printf("PTS. SCORED BY EACH PLAYER :-\n");
    printf("PLAYER 1 : %d\n",pts_1);
    printf("PLAYER 2 : %d\n",pts_2);
    return 0;
}
