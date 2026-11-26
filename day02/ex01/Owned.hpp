#pragma once

struct Enemy { int hp = 100; };

class Owned
{
    public:
        Owned();
        ~Owned();

        Owned(const Owned&) = delete; // Copy block
        Owned& operator=(const Owned&) = delete; // Block reassignation

        Enemy* operator->();

    private:
        Enemy* m_enemy;
};

