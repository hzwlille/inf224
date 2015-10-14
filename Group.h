#ifndef GROUP_H
#define GROUP_H
#include <list>

class Group: public list<Multimedia*>{

private:
    string m_nomDuGroupe;
public:

    //un constructeur

    Group(string nomDuGroupe):list<Multimedia*>(){
        m_nomDuGroupe=nomDuGroupe;
    }

    //un accesseur qui renvoie le nom du groupe
    string getName(){
        return m_nomDuGroupe;
    }

    //une méthode d'affichage qui affiche les attributs de tous les objets de la liste
    void affiche(ostream& s){
        s<<"Le groupe: "<<m_nomDuGroupe<<":"<<endl;
        //while(this->has){
         int a=this->size();
         for(int i=0;i<a;i++){
             Multimedia* w=(this->front());
             *w->affiche(s);

             s<<"good"<<endl;
         }

    }

};



#endif // GROUP_H
