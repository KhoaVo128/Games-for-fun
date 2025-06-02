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
    float shape_MoveSpeedX = 0.3f;
    float shape_MoveSpeedY = 0.3f;

    
    sf::RectangleShape player1({100,20});
    player1.setFillColor(sf::Color::Green);
    player1.setPosition(25,100);
    float shape_MoveSpeedX = 0.0f;
    float shape_MoveSpeedY = 0.0f;



    sf::Font myFont;

    if (!myFont.loadFromFile("./Fonts/ARCADECLASSIC.TTF"))
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
            }    
        }

        
        shape.setPosition(shape.getPosition().x-shape_MoveSpeedX,shape.getPosition().y-shape_MoveSpeedY);
        
        if (shape.getPosition().x > wWidth-50 || shape.getPosition().x<0)
        {
            shape_MoveSpeedX*=-1.0f;
        }

        if (shape.getPosition().y > wHeight-50 || shape.getPosition().y<0)
        {
            shape_MoveSpeedY*=-1.0f;
        }

        
        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }
}