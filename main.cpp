#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include "menu.h"
#include "Mappa.h"
#include "MapLoader.h"
#include "Enemy.h"
#include "Observer.h"
#include <array>

int main()
{

    int width=40;
    int heigth=36;
    int tileSize=32;

    int caricatore_proiettili=10;

  //  Menu menu;

//    menu.start();
    MapLoader mapLoader;
    int* mapArray = mapLoader.load("mappetta prova",width*heigth); //carica mappetta prova in mapArray

    Eyes eyes(mapArray,width);  //gli occhi sono gli stessi per tutti

    std::vector<Drawable*> array_of_bullet;

    std::array<Drawable*,4> array_of_enemies; //ARRAY DI Drawable (qui ci sono tutti gli oggetti disegnabili)
    array_of_enemies.at(0)= new Player(50,50 ,4,&eyes, &array_of_bullet);    //riempimento array
    array_of_enemies.at(1)= new Enemy (50,50 ,1,&eyes);
    array_of_enemies.at(2)= new Enemy (50,150,1,&eyes);
    array_of_enemies.at(3)= new Enemy (50,250,1,&eyes);





    Mappa mappa(&array_of_enemies, &array_of_bullet, mapArray); //crea oggetto mappa

    Observer observer(&array_of_enemies); //oggetto observer


    sf::RenderWindow window(sf::VideoMode(1280, 704), "Mappa"); //crea la finestra con il gioco


    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {

             switch (event.type)
            {
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Space:
                                (*array_of_enemies.at(0)).shoot();
                            break;
                        case sf::Keyboard::Up:
                            (*array_of_enemies.at(0)).move(0,-1);
                            break;
                        case sf::Keyboard::Down:
                            (*array_of_enemies.at(0)).move(0,+1);
                            break;
                        case sf::Keyboard::Left:
                            (*array_of_enemies.at(0)).move(-1,0);
                            break;
                        case sf::Keyboard::Right:
                            (*array_of_enemies.at(0)).move(1,0);
                            break;
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                    }

                    //std::cout<<(*array_of_bullet.at(0)).getPositionX()<<std::endl;

                    sf::View playerview;
                    //sf::View mapview;
                    //sf::View minimapview;
                    playerview.setCenter(sf::Vector2f( (*array_of_enemies.at(0)).getPositionX()+32, (*array_of_enemies.at(0)).getPositionY()+32 ));
                    playerview.setSize(sf::Vector2f(1150,640));
                    //mapview.setViewport(sf::FloatRect(0, 0, 1 , 1));
                    //minimapview.setViewport(sf::FloatRect(0.75, 0, 0.25, 0.25));
                    window.setView(playerview);
                    //window.setView(minimapview);
                    //window.setView(mapview);

                    break;

            }
        }


        std::vector<Drawable*>::const_iterator iter;
        int i=0;
        if(array_of_bullet.empty()){}
        else {

            for (iter=array_of_bullet.begin(); iter!=array_of_bullet.end(); iter++) {

                (*array_of_bullet.at(i)).move((*array_of_enemies.at(0)).getDirection());

                if(!(eyes.isWalkable((*array_of_bullet.at(i)).getPositionX(),(*array_of_bullet.at(i)).getPositionY(),(*array_of_enemies.at(0)).getDirection()))){
                    array_of_bullet.erase(array_of_bullet.begin());
                    break;
                }
                i++;
            }
        }


        for(int i=1; i<4; i++)
        {
            (*array_of_enemies.at(i)).move();
        }


        observer.Collision(); //collisione visiva da usare per danno a player
        window.clear();
        window.draw(mappa);
        window.display();
    }

    return 0;

}
