#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/scrabble.h"
#include "util/print_board.h"

//Functia pentru prima cerinta.
void task0(char mat[15][15])
{
    for(int i=0; i<15; i++)
        {
            for(int j=0; j<15; j++)
                mat[i][j]='.';
        }
        print_board(mat);
}

//O functie asemanatoare cu cea de la primul task doar ca aceasta nu afiseaza matricea.
void fill(char mat[15][15])
{
    for(int i=0; i<15; i++)
        {
            for(int j=0; j<15; j++)
                mat[i][j]='.';
        }
}
int main()
{
    char task[10],mat[15][15];
    int n;

    fgets(task, 10, stdin);
    n=atoi(task);
    
    if(n==0)
    {
        task0(mat);
    }
    else if(n==1)
    {
        fill(mat);
        int N,coordonate[100];
        char *token,delimitators[2]=" ",nr_of_lines[10],word[16][16],aux[100];
        fgets(nr_of_lines, 10, stdin);
        N=atoi(nr_of_lines);
        //Citirea si salvarea fiecarui cuvantul impreuna cu coordonatele acestuia si cu directia pe care acesta va fi scris in matrice.
        for(int a=0; a<N; a++)
        {
            fgets(aux, 100, stdin);
            token = strtok (aux, delimitators);
            for(int i=0; i<4; i++)
            {
                if(token!=NULL)
                {
                    if(i!=3)
                    {
                        coordonate[ a*3+i ] = atoi(token);
                    }
                    else
                        strcpy( word[ a ],token );
                }
                else break;
                token = strtok (NULL,delimitators);
            }
        }
        //Introducerea cuvintelor in matrice si afisarea acesteia.
        for(int a=0; a<N; a++)
        {
            int x,y,d,lungime;
            y=coordonate[a*3];
            x=coordonate[a*3+1];
            d=coordonate[a*3+2];
            lungime=strlen(word[a]);
            if(d==1)
            {
                for(int j=y; j<(y+lungime-1); j++)
                    mat[j][x] = word[a][j-y];
            }
            else if (d==0)
            {
                for(int j=x; j<(x+lungime-1); j++)
                    mat[y][j] = word[a][j-x];
            }
        }
        print_board(mat);
    }
    else if(n==2)
    {
        int N,w=0,s=0;
        char *token,delimitators[2]=" ",nr_of_lines[10],word[20][20],aux[100];

        fgets(nr_of_lines, 10, stdin);
        N=atoi(nr_of_lines);
        //La fel ca la cerinta precedenta(citirea si salvarea cuvantului,coordoonatelor si directiilor).
        for(int a=0; a<N; a++)
        {
            fgets(aux, 100, stdin);
            token = strtok (aux, delimitators);
            for(int i=0; i<4; i++)
            {
                if(token!=NULL)
                {
                    if(i==3)
                        strcpy( word[a],token );
                }
                else break;
                token = strtok (NULL,delimitators);
            }
        }
        //Calculul punctelor pentru primul player caruia ii corespund cuvintele de pe pozitii pare.
        for(int a=0; a<N; a+=2)
        {
            int lungime;
            lungime=strlen(word[a]);
            for(int j=0; j<lungime; j++)
            {
                if( word[a][j] == 'A' || word[a][j] == 'E'|| word[a][j] == 'I'|| word[a][j] == 'L'|| word[a][j] == 'N'|| word[a][j] == 'O'|| word[a][j] == 'R'|| word[a][j] == 'S'|| word[a][j] == 'T'|| word[a][j] == 'U')
                    w += 1;
                else if( word[a][j] == 'D' || word[a][j] == 'G')
                    w += 2;
                else if( word[a][j] == 'B'||word[a][j] == 'C'||word[a][j] == 'M'||word[a][j] == 'P')
                    w += 3;
                else if( word[a][j] == 'F'||word[a][j] == 'H'||word[a][j] == 'V'||word[a][j] == 'W'||word[a][j]=='Y')
                    w += 4;
                else if( word[a][j] == 'K' )
                    w += 5;
                else if( word[a][j] == 'J'|| word[a][j] == 'X')
                    w += 8;
                else if( word[a][j] == 'Q' || word[a][j] == 'Z')
                    w += 10;
            }
        }
        //Calculul punctelor pentru al doilea player caruia ii corespund cuvintele de pe pozitii impare.
        for(int a=1; a<N; a+=2)
        {
            int lungime;
            lungime=strlen(word[a]);
            for(int j=0; j<lungime; j++)
            {
                if( word[a][j] == 'A' || word[a][j] == 'E'|| word[a][j] == 'I'|| word[a][j] == 'L'|| word[a][j] == 'N'|| word[a][j] == 'O'|| word[a][j] == 'R'|| word[a][j] == 'S'|| word[a][j] == 'T'|| word[a][j] == 'U')
                    s += 1;
                else if( word[a][j] == 'D' || word[a][j] == 'G')
                    s += 2;
                else if( word[a][j] == 'B'||word[a][j] == 'C'||word[a][j] == 'M'||word[a][j] == 'P')
                    s += 3;
                else if( word[a][j] == 'F'||word[a][j] == 'H'||word[a][j] == 'V'||word[a][j] == 'W'||word[a][j]=='Y')
                    s += 4;
                else if( word[a][j] == 'K' )
                    s += 5;
                else if( word[a][j] == 'J'|| word[a][j] == 'X')
                    s += 8;
                else if( word[a][j] == 'Q' || word[a][j] == 'Z')
                    s += 10;
            }
        }
        //Afisarea rezultatelor celor doi.
        printf("Player 1: %d Points\n",w);
        printf("Player 2: %d Points",s);
    }
    else if(n==3)
    {
        int N,coordonate[100],scoruri[100],w=0,s=0,score_multiplier[100];
        char *token,delimitators[2]=" ",nr_of_lines[10],word[16][16],aux[100],xx[10],yy[10];

        fgets(xx, 10, stdin);
        fgets(yy, 10, stdin);

        fgets(nr_of_lines, 10, stdin);
        N=atoi(nr_of_lines);
        
        //Initializarea cu 0 a vectorilor de scoruri si cu 1 a vectorului cu multiplicatorii de scoruri.
        for(int a=0; a<N; a++)
        {
            scoruri[a]=0;
            score_multiplier[a]=1;
        }
        //Citirea si memorarea datelor.
        for(int a=0; a<N; a++)
        {
            fgets(aux, 100, stdin);
            token = strtok (aux, delimitators);
            for(int i=0; i<4; i++)
            {
                if(token!=NULL)
                {
                    if(i!=3)
                    {
                        coordonate[ a*3+i] = atoi(token);
                    }
                    else
                        strcpy( word[a],token );
                }
                else break;
                token = strtok (NULL,delimitators);
            }
        }
        //Introducerea cuvintelor in matrice plus calcularea bonusurilor(multiplicarilor) pentru fiecare cuvant.
        //Fiecare multiplicare de pe pozitia i din vectorul score_multiplier[] ii corespunde scorului de pe pozitia i din vectorul scoruri[].
        for(int a=0; a<N; a++)
        {
            int x,y,d,lungime;
            y=coordonate[a*3];
            x=coordonate[a*3+1];
            d=coordonate[a*3+2];
            lungime=strlen(word[a]);
            if(d==1)
            {
                for(int j=y; j<(y+lungime-1); j++)
                    mat[j][x] = word[a][j-y];
                for(int j=y; j<(y+lungime-1); j++)
                {
                    if(bonus_board[j][x]==2 && word[a][lungime-3]==yy[0] && word[a][lungime-2]==yy[1])
                    {
                        score_multiplier[a] *=3;
                    }
                    else if(bonus_board[j][x]==1)
                    {
                        for(int i=0; i<lungime; i++)
                        {
                            if(word[a][i]==xx[0] && word[a][i+1]==xx[1])
                                score_multiplier[a] *=2;
                        }
                    }
                    else if(bonus_board[j][x]==0)
                        score_multiplier[a] *=1;
                }
            }
            else if (d==0)
            {
                for(int j=x; j<(x+lungime-1); j++)
                    mat[y][j] = word[a][j-x];
                for(int j=x; j<(x+lungime-1); j++)
                {
                    if(bonus_board[y][j]==2 && word[a][lungime-3]==yy[0] && word[a][lungime-2]==yy[1])
                        score_multiplier[a] *=3;
                    else if(bonus_board[y][j]==1)
                    {
                        for(int i=0; i<lungime; i++)
                        {
                            if(word[a][i] == xx[0] && word[a][i+1] == xx[1])
                                score_multiplier[a] *=2;
                        }
                    }
                    else if(bonus_board[y][j]==0)
                        score_multiplier[a] *=1;
                }
            }
        }
        //Calculul scorurilor pe care le retinem in vectorul scoruri[].
        for(int a=0; a<N; a++)
        {
            int lungime;
            lungime=strlen(word[a]);
            for(int j=0; j<lungime; j++)
            {
                if( word[a][j] == 'A' || word[a][j] == 'E'|| word[a][j] == 'I'|| word[a][j] == 'L'|| word[a][j] == 'N'|| word[a][j] == 'O'|| word[a][j] == 'R'|| word[a][j] == 'S'|| word[a][j] == 'T'|| word[a][j] == 'U')
                    scoruri[a] += 1;
                else if( word[a][j] == 'D' || word[a][j] == 'G')
                    scoruri[a] += 2;
                else if( word[a][j] == 'B'||word[a][j] == 'C'||word[a][j] == 'M'||word[a][j] == 'P')
                    scoruri[a] += 3;
                else if( word[a][j] == 'F'||word[a][j] == 'H'||word[a][j] == 'V'||word[a][j] == 'W'||word[a][j]=='Y')
                    scoruri[a] += 4;
                else if( word[a][j] == 'K' )
                    scoruri[a] += 5;
                else if( word[a][j] == 'J'|| word[a][j] == 'X')
                    scoruri[a] += 8;
                else if( word[a][j] == 'Q' || word[a][j] == 'Z')
                    scoruri[a] += 10;
            }
        }
        //Scorul pentru primul player caruia ii corespund pozitiile pare din vectorul de scoruri si din cel de multiplicari.
        for(int a=0; a<N; a+=2)
        {
            w=w+(scoruri[a]*score_multiplier[a]);
        }
        for(int a=1; a<N; a+=2)
        {
            s=s+(scoruri[a]*score_multiplier[a]);
        }
        printf("Player 1: %d Points\n",w);
        printf("Player 2: %d Points",s);
        
    }
    else if(n==4)
    {
        fill(mat);
        int N,coordonate[100];
        char *token,delimitators[2]=" ",nr_of_lines[10],word[16][16],aux[100],xx[10],yy[10];

        fgets(xx, 10, stdin);
        fgets(yy, 10, stdin);

        fgets(nr_of_lines, 10, stdin);
        N=atoi(nr_of_lines);

        for(int a=0; a<N; a++)
        {
            fgets(aux, 100, stdin);
            token = strtok (aux, delimitators);
            for(int i=0; i<4; i++)
            {
                if(token!=NULL)
                {
                    if(i!=3)
                    {
                        coordonate[ a*3+i] = atoi(token);
                    }
                    else
                        strcpy( word[a],token );
                }
                else break;
                token = strtok (NULL,delimitators);
            }
        }
        for(int a=0; a<N; a++)
        {
            int x,y,d,lungime;
            y=coordonate[a*3];
            x=coordonate[a*3+1];
            d=coordonate[a*3+2];
            lungime=strlen(word[a]);

            if(d==1)
            {
                for(int j=y; j<(y+lungime-1); j++)
                    mat[j][x] = word[a][j-y];
            }
            else if (d==0)
            {
                for(int j=x; j<(x+lungime-1); j++)
                    mat[y][j] = word[a][j-x];
            }
        }

        int ok=0;
        for(int i=0; i<=99; i++)//parcurgerea tuturor cuvintelor din vectorul words[].
        {
            int lungime_cuvant_bonus=0,cuvant_nou=1;
            lungime_cuvant_bonus=strlen(words[i]);
            //verificam daca cuvantul din words se afla printre cele introduse deja in matrice.
            for(int j=0; j<N; j++)
            {
                if(strncmp(words[i],word[j],strlen(word[j])-1)==0)
                {
                    cuvant_nou=0;
                    break;
                }
            }
            //parcurgerea matricei de cuvinte.
            for(int a=0; a<15; a++)
            {
                for(int b=0; b<15; b++)
                {
                    if(words[i][0] == mat[a][b] && ok==0 && cuvant_nou==1 )//verificam daca prima litera din cuvant este egala cu cea din matrice(prima conditie), daca nu a mai fost introdus niciun cuvant(a doua conditie) si daca cuvantul este diferit de toate cele introduse(a treia conditie).
                    {
                        int vertical=1,orizontal=1;
                        if(b+lungime_cuvant_bonus <= 15)//verificam daca cuvantul poate fi introdus pe orizontala
                        {
                            for(int c=b+1; c<b+lungime_cuvant_bonus; c++)
                            {
                                if(mat[a][c] != '.')
                                {
                                    orizontal=0;
                                    break;
                                }
                            }
                            if(orizontal == 1)
                            {
                                for(int c=b+1; c<b+lungime_cuvant_bonus; c++)
                                {
                                    mat[a][c] = words[i][c-b];
                                }
                                ok=1;//schimbam valoare lui ok in 1 deoarece am introdus deja un cuvant si nu mai este nevoie de altul.
                            }


                        }
                        if(a+lungime_cuvant_bonus <= 15)//verificam daca cuvantul poate fi introdus pe verticala.
                        {
                            for(int c=a+1; c<a+lungime_cuvant_bonus; c++)
                            {
                                if(mat[c][b] != '.')
                                {
                                    vertical=0;
                                    break;
                                }
                            }
                            if (vertical == 1)
                            {
                                for(int c=a+1; c<a+lungime_cuvant_bonus; c++)
                                {
                                    mat[c][b] = words[i][c-a];
                                }
                                ok=1;//schimbam valoare lui ok in 1 deoarece am introdus deja un cuvant si nu mai este nevoie de altul.
                            }
                        }

                    }
                }
            }
        }
        print_board(mat);
    }
    else if( n==5 )
    {
        fill(mat);
        int N,coordonate[100],scor_bonus[100][10],score_multiplier[100][10],poz,var,MAX=0,score_multiplier_word[100],scoruri[100],w=0,s=0;
        char *token,delimitators[2]=" ",nr_of_lines[10],word[16][16],aux[100],xx[10],yy[10];
        
        fgets(xx, 10, stdin);
        fgets(yy, 10, stdin);

        fgets(nr_of_lines, 10, stdin);
        N=atoi(nr_of_lines);

        for(int a=0; a<N; a++)
        {
            fgets(aux, 100, stdin);
            token = strtok (aux, delimitators);
            for(int i=0; i<4; i++)
            {
                if(token!=NULL)
                {
                    if(i!=3)
                    {
                        coordonate[ a*3+i] = atoi(token);
                    }
                    else
                        strcpy( word[a],token );
                }
                else break;
                token = strtok (NULL,delimitators);
            }
        }

        for(int a=0; a<N; a++)
            score_multiplier_word[a]=1;
        //Calculam scorurile cuvintelor deja introduse
        for(int a=0; a<N; a++)
        {
            int x,y,d,lungime;
            y=coordonate[a*3];
            x=coordonate[a*3+1];
            d=coordonate[a*3+2];
            lungime=strlen(word[a]);

            if(d==1)
            {
                for(int j=y; j<(y+lungime-1); j++)
                    mat[j][x] = word[a][j-y];
                for(int j=y; j<(y+lungime-1); j++)//dupa ce am introdus cuvantul in matrice la structura anterioara calculam si bonusul acestuia.
                {
                    if(bonus_board[j][x]==2 && word[a][lungime-3]==yy[0] && word[a][lungime-2]==yy[1])
                    {
                        score_multiplier_word[a] *=3;
                    }

                    else if(bonus_board[j][x]==1)
                    {
                        for(int i=0; i<lungime; i++)
                        {
                            if(word[a][i]==xx[0] && word[a][i+1]==xx[1])
                                score_multiplier_word[a] *=2;
                        }
                    }
                    else if(bonus_board[j][x]==0)
                        score_multiplier_word[a] *=1;
                }
            }
            else if (d==0)//idee asemanatoare cu cea de la d==1.
            {
                for(int j=x; j<(x+lungime-1); j++)
                    mat[y][j] = word[a][j-x];
                for(int j=x; j<(x+lungime-1); j++)
                {
                    if(bonus_board[y][j]==2 && word[a][lungime-3]==yy[0] && word[a][lungime-2]==yy[1])
                        score_multiplier_word[a] *=3;

                    else if(bonus_board[y][j]==1)
                    {
                        for(int i=0; i<lungime; i++)
                        {
                            if(word[a][i] == xx[0] && word[a][i+1] == xx[1])
                                score_multiplier_word[a] *=2;
                        }
                    }
                    else if(bonus_board[y][j]==0)
                        score_multiplier_word[a] *=1;
                }
            }
        }

        for(int a=0; a<N; a++)
            scoruri[a]=0;
        //calculul scorurilor.
        for(int a=0; a<N; a++)
        {
            int lungime;
            lungime=strlen(word[a]);
            for(int j=0; j<lungime; j++)
            {
                if( word[a][j] == 'A' || word[a][j] == 'E'|| word[a][j] == 'I'|| word[a][j] == 'L'|| word[a][j] == 'N'|| word[a][j] == 'O'|| word[a][j] == 'R'|| word[a][j] == 'S'|| word[a][j] == 'T'|| word[a][j] == 'U')
                    scoruri[a] += 1;
                else if( word[a][j] == 'D' || word[a][j] == 'G')
                    scoruri[a] += 2;
                else if( word[a][j] == 'B'||word[a][j] == 'C'||word[a][j] == 'M'||word[a][j] == 'P')
                    scoruri[a] += 3;
                else if( word[a][j] == 'F'||word[a][j] == 'H'||word[a][j] == 'V'||word[a][j] == 'W'||word[a][j]=='Y')
                    scoruri[a] += 4;
                else if( word[a][j] == 'K' )
                    scoruri[a] += 5;
                else if( word[a][j] == 'J'|| word[a][j] == 'X')
                    scoruri[a] += 8;
                else if( word[a][j] == 'Q' || word[a][j] == 'Z')
                    scoruri[a] += 10;
            }
        }
        //scorul pentru primul player.
        for(int a=0; a<N; a+=2)
        {
            w=w+(scoruri[a]*score_multiplier_word[a]);
        }
        //scorul pentru cel de-al doilea player.
        for(int a=1; a<N; a+=2)
        {
            s=s+(scoruri[a]*score_multiplier_word[a]);
        }
        //Pentru a salva scorurile si bonusurile cuvintelor ce pot fi introduse ne vom folosi de doua matrici(pentru ca exista posibilitatea ca un cuvant sa se plaseze in mai multe locuri si sa obtina punctaje diferite).
        for(int i=0; i<=99; i++)
        {
            for(int j=0; j<10; j++)
            {
                scor_bonus[i][j]=0;
                score_multiplier[i][j]=1;
            }
        }
        for(int i=0; i<=99; i++)
        {
            int lungime_cuvant_bonus=0,cuvant_nou=1,k=0;

            lungime_cuvant_bonus=strlen(words[i]);

            for(int j=0; j<N; j++)
            {
                if(strncmp(words[i],word[j],strlen(word[j])-1)==0)
                {
                    cuvant_nou=0;
                    break;
                }
            }

            for(int a=0; a<15; a++)
            {
                for(int b=0; b<15; b++)
                {
                    if(words[i][0] == mat[a][b] && cuvant_nou==1 )
                    {
                        int vertical=1,orizontal=1;
                        if(b+lungime_cuvant_bonus <= 15)
                        {
                            for(int c=b+1; c<b+lungime_cuvant_bonus; c++)
                            {
                                if(mat[a][c] != '.')
                                {
                                    orizontal=0;
                                    break;
                                }
                            }
                            if(orizontal == 1)
                            {
                                for(int c=b; c<b+lungime_cuvant_bonus; c++)//calculul scorului cuvantului de pe pozitia i si introducerea acestuia la linia i din matrice si pe coloana k.
                                {
                                    if( words[i][c-b] == 'A' || words[i][c-b] == 'E'|| words[i][c-b] == 'I'|| words[i][c-b] == 'L'|| words[i][c-b] == 'N'|| words[i][c-b] == 'O'|| words[i][c-b] == 'R'|| words[i][c-b] == 'S'|| words[i][c-b] == 'T'|| words[i][c-b] == 'U')
                                        scor_bonus[i][k] += 1;
                                    else if( words[i][c-b] == 'D' || words[i][c-b] == 'G')
                                        scor_bonus[i][k] += 2;
                                    else if( words[i][c-b] == 'B'||words[i][c-b] == 'C'||words[i][c-b] == 'M'||words[i][c-b] == 'P')
                                        scor_bonus[i][k] += 3;
                                    else if( words[i][c-b] == 'F'||words[i][c-b] == 'H'||words[i][c-b] == 'V'||words[i][c-b] == 'W'||words[i][c-b]=='Y')
                                        scor_bonus[i][k] += 4;
                                    else if( words[i][c-b] == 'K' )
                                        scor_bonus[i][k] += 5;
                                    else if( words[i][c-b] == 'J'|| words[i][c-b] == 'X')
                                        scor_bonus[i][k] += 8;
                                    else if( words[i][c-b] == 'Q' || words[i][c-b] == 'Z')
                                        scor_bonus[i][k] += 10;
                                    //calculam si bonusurile pentru cuvantul respectiv.
                                    if(bonus_board[a][c]==2 && words[i][lungime_cuvant_bonus-2]==yy[0] && words[i][lungime_cuvant_bonus-1]==yy[1])
                                    {
                                        score_multiplier[i][k] *=3;
                                    }
                                    else if(bonus_board[a][c]==1)
                                    {
                                        for(int j=0; j<lungime_cuvant_bonus; j++)
                                        {
                                            if(words[i][j]==xx[0] && words[i][j+1]==xx[1])
                                                score_multiplier[i][k] *=2;
                                        }
                                    }
                                    else if(bonus_board[a][c]==0)
                                        score_multiplier[i][k] *=1;
                                }
                                k++;
                            }
                        }
                        if(a+lungime_cuvant_bonus <= 15)
                        {
                            for(int c=a+1; c<a+lungime_cuvant_bonus; c++)
                            {
                                if(mat[c][b] != '.')
                                {
                                    vertical=0;
                                    break;
                                }
                            }

                            if (vertical == 1)
                            {

                                for(int c=a; c<a+lungime_cuvant_bonus; c++)
                                {
                                    if( words[i][c-a] == 'A' || words[i][c-a] == 'E'|| words[i][c-a] == 'I'|| words[i][c-a] == 'L'|| words[i][c-a] == 'N'|| words[i][c-a] == 'O'|| words[i][c-a] == 'R'|| words[i][c-a] == 'S'|| words[i][c-a] == 'T'|| words[i][c-a] == 'U')
                                        scor_bonus[i][k] += 1;
                                    else if( words[i][c-a] == 'D' || words[i][c-a] == 'G')
                                        scor_bonus[i][k] += 2;
                                    else if( words[i][c-a] == 'B'||words[i][c-a] == 'C'||words[i][c-a] == 'M'||words[i][c-a] == 'P')
                                        scor_bonus[i][k] += 3;
                                    else if( words[i][c-a] == 'F'||words[i][c-a] == 'H'||words[i][c-a] == 'V'||words[i][c-a] == 'W'||words[i][c-a]=='Y')
                                        scor_bonus[i][k] += 4;
                                    else if( words[i][c-a] == 'K' )
                                        scor_bonus[i][k] += 5;
                                    else if( words[i][c-a] == 'J'|| words[i][c-a] == 'X')
                                        scor_bonus[i][k] += 8;
                                    else if( words[i][c-a] == 'Q' || words[i][c-a] == 'Z')
                                        scor_bonus[i][k] += 10;
                                    if(bonus_board[c][b]==2 && words[i][lungime_cuvant_bonus-2]==yy[0] && words[i][lungime_cuvant_bonus-1]==yy[1])
                                    {
                                        score_multiplier[i][k] *=3;
                                    }
                                    else if(bonus_board[c][b]==1)
                                    {
                                        for(int j=0; j<lungime_cuvant_bonus; j++)
                                        {
                                            if(words[i][j]==xx[0] && words[i][j+1]==xx[1])
                                                score_multiplier[i][k] *=2;
                                        }
                                    }
                                    else if(bonus_board[c][b]==0)
                                        score_multiplier[i][k] *=1;
                                }
                                k++;
                            }
                        }

                    }
                }
            }
        }
        //calculul scorurilor pentru fiecare cuvant cu tot cu bonusurile acestuia.
        for(int i=0; i<=99; i++)
        {
            for(int j=0; j<10; j++)
            {
                scor_bonus[i][j] *= score_multiplier[i][j];
            }
        }
        //calculam maximul de puncte care poate fi produs prin introducerea unui cuvant.
        for(int i=0; i<=99; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(scor_bonus[i][j]>MAX)
                {
                    MAX=scor_bonus[i][j];
                }
            }
        }
        //calculam pozitia maximului pentru a stii ce cuvant trebuie introdus, respectiv in var retinem pe a cata posibilitate de plasare poate fi introdus cuvantul respectiv.
        //in cazul in care cuvantul poate fi introdus pe mai multe pozitii si obtine scor maxim doar pe una dintre ele sa retinem a cata posibilitate de introducere este aceasta.
        for(int i=0; i<=99; i++)
        {
            for(int j=9; j>=0; j--)//in cazul in care un cuvant se poate introduce in mai multe locuri si genereaza acelasi punctaj sa ne ramana in var prima posibilitate de introducere.
            {
                if(scor_bonus[i][j] == MAX)
                {
                    poz=i;
                    var=j;
                }
            }
        }
        //verificam daca prin cuvantul introdus cel de-al doilea player poate castiga sau poate face remiza.
        if(MAX >= w-s)
        {
            int lungime_cuvant_introdus,done=0;
            lungime_cuvant_introdus=strlen(words[poz]);
            if(var == 0)//cazul in care acesta trebuie introdus in prima posibilitate de plasare gasita.
            {
                for(int a=0; a<15; a++)
                {
                    for(int b=0; b<15; b++)
                    {
                        if(words[poz][0] == mat[a][b] && done==0)
                        {
                            int vertical=1,orizontal=1;
                            if(b+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[a][c] != '.')
                                    {
                                        orizontal=0;
                                        break;
                                    }
                                }
                                if(orizontal == 1)
                                {
                                    for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                    {
                                        mat[a][c] = words[poz][c-b];
                                    }
                                    done=1;//inseamna ca deja am introdus cuvantul si nu mai e nevoie sa continuam.
                                }
                            }
                            if(a+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[c][b] != '.')
                                    {
                                        vertical=0;
                                        break;
                                    }
                                }

                                if (vertical == 1)
                                {
                                    for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                    {
                                        mat[c][b] = words[poz][c-a];
                                    }
                                    done=1;//inseamna ca deja am introdus cuvantul si nu mai e nevoie sa continuam.
                                }
                            }
                        }
                    }
                }
            }
            else//inseamna ca trebuie introdus in alta posibilitate fata de prima
            {
                int nr=0,done=0;
                for(int a=0; a<15; a++)
                {
                    for(int b=0; b<15; b++)
                    {
                        if(words[poz][0] == mat[a][b] && done==0)
                        {
                            int vertical=1,orizontal=1;
                            if(b+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[a][c] != '.')
                                    {
                                        orizontal=0;
                                        break;
                                    }
                                }
                                if(orizontal == 1)
                                {
                                    nr++;//inseamna ca poate fi introdus intr-un loc.
                                    if(var==nr-1)//verificam daca posibilitatea noastra este egala cu numarul de locuri de introducere gasite pana acum -1(deoarece nr va avea intotdeauna cu unul mai mult).
                                    {
                                        for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                            mat[a][c]=words[poz][c-b];
                                        done=1;//ne oprim pentru ca ne-am indeplinit sarcina.
                                    }
                                }
                            }
                            if(a+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[c][b] != '.')
                                    {
                                        vertical=0;
                                        break;
                                    }
                                }
                                if (vertical == 1)
                                {
                                    nr++;
                                    if(var==n-1)
                                    {
                                        for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                            mat[c][b]=words[poz][c-a];
                                        done=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            print_board(mat);
        }
        else printf("Fail!");//inseamna ca player 2 nu poate obtine rezultaltul dorit indiferent de ce cuvant putem introduce.
    }
    else if(n==6)
    {
        fill(mat);

        int N,coordonate[100],w=0,s=0,scoruri_player1[100],score_multiplier_word[100];
        char *token,delimitators[2]=" ",nr_of_lines[10],word[16][16],aux[100],xx[10],yy[10];

        fgets(xx,10,stdin);
        fgets(yy,10,stdin);

        fgets(nr_of_lines,10,stdin);
        N=atoi(nr_of_lines);

        for(int a=0; a<N; a++)
        {
            fgets(aux, 100, stdin);
            token = strtok (aux,delimitators);
            for(int i=0; i<4; i++)
            {
                if(token!=NULL)
                {
                    if(i!=3)
                        coordonate[a*3+i] = atoi(token);
                    else strcpy(word[a],token);
                }
                else break;
                token = strtok(NULL,delimitators);
            }
        }
        for(int i=0; i<100; i++)
        {
            scoruri_player1[i]=0;
            score_multiplier_word[i]=1;
        }
        for(int a=0; a<N; a++)
        {
            int x,y,d,lungime;
            y=coordonate[a*3];
            x=coordonate[a*3+1];
            d=coordonate[a*3+2];
            lungime=strlen(word[a]);

            if(d==1)
            {
                for(int j=y; j<(y+lungime-1); j++)
                    mat[j][x] = word[a][j-y];
                for(int j=y; j<(y+lungime-1); j++)
                {
                    if(bonus_board[j][x]==2 && word[a][lungime-3]==yy[0] && word[a][lungime-2]==yy[1])
                    {
                        score_multiplier_word[a] *=3;
                    }

                    else if(bonus_board[j][x]==1)
                    {
                        for(int i=0; i<lungime; i++)
                        {
                            if(word[a][i]==xx[0] && word[a][i+1]==xx[1])
                                score_multiplier_word[a] *=2;
                        }
                    }
                    else if(bonus_board[j][x]==0)
                        score_multiplier_word[a] *=1;
                }
            }
            else if (d==0)
            {
                for(int j=x; j<(x+lungime-1); j++)
                    mat[y][j] = word[a][j-x];
                for(int j=x; j<(x+lungime-1); j++)
                {
                    if(bonus_board[y][j]==2 && word[a][lungime-3]==yy[0] && word[a][lungime-2]==yy[1])
                        score_multiplier_word[a] *=3;

                    else if(bonus_board[y][j]==1)
                    {
                        for(int i=0; i<lungime; i++)
                        {
                            if(word[a][i] == xx[0] && word[a][i+1] == xx[1])
                                score_multiplier_word[a] *=2;
                        }
                    }
                    else if(bonus_board[y][j]==0)
                        score_multiplier_word[a] *=1;
                }

            }
        }
        for(int a=0; a<N; a++)
        {
            int lungime;
            lungime=strlen(word[a]);
            for(int j=0; j<lungime; j++)
            {
                if( word[a][j] == 'A' || word[a][j] == 'E'|| word[a][j] == 'I'|| word[a][j] == 'L'|| word[a][j] == 'N'|| word[a][j] == 'O'|| word[a][j] == 'R'|| word[a][j] == 'S'|| word[a][j] == 'T'|| word[a][j] == 'U')
                    scoruri_player1[a] += 1;
                else if( word[a][j] == 'D' || word[a][j] == 'G')
                    scoruri_player1[a] += 2;
                else if( word[a][j] == 'B'||word[a][j] == 'C'||word[a][j] == 'M'||word[a][j] == 'P')
                    scoruri_player1[a] += 3;
                else if( word[a][j] == 'F'||word[a][j] == 'H'||word[a][j] == 'V'||word[a][j] == 'W'||word[a][j]=='Y')
                    scoruri_player1[a] += 4;
                else if( word[a][j] == 'K' )
                    scoruri_player1[a] += 5;
                else if( word[a][j] == 'J'|| word[a][j] == 'X')
                    scoruri_player1[a] += 8;
                else if( word[a][j] == 'Q' || word[a][j] == 'Z')
                    scoruri_player1[a] += 10;
            }
        }
        for(int i=0; i<N; i++)
        {
            w=w+(scoruri_player1[i]*score_multiplier_word[i]);
        }
        for(int l=0; l<N; l++)
        {
            int scor_bonus[100][10],score_multiplier[100][10],poz=0,var=0,MAX=0;
            for(int i=0; i<=99; i++)
            {
                for(int j=0; j<10; j++)
                {
                    scor_bonus[i][j]=0;
                    score_multiplier[i][j]=1;
                }
            }
            for(int i=0; i<=99; i++)
            {
                int lungime_cuvant_bonus=0,cuvant_nou=1,k=0;
                lungime_cuvant_bonus=strlen(words[i]);
                for(int j=0; j<N+l; j++)
                {
                    if(strncmp(words[i],word[j],strlen(word[j])-1)==0)
                    {
                        cuvant_nou=0;
                        break;
                    }
                }

                for(int a=0; a<15; a++)
                {
                    for(int b=0; b<15; b++)
                    {
                        if(words[i][0] == mat[a][b] && cuvant_nou==1 )
                        {
                            int vertical=1,orizontal=1;
                            if(b+lungime_cuvant_bonus <= 15)
                            {
                                for(int c=b+1; c<b+lungime_cuvant_bonus; c++)
                                {
                                    if(mat[a][c] != '.' && mat[a][c] != words[i][c-b])
                                    {
                                        orizontal=0;
                                        break;
                                    }
                                }
                                if(orizontal == 1)
                                {
                                    for(int c=b; c<b+lungime_cuvant_bonus; c++)
                                    {
                                        if( words[i][c-b] == 'A' || words[i][c-b] == 'E'|| words[i][c-b] == 'I'|| words[i][c-b] == 'L'|| words[i][c-b] == 'N'|| words[i][c-b] == 'O'|| words[i][c-b] == 'R'|| words[i][c-b] == 'S'|| words[i][c-b] == 'T'|| words[i][c-b] == 'U')
                                            scor_bonus[i][k] += 1;
                                        else if( words[i][c-b] == 'D' || words[i][c-b] == 'G')
                                            scor_bonus[i][k] += 2;
                                        else if( words[i][c-b] == 'B'||words[i][c-b] == 'C'||words[i][c-b] == 'M'||words[i][c-b] == 'P')
                                            scor_bonus[i][k] += 3;
                                        else if( words[i][c-b] == 'F'||words[i][c-b] == 'H'||words[i][c-b] == 'V'||words[i][c-b] == 'W'||words[i][c-b]=='Y')
                                            scor_bonus[i][k] += 4;
                                        else if( words[i][c-b] == 'K' )
                                            scor_bonus[i][k] += 5;
                                        else if( words[i][c-b] == 'J'|| words[i][c-b] == 'X')
                                            scor_bonus[i][k] += 8;
                                        else if( words[i][c-b] == 'Q' || words[i][c-b] == 'Z')
                                            scor_bonus[i][k] += 10;

                                        if(bonus_board[a][c]==2 && words[i][lungime_cuvant_bonus-2]==yy[0] && words[i][lungime_cuvant_bonus-1]==yy[1])
                                        {
                                            score_multiplier[i][k] *=3;
                                        }
                                        else if(bonus_board[a][c]==1)
                                        {
                                            for(int j=0; j<lungime_cuvant_bonus; j++)
                                            {
                                                if(words[i][j]==xx[0] && words[i][j+1]==xx[1])
                                                    score_multiplier[i][k] *=2;
                                            }
                                        }
                                        else if(bonus_board[a][c]==0)
                                            score_multiplier[i][k] *=1;
                                    }
                                    k++;
                                }
                            }
                            if(a+lungime_cuvant_bonus <= 15)
                            {
                                for(int c=a+1; c<a+lungime_cuvant_bonus; c++)
                                {
                                    if(mat[c][b] != '.' && mat[c][b]!=words[i][c-a])
                                    {
                                        vertical=0;
                                        break;
                                    }
                                }

                                if (vertical == 1)
                                {

                                    for(int c=a; c<a+lungime_cuvant_bonus; c++)
                                    {
                                        if( words[i][c-a] == 'A' || words[i][c-a] == 'E'|| words[i][c-a] == 'I'|| words[i][c-a] == 'L'|| words[i][c-a] == 'N'|| words[i][c-a] == 'O'|| words[i][c-a] == 'R'|| words[i][c-a] == 'S'|| words[i][c-a] == 'T'|| words[i][c-a] == 'U')
                                            scor_bonus[i][k] += 1;
                                        else if( words[i][c-a] == 'D' || words[i][c-a] == 'G')
                                            scor_bonus[i][k] += 2;
                                        else if( words[i][c-a] == 'B'||words[i][c-a] == 'C'||words[i][c-a] == 'M'||words[i][c-a] == 'P')
                                            scor_bonus[i][k] += 3;
                                        else if( words[i][c-a] == 'F'||words[i][c-a] == 'H'||words[i][c-a] == 'V'||words[i][c-a] == 'W'||words[i][c-a]=='Y')
                                            scor_bonus[i][k] += 4;
                                        else if( words[i][c-a] == 'K' )
                                            scor_bonus[i][k] += 5;
                                        else if( words[i][c-a] == 'J'|| words[i][c-a] == 'X')
                                            scor_bonus[i][k] += 8;
                                        else if( words[i][c-a] == 'Q' || words[i][c-a] == 'Z')
                                            scor_bonus[i][k] += 10;
                                        if(bonus_board[c][b]==2 && words[i][lungime_cuvant_bonus-2]==yy[0] && words[i][lungime_cuvant_bonus-1]==yy[1])
                                        {
                                            score_multiplier[i][k] *=3;
                                        }
                                        else if(bonus_board[c][b]==1)
                                        {
                                            for(int j=0; j<lungime_cuvant_bonus; j++)
                                            {
                                                if(words[i][j]==xx[0] && words[i][j+1]==xx[1])
                                                    score_multiplier[i][k] *=2;
                                            }
                                        }
                                        else if(bonus_board[c][b]==0)
                                            score_multiplier[i][k] *=1;
                                    }
                                    k++;
                                }
                            }

                        }
                    }
                }
            }
            for(int i=0; i<=99; i++)
            {
                for(int j=0; j<10; j++)
                {
                    scor_bonus[i][j] *= score_multiplier[i][j];
                }
            }
            for(int i=0; i<=99; i++)
            {
                for(int j=0; j<10; j++)
                {
                    if(scor_bonus[i][j]>MAX)
                    {
                        MAX=scor_bonus[i][j];
                    }
                }
            }
            for(int i=0; i<=99; i++)
            {
                for(int j=10; j>=0; j--)
                {
                    if(scor_bonus[i][j] == MAX )
                    {
                        poz=i;
                        var=j;
                    }
                }
            }
            int nr=0,done=0,lungime_cuvant_introdus;
            lungime_cuvant_introdus=strlen(words[poz]);
            if(var == 0)
            {
                for(int a=0; a<15; a++)
                {
                    for(int b=0; b<15; b++)
                    {
                        if(words[poz][0] == mat[a][b] && done==0)
                        {
                            int vertical=1,orizontal=1;
                            if(b+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[a][c] != '.' && mat[a][c]!=words[poz][c-b])
                                    {
                                        orizontal=0;
                                        break;
                                    }
                                }
                                if(orizontal == 1)
                                {
                                    for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                    {
                                        mat[a][c] = words[poz][c-b];
                                    }
                                    done=1;
                                }
                            }
                            if(a+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[c][b] != '.' && mat[c][b]!=words[poz][c-a])
                                    {
                                        vertical=0;
                                        break;
                                    }
                                }

                                if (vertical == 1)
                                {
                                    for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                    {
                                        mat[c][b] = words[poz][c-a];
                                    }
                                    done=1;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                for(int a=0; a<15; a++)
                {
                    for(int b=0; b<15; b++)
                    {
                        if(words[poz][0] == mat[a][b] && done==0)
                        {
                            int vertical=1,orizontal=1;
                            if(b+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[a][c] != '.' && mat[a][c] != words[poz][c-b])
                                    {
                                        orizontal=0;
                                        break;
                                    }
                                }
                                if(orizontal == 1)
                                {
                                    nr++;
                                    if(var==nr-1)
                                    {
                                        for(int c=b+1; c<b+lungime_cuvant_introdus; c++)
                                            mat[a][c]=words[poz][c-b];
                                        done=1;
                                    }
                                }
                            }
                            if(a+lungime_cuvant_introdus <= 15)
                            {
                                for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                {
                                    if(mat[c][b] != '.' && mat[c][b] != words[poz][c-a])
                                    {
                                        vertical=0;
                                        break;
                                    }
                                }
                                if (vertical == 1)
                                {
                                    nr++;
                                    if(var==n-1)
                                    {
                                        for(int c=a+1; c<a+lungime_cuvant_introdus; c++)
                                            mat[c][b]=words[poz][c-a];
                                        done=1;
                                    }
                                }
                            }
                        }
                    }
                }

            }
            s+=MAX;
            strcpy(word[N+l],words[poz]);
        }
        print_board(mat);
        if(w>s)
            printf("Player 1 Won!");
        else
            printf("Player 2 Won!");
    }
    return 0;
}
