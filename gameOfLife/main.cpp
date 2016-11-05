
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//
//To do list:
/*
1.Clean code and 
*/
#include "GameBoard.hpp"
using namespace std;
//To-do: work on user input!
int main(int, char const**)
{
    //This is the setup process, creates window and icon
    sf::RenderWindow window(sf::VideoMode(700, 500), "Game of Life by Jackson Lewis"); //window
    sf::Image icon; //icon
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }//load image
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());//icon setup
    sf::Font font;//font
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }//load font
    GameBoard* board =  new GameBoard(20, 20);
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                board->update();
            }
            else board->getUserInput(event,window);
            
        }

        // Clear screen
        window.clear();

        board->draw(window,font);
        //cout<<board->board[1][1]<<endl;
        // Update the window
        window.display();
    }
    delete board;
    return EXIT_SUCCESS;
}
