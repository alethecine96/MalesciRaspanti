#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include "menu.h"
#include "Mappa.h"
#include "MapLoader.h"
#include "Enemy.h"
#include "Observer.h"
#include "Powerup.h"
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

    std::vector<Drawable*> array_of_coin;

    Player player(250,50 ,4, 100, &eyes, &array_of_bullet);

    std::vector<Drawable*> array_of_enemies; //Vettore DI Drawable (qui ci sono tutti gli oggetti disegnabili)
    //riempimento array
    array_of_enemies.push_back(new Enemy (50,50 ,1, 5, 10, &eyes));
    array_of_enemies.push_back(new Enemy (450,50,1, 5, 100, &eyes));
    array_of_enemies.push_back(new Enemy (850,50,1, 5, 100, &eyes));

    std::vector<Drawable*> array_of_powerup;
    array_of_powerup.push_back(new Powerup (350,50, true, false));
    array_of_powerup.push_back(new Powerup (450,550,false, true));

    Mappa mappa(&array_of_enemies, &array_of_bullet, mapArray, &player, &array_of_coin, &array_of_powerup); //crea oggetto mappa

    Observer observer(&array_of_enemies, &player); //oggetto observer


    //Create menu window
    sf::RenderWindow windowMenu(sf::VideoMode(1600,900),"Gioco");
    windowMenu.setVerticalSyncEnabled(true);

    int chooseMenu;
    Menu menu(windowMenu.getSize().x, windowMenu.getSize().y);


    //run the MainMenu loop
    while (windowMenu.isOpen()) {

        //handle events
        sf::Event event;
        while (windowMenu.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    chooseMenu=1;
                                    std::cout << "Play button has been pressed" << std::endl;
                                    windowMenu.close();
                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    windowMenu.close();
                                    break;
                            }
                            break;
                    }
            }
        }

        // draw the map
        windowMenu.clear();
        menu.draw(windowMenu);
        windowMenu.display();
    }


    //Finestra gioco
    sf::RenderWindow window(sf::VideoMode(1280, 704), "Mappa"); //crea la finestra con il gioco

    if(chooseMenu==1) {
        while (window.isOpen()) {
            sf::Event event;


            while (window.pollEvent(event)) {

                switch (event.type) {
                    case sf::Event::KeyPressed:
                        switch (event.key.code) {
                            case sf::Keyboard::Space:
                                player.shoot();
                                break;
                            case sf::Keyboard::Up:
                                player.move(0, -1);
                                break;
                            case sf::Keyboard::Down:
                                player.move(0, +1);
                                break;
                            case sf::Keyboard::Left:
                                player.move(-1, 0);
                                break;
                            case sf::Keyboard::Right:
                                player.move(1, 0);
                                break;
                            case sf::Keyboard::Escape:
                                window.close();
                                break;
                        }

                        //std::cout<<(*array_of_bullet.at(0)).getPositionX()<<std::endl;

                        sf::View playerview;
                        //sf::View mapview;
                        //sf::View minimapview;
                        playerview.setCenter(sf::Vector2f(player.getPositionX() + 32, player.getPositionY() + 32));
                        playerview.setSize(sf::Vector2f(1150, 640));
                        //mapview.setViewport(sf::FloatRect(0, 0, 1 , 1));
                        //minimapview.setViewport(sf::FloatRect(0.75, 0, 0.25, 0.25));
                        window.setView(playerview);
                        //window.setView(minimapview);
                        //window.setView(mapview);

                        break;

                }
            }

            //Cancellazione proiettili
            std::vector<Drawable *>::const_iterator iter;
            int i = 0;
            if (array_of_bullet.empty()) {}
            else {
                for (iter = array_of_bullet.begin(); iter != array_of_bullet.end(); iter++) {

                    (*array_of_bullet.at(i)).move();

                    if (!(eyes.isWalkable((*array_of_bullet.at(i)).getPositionX(),
                                          (*array_of_bullet.at(i)).getPositionY(), player.getDirection()))) {
                        array_of_bullet.erase(array_of_bullet.begin());
                        break;
                    }
                    i++;
                }
            }

            //Movimento nemici
            std::vector<Drawable *>::const_iterator iter1;
            int j = 0;
            for (iter1 = array_of_enemies.begin(); iter1 != array_of_enemies.end(); iter1++) {
                (*array_of_enemies.at(j)).move();
                if (i < array_of_enemies.size()) {
                    j++;
                } else {
                    j = 1;
                }
            }


            //Funzioni Update
            observer.CollisionPlayer();
            observer.CollisionProjectile(&array_of_bullet, &array_of_coin);
            observer.CollisionPickup(&array_of_coin, &array_of_powerup);

            window.clear();
            window.draw(mappa);
            window.display();
        }

        return 0;
    }
}

