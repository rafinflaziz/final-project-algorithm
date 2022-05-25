#include "jam.h"
#include <stdio.h>

JAM buka;
JAM tutup;

boolean IsJAMValid (int H, int M, int S){
    return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59) && (S >= 0) && (S <= 59));
}

JAM MakeJAM (int HH, int MM, int SS){
    JAM j;
    j.HH = HH;
    j.MM = MM;
    j.SS = SS;
    return j;
}

void BacaJAM (JAM * J){
    int H, M, S;
    scanf("%d %d %d", &H, &M, &S);
    while(!IsJAMValid(H, M, S)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &H, &M, &S);
    }
    *J = MakeJAM(H, M, S);
}

void MakeJamBuka (JAM * J){
    int H, M, S;
    H = 9;
    M = 00;
    S = 00;
    *J = MakeJAM(H, M, S );
}

void MakeJamTutup (JAM *J){
    int H, M, S;
    H = 21;
    M = 00;
    S = 00;
    *J = MakeJAM(H, M, S );  
}

void TulisJAM (JAM J){
    if (Hour(J) < 10 && Minute(J) < 10)
    {
        printf("%d%d.%d%d", 0, Hour(J), Minute(J), 0); 
    }
    else if (Hour(J) < 10 && Minute(J) >= 10)
    {
        printf("%d%d.%d", 0, Hour(J), Minute(J));
    }
    else if (Hour(J) >= 10 && Minute(J) < 10)
    {
        printf("%d.%d%d", Hour(J), Minute(J), 0);
    }
    else
    {
        printf("%d.%d", Hour(J), Minute(J));
    }
}

long JAMToDetik (JAM J){
    return (3600*J.HH + 60*J.MM + 1*J.SS);
}

JAM DetikToJAM (long N){
    return MakeJAM(((N % 86400) / 3600), (((N % 86400) % 3600) / 60), (((N % 86400) % 3600) % 60));
}

boolean JEQ (JAM J1, JAM J2){
    return(JAMToDetik(J1) == JAMToDetik(J2));
}

boolean JNEQ (JAM J1, JAM J2){
    return(JAMToDetik(J1) != JAMToDetik(J2));
}

boolean JLT (JAM J1, JAM J2){
    return(JAMToDetik(J1) < JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2){
    return(JAMToDetik(J1) > JAMToDetik(J2));
}

JAM NextNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J) + (1L*N));
}

JAM NextDetik (JAM J){
    return NextNDetik(J, 1);
}

JAM PrevNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J) - (1*N) + 86400);
}

JAM PrevDetik (JAM J){
    return PrevNDetik(J, 1);
}

long Durasi (JAM JAw, JAM JAkh){
    return((JAMToDetik(JAkh)-JAMToDetik(JAw)+86400)%86400);
}
