#include "Item.h"


Item::Item(Julkinen::Koordinaatti coord, char sign, std::string player):
mLocation(coord), mSign(sign), mPlayer(player)
{
}


Item::~Item()
{
}

Julkinen::Koordinaatti Item::getLocation() const{
	return mLocation;
}
char Item::getSign() const{
	return mSign;
}

std::string Item::getPlayer() const{
	return mPlayer;
}

void Item::setLocation(Julkinen::Koordinaatti coord){
	mLocation = coord;
}