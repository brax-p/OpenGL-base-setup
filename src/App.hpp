#pragma once
#include "Model.hpp"
#include <GL/glew.h>
namespace Tutorial {
    using namespace sf;
    struct App{
        public:
            App(const std::string& title);
            void run();
        private:
            std::string _Title;
    };

    App::App(const std::string& title)
    {
        _Title = title;
    }
    
    void 
    App::run()
    {
       sf::ContextSettings settings;
       settings.depthBits = 24;
       settings.stencilBits = 8;
       settings.antialiasingLevel = 2;
       settings.majorVersion = 3;
       settings.minorVersion = 2;
       settings.attributeFlags = sf::ContextSettings::Core;
       
       sf::Window window(sf::VideoMode(800, 600), this->_Title, sf::Style::Close, settings);
       glewExperimental = GL_TRUE;
       glewInit();

       Model model(window);

       bool running = true;
       while(running)
       {
            Clock clock;
            sf::Event windowEvent;
            while(window.pollEvent(windowEvent))
            {
                switch(windowEvent.type)
                {
                    case sf::Event::Closed:
                    {
                        running = false;
                    } break;
                    case sf::Event::KeyPressed:
                    {
                        if(windowEvent.key.code == sf::Keyboard::Escape)
                            running = false;
                    } break;
                } 
            }
            Time t1 = clock.getElapsedTime();
            model.draw();
            window.display();
            Time t2 = clock.restart();
            std::cout << "Frames Per Second: " << 1.f / t2.asSeconds() << '\n';
       }
    }
} //End of Namespace Tutorial