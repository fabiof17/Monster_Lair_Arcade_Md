#ifndef _VARIABLES_H
#define _VARIABLES_H

///////////////////////////////////
//		Variables principales
///////////////////////////////////

extern s16 i;
extern u16 ind;

extern u16 StatutJoy;

extern u16 palette[64];

extern u8 nb_Vie;
extern u16 GameOver;
extern u16 PauseJeu;

extern u8 num_Niveau;

///////////////////////////////////
//		Variables scrolling
///////////////////////////////////

extern u8 vitesseScrolling;

extern s16 CamPosX;
extern s16 CamPosY;

extern s16 scrollOffset_TILE_TITRE[10];
extern s16 scrollOffset_TILE_NIVEAU1_BGA[28];
extern s16 scrollOffset_TILE_NIVEAU1_BGB[28];

extern u16 tilemapOffset;

///////////////////////////////////
//		Sprites
///////////////////////////////////

extern Sprite *sprite_Vie[3];
extern Sprite *sprite_Pause[2];



typedef struct
{
    Sprite* SpriteJ;
    u8 phase; // 0=ARRET - 1=MARCHE - 2=CHUTE - 99=CHITE DEBUT
    u8 axe; // 0=DROITE - 1=GAUCHE
    s16 PosX;
    s16 PosY;
    u16 pt_Coll1_X;
    u16 pt_Coll1_Y;
    u16 pt_Coll2_X;
    u16 pt_Coll2_Y;
} SpriteJoueur_;

extern SpriteJoueur_ *Joueur;



typedef struct
{
    Sprite* SpriteE;
    u8 Init;                // Sprite créé ou non
    u8 ID;                  // Type d'ennemi
    u8 PointsVie;           // Nb points de vie
    s16 PosX;               // Position X
    s16 PosY;               // Position Y
    u8 Phase;              // 1 = vivant / 2 = touché
    u8 CompteurFrame;  // Compteur pour passer à la prochaine FRAME
    u8 IndexFrame;     // Index des FRAME
    //u8 Bonus;             // Type de bonus
} SpriteEnnemi_;

extern SpriteEnnemi_ Ennemi[10];









extern Map *tilemapCollision;
extern Map *tilemapEnnemis;

extern u16 tileID_G;
extern u16 tileID_D;

extern u16 tileID_ENNEMI;
extern u8 indexCreaEnnemis;
extern u8 compteurTile; // 0 -> 7 //

extern char monTexte[2];
extern char *texte;

#endif // _MAIN