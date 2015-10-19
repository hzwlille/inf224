#include <list>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include <memory>
int main()
{
    typedef shared_ptr<Film> FilmPtr;
    typedef shared_ptr<Photo> PhotoPtr;
    typedef shared_ptr<Group> GroupPtr;

    FilmPtr  tryFilm(new Film("New Film1"));

    unsigned int * a= new unsigned int[10];
    for (int i=1;i<10;i++){
        a[i]=i;
    }
    tryFilm->modify(a,10);
    unsigned int* b=tryFilm->getDureeChapitre();
    b[2]=3;



    GroupPtr group1(new Group("My group"));

    group1->push_back(tryFilm);
    group1->push_back(PhotoPtr(new Photo()));
    group1->clear();
    cout<<"éééééééééééééééééééééééééééééééééééééééé"<<endl;
   // group1->affiche(cout);
}
