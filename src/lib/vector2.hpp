namespace gp {
    class vector2{
        private :
            struct coor
            {
                float x ,y;
            };
            
            coor m_coor;
            
        public:
            vector2() : m_coor({0, 0}) { };
            vector2(float x, float y) : m_coor({x, y}) { };
            
            float getX() { return m_coor.x; }
            float getY() { return m_coor.y; }
            void setX(float x) { m_coor.x = x; };
            void setY(float y) { m_coor.y = y; }; 

            vector2 operator+(vector2 vec) { return vector2(m_coor.x + vec.m_coor.x, m_coor.y + vec.m_coor.y); };
            vector2 operator-(vector2 vec) { return vector2(m_coor.x - vec.m_coor.x, m_coor.y - vec.m_coor.y); };
            vector2 operator*(vector2 vec) { return vector2(m_coor.x * vec.m_coor.x, m_coor.y * vec.m_coor.y); }; 
            vector2 operator/(vector2 vec) { return vector2(m_coor.x / vec.m_coor.x, m_coor.y / vec.m_coor.y); }; 
            vector2 operator*(float num) { return vector2(m_coor.x * num, m_coor.y * num); } 
            vector2 operator/(float num) { return vector2(m_coor.x / num, m_coor.y / num); }

            vector2 operator+=(vector2 vec) { return *this = *this + vec; }
            vector2 operator-=(vector2 vec) { return *this = *this - vec; }
            vector2 operator*=(vector2 vec) { return *this = *this * vec; }
            vector2 operator/=(vector2 vec) { return *this = *this / vec; }
            vector2 operator*=(float num) { return *this = *this * num; }
            vector2 operator/=(float num) { return *this = *this / num; }
            
    };
}