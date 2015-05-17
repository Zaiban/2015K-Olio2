#pragma once
#include "pelirajapinta.hh"
class Piece
{
public:
	Piece(Julkinen::Koordinaatti coord, Julkinen::PalaTyyppi type, unsigned int rotation);
	~Piece();

	Julkinen::Koordinaatti getLocation() const;
	Julkinen::PalaTyyppi getType() const;
	unsigned int getRotation() const;

	void setLocation(Julkinen::Koordinaatti coord);
	void setType(Julkinen::PalaTyyppi type);
	void setRotation(unsigned int rotation);

private:
	Julkinen::Koordinaatti mLocation;
	Julkinen::PalaTyyppi mType;
	unsigned int mRotation;
};

