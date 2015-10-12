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


    // un modifieur permettant de passer en argument un tableau de durées
    void  virtual modify(unsigned int* dureeChapitre, unsigned int numberChapitre){
        m_dureeChapitre=dureeChapitre;
        m_numberChapitre=numberChapitre;
    }



    //un (ou des) accesseur(s) retournant le tableau de durées et le nombre de chapitres
    unsigned int virtual getDureeChapitre() const{        //?Je ne comprends pas pourquoi on ne peut pas utiliser le pointeur?
        return m_dureeChapitre;
    }

    unsigned int virtual getNumberChapitre() const{
        return m_numberChapitre;
    }

    // une méthode d'affichage affichant la durée des chapitres (la méthode pour jouer l'objet n'a pas besoin d'être redéfinie)
    void virtual affiche(ostream& s){
        Video::affiche(s);
        s<<"****************************\n";
        for(int i=0;i<m_numberChapitre;i++)
        {
            s<<"Chapitre: "<<i<<"  Durée:"<<m_dureeChapitre[i]<<"\n";
        }

    }

};
