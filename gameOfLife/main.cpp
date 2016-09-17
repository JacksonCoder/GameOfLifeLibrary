
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
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
using namespace std;
/*
 THIS THINGS WORKS!!!!!!!!!!!!!!!!
 */
//Main screen:
int fullArray[12][20] = {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

int fateArray[12][20];

//Function definitions
string getString(int i){
    string line;
    
    
    for(int a = 1; a < 19; a++){
        char c;
        if(fullArray[i][a] == 0){
            c = '0';
        }else c = '%';
        line += c;
        
    }
    return line;
}
int fullScan(int y, int x){ //status: working
    int c = fullArray[y][x+1] + fullArray[y+1][x+1] + fullArray[y-1][x] + fullArray[y+1][x] + fullArray[y][x-1] + fullArray[y-1][x-1] + fullArray[y+1][x-1] + fullArray[y-1][x+1];
    //cout<<"Count is "<<c<<endl;
    return c;
}
void checkCells(){
    for(int i = 0; i < 12;i++){
        for(int a = 0; a < 20;a++){
            fateArray[i][a] = fullArray[i][a];
        }
    }
    for(int i = 1; i < 11; i++){//This runs the check for each cell in the main screen
        for(int a = 1; a < 19; a++){
            int count = 0;
            count = fullScan(i,a);
            if(fullArray[i][a] == 1){
                if(count < 2 || count > 3){
                    fateArray[i][a] = 0;
                }
            }else if(count == 3) fateArray[i][a] = 1;
        }
        
    }
    for(int i = 0; i < 12; i++){
        for(int a = 0; a < 20;a++){
            fullArray[i][a] = fateArray[i][a];
        }
    }

}
void cpyinfo(sf::Text &lin1, sf::Text &lin2, sf::Text &lin3, sf::Text &lin4, sf::Text &lin5,sf::Text &lin6, sf::Text &lin7, sf::Text &lin8, sf::Text &lin9, sf::Text &lin10){
    
    lin1.setString(getString(1));
    
    lin2.setString(getString(2));
    
    lin3.setString(getString(3));
    
    lin4.setString(getString(4));
    
    lin5.setString(getString(5));
    
    lin6.setString(getString(6));
    
    lin7.setString(getString(7));
    
    lin8.setString(getString(8));
    
    lin9.setString(getString(9));
    
    lin10.setString(getString(10));
    
}

void updateGame(sf::Text &lin1, sf::Text &lin2, sf::Text &lin3, sf::Text &lin4, sf::Text &lin5,sf::Text &lin6, sf::Text &lin7, sf::Text &lin8, sf::Text &lin9, sf::Text &lin10){

    
    checkCells();

    //Now that we have the updating covered, it's time to transfer that to cells!
    cpyinfo(lin1,lin2,lin3,lin4,lin5,lin6,lin7,lin8,lin9,lin10);
}

void processClick(int x, int y,sf::Text &lin1, sf::Text &lin2, sf::Text &lin3, sf::Text &lin4, sf::Text &lin5,sf::Text &lin6, sf::Text &lin7, sf::Text &lin8, sf::Text &lin9, sf::Text &lin10){
    //cout<<"This loop HAS been activated, and the coordinates are: "<<x<<","<<y<<endl;
    //new formula
    int cx=0;
    int cy=0;
    for(int i = 0; i < 10;i++){
        if(y > i*50){
            cy++;
        }
    }
    for(int a = 2; a < 19; a++){
        if(x > (a*33)){
            cx++;
        }

    }
    if(fullArray[cy][cx] == 0) fullArray[cy][cx] = 1; else fullArray[cy][cx] = 0;
    //cout<<cx<<","<<cy<<endl;
    cpyinfo(lin1,lin2,lin3,lin4,lin5,lin6,lin7,lin8,lin9,lin10);
}


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
    
    
    for(int i = 0; i < 12;i++){
        for(int a = 0; a < 20;a++){
            fateArray[i][a] = fullArray[i][a];
        }
    }
    //Next is our filler variables, and the 5 lines of text
    string line1, line2, line3, line4, line5;
    
    sf::Text l1(line1, font, 50);
    l1.setColor(sf::Color::White);
    
    sf::Text l2(line2, font, 50);
    l2.setColor(sf::Color::White);
    
    sf::Text l3(line3, font, 50);
    l3.setColor(sf::Color::White);
    
    sf::Text l4(line4, font, 50);
    l4.setColor(sf::Color::White);
    
    sf::Text l5(line5, font, 50);
    l5.setColor(sf::Color::White);
    
    sf::Text l6(line1, font, 50);
    l1.setColor(sf::Color::White);
    
    sf::Text l7(line2, font, 50);
    l2.setColor(sf::Color::White);
    
    sf::Text l8(line3, font, 50);
    l3.setColor(sf::Color::White);
    
    sf::Text l9(line4, font, 50);
    l4.setColor(sf::Color::White);
    
    sf::Text l10(line5, font, 50);
    l5.setColor(sf::Color::White);
    // Start the game loop
    cpyinfo(l1,l2,l3,l4,l5,l6,l7,l8,l9,l10);
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
                updateGame(l1,l2,l3,l4,l5,l6,l7,l8,l9,l10);
            }
            else if(event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i v = sf::Mouse::getPosition(window);
                processClick(v.x,v.y,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10);
                //cout<<"The mouse WAS clicked."<<endl;
            }
        }

        // Clear screen
        window.clear();


        // Draw the string
        l1.setPosition(50, 0);
        window.draw(l1);
        l2.setPosition(50, 50);
        window.draw(l2);
        l3.setPosition(50, 100);
        window.draw(l3);
        l4.setPosition(50, 150);
        window.draw(l4);
        l5.setPosition(50, 200);
        window.draw(l5);
        l6.setPosition(50, 250);
        window.draw(l6);
        l7.setPosition(50, 300);
        window.draw(l7);
        l8.setPosition(50, 350);
        window.draw(l8);
        l9.setPosition(50, 400);
        window.draw(l9);
        l10.setPosition(50, 450);
        window.draw(l10);

        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
