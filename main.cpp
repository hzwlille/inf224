
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
int main()
{
    Video* th=new Video("Like","c: is/like/good",150);
    th->affiche(cout);
    th->jouer();
}
