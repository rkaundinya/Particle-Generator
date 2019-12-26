#include "Particle.h"
#include <math.h>
#include <stdlib.h>

Particle::Particle() : x(0), y(0)
{
	init();
}

void Particle::init()
{
    x = 0;
    y = 0;
    direction = (2 * M_PI * rand())/RAND_MAX;
    speed = (0.16 * rand())/RAND_MAX;

    speed *= speed;
}

Particle::~Particle() {}

void Particle::Update( int deltaTime ) 
{
    direction += deltaTime * 0.00009;

    double xSpeed = speed * cos(direction);
    double ySpeed = speed * sin(direction);

    x += xSpeed * deltaTime;
    y += ySpeed * deltaTime;

    if ( x < -1 || x > 1 || y < -1 || y > 1 )
    {
        init();
    }

    if ( rand() < RAND_MAX / 100 )
    {
        init();
    }
}