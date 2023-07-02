#include "lib/animation.hpp"
#include <iostream>
#include <filesystem>

namespace gp {
    void animation::load(std::string path, int width, int height)
    {
        frames.clear();

        int i = 0;

        while(1)
        {
            if (!std::filesystem::exists(path + "/" +  std::to_string(i) + ".gif")) break;

            m_frameCount++;

            std::unique_ptr<image> fr = std::make_unique<image>(image());
            fr->setScale(m_scale);
            fr->load(path + "/" +  std::to_string(i) + ".gif", width, height);
            frames.push_back(std::move(fr));

            i++;
        }   
    }

    void animation::draw(double deltaTime)
    {
        if (frames.empty()) return;
        
        frames[m_currentFrame]->setOrigin(m_origin);
        frames[m_currentFrame]->setPosition(m_position);
        frames[m_currentFrame]->draw();
        
        m_time += deltaTime;

        if (m_time >= 1.0 / m_frameRate)
        {
            m_currentFrame ++;
            m_time = 0;
        }
        
        if (m_currentFrame >= m_frameCount) m_currentFrame = 0;
    }

    void animation::setScale(vector2 scale)
    {
        if (frames.empty()) 
        {
            m_scale = scale;
            return;
        }
        if (scale == m_scale) return;

        m_scale = scale;
        for (auto& frame : frames) frame->setScale(scale);
    }
}