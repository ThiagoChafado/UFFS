#ifndef CIRCLE_H

#define CIRCLE_H

class Circle {
public:
    Circle(double radius_);
    
    double calcula_area();
    void imprime_area();
private:
    double radius_;
};

#endif /* CIRCLE_H */
