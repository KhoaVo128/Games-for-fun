#include <math.h>
#include "Vec2.h"

Vec2::Vec2(){

}

Vec2::Vec2(float xin, float yin) : x(xin), y(yin){

}

bool Vec2::operator ==(const Vec2 & rhs) const{
    return (x==rhs.x) && (y==rhs.x);
}

bool Vec2::operator !=(const Vec2 & rhs) const{
    return (x!=rhs.x) || (y!=rhs.x);
}


Vec2 Vec2::operator + (const Vec2 & rhs) const{
    return Vec2(x+rhs.x, y+rhs.y);
}

Vec2 Vec2::operator - (const Vec2 & rhs) const{
    return Vec2(x-rhs.x, y-rhs.y);
}

Vec2 Vec2::operator * (const float val) const{
    return Vec2(x*val, y*val);
}

Vec2 Vec2::operator / (const float val) const{
    return Vec2(0,0);
}

void Vec2::operator += (const Vec2 & rhs){
    x+=rhs.x;
    y+=rhs.y;
}

void Vec2::operator -= (const Vec2 & rhs){
    x-=rhs.x;
    y-=rhs.y;
}

void Vec2::operator *=(const float val){
    x*=val;
    y*=val;
}

void Vec2::operator/=(const float val){
    x/=val;
    y/=val;
}

float Vec2:: dist(const Vec2 & rhs) const{
    return sqrt((x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y));
}

float Vec2:: length() const{
    return sqrt(x*x + y*y);
}



