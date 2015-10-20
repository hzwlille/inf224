#include <list>
#include "Multimedia.h"
#include "Administrator.h"
#include "Group.h"
#include <memory>
int main()
{
    Administrator* tryit=new Administrator();
    shared_ptr<Film> film1(tryit->creatFilm("Film1"));
    shared_ptr<Film> film2(tryit->creatFilm("Film2"));
    tryit->creatPhoto("Photo1");
    shared_ptr<Group> group1(tryit->creatGroup("Group1"));
    tryit->findObjet("Film2");

    tryit->findObjet("Group1");
    group1->affiche(cout);
    group1->push_back(film1);
    group1->push_back(film2);
    group1->affiche(cout);
    cout<<"§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§"<<endl;
    tryit->deleteObjet("Film1");
    //tryit->play("Photo1");


}
