#include "Game.h"
#include "debug.hh"
#include "vaittama.hh"

Game::Game() :
mInitialization(true), mScreen(nullptr), mAreaSize(0), mActivePlayer(0)
{}


Game::~Game()
{
	DEBUG_OUTPUT("Game destructor" << std::endl);
	if (debug_output)
		system("PAUSE");
}
bool Game::onkoAlustustilassa() const{
	return mInitialization;
}
void Game::lisaaNaytto(Julkinen::Nayttorajapinta* naytto){
	DEBUG_OUTPUT("lisaaNaytto()" << std::endl);
	mScreen = dynamic_cast<Naytto*>(naytto);
	mScreen->komentoAloitaRakennus();
}
void Game::maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko){
	mAreaSize = koko.haeXkoordinaatti();
}
void Game::lisaaPelaaja(Julkinen::PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti){
	DEBUG_OUTPUT("lisaaPelaaja()" << std::endl);

	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, sijainti.haeXkoordinaatti() <= mAreaSize, std::string(std::to_string(sijainti.haeXkoordinaatti()) + "<" + std::to_string(mAreaSize)).c_str(), "Game.cpp", 29, "lisaaPelaaja");
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, sijainti.haeXkoordinaatti() <= mAreaSize, std::string(std::to_string(sijainti.haeYkoordinaatti()) + "<" + std::to_string(mAreaSize)).c_str(), "Game.cpp", 29, "lisaaPelaaja");

	mPlayers.push_back(Player(tyyppi, nimi, lyhenne, sijainti));
}
void Game::lisaaPala(Julkinen::PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti){
	DEBUG_OUTPUT("lisaaPala()" << std::endl);
	// TO-DO: ehdot
	mPieces.insert(std::pair<Julkinen::Koordinaatti, pieceTypeRotation>(sijainti, pieceTypeRotation(pala, rotaatio)));
}
void Game::lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja){
	DEBUG_OUTPUT("lisaaEsine()" << std::endl);
	mScreen->esineLaudalle(merkki, sijainti);
}
void Game::asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde){
	DEBUG_OUTPUT("asetaPalanTyyppi()" << std::endl);

}
void Game::alustusLopeta(){
	DEBUG_OUTPUT("alustusLopeta()" << std::endl);

	updateScreen();
	mScreen->komentoLopetaRakennus();
	mInitialization = false;

}
bool Game::onkoPelitilassa() const{
	return !mInitialization;
}
void Game::komentoTyonna(Julkinen::Reuna reuna, unsigned int paikka, unsigned int rotaatio){
	DEBUG_OUTPUT("komentoTyonna()" << std::endl);
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, onkoPelitilassa(), "onkoPelitilassa", "Game.cpp", 59, "vaihdaVuoro");
	mScreen->komentoAloitaRakennus();
	mInitialization = true;

	updateScreen();

	mScreen->komentoLopetaRakennus();
	mInitialization = false;
}
void Game::komentoLiiku(Julkinen::Suunta suunta, unsigned int maara){
	DEBUG_OUTPUT("komentoLiiku()" << std::endl);
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, onkoPelitilassa(), "onkoPelitilassa", "Game.cpp", 67, "vaihdaVuoro");

	// Check in case of wall collision
	if (isWallCollision(suunta, maara)){
		Julkinen::Toimintovirhe(Julkinen::Toimintovirhe::VIRHE_EI_VOITU_LIIKKUA_ANNETTUA_MAARAA).tulosta(std::cout);
		return;
	}

	// Move the player
	int x = mPlayers.at(mActivePlayer).location.haeXkoordinaatti();
	int y = mPlayers.at(mActivePlayer).location.haeYkoordinaatti();
	switch (suunta){
	case Julkinen::ALAS:
		y += maara;
		break;
	case Julkinen::YLOS:
		y -= maara;
		break;
	case Julkinen::OIKEALLE:
		x += maara;
		break;
	case Julkinen::VASEMMALLE:
		x -= maara;
		break;
	case Julkinen::AUTOMAATTI:
		handleCPU();
		break;
	}
	mPlayers.at(mActivePlayer).location = Julkinen::Koordinaatti(x, y);
}
bool Game::vaihdaVuoro(){
	DEBUG_OUTPUT("vaihdaVuoro()" << std::endl);
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, onkoPelitilassa(), "onkoPelitilassa", "Game.cpp", 70, "vaihdaVuoro");
	mScreen->komentoAloitaRakennus();
	mInitialization = true;

	updateScreen();

	mScreen->komentoLopetaRakennus();
	mInitialization = false;

	if (mActivePlayer == mPlayers.size()-1 )
		mActivePlayer = 0;
	else
		mActivePlayer++;
	DEBUG_OUTPUT("Active Player:" << mActivePlayer << std::endl);

	return true;
}
Julkinen::PelaajaTyyppi Game::haeVuorossa(){
	DEBUG_OUTPUT("haeVuorossa()" << std::endl);
	return mPlayers.at(mActivePlayer).type;
}

