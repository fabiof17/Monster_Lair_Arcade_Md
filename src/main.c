// Librairies Projet
#include <genesis.h>
#include <dma.h>
#include <main.h>
#include <init.h>
#include <variables.h>
#include <palettes.h>
#include <routines.h>
#include <sprites_JEU.h>

void joyEventCallback(u16 joy, u16 changed, u16 state)
{

    // START //
    if (changed & state & BUTTON_START)
    {
        // Mettre en mode Pause //
        if (PauseJeu==0)
        {
            PauseJeu=1;
            StatutJoy=0;

            SPR_setPosition(sprite_Pause[0], 140, 116);
            SPR_setPosition(sprite_Pause[1], 172, 116);

            //break;
        }
        // Sortir du mode Pause //
        else if (PauseJeu==1)
        {
            PauseJeu=0;
            StatutJoy=0;

            SPR_setPosition(sprite_Pause[0], -40, 0);
            SPR_setPosition(sprite_Pause[1], -32, 0);

            //break;
        }
    }

    // can't do more in paused state
    if (PauseJeu==1) return;

}

// Procédure principale //
int main(u16 hardreset)
{

    if (!hardreset) SYS_hardReset();

	// Init HW
	InitSystem();

    // Ecran Titre
    StartMain();

    return 0;
}

// Titre + Selection joueur //
void StartMain()
{
    // Init Ecran Titre
    InitTitre();

    // Init Ecran sélection
    InitSelection();

    // Init Niveaux
    InitNiveaux();

    // Boucle du jeu
    MainLoop();

    return;  
}

// Boucle Niveaux //
void MainLoop()
{
    SYS_showFrameLoad(TRUE);

    // Manette
    JOY_setEventHandler(joyEventCallback);
    
    switch (num_Niveau)
    {
        case 1:
        while(TRUE)
        {

            // Jeu en Pause ?
            if(PauseJeu==0)
            {
                Phases_Joueur();
                MvtJoueur();
                TilesJoueur();

                Scrolling_Niveau1();

                CreaSprites_Niveau1();
                MvtSprites_Niveau1();

                Collision_Decor();
                Collision_Ennemis();

            }


            // MAJ sprites
            SPR_update();

            // MAJ tiles BG
            Tiles_Niveau1();

            

            //VDP_drawInt( nb_Ennemis , 2 , 36 , 10);

            // Vblank
            SYS_doVBlankProcess();

            // CHANGEMENT DES PALETTES
            ChgtPalette_Niveau1();

        }
        
        break;


    }

    //updateCamera();
    //SYS_doVBlankProcess();
}