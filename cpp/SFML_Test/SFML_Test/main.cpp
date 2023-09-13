#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Headers/ResourcePath.hpp"

#include "Headers/Settings.h"
#include "Headers/Entities.h"

//using namespace sf;


int main(int argc, const char *argv[])
{
    // Create the main window
    RenderWindow window(sf::VideoMode(window_width, window_height), window_name, Style::Default);

    // Set the Icon
    Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png"))
    {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    window.setFramerateLimit(20);
    
    window.setActive(true);
    
    Clock game_clock;
    
    Player player(vec2d<double>(400.0, 400.0 - 100.0));
    player.set_velocity(vec2d<double>(50.0, 0.0));
    
    player.set_acceleration(vec2d<double>(0.0, 2500.0 / 100.0));
    //player.
    
    CircleShape game_entity(float(window_width / (2 * 16)));
    game_entity.setFillColor(Color(0, 0, 255));
    
    CircleShape cross(float(window_width / (10 * 2 * 16)));

    // Start the game loop
    while (window.isOpen())
    {
        float game_time = game_clock.getElapsedTime().asMicroseconds();
        game_clock.restart();
        game_time /= 1000000.f;
        //std::cout << 1.f / game_time << std::endl;
        
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                else player.control(&event);
            }
        }
        
        player.move(&game_time);
        
        
        
        player.set_velocity(normalize(player.get_velocity()) * 50.0);
        
        double new_acceleration_angle = player.get_velocity().get_radians() + 3.1415 / 2.0;
        player.set_acceleration(vec2d<double>(cos(new_acceleration_angle), sin(new_acceleration_angle))
                                * pow(player.get_velocity().get_length(), 2.0) * 0.01/*player.get_acceleration().get_length()*/);
        
        window.clear();
        
        // Draw player
        game_entity.setPosition(player.get_position().get_x() - window_width / (2 * 16),
                                player.get_position().get_y() - window_width / (2 * 16));
        window.draw(game_entity);
        
        // Draw velocity vect
        cross.setFillColor(Color(255, 0, 0));
        cross.setPosition(player.get_position().get_x() + player.get_velocity().get_x() - window_width / (10 * 2 * 16),
                          player.get_position().get_y() + player.get_velocity().get_y() - window_width / (10 * 2 * 16));
        window.draw(cross);
        
        // Draw acceleration vect
        cross.setFillColor(Color(0, 255, 0));
        cross.setPosition(player.get_position().get_x() + player.get_acceleration().get_x() - window_width / (10 * 2 * 16),
                          player.get_position().get_y() + player.get_acceleration().get_y() - window_width / (10 * 2 * 16));
        window.draw(cross);
        
        cross.setPosition(400 - window_width / (10 * 2 * 16), 400 - window_width / (10 * 2 * 16));
        window.draw(cross);
        
        window.display();
        
        std::cout << sqrt(pow(player.get_position().get_x() - 400.0, 2.0) + pow(player.get_position().get_y() - 400.0, 2.0)) << "\r\n";
    }

    return EXIT_SUCCESS;
}
