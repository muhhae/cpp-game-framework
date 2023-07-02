#include <chrono>

namespace gp {
    class Timer {
        private :
            std::chrono::_V2::system_clock::time_point timeStart = std::chrono::system_clock::now();
            std::chrono::_V2::system_clock::time_point timeEnd = std::chrono::system_clock::now();
            double m_deltaTime = 0;
        public :
            void start() { timeStart = std::chrono::system_clock::now(); }
            void end() { timeEnd = std::chrono::system_clock::now(); m_deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(timeEnd - timeStart).count(); }
            double deltaTime() { return m_deltaTime; }
    };
}