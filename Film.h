#ifndef FILM_H
#define FILM_H

#endif // FILM_H

class Film : public Video
{

private:
    unsigned int* m_dureeChapitre;




public:
    //constructeurs
    Film(string nom_multimedia="new_Film", string pathname="/new_project/", unsigned int duree=10, unsigned int* dureeChapitre):Video(nom_multimedia,pathname,duree){
    m_dureeChapitre=dureeChapitre;
    }


   // un modifieur permettant de passer en argument un tableau de durées
    void  virtual modify(unsigned int* dureeChapitre){
        m_dureeChapitre=dureeChapitre;
    }



    //un (ou des) accesseur(s) retournant le tableau de durées et le nombre de chapitres
    unsigned int* virtual getDureeChapitre() const{
        return m_getDureeChapitre;
    }


    // une méthode d'affichage affichant la durée des chapitres (la méthode pour jouer l'objet n'a pas besoin d'être redéfinie)
    void virtual affiche(ostream& s){
        Video::affiche(s);
        while(m_dureeChapitre)
        s<<<<;


    }

};
