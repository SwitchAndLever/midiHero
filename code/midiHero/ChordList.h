/*
  List of 132 common chords and their respective notes in [array] format.
*/

/*
  {F1, C2, F2, A2, C3, F3};       Ab
  {F1, C2, F2, A2b, C3, F3};      Abm
  {A1b, C2, E2b, A2b, C3, F3};    Ab6
  {E2b, A2b, C3, G3b};            Ab6
  {E2b, B2b, C3, G3b};            Ab9
  {B2, E3b, A3b};                 Abm6
  {E2b, A2b, B2, G3b};            Abm7
  {E2b, A2b, C3, G3};             Abmaj7
  {D2, A2b, B2, F3};              Abº
  {E2, A2b, C3, E3};              Ab+
  {E2b, A2b, D3b, A3b};           Absus4
  {A1, E2, A2, D3b, E3};          A
  {A1, E2, A2, C3, E3};           Am
  {A1, E2, A2, D3b, G3b};         A6
  {A1, E2, A2, D3b, G3};          A7
  {A1, E2, B2, D3b, G3};          A9
  {A1, E2, A2, C3, G3b};          Am6
  {A1, E2, A2, C3, G3};           Am7
  {A1, E2, A2b, D3b, E3};         Amaj7
  {E2b, A2, C3, G3b};             Aº
  {A1, F2, A2, D3b, F3};          A+
  {A1, E2, A2, D3, E3};           Asus4
  {B1b, F2, B2b, D3, F3};         Bb
  {B1b, F2, B2b, D3b, F3};        Bbm
  {F1, B1b, F2, B2b, D3, G3};     Bb6
  {E2b, A2b, C3, G3b};            Bb7
  {F1, B1b, F2, A2b, C3, F3};     Bb9
  {F2, B2b, D3b, G3};             Bbm6
  {F2, B2b, D3b, A3b};            Bbm7
  {B1b, F2, A2, D3, };            Bbmaj7
  {E2, B2b, D3b, G3};             Bbº
  {D2, B2b, D3, G3b};             Bb+
  {F2, B2b, E3b, F3};             Bbsus4
  {B1, G2b, B2, E3b, G3b};        B
  {B1, G2b, B2, D3, G3b};         Bm
  {G1b, B1, G2b, B2, E3b, A3b};   B6
  {B1, E2b, A2, B2, G3b};         B7
  {B1, E2b, A2, D3b, G3b};        B9
  {G2b, B2, D3, A3b};             Bm6
  {B1b, F2, A2b, D3b, F3};        Bm7
  {B1, G2b, B2b, E3b, };          Bmaj7
  {D2, A2b, B2, F3};              Bº
  {F2, A2, D3b, F3};              B+
  {F2, B2b, E3b, F3};             Bsus4
  {G1, C2, E2, G2, C3, E3};       C
  {B1b, F2, B2b, D3b, F3};        Cm
  {C2, E2, G2, D3, G3};           Cadd9
  {E2, A2, C3, G3};               C6
  {C2, E2, B2b, C3, E3};          C7
  {C2, E2, B2b, D3, G3};          C9
  {E2b, A2, C3, G3};              Cm6
  {E2b, B2b, C3, G3};             Cm7
  {C2, E2, G2, B2, E3};           Cmaj7
  {E2b, A2, C3, G3b};             Cº
  {E2, A2b, C3, E3};              C+
  {F2, G2, C3, G3};               Csus4
  {F2, A2b, D3b, F3};             Db
  {E2, A2b, D3b, E3};             Dbm
  {F2, B2b, D3b, A3b};            Db6
  {F2, B2, D3b, A3b};             Db7
  {D2b, F2, B2, E3b, A3b};        Db9
  {E2, B2b, D3b, A3b};            Dbm6
  {E2, B2, D3b, A3b};             Dbm7
  {D2b, F2, A2b, C3, F3};         Dbmaj7
  {E2, B2b, D3b, G3};             Dbº
  {F2, A2, D3b, F3};              Db+
  {F2, B2b, E3b, F3};             Dbsus4
  {D2, A2, D3, G3b};              D
  {D2, A2, D3, F3};               Dm
  {A1, D2, A2, B2, G3b};          D6
  {D2, A2, C3, G3b};              D7
  {G1b, A1, D2, A2, C3, E3};      D9
  {D2, A2, B2, F3};               Dm6
  {D2, A2, C3, F3};               Dm7
  {D2, A2, D3b, G3b};             Dmaj7
  {D2, A2b, B2, F3};              Dº
  {D2, B2b, D3, G3b};             D+
  {D2, A2, D3, G3};               Dsus4
  {F2, A2b, D3b, F3};             Eb
  {G2b, B2b, E3b, G3b};           Ebm
  {E2b, B2b, C3, G3};             Eb6
  {E2b, B2b, D3b, G3};            Eb7
  {F1, B1b, E2b, B2b, D3b, F3};   Eb9
  {E2b, B2b, C3, G3b};            Ebm6
  {E2b, B2b, D3b, G3b};           Ebm7
  {E2b, B2b, D3, G3};             Ebmaj7
  {E2b, A2, C3, G3b};             Ebº
  {E2b, G2, B2, G3};              Eb+
  {E2b, B2b, E3b, A3b};           Ebsus4
  {E1, B1, E2, A2b, B2, E3};      E
  {E1, B1, E2, G2, B2, E3};       Em
  {E1, B1, E2, A2b, D3b, E3};     E6
  {E1, B1, E2, A2b, D3, E3};      E7
  {E1, B1, D2, A2b, B2, G3b};     E9
  {E1, B1, E2, G2, C3, E3};       Em6
  {E1, B1, D2, G2, B2, E3};       Em7
  {E1, B1, E2b, A2b, B2, E3};     Emaj7
  {E2, B2b, D3b, G3};             Eº
  {E2, A2b, C3, E3};              E+
  {E1, B1, E2, A2, B2, E3};       Esus4
  {F1, C2, F2, A2, C3, F3};       F
  {F1, B1, E2, A2b, C3, F3};      Fm
  {D2, A2, C3, F3};               F6
  {F1, C2, E2b, A2, C3, F3};      F7
  {F2, A2, E3b, G3};              F9
  {D2, A2b, C3, F3};              Fm6
  {E1, C2, E2b, A2b, C3, F3};     Fm7
  {F2, A2, C3, E3};               Fmaj7
  {D2, A2b, B2, F3};              Fº
  {F2, A2, D3b, F3};              F+
  {F2, B2b, C3, F3};              Fsus4
  {G1b, D2b, G2b, B2b, D3b, G3b}; F#
  {G1b, D2b, G2b, A2, D3b, G3b};  F#m
  {D2b, G2b, B2b, E3b, };         F#6
  {G2b, B2b, D3b, E3};            F#7
  {E2, A2b, D3, G3b};             F#9
  {E2b, A2, D3b, G3b};            F#m6
  {E2, A2, D3b, G3b};             F#m7
  {G2b, B2b, D3b, F3};            F#maj7
  {E2b, A2, C3, G3b};             F#º
  {G2b, B2b, D3, G3b};            F#+
  {G2b, B2, D3b, G3b};            F#sus4
  {G1, B1, D2, G2, B2, G3};       G
  {F1, C2, F2, A2b, C3, F3};      Gm
  {G1, B1, D2, G2, B2, E3};       G6
  {G1, B1, D2, G2, B2, F3};       G7
  {G1, A1, D2, A2, B2, F3};       G9
  {E2, B2b, D3, G3};              Gm6
  {F1, C2, E2b, A2b, C3, F3};     Gm7
  {G2b, B2b, D3b, F3};            Gmaj7
  {E2, B2b, D3b, G3};             Gº
  {E2b, G2, B2, G3};              G+
  {D2, G2, C3, G3};               Gsus4
*/
