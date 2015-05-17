#pragma once
#include "pelirajapinta.hh"
class Item
{
public:
	Item(Julkinen::Koordinaatti coord, char sign, std::string player);
	~Item();

	Julkinen::Koordinaatti getLocation() const;
	char getSign() const;
	std::string getPlayer() const;

	void setLocation(Julkinen::Koordinaatti coord);

private:
	Julkinen::Koordinaatti mLocation;
	char mSign;
	const std::string mPlayer;
};

