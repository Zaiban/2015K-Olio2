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

void Player::setLocation(Julkinen::Koordinaatti coord){
	mLocation = coord;
}