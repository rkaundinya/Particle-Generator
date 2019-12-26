#include "Swarm.h"

Swarm::Swarm() : lastTime(0)
{
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
    delete[] m_pParticles;
}

void Swarm::Update( int elapsed )
{
    int deltaTime = elapsed - lastTime;

    for (int i = 0; i < Swarm::NPARTICLES; ++i)
    {
        m_pParticles[i].Update( deltaTime );
    }

    lastTime = elapsed;
}