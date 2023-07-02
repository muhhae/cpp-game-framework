// #pragma once

// #include <vector>

// #include "image.hpp"

// namespace gp {
//     class animation
//     {
//         private :
//             std::vector<image> frames;

//             vector2 m_origin = vector2(0, 0);
//             vector2 m_position = vector2(0, 0);
//             vector2 m_scale = vector2(1, 1);
//             int m_currentFrame;
//             int m_frameCount;

//         public :
//             animation() { }
            
//             void load(std::string path, int frameCount); 
//             void draw();
//             image& getFrame(int frame);

//             void setOrigin(double x, double y) { m_origin = vector2(x, y); }
//             void setOrigin(vector2 origin) { m_origin = origin; }
//             vector2 getOrigin() { return m_origin; }

//             void setPosition(double x, double y) { m_position = vector2(x, y); }
//             void setPosition(vector2 position) { m_position = position; }
//             vector2 getPosition() { return m_position; }

//             void setScale(double x, double y) { m_scale = vector2(x, y); }
//             void setScale(vector2 scale) { m_scale = scale; }
//             vector2 getScale() { return m_scale; }

//     };
// }