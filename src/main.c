// Librairies Projet
#include <genesis.h>
#include <dma.h>
#include <main.h>
#include "init.h"
#include "variables.h"
#include "palettes.h"
#include "routines.h"
#include "sprites_JEU.h"
#include "musique.h"


// Procédure principale //
int main(u16 hardreset)
{

    if (!hardreset) SYS_hardReset();

	// Init HW //
	InitSystem();

    // Reset variables //
    InitVariablesGeneral();

    // init VDP //
    VDP_init();

    // Init joypad //
    JOY_init();

    // Waiting VBLANK //
    //SYS_doVBlankProcess();

    //******************************************************************************************//
    //******************************************************************************************//
    //                                                                                          //
    //                                   BOUCLE PRINCIPALE                                      //
    //                                                                                          //
    //******************************************************************************************//
    //******************************************************************************************//
    while(TRUE)
    {
        //**************************************************************************************//
        //                                  ECRAN TITRE                                         //
        //**************************************************************************************//       
        if(Scene==0)
        {
            //////////////////////////////////////////////////////////////////////////////////////
            //                            CHARGEMENT ECRAN TITRE                                //
            //////////////////////////////////////////////////////////////////////////////////////         
            if(Titre_OK==0)
            {
                // Init ECRAN TITRE //
                InitTitre();
            }

            //////////////////////////////////////////////////////////////////////////////////////
            //                             ANIMATION ECRAN TITRE                                //
            ////////////////////////////////////////////////////////////////////////////////////// 
            else
            {
                // Anim ECRAN TITRE //
                AnimTitre();
            }
        }

        //**************************************************************************************//
        //                                ECRAN SELECTION                                       //
        //**************************************************************************************// 
        else if(Scene==1)
        {
            ///////////////////////////////////////////////////////////////////////////////////////
            //                              CHARGEMENT SELECTION                                 //
            ///////////////////////////////////////////////////////////////////////////////////////
            if(Selection_OK==0)
            {
                // Init ECRAN SELECTION //
                InitSelection();

            }
            //////////////////////////////////////////////////////////////////////////////////////
            //                           ANIMATION ECRAN SELECTION                              //
            //////////////////////////////////////////////////////////////////////////////////////
            else
            {
                // Anim ECRAN SELECTION //
                AnimSelection();
            }
        }

        //**************************************************************************************//
        //                                    NIVEAUX                                           //
        //**************************************************************************************// 
        else if(Scene==2)
        {
            ///////////////////////////////////////////////////////////////////////////////////////
            //                                CHARGEMENT NIVEAU                                  //
            ///////////////////////////////////////////////////////////////////////////////////////
            if(Niveau_OK==0)
            {
                // Init NIVEAU //
                InitNiveaux();
            }

            ///////////////////////////////////////////////////////////////////////////////////////
            //                                       JEU                                         //
            ///////////////////////////////////////////////////////////////////////////////////////
            else
            {
                //SYS_showFrameLoad(TRUE);
                
                switch (Num_Niveau)
                {
                    case 1:

                    XGM_startPlay(Niveau1);

                    while(GameOver==0)
                    {

                        JOY_setEventHandler(Game_PF_Callback);

                        // En attente Continue ? //
                        if(Continue==0)
                        {
                            // Jeu en Pause ? //
                            if(PauseJeu==0)
                            {
                                Phases_Joueur();

                                Scrolling_Niveau1();

                                CreaSprites_Niveau1();
                                MvtEnnemis_Niveau1();
                                
                                MvtPlateformes_Niveau1();

                                MvtJoueur();
                                //GestionTirs();
                                
                                TilesJoueur();

                                Maj_CompteurEnergie();
                                Maj_BarreEnergie(CompteurEnergie, Energie);                               
                            }

                            // DEBUG
                            //VDP_drawInt( Niveau_OK , 5 , 10 , 6);

                        }

                        else
                        {
                            Maj_Continue();
                        }

                        // MAJ sprites
                        SPR_update();

                        // MAJ tiles BG
                        Tiles_Niveau1();

                        // Vblank
                        SYS_doVBlankProcess();

                        // CHANGEMENT DES PALETTES
                        ChgtPalette_Niveau1();
                    }

                    //XGM_pausePlay();
                    //XGM_stopPlay();
                    waitMs(4000);
                    XGM_pausePlay();
                    XGM_stopPlay();


                    Clear_Niveau1();
                    SYS_doVBlankProcess();

                    SPR_end();
                    SYS_doVBlankProcess();

                    InitVariablesGeneral();

                    //SYS_hardReset();
                }
            }
        }
    }
    
    return 0;
}
