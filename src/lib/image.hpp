#pragma once

#include <graphics.h>
#include <string>

#include "vector2.hpp"

namespace gp {
    class image {
        private :
            vector2 m_origin;
            vector2 m_position;

            void* img;

        public :
            //main function
            void load(std::string path);
            void draw();

            //get and set
            void setOrigin(float x, float y) { m_origin.setX(x); m_origin.setY(y); }
            void setOrigin(vector2 origin) { m_origin = origin; }
            vector2 getOrigin() { return m_origin; }

            void setPositon(float x, float y) { m_position.setX(x); m_position.setY(y); }
            void setPosition(vector2 position) { m_position = position; }
            vector2 getPosition() { return m_position; }
    };
}