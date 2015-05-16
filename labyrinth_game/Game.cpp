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
	mScreen = dynamic_cast<Naytto*>(naytto);
	mScreen->komentoAloitaRakennus();
}
void Game::maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko){
	mAreaSize = koko.haeXkoordinaatti();
}
void Game::lisaaPelaaja(Julkinen::PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti){

	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, sijainti.haeXkoordinaatti() <= mAreaSize, std::string(std::to_string(sijainti.haeXkoordinaatti()) + "<" + std::to_string(mAreaSize)).c_str(), "Game.cpp", 29, "lisaaPelaaja");
	Julkinen::vaittamaToteutus(Julkinen::ESIEHTOVAITTAMA, sijainti.haeXkoordinaatti() <= mAreaSize, std::string(std::to_string(sijainti.haeYkoordinaatti()) + "<" + std::to_string(mAreaSize)).c_str(), "Game.cpp", 29, "lisaaPelaaja");

	mScreen->pelaajaLaudalle(lyhenne, sijainti);
	mPlayers.push_back(player(tyyppi, nimi, lyhenne, sijainti));
}
void Game::lisaaPala(Julkinen::PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti){
	// TO-DO: ehdot
	mScreen->palaLaudalle(pala, Julkinen::ErikoispalaTyyppi(), rotaatio, sijainti, Julkinen::Koordinaatti());
}
void Game::lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja){
	mScreen->esineLaudalle(merkki, sijainti);
}
void Game::asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde){
	
}
void Game::alustusLopeta(){
	mInitialization = false;
	mScreen->komentoLopetaRakennus();
}
bool Game::onkoPelitilassa() const{
	return !mInitialization;
}
void Game::komentoTyonna(Julkinen::Reuna reuna, unsigned int paikka, unsigned int rotaatio){
	// TO-DO
}
void Game::komentoLiiku(Julkinen::Suunta suunta, unsigned int maara){
	// TO-DO
}
bool Game::vaihdaVuoro(){
	if (mActivePlayer == mPlayers.size())
		mActivePlayer = 0;
	else
		mActivePlayer++;
	DEBUG_OUTPUT("Active Player:" << mActivePlayer << std::endl);
	return true;
}
Julkinen::PelaajaTyyppi Game::haeVuorossa(){
	return mPlayers.at(mActivePlayer).type;
}



