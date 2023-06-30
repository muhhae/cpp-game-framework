#include "lib/image.hpp"
#include <iostream>

namespace gp {
    void image::draw()
    {
        putimage(m_position.getX() - m_origin.getX() * m_scale.getX(), m_position.getY() - m_origin.getY() * m_scale.getY(), img, XOR_PUT);
    }

    void image::load(std::string path, int width, int height)
    {
        setactivepage(0);
        setvisualpage(0);

        std::cout<<"Loading image: "<<path<<std::endl;

        readimagefile("Image/attack1_1.gif", 0, 0, width * m_scale.getX(), height * m_scale.getY());
        unsigned size = imagesize(0, 0, width * m_scale.getX(), height * m_scale.getY());

        img = (BITMAP*)malloc(size);

        std::cout<<"Image Read"<<std::endl;

        getimage(0, 0, width * m_scale.getX(), height * m_scale.getY(), img);     
        
        std::cout<<"Image loaded"<<std::endl;
    }
}