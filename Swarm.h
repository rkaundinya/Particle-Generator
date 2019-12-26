#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

class Swarm
{
    public: 
        const static int NPARTICLES = 5000;

    private: 
        Particle *m_pParticles;
        int lastTime;
    
    public:
        Swarm();
        virtual ~Swarm();
        void Update( int elapsed );

        const Particle *const getparticles() { return m_pParticles; };
};

#endif