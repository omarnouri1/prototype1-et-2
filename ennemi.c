#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"



ennemi initialisation_ennemi(ennemi e)
{
	
e.sprite=IMG_Load("sprite.jpg");	
	e.positionennemi.x=500 ;
	e.positionennemi.y=300 ;
e.direction=1;
e.ligne=0;
e.col=0;
      e.posSprite[0][0].x =0 ;
      e.posSprite[0][0].y =0 ;
      e.posSprite[0][0].w =672/6 ; 
      e.posSprite[0][0].h =254/2  ;

      e.posSprite[0][1].x =112 ;
      e.posSprite[0][1].y =0 ;
      e.posSprite[0][1].w =672/6 ; 
      e.posSprite[0][1].h =254/2  ; 


      e.posSprite[0][2].x =112*2 ;
      e.posSprite[0][2].y =0 ;
      e.posSprite[0][2].w =672/6 ; 
      e.posSprite[0][2].h =254/2  ;

      e.posSprite[0][3].x =112*3 ;
      e.posSprite[0][3].y =0 ;
      e.posSprite[0][3].w =672/6 ; 
      e.posSprite[0][3].h =254/2  ;

      e.posSprite[0][4].x =112*4 ;
      e.posSprite[0][4].y =0 ;
      e.posSprite[0][4].w =672/6 ; 
      e.posSprite[0][4].h =254/2  ;

      e.posSprite[0][5].x =112*5 ;
      e.posSprite[0][5].y =0 ;
      e.posSprite[0][5].w =672/6 ; 
      e.posSprite[0][5].h =254/2  ;

      e.posSprite[1][0].x =0 ;
      e.posSprite[1][0].y =127 ;
      e.posSprite[1][0].w =672/6 ; 
      e.posSprite[1][0].h =254/2  ;

      e.posSprite[1][1].x =112 ;
      e.posSprite[1][1].y =127 ;
      e.posSprite[1][1].w =672/6 ; 
      e.posSprite[1][1].h =254/2  ; 


      e.posSprite[1][2].x =112*2 ;
      e.posSprite[1][2].y =127 ;
      e.posSprite[1][2].w =672/6 ; 
      e.posSprite[1][2].h =254/2  ;

      e.posSprite[1][3].x =112*3 ;
      e.posSprite[1][3].y =127 ;
      e.posSprite[1][3].w =672/6 ; 
      e.posSprite[1][3].h =254/2  ;

      e.posSprite[1][4].x =112*4 ;
      e.posSprite[1][4].y =127 ;
      e.posSprite[1][4].w =672/6 ; 
      e.posSprite[1][4].h =254/2  ;

      e.posSprite[1][5].x =112*5 ;
      e.posSprite[1][5].y =127  ;
      e.posSprite[1][5].w =672/6 ; 
      e.posSprite[1][5].h =254/2  ;	
	

return e;
}

void afficher(ennemi e ,SDL_Surface *ecran)
{
	
SDL_BlitSurface(e.sprite,&e.posSprite[e.ligne][e.col],ecran,&e.positionennemi);
SDL_FreeSurface(&e.posSprite[e.ligne][e.col]);
	
}


void deplacement_aleatoire(ennemi *e)
{

if ((e->positionennemi).x>=588 ) 
		e->direction = 0;

if ((e->positionennemi).x<=0 )
		e->direction = 1;
if (e->direction == 1)
		(e->positionennemi).x ++ ;
	if (e->direction == 0)
		(e->positionennemi).x -- ;

} 

void animer_ennemi(ennemi *e ) 
{
e->ligne = e->direction ; 
if   (e->posSprite[e->ligne][e->col].x==672-e->posSprite[e->ligne][e->col].w)
{
e->posSprite[e->ligne][e->col].x=0;
}
else e->posSprite[e->ligne][e->col].x=e->posSprite[e->ligne][e->col].x+e->posSprite[e->ligne][e->col].w ; 
}
		

void maj_ennemi (ennemi *e) {
deplacement_aleatoire(e) ;
animer_ennemi(e);  
}


int collision_bb(ennemi e , SDL_Rect poshero )
{
int collision ;
if (( poshero.x+poshero.w<(e.positionennemi).x) || (poshero.x>(e.positionennemi).x + (e.positionennemi).w) || (poshero.y+poshero.h<(e.positionennemi).y) || (poshero.y>(e.positionennemi).y+(e.positionennemi).h))
{
collision=0 ;
}
else collision=1 ; 
return collision ;
}









