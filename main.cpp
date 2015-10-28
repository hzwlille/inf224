#include <list>
#include "Multimedia.h"
#include "Administrator.h"
#include "Group.h"
#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include "TCPServer.h"
using namespace std;

const int DEFAULT_PORT = 3331;
Administrator* tryit=new Administrator();
class MyApp {
public:

    /// Cette fonction est appelée chaque fois qu'il y a une requête à traiter.
    /// - 'request' contient la requête
    /// - 'response' sert à indiquer la réponse qui sera renvoyée au client
    /// - si la fonction renvoie false la connexion est close.
    //
    // Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
    // un thread par client).
    // Si le verrou 'lock' est bloqué en mode WRITE, les autres appels sont bloqués
    // jusqu'à la fin l'appel qui a bloqué le verrou.
    //
    bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response)
    {
        // mettre cette variable à true si la commande modifie les donnees du programme
        bool changeData = false;
        if (request == "delMedias" || request == "delGroups") changeData = true;

        // suivant le cas on bloque le verrou en mode WRITE ou en mode READ
        TCPServer::Lock lock(cnx, changeData);

        cerr << "request: '" << request << "'" << endl;

        // simule un traitement long (décommenter pour tester le verrou)
        // if (changeData) sleep(10); else sleep(5);
        //Traitement des demandes::


        // response = "OK: " + request;
        // cerr << "responsed: '" << response << "'" << endl;



        stringstream myRequest(request);
        stringstream textSend;


        string commande;
        string findString;
        myRequest>>commande;
        myRequest>>findString;

        // Administrator* tryit=new Administrator();
        if(commande=="find")                    //rechercher un objet multimédia
        {
            tryit->findObjet(findString,textSend);
        }
        else
        {
            if(commande=="affiche")             //afficher ses attributs
            {
                string findString;
                myRequest>>findString;
                tryit->findObjet(findString,cerr);
                cerr <<"find"<<endl;

            }
            else
            {
                if(commande=="play")            //jouer un objet multimédia
                {
                    cerr <<"play"<<endl;
                    tryit->play(findString, textSend);

                }
                else
                {
                    textSend<<"Commande inconnue!";
                    cerr <<"Commande inconnue!\n"<<endl;
                }
            }
        }

        response=textSend.str();
        cerr<<response;

        // renvoyer false pour clore la connexion avec le client
        return true;
    }
};


int main(int argc, char* argv[])
{


    shared_ptr<Film> film1(tryit->creatFilm("Film1"));
    shared_ptr<Film> film2(tryit->creatFilm("Film2"));
    shared_ptr<Film> film3(tryit->creatFilm("Film3"));
    tryit->creatPhoto("Photo1");
    shared_ptr<Group> group1(tryit->creatGroup("Group1"));

    group1->push_back(film1);
    group1->push_back(film2);
    group1->push_back(film3);

    cout<<"§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§"<<endl;
    tryit->deleteObjet("Film1");
    cout<<"§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§"<<endl;

    group1->affiche(cout);

    tryit->save("foo.txt");

    TCPServer * server = new TCPServer();
    MyApp * app = new MyApp();
    server->setCallback(app, &MyApp::processRequest);

    int port = (argc >= 2) ? atoi(argv[1]) : DEFAULT_PORT;
    cout << "Starting Server on port " << port << endl;
    int status = server->run(port);

    if (status < 0) {
        cerr << "Could not start Server on port " << port << endl;
        return 1;
    }
    else return 0;
}



