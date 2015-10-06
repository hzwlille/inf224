#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>
using namespace std;


#endif // MULTIMEDIA_H


class Multimedia {
private :

    string m_nom_multimedia;  //nom de l'objet multimédia

    string m_pathname;        //nom du fichier

public :

    Multimedia();

    Multimedia(string nom_multimedia, string pathname);

    virtual ~Multimedia();

    virtual string getNom_multimedia() const;

    virtual string getPathname() const;

    virtual void setNom_multimedia(string nom_multimedia_r);

    virtual void setPathname(string pathname_r);

    //Afficher les données
    virtual void affiche(ostream&) const;

    //Jouer l'objet multimédia
    virtual void jouer() const=0;
};

