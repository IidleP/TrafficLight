#include "traficlight.h"
#include <iostream>

// pi_Light
pi_Light::pi_Light() : state(1) {}

void pi_Light::switch_light() {
    state = !state;
}

bool pi_Light::isGreen() {
    return state;
}

bool pi_Light::isYellow() {
    return false;
}

bool pi_Light::isRed() {
    return !state;
}

// car_Light
car_Light::car_Light() : state(0) {}

void car_Light::switch_light() {
    state = (state + 1) % 3;
}

bool car_Light::isGreen() {
    return state == 0;
}

bool car_Light::isYellow() {
    return state == 1;
}

bool car_Light::isRed() {
    return state == 2;
}

// Road 
Road::Road() {
    if (pl.isGreen()) {
        while (!cl.isRed()) {
            cl.switch_light();
        }
    }
    else {
        while (!cl.isGreen()) {
            cl.switch_light();
        }
    }
}

void Road::switch_light() {
    cl.switch_light();

    if (cl.isRed()) {

        if (!pl.isGreen()) {
            pl.switch_light();
        }
    }
    else {
        if (pl.isGreen()) {
            pl.switch_light();
        }
    }
}

void Road::printl(std::ostream& out, Light& l) {
    if (l.isGreen()) out << "Green";
    else if (l.isYellow()) out << "Yellow";
    else if (l.isRed()) out << "Red";
}

std::ostream& operator<<(std::ostream& out, Road& r) {
    out << "P: ";
    r.printl(out, r.pl);
    out << " | C: ";
    r.printl(out, r.cl);
    return out;
}