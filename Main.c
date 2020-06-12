#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int main (void)

{

    int continuee=1;

    SDL_Surface *ecran =NULL;

    SDL_Surface *image=NULL;
	
    SDL_Rect posimage,poshero;

	SDL_Event event ; 
    SDL_Init(SDL_INIT_VIDEO);

    ennemi e ;
    minimap m ;
    curseur c;


    ecran = SDL_SetVideoMode(700,490,32, SDL_HWSURFACE | SDL_DOUBLEBUF);




    image=IMG_Load("m.jpeg");
    posimage.x=0;
    posimage.y=0;


	

    if (ecran==NULL)

    {

        printf("error: %s ",SDL_GetError());

        exit(EXIT_FAILURE);

    }




	e=initialisation_ennemi(e);
	c=initialisation_curseur(c);
	m=initialisation_minimap(m);	
	

    while (continuee)
    {
      SDL_PollEvent(&event) ; 
 switch  ( event.type )  
	{ 
             case  SDL_QUIT : 
                 continuee  =  0 ; 
break;
	}
        SDL_BlitSurface(image, NULL, ecran, &posimage);
	afficher_minimap(m,c,ecran);
	
        afficher(e,ecran);
	
        maj_ennemi (&e) ;
	mini_map(&c ,&e) ;
        SDL_Flip(ecran);




    }










    SDL_FreeSurface(ecran);
	
    SDL_Quit();

    return EXIT_SUCCESS;

}

