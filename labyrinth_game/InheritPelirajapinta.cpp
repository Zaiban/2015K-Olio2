#include "InheritPelirajapinta.h"

namespace Julkinen{
	InheritPelirajapinta::InheritPelirajapinta()
	{
		// TODO
	}


	InheritPelirajapinta::~InheritPelirajapinta()
	{
	}
	bool InheritPelirajapinta::onkoAlustustilassa(){
		// TO-DO
		return false;
	}
	void InheritPelirajapinta::lisaaNaytto(Nayttorajapinta* naytto){
		// TO-DO
	}
	void InheritPelirajapinta::maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko){
		// TO-DO
	}
	void InheritPelirajapinta::lisaaPelaaja(PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti){
		// TO-DO
	}
	void InheritPelirajapinta::lisaaPala(PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti){
		// TO-DO
	}
	void InheritPelirajapinta::lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja){
		// TO-DO
	}
	void InheritPelirajapinta::asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde){
		// TO-DO
	}
	void InheritPelirajapinta::alustusLopeta(){
		// TO-DO
	}
	bool InheritPelirajapinta::onkoPelitilassa(){
		// TO-DO
		return false;
	}
	void InheritPelirajapinta::komentoTyonna(Reuna reuna, unsigned int paikka, unsigned int rotaatio){
		// TO-DO
	}
	void InheritPelirajapinta::komentoLiiku(Suunta suunta, unsigned int maara){
		// TO-DO
	}
	bool InheritPelirajapinta::vaihdaVuoro(){
		// TO-DO
		return false;
	}
	PelaajaTyyppi InheritPelirajapinta::haeVuorossa(){
		// TO-DO
		return PelaajaTyyppi();
	}
}


