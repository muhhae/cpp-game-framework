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
    };
}