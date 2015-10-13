
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
int main()
{
   /* Multimedia** tableOfMultimeida=new Multimedia*[20];
    for(int i=0;i<20;i++){
        if(i/3==1)
            tableOfMultimeida[i]= new Photo();
        else
            tableOfMultimeida[i]= new Video();
    }

    for(int i=0; i<20; i++){

        tableOfMultimeida[i]->affiche(cout);
    }
    */

    Film*  tryFilm= new Film();
    tryFilm->affiche(cout);
    unsigned int * a= new unsigned int[10];
    for (int i=1;i<10;i++){
        a[i]=i;
    }
    tryFilm->modify(a,10);
    tryFilm->affiche(cout);
    unsigned int* b=tryFilm->getDureeChapitre();
    b[2]=3;
    tryFilm->affiche(cout);
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    for(int i=0;i<10;i++){
        cout<<b[i]<<endl;
    }
}
