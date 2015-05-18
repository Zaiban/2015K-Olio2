#include "Piece.h"


Piece::Piece(Julkinen::Koordinaatti coord, Julkinen::PalaTyyppi type, unsigned int rotation) :
mLocation(coord), mType(type), mRotation(rotation), mSpecialType(Julkinen::ErikoispalaTyyppi()), mTarget(Julkinen::Koordinaatti())
{
}


Piece::~Piece()
{
}

Julkinen::Koordinaatti Piece::getLocation() const{
	return mLocation;
}
Julkinen::PalaTyyppi Piece::getType() const{
	return mType;
}
unsigned int Piece::getRotation() const{
	return mRotation;
}
Julkinen::ErikoispalaTyyppi Piece::getSpecialType() const{
	return mSpecialType;
}
Julkinen::Koordinaatti Piece::getTarget() const{
	return mTarget;
}

void Piece::setType(Julkinen::PalaTyyppi type){
	mType = type;
}
void Piece::setRotation(unsigned int rotation){
	mRotation = rotation;
}
void Piece::setLocation(Julkinen::Koordinaatti coord){
	mLocation = coord;
}
void Piece::setSpecialType(Julkinen::ErikoispalaTyyppi specialType){
	mSpecialType = specialType;
}
void Piece::setTarget(Julkinen::Koordinaatti coord){
	mTarget = coord;
}