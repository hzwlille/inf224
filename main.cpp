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
    shared_ptr<Film> film3(tryit->creatFilm("Film3"));
    tryit->creatPhoto("Photo1");
    shared_ptr<Group> group1(tryit->creatGroup("Group1"));

    group1->push_back(film1);
    group1->push_back(film2);
    group1->push_back(film3);

    cout<<"§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§"<<endl;
    tryit->deleteObjet("Film");
    cout<<"§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§"<<endl;

    group1->affiche(cout);


}
