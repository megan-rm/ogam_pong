#pragma once

#ifndef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <string>

class Entity
{
public:
    Entity();
    virtual ~Entity();
    virtual void update(float dt);
    virtual void draw(SDL_Renderer* renderer);
    virtual void move(float x, float y);

    void set_position(int x, int y);
    void set_size(int w, int h);
    void stretch_width(float w);
    void stretch_height(float h);

    bool register_texture(SDL_Texture* tex);
    void register_rect(SDL_Rect& rect);

    int get_width();
    int get_height();
    int get_xpos();
    int get_ypos();
private:
protected:
    SDL_Texture* texture;
    SDL_Rect collision_box;
    float x_pos, y_pos;
    float x_accel, y_accel;
    bool alive;
};