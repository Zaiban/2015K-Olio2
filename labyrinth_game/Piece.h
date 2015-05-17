#pragma once
#include "pelirajapinta.hh"
class Piece
{
public:
	Piece(Julkinen::PalaTyyppi type, unsigned int rotation);
	~Piece();

	Julkinen::PalaTyyppi getType() const;
	unsigned int getRotation() const;

	void setType(Julkinen::PalaTyyppi type);
	void setRotation(unsigned int rotation);

private:
	Julkinen::PalaTyyppi mType;
	unsigned int mRotation;
};

