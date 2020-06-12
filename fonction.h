#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_




typedef struct ennemi
{

SDL_Surface *sprite ;


SDL_Rect posSprite[2][6];

int ligne ;
int col ;

SDL_Rect positionennemi ;

int direction ;

}ennemi;

typedef struct minimap
{ 
  SDL_Surface* s ;
  SDL_Rect position ;
}minimap ; 

typedef struct curseur
{ 
  SDL_Surface* cu ;
  SDL_Rect position ;
}curseur ; 

               



ennemi initialisation_ennemi(ennemi e);

void afficher(ennemi e ,SDL_Surface *ecran) ;

void deplacement_aleatoire(ennemi *e);

void animer_ennemi(ennemi *e ) ;

void maj_ennemi (ennemi *e) ;

int collision_bb(ennemi e , SDL_Rect poshero ) ;

minimap initialisation_minimap (minimap m) ;

curseur initialisation_curseur (curseur c) ; 

void afficher_minimap(minimap m,curseur c,SDL_Surface *ecran);

void mini_map(curseur * c ,ennemi *e);






#endif

