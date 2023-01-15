#ifndef MODEL_H
#define MODEL_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Model 
{
    public:
        Model(sf::Window& w);
        void update(sf::Window& window, int mouse_x, int mouse_y);
        void draw();
        void handleKeyMovement(sf::Event &event)
        {
            switch(event.key.code){
                case sf::Keyboard::Escape:
                    window.close();
                    break;
            }
        }
        std::vector<sf::ConvexShape> staticShapes;
        sf::Window& window;
};

Model::Model(sf::Window& p_Window) : window(p_Window)
{
    
}

void 
Model::update(sf::Window &window, int mouse_x, int mouse_y)
{
    sf::Vector2f mouses = sf::Vector2f((float)mouse_x, (float)mouse_y);
}

void 
Model::draw()
{
    
}

#endif // ! MODEL_H