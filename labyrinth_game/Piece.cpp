#include "Piece.h"


Piece::Piece(Julkinen::Koordinaatti coord, Julkinen::PalaTyyppi type, unsigned int rotation) :
mLocation(coord), mType(type), mRotation(rotation)
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

void Piece::setType(Julkinen::PalaTyyppi type){
	mType = type;
}
void Piece::setRotation(unsigned int rotation){
	mRotation = rotation;
}
void Piece::setLocation(Julkinen::Koordinaatti coord){
	mLocation = coord;
}