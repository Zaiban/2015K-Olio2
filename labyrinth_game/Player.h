#pragma once
#include "pelirajapinta.hh"
class Player
{
public:
	Player(Julkinen::PelaajaTyyppi type, std::string name, char abbr, Julkinen::Koordinaatti location);
	~Player();

	Julkinen::PelaajaTyyppi getType() const;
	std::string getName() const;
	char getAbbr() const;
	Julkinen::Koordinaatti getLocation() const;
	std::string getLastCommand() const;

	void setLocation(Julkinen::Koordinaatti coord);
	void setLastCommand(std::string command);

private:
	Julkinen::PelaajaTyyppi mType;
	std::string mName;
	char mAbbr;
	Julkinen::Koordinaatti mLocation;
	std::string mLastCommand;
};
