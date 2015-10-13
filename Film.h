#ifndef FILM_H
#define FILM_H

#endif // FILM_H

class Film : public Video
{

private:
    unsigned int* m_dureeChapitre;
    unsigned int  m_numberChapitre;



public:
    //constructeurs
    Film(string nom_multimedia="new_Film", string pathname="/new_project/", unsigned int duree=10):Video(nom_multimedia,pathname,duree){

    }


    //Déstructeur
    ~Film(){
        delete []m_dureeChapitre;
        m_dureeChapitre=nullptr;
        cout<<"Détruit de l'objet "<<getNom_multimedia()<<endl;
       //delete   m_numberChapitre;
    }

    // un modifieur permettant de passer en argument un tableau de durées
    void  virtual modify(unsigned int* dureeChapitre, unsigned int numberChapitre){
        m_dureeChapitre=new unsigned int[numberChapitre];
        for(unsigned int i=0;i<numberChapitre;i++){
            m_dureeChapitre[i]=dureeChapitre[i];
        }
        m_numberChapitre=numberChapitre;
    }



    //un (ou des) accesseur(s) retournant le tableau de durées et le nombre de chapitres
    virtual unsigned int*  getDureeChapitre() const{        //Pour que l'encapsulation ne soit pas romptre, on crée un nouvel objet dont on passe le pointeur au retour
        unsigned int*copie_m_dureeChapitre=new unsigned int[m_numberChapitre];
        for(unsigned int i=0;i<m_numberChapitre;i++){
            copie_m_dureeChapitre[i]=m_dureeChapitre[i];
        }
        return copie_m_dureeChapitre;
    }

    unsigned int virtual getNumberChapitre() const{
        return m_numberChapitre;
    }

    // une méthode d'affichage affichant la durée des chapitres (la méthode pour jouer l'objet n'a pas besoin d'être redéfinie)
    void virtual affiche(ostream& s){
        Video::affiche(s);
        s<<"****************************\n";
        for(unsigned int i=0;i<m_numberChapitre;i++)
        {
            s<<"Chapitre: "<<i<<"  Durée:"<<m_dureeChapitre[i]<<"\n";
        }

    }

};
