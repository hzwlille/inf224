#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <map>
#include <fstream>
#include <regex>
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
    shared_ptr<Photo> creatPhoto(string photoName="new_photo", string pathname="/new_project/", float latitude=100, float longitude=100){
        shared_ptr<Photo> myPhoto(new Photo(photoName,pathname,latitude,longitude));
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

            MultimediaMap:: iterator myObjet=m_multimediaMap.find(nomObjet);
            shared_ptr<Multimedia> myObjetFind((*myObjet).second);
            for(GroupMap:: iterator it=m_groupMap.begin();it!=m_groupMap.end();++it){       //Itérer pour tous les groupes

                shared_ptr<Group> myGroupFind((*it).second);

                for(Group::iterator itrGroup=myGroupFind.get()->begin();itrGroup!=myGroupFind.get()->end();++itrGroup){
                    if(*itrGroup==myObjetFind){
                        myGroupFind->erase(itrGroup);
                        break;
                    }
                }

            }
            m_multimediaMap.erase(nomObjet);
        }


        else if(m_groupMap.find(nomObjet)!=m_groupMap.end()){                       //Le cas où c'est un objet group
            m_groupMap.erase(nomObjet);
            cout<<"Le groupe "<<nomObjet<<" est effacée"<<endl;
        }


        else{
            cout<<"L'objet n'est pas trouver dans aucun tableau";
        }
    }







    //Rechercher un objet multimédia ou un groupe à partir de son nom, donné en argument
    void findObjet(string nomObjet, ostream& s){
       // s<<"give result"<<endl;
        if(m_multimediaMap.find(nomObjet)!=m_multimediaMap.end()){                 //Le cas où c'est un objet multimedia
            m_multimediaMap[nomObjet]->affiche(s);
        }
        else if(m_groupMap.find(nomObjet)!=m_groupMap.end()){
            m_groupMap[nomObjet]->affiche(s);
        }
        else{
            s<<"L'objet n'est pas trouver dans aucun tableau\nff";
        }
    }


    //Jouer un objet multimédia (à partir de son nom, donné en argument)
    //A compléter*****************************
    void play(string nomObjet, ostream& s){
        if(m_multimediaMap.find(nomObjet)!=m_multimediaMap.end()){                 //Le cas où c'est un objet multimedia
            m_multimediaMap[nomObjet]->jouer();
            s<<"On démarre le jeux:)";
        }
        else
        {
            if(m_groupMap.find(nomObjet)!=m_groupMap.end()){
                s<<"On ne peut pas jouer au groupe";
            }
            else{
                s<<"L'objet n'est pas trouver dans aucun tableau pour jouer";
            }
        }
        s<<"***************";
    }






    //Sérialisation



    fabriqueObjet(ifstream f ,string objet){

        if(objet=="photo"){

            string photoName;
            f.getline(photoName,streamsize(20),'Nom de multimedia: ');

            string pathName;
            f.getline(pathName,streamsize(20),'Pathname: ');
            string slatitude;
            f.getline(slatitude,streamsize(20),'Latitude:');
            long latitude=atol(slatitude);
            string slongitude;
            f.getline(slongitude,streamsize(20),'Latitude:');
            long longitude=atol(slongitude);

            creatPhoto(photoName,pathName,latitude,longitude);
        }
        if(objet=="video"){

        }
        if(objet=="film"){

        }
        if(objet=="pho"){

        }



    }

    bool   save(const string & fileName)
    {
        ofstream f ;
        f.open(fileName);
        if (!f.is_open()) {
            cerr << "Can't open file " << fileName << endl;
            return false;
        }
        for (auto it : m_multimediaMap)
        {

            f<<"**"<<it.first<<"**\n";
            it.second->affiche(f);
            f<<"$$FIN OF THIS OBJECT$$\n\n";
        }

        return true;
}

    bool   load(const string & fileName)
    {
        ifstream f;
        f.open(fileName);
        if(!f.is_open()){
            cerr << "Can't open file " << fileName << endl;
            return false;
        }
        string myCommand="new";

        while(f)

        return true;
    }

};


#endif // ADMINISTRATOR_H
