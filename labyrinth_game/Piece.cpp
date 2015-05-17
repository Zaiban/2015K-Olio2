#include "Piece.h"


Piece::Piece(Julkinen::PalaTyyppi type, unsigned int rotation) :
mType(type), mRotation(rotation)
{
}


Piece::~Piece()
{
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