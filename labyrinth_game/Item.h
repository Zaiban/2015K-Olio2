#pragma once
#include <string>
class Item
{
public:
	Item(char sign, std::string player);
	~Item();

	char getSign() const;
	std::string getPlayer() const;

private:
	char mSign;
	const std::string mPlayer;
};

