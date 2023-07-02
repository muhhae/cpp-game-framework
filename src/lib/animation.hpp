#pragma once

#include <vector>

#include "image.hpp"

namespace gp {
    class animation
    {
        private :
            std::vector<std::unique_ptr<image>> frames;

            vector2 m_origin = vector2(0, 0);
            vector2 m_position = vector2(0, 0);
            vector2 m_scale = vector2(1, 1);
            int m_currentFrame = 0;
            int m_frameCount = 0;
            int m_frameRate = 0;

            double m_time = 0;

        public :
            animation() { }
            
            void load(std::string path, int width = INT_MAX, int height = INT_MAX); 
            void draw(double deltaTime);

            void setOrigin(double x, double y) { m_origin = vector2(x, y); }
            void setOrigin(vector2 origin) { m_origin = origin; }
            vector2 getOrigin() { return m_origin; }

            void setPosition(double x, double y) { m_position = vector2(x, y); }
            void setPosition(vector2 position) { m_position = position; }
            vector2 getPosition() { return m_position; }

            void setScale(double x, double y) { setScale(vector2(x, y)); }
            void setScale(vector2 scale);
            vector2 getScale() { return m_scale; }

            void setFrameRate(int frameRate) { m_frameRate = frameRate; }
            void resetFrame() { m_currentFrame = 0; }

    };
}