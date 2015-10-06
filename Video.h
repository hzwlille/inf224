#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
using namespace std;

#endif // VIDEO_H

class Video : public Multimedia {
private :

    unsigned int m_duree;        // La durée de la vidéo

public :
    //Constructeur de l'objet vidéo
    Video(string nom_multimedia="new_video", string pathname="/new_project/", unsigned int duree=10):Multimedia(nom_multimedia,pathname){
        m_duree=duree;
    }




    //Destructeur de l'objet vidéo
    virtual ~Video(){
    }




    //Les getters et setters

    virtual unsigned int getDuree() const {
        return m_duree;
    }

    virtual void setDuree(unsigned int duree){
        m_duree=duree;
    }


    //Affichage des données
    virtual void affiche(ostream& s) const{
        Multimedia::affiche(s);
        s<<"\nDurée:"<<m_duree<<"\n";
    }

    //Jouer l'objet vidéo
    virtual void jouer() const{
        string file=this->getPathname();
        string commande="kmplayer "+file+"&";
        system(commande.c_str());
    }
};
