#include "lib/image.hpp"
#include <iostream>
#include <filesystem>

namespace gp {
    void image::draw()
    {
        putimage(m_position.getX() - m_origin.getX() * m_scale.getX(), m_position.getY() - m_origin.getY() * m_scale.getY(), img, XOR_PUT);
    }

    void image::load(std::string path, int width, int height)
    {
        std::cout<<"\n";
        free(img);

        this->path = path;
        this->width = width;
        this->height = height;

        int currentActivePage = getactivepage();
        setactivepage(0);
        cleardevice();

        std::cout<<"Loading image: \""<<path<<"\""<<std::endl;
        std::cout<<"Checking if file exists"<<std::endl;

        if (std::filesystem::exists(path))
        {
            std::cout<<"\""<<path<< "\" Exists"<<std::endl;
        }
        else 
        {
            std::cout<<"\""<<path<< "\" Does not exist"<<std::endl;
            return;
        }

        readimagefile(path.c_str(), 0, 0, width * m_scale.getX(), height * m_scale.getY());
        unsigned size = imagesize(0, 0, width * m_scale.getX(), height * m_scale.getY());
        std::cout<<"Image size: "<<size<<std::endl;

        img = (BITMAP*)malloc(size);

        std::cout<<"Image read"<<std::endl;

        getimage(0, 0, width * m_scale.getX(), height * m_scale.getY(), img);     
        
        std::cout<<"Image loaded"<<std::endl;
        setactivepage(currentActivePage);
    }

    void image::updateImage()
    {
        load(path, width, height);
    }

    void image::setScale(vector2 scale)
    {
        if (m_scale == scale) return;

        m_scale = scale; 
        updateImage();
    }
}