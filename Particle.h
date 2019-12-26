#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle
{ 
    private: 
        double speed;
        double direction;
    private:
        void init();

    public: 
        double x;
        double y;
    public: 
        Particle();
        virtual ~Particle();
        void Update( int deltaTime );
};

#endif