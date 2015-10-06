
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
int main()
{
    Multimedia** tableOfMultimeida=new Multimedia*[20];
    for(int i=0;i<20;i++){
        if(i/3==1)
            tableOfMultimeida[i]= new Photo();
        else
            tableOfMultimeida[i]= new Video();
    }

    for(int i=0; i<20; i++){

        tableOfMultimeida[i]->affiche(cout);
    }

}