void Game::updateScreen(){

	std::for_each(mPieces.begin(), mPieces.end(), [&](std::pair<Julkinen::Koordinaatti, pieceTypeRotation> mapItem){
		mScreen->palaLaudalle(mapItem.second.first, Julkinen::ErikoispalaTyyppi(), mapItem.second.second, mapItem.first, Julkinen::Koordinaatti());
	});
	std::for_each(mPlayers.begin(), mPlayers.end(), [&](Player player){
		mScreen->pelaajaLaudalle(player.abbr, player.location);
	});
	std::for_each(mPlayers.begin(), mPlayers.end(), [&](Player player){
		mScreen->tulostaPelaajantiedot(player.name, "keratytesineet", "kerattavatesineet", "edellinentoiminto");
	});
}
bool Game::isWallCollision(Julkinen::Suunta direction, unsigned int amount){
	 int x = mPlayers.at(mActivePlayer).location.haeXkoordinaatti();
	 int y = mPlayers.at(mActivePlayer).location.haeYkoordinaatti();

	

	switch (direction){
	case Julkinen::ALAS:
		// check if out of game area
		if ((y + amount) > mAreaSize) return true;
		// check for collision
		for (int i = 0; i < amount; i++){
			Julkinen::PalaTyyppi startType = mPieces.at(Julkinen::Koordinaatti(x, y)).first;
			unsigned int startRotation = mPieces.at(Julkinen::Koordinaatti(x, y)).second;
			if ((startType == Julkinen::IPALA && startRotation == 2)
				|| (startType == Julkinen::IPALA && startRotation == 4)
				|| (startType == Julkinen::LPALA && startRotation == 1)
				|| (startType == Julkinen::LPALA && startRotation == 4)
				|| (startType == Julkinen::TPALA && startRotation == 3)
				) return true;

			Julkinen::PalaTyyppi destType = mPieces.at(Julkinen::Koordinaatti(x, y + 1)).first;
			unsigned int destRotation = mPieces.at(Julkinen::Koordinaatti(x, y + 1)).second;
			if ((destType == Julkinen::IPALA && destRotation == 2)
				|| (destType == Julkinen::IPALA && destRotation == 4)
				|| (destType == Julkinen::LPALA && destRotation == 2)
				|| (destType == Julkinen::LPALA && destRotation == 3)
				|| (destType == Julkinen::TPALA && destRotation == 1)
				) return true;
			y++;
		}
		break;
	case Julkinen::YLOS:
		// check if out of game area
		if ((y - amount) < 1) return true;
		// check for collision
		for (int i = 0; i < amount; i++){
			Julkinen::PalaTyyppi startType = mPieces.at(Julkinen::Koordinaatti(x, y)).first;
			unsigned int startRotation = mPieces.at(Julkinen::Koordinaatti(x, y)).second;
			if ((startType == Julkinen::IPALA && startRotation == 2)
				|| (startType == Julkinen::IPALA && startRotation == 4)
				|| (startType == Julkinen::LPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 3)
				|| (startType == Julkinen::TPALA && startRotation == 1)
				) return true;

			Julkinen::PalaTyyppi destType = mPieces.at(Julkinen::Koordinaatti(x, y - 1)).first;
			unsigned int destRotation = mPieces.at(Julkinen::Koordinaatti(x, y - 1)).second;
			if ((destType == Julkinen::IPALA && destRotation == 2)
				|| (destType == Julkinen::IPALA && destRotation == 4)
				|| (destType == Julkinen::LPALA && destRotation == 1)
				|| (destType == Julkinen::LPALA && destRotation == 4)
				|| (destType == Julkinen::TPALA && destRotation == 3)
				) return true;
			y--;
		}
		break;
	case Julkinen::OIKEALLE:
		// check if out of game area
		if ((x + amount) > mAreaSize) return true;
		// check for collision
		for (int i = 0; i < amount; i++){
			Julkinen::PalaTyyppi startType = mPieces.at(Julkinen::Koordinaatti(x, y)).first;
			unsigned int startRotation = mPieces.at(Julkinen::Koordinaatti(x, y)).second;
			if ((startType == Julkinen::IPALA && startRotation == 1)
				|| (startType == Julkinen::IPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 4)
				|| (startType == Julkinen::TPALA && startRotation == 2)
				) return true;

			Julkinen::PalaTyyppi destType = mPieces.at(Julkinen::Koordinaatti(x + 1, y)).first;
			unsigned int destRotation = mPieces.at(Julkinen::Koordinaatti(x + 1, y)).second;
			if ((destType == Julkinen::IPALA && destRotation == 1)
				|| (destType == Julkinen::IPALA && destRotation == 3)
				|| (destType == Julkinen::LPALA && destRotation == 1)
				|| (destType == Julkinen::LPALA && destRotation == 2)
				|| (destType == Julkinen::TPALA && destRotation == 4)
				) return true;
			x++;
		}
		break;
	case Julkinen::VASEMMALLE:
		// check if out of game area
		if ((x - amount) < 1) return true;
		// check for collision
		for (int i = 0; i < amount; i++){
			Julkinen::PalaTyyppi startType = mPieces.at(Julkinen::Koordinaatti(x, y)).first;
			unsigned int startRotation = mPieces.at(Julkinen::Koordinaatti(x, y)).second;
			if ((startType == Julkinen::IPALA && startRotation == 1)
				|| (startType == Julkinen::IPALA && startRotation == 3)
				|| (startType == Julkinen::LPALA && startRotation == 1)
				|| (startType == Julkinen::LPALA && startRotation == 2)
				|| (startType == Julkinen::TPALA && startRotation == 4)
				) return true;

			Julkinen::PalaTyyppi destType = mPieces.at(Julkinen::Koordinaatti(x - 1, y)).first;
			unsigned int destRotation = mPieces.at(Julkinen::Koordinaatti(x - 1, y)).second;
			if ((destType == Julkinen::IPALA && destRotation == 1)
				|| (destType == Julkinen::IPALA && destRotation == 3)
				|| (destType == Julkinen::LPALA && destRotation == 3)
				|| (destType == Julkinen::LPALA && destRotation == 4)
				|| (destType == Julkinen::TPALA && destRotation == 2)
				) return true;
			x--;
		}
		break;
	}
	// If got to this point, no collisions detected
	return false;
}
void Game::handleCPU(){
	if (mActivePlayer == mPlayers.size() - 1)
		mActivePlayer = 0;
	else
		mActivePlayer++;
	DEBUG_OUTPUT("Active Player:" << mActivePlayer << std::endl);
}