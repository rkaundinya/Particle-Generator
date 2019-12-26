#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

int main()
{
    srand(time(NULL));

    Screen screen;

    if (screen.Init() == false)
    {
        std::cout << "Error initializing SDL." << std::endl;
    }

    Swarm swarm;
    int halfScreenWidth = Screen::SCREEN_WIDTH / 2;
    int halfScreenHeight = Screen::SCREEN_HEIGHT / 2;

    while (true)
    {
        // Update particles
        
        // Draw Particles
        int elapsed = SDL_GetTicks();

        // screen.Clear();

        swarm.Update( elapsed );

        unsigned char red = (unsigned char)((1 + cos(elapsed * 0.0001)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);

        const Particle *const pParticles = swarm.getparticles();

        for (int i=0; i < Swarm::NPARTICLES; ++i)
        {
            Particle particle = pParticles[i];

            int x = (particle.x + 1) * halfScreenWidth;
            int y = particle.y * halfScreenWidth + halfScreenHeight;

            screen.SetPixel(x, y, red, green, 0);
        }

        screen.boxBlur();

        // Draw Screen
        screen.Update();

        // Check for messages/events
        if (screen.ProcessEvents() == false)
        {
            break;
        }
    }

    screen.Close();

    return 0;
}