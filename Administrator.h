#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Multimedia.h"
#include "Film.h"
#include "Photo.h"
#include "Video.h"
#include "Group.h"
using namespace std;

typedef map<string, shared_ptr<Multimedia> > MultimediaMap;
typedef map<string, shared_ptr<Group> > GroupMap;
class Administrator{

private:
    MultimediaMap m_multimediaMap;
    GroupMap m_groupMap;

public:


    Administrator(){

    }


    //Créér une Photo, une Vidéo, un Film, un Groupe
    shared_ptr<Photo> creatPhoto(string photoName){
        shared_ptr<Photo> myPhoto(new Photo(photoName));
        m_multimediaMap[photoName] =myPhoto;
        return myPhoto;
    }

    shared_ptr<Video> creatVideo(string videoName){
        shared_ptr<Video> myVideo(new Video(videoName));
        m_multimediaMap[videoName] =myVideo;
        return myVideo;
    }

    shared_ptr<Film> creatFilm(string filmName){
        shared_ptr<Film> myFilm(new Film(filmName));
        m_multimediaMap[filmName] =myFilm;
        return myFilm;
    }

    shared_ptr<Group> creatGroup(string groupName){
        shared_ptr<Group> myGroup(new Group(groupName));
        m_groupMap[groupName]=myGroup;
        return myGroup;
    }


    //Supprimer un objet multimédia ou un groupe à partir de son nom, donné en argument
    void deleteObjet(string nomObjet){

        if(m_multimediaMap.find(nomObjet)!=m_multimediaMap.end()){                 //Le cas où c'est un objet multimedia
            m_multimediaMap.erase(nomObjet);
            for(auto it:m_groupMap){                        //Itérer pour tous les groupes
                //  if((*it).){  //Trouver celui cotenant objet et l'enleve du groupe
            }
        }
        else if(m_groupMap.find(nomObjet)!=m_groupMap.end()){

        }
        else{
            cout<<"L'objet n'est pas trouver dans aucun tableau"<<endl;
        }
    }


    //Rechercher un objet multimédia ou un groupe à partir de son nom, donné en argument
    void findObjet(string nomObjet){

        if(m_multimediaMap.find(nomObjet)!=m_multimediaMap.end()){                 //Le cas où c'est un objet multimedia
            m_multimediaMap[nomObjet]->affiche(cout);
        }
        else if(m_groupMap.find(nomObjet)!=m_groupMap.end()){
            m_groupMap[nomObjet]->affiche(cout);
        }
        else{
            cout<<"L'objet n'est pas trouver dans aucun tableau"<<endl;
        }
    }


    //Jouer un objet multimédia (à partir de son nom, donné en argument)
    //A compléter*****************************


};


#endif // ADMINISTRATOR_H
