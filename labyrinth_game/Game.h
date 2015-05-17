#pragma once
#include <memory>
#include <map>
#include <algorithm>
#include "pelirajapinta.hh"
#include "koordinaatti.hh"
#include "toimintovirhe.hh"
#include "valmiiden_toteutus\include\naytto.hh"

struct Player{
	Julkinen::PelaajaTyyppi type;
	std::string name;
	char abbr;
	Julkinen::Koordinaatti location;
	// Constructor
	Player(Julkinen::PelaajaTyyppi type, std::string name, char abbr, Julkinen::Koordinaatti location) :
		type(type), name(name), abbr(abbr), location(location){};
};

// pieceTypeRotation is a pair that contains the type of the piece and its rotation
typedef std::pair<Julkinen::PalaTyyppi, unsigned int> pieceTypeRotation;


class Game :
	public Julkinen::Pelirajapinta
{
public:
	Game();
	~Game();

	// Inherited methods

	bool onkoAlustustilassa() const;
	void lisaaNaytto(Julkinen::Nayttorajapinta* naytto);
	void maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko);
	void lisaaPelaaja(Julkinen::PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti);
	void lisaaPala(Julkinen::PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti);
	void lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja);
	void asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde = Julkinen::Koordinaatti());
	void alustusLopeta();
	bool onkoPelitilassa() const;
	void komentoTyonna(Julkinen::Reuna reuna, unsigned int paikka, unsigned int rotaatio);
	void komentoLiiku(Julkinen::Suunta suunta, unsigned int maara = 0);
	bool vaihdaVuoro();
	Julkinen::PelaajaTyyppi haeVuorossa();

	// New methods

	void updateScreen();
	bool isWallCollision(Julkinen::Suunta direction, unsigned int amount);
	void handleCPU();

private:
	bool mInitialization;
	Naytto* mScreen;
	unsigned mAreaSize;
	std::vector<Player> mPlayers;
	std::map < Julkinen::Koordinaatti,  pieceTypeRotation> mPieces;
	int mActivePlayer;
};

