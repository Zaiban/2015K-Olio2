#include "Player.h"


Player::Player(Julkinen::PelaajaTyyppi type, std::string name, char abbr, Julkinen::Koordinaatti location) :
mType(type), mName(name), mAbbr(abbr), mLocation(location){};


Player::~Player()
{
}

Julkinen::PelaajaTyyppi Player::getType() const{
	return mType;
}
std::string Player::getName() const{
	return mName;
}
char Player::getAbbr() const{
	return mAbbr;
}
Julkinen::Koordinaatti Player::getLocation() const{
	return mLocation;
}
std::string Player::getLastCommand() const{
	return mLastCommand;
}

void Player::setLocation(Julkinen::Koordinaatti coord){
	mLocation = coord;
}
void Player::setLastCommand(std::string command){
	mLastCommand = command;
}