#include "Item.h"


Item::Item(char sign, std::string player):
mSign(sign), mPlayer(player)
{
}


Item::~Item()
{
}

char Item::getSign() const{
	return mSign;
}

std::string Item::getPlayer() const{
	return mPlayer;
}