#pragma once

#include <graphics.h>
#include <string>
#include <memory>

#include "vector2.hpp"

namespace gp {
    class image {
        private :
            vector2 m_origin = vector2(0, 0);
            vector2 m_position = vector2(0, 0);
            vector2 m_scale = vector2(1, 1);

            std::string path;
            int width;
            int height;
            BITMAP* img;

        public :
            //constructor destructor
            image() {}
            ~image() { free(img); }

            //main function
            void load(std::string path, int width = INT_MAX, int height = INT_MAX);
            void draw();

            //get and set
            void setOrigin(double x, double y) { m_origin.setX(x); m_origin.setY(y); }
            void setOrigin(vector2 origin) { m_origin = origin; }
            vector2 getOrigin() { return m_origin; }

            void setPosition(double x, double y) { m_position.setX(x); m_position.setY(y); }
            void setPosition(vector2 position) { m_position = position; }
            vector2 getPosition() { return m_position; }

            void setScale(double x, double y) { vector2 scale = vector2(x, y); setScale(scale); }
            void setScale(vector2 scale);
            vector2 getScale() { return m_scale; }

            void updateImage();
    };
}