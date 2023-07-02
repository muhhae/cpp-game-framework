namespace gp {
    class vector2{
        private :
            struct coor
            {
                double x ,y;
            };
            
            coor m_coor;
            
        public:
            //constructor
            vector2() : m_coor({0, 0}) { };
            vector2(double x, double y) : m_coor({x, y}) { };
            
            //getter and setter
            double getX() { return m_coor.x; }
            double getY() { return m_coor.y; }
            void setX(double x) { m_coor.x = x; };
            void setY(double y) { m_coor.y = y; }; 

            //operator overloading
            vector2 operator+(vector2 vec) { return vector2(m_coor.x + vec.m_coor.x, m_coor.y + vec.m_coor.y); };
            vector2 operator-(vector2 vec) { return vector2(m_coor.x - vec.m_coor.x, m_coor.y - vec.m_coor.y); };
            vector2 operator*(vector2 vec) { return vector2(m_coor.x * vec.m_coor.x, m_coor.y * vec.m_coor.y); }; 
            vector2 operator/(vector2 vec) { return vector2(m_coor.x / vec.m_coor.x, m_coor.y / vec.m_coor.y); }; 
            vector2 operator*(double num) { return vector2(m_coor.x * num, m_coor.y * num); } 
            vector2 operator/(double num) { return vector2(m_coor.x / num, m_coor.y / num); }

            vector2 operator+=(vector2 vec) { return *this = *this + vec; }
            vector2 operator-=(vector2 vec) { return *this = *this - vec; }
            vector2 operator*=(vector2 vec) { return *this = *this * vec; }
            vector2 operator/=(vector2 vec) { return *this = *this / vec; }
            vector2 operator*=(double num) { return *this = *this * num; }
            vector2 operator/=(double num) { return *this = *this / num; }

            bool operator==(vector2 vec) { return m_coor.x == vec.m_coor.x && m_coor.y == vec.m_coor.y; }
            bool operator!=(vector2 vec) { return m_coor.x != vec.m_coor.x || m_coor.y != vec.m_coor.y; }

    };
}