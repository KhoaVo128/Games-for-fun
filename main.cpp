#include <SFML/Graphics.hpp>
#include <iostream>
const unsigned int wWidth = 1280;
const unsigned int wHeight = 720;
int main()
{
    sf::RenderWindow window(sf::VideoMode({wWidth, wHeight}), "SFML works!");
    
    std::vector<sf::CircleShape> circles;
    std::vector<sf::RectangleShape> rectangles;

    
    
    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(wWidth/2,wHeight/2);
    float shape_MoveSpeed = 0.01f;




    sf::Font myFont;

    if (!myFont.loadFromFile("./ARCADECLASSIC.TTF"))
    {
        std::cerr<<"Could not load font\n";
        exit(-1);
    }
    
    sf::Text text("Sample Text",myFont,24);
    text.setPosition(0,wHeight-(float)text.getCharacterSize());


    while (window.isOpen())
    {   
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed){
                window.close();
            }

            if(event.type==sf::Event::KeyPressed){
                std::cout<< "Key pressed with code = "<< event.key.code <<"/n";

                if(event.key.code== sf::Keyboard::X){
                    //window.close();
                    shape_MoveSpeed*=-1.0f;
                }
            }    
        }
        shape.setPosition(shape.getPosition().x-shape_MoveSpeed,shape.getPosition().y-shape_MoveSpeed);

        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }
}