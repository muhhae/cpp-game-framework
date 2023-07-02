#pragma once

#include <chrono>

namespace gp {
    class Timer {
        private :
            std::chrono::_V2::high_resolution_clock::time_point timeStart = std::chrono::high_resolution_clock::now();
            std::chrono::_V2::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
            double m_deltaTime = 0;
        public :
            void start() { timeStart = std::chrono::high_resolution_clock::now(); }
            void end() { timeEnd = std::chrono::high_resolution_clock::now(); m_deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(timeEnd - timeStart).count(); }
            double deltaTime() { return m_deltaTime; }
    };
}