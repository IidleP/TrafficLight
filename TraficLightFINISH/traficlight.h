#pragma once
#include <iostream>

class Light
{
public:
    virtual bool isGreen() = 0;
    virtual bool isYellow() = 0;
    virtual bool isRed() = 0;
    virtual void switch_light() = 0;
    virtual ~Light() {}
};

class pi_Light : public Light {
    bool isGreenState;
public:
    pi_Light();
    void switch_light() override;
    bool isGreen() override;
    bool isYellow() override;
    bool isRed() override;
};

class car_Light : public Light {
    int state;
public:
    car_Light();
    void switch_light() override;
    bool isGreen() override;
    bool isYellow() override;
    bool isRed() override;
};

class Road {
    pi_Light pl;
    car_Light cl;
public:
    Road();
    void switch_light();
    void printl(std::ostream& out, Light& l);
    friend std::ostream& operator<<(std::ostream& out, Road& r);
};
#pragma once
