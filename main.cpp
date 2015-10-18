#include <list>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
int main()
{
    Film*  tryFilm= new Film();

    unsigned int * a= new unsigned int[10];
    for (int i=1;i<10;i++){
        a[i]=i;
    }
    tryFilm->modify(a,10);
    unsigned int* b=tryFilm->getDureeChapitre();
    b[2]=3;


    Photo* tryPhoto= new Photo();

    Group* group1=new Group("My group");

    group1->push_back(tryFilm);
    group1->push_back(tryPhoto);

    group1->affiche(cout);
}
