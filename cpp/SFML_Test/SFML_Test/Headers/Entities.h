#ifndef ENTITIES_H
#define ENTITIES_H

#include "vec2d_type.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Entity
{
protected:
    vec2d<double> position_;
    vec2d<double> velocity_;
    vec2d<double> acceleration_;
    double angle_velocity_;
    
public:
    Entity(vec2d<double> position = vec2d<double>(0.0, 0.0),
           vec2d<double> velocity = vec2d<double>(0.0, 0.0),
           vec2d<double> acceleration = vec2d<double>(0.0, 0.0),
           double angle_velocity = 0.0)
    :
    position_(position), velocity_(velocity), acceleration_(acceleration), angle_velocity_(angle_velocity) {}
    virtual ~Entity() {}
    
    void move(float *game_time) {
        //double new_angle = velocity_.get_radians() + angle_velocity_ * (double)*game_time * 0.5;
        position_ = position_ + velocity_ * (double)*game_time + acceleration_ * pow((double)*game_time, 2.0) * 0.5;
        velocity_ = velocity_ + acceleration_ * (double)*game_time;
    }
    
    // Getters
    vec2d<double> get_position() const {
        return position_;
    }
    vec2d<double> get_velocity() const {
        return velocity_;
    }
    vec2d<double> get_acceleration() const {
        return acceleration_;
    }
    
    // Setters
    void set_position(vec2d<double> vect) {
        position_ = vect;
    }
    void set_velocity(vec2d<double> vect) {
        velocity_ = vect;
    }
    void set_acceleration(vec2d<double> vect) {
        acceleration_ = vect;
    }
};

class Player : public Entity
{
public:
    Player(vec2d<double> position = vec2d<double>(0.0, 0.0),
           vec2d<double> velocity = vec2d<double>(0.0, 0.0),
           vec2d<double> acceleration = vec2d<double>(0.0, 0.0))
    :
    Entity(position, velocity, acceleration) {}
    ~Player() override {}
    
    void control(Event *event)
    {
        if (event->key.code == Keyboard::A)
        {
            // Get curent angle
            double velocity_angle = velocity_.get_radians();
            // Change angle
            velocity_angle -= 3.1415 / 36.0;
            // Set vector
            velocity_ = vec2d<double>(cos(velocity_angle), sin(velocity_angle)) * velocity_.get_length();
        }
        else if (event->key.code == Keyboard::D)
        {
            // Get curent angle
            double velocity_angle = velocity_.get_radians();
            // Change angle
            velocity_angle += 3.1415 / 36.0;
            // Set vector
            velocity_ = vec2d<double>(cos(velocity_angle), sin(velocity_angle)) * velocity_.get_length();
        }
    }
};

#endif
