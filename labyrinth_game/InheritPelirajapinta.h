#pragma once
#include "pelirajapinta.hh"

namespace Julkinen{
	class InheritPelirajapinta :
		public Pelirajapinta
	{
	public:
		InheritPelirajapinta();
		~InheritPelirajapinta();

		bool onkoAlustustilassa();
		void lisaaNaytto(Nayttorajapinta* naytto);
		void maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko);
		void lisaaPelaaja(PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti);
		void lisaaPala(PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti);
		void lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja);
		void asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde = Julkinen::Koordinaatti());
		void alustusLopeta();
		bool onkoPelitilassa();
		void komentoTyonna(Reuna reuna, unsigned int paikka, unsigned int rotaatio);
		void komentoLiiku(Suunta suunta, unsigned int maara = 0);
		bool vaihdaVuoro();
		PelaajaTyyppi haeVuorossa();

	};

}