#include <mbed.h>
#include "i2c-lib.h"
#include "si4735-lib.h"
#include <string>

// Direction of I2C communication
#define R	0b00000001
#define W	0b00000000

Serial pc( USBTX, USBRX );

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

void autoTuning(int direction, int repeatTuning);
void setFrequency(int frequency);
void changeVolume(int volume);
void leds(int ledky);
int selectLeds(int number);
void readBasicRDS();
void checkQualityOfSignal();
void readTunedFrequency();
string getStationName();
double getAlternativeFrequency();
string getNameTypeOfProgram(int number);
string getRadiotext();

class FMRadio {
	uint8_t fm_adr, pcf_adr;

	FMRadio(uint8_t fm_adr, uint8_t pcf_adr) {
		this->fm_adr = fm_adr;
		this->pcf_adr = pcf_adr;
	}

	uint8_t ACKCheck(uint8_t ACK){
		if (ACK != 0) {
			pc.printf("ERROR!\r\n");
		}
		else {
			pc.printf("OK\r\n");
		}

	}


	uint8_t set_volume(uint8_t vol) {
		uint8_t ack = 0;
		int status
		switch (vol) {
		case 0:
			status = 0b00000000;
			break;
		case 1:
			status = 0b00000001;
			break;
		case 2:
			status = 0b00000011;
			break;
		case 3:
			status = 0b00000111;
			break;
		case 4:
			status = 0b00001111;
			break;
		case 5:
			status = 0b00011111;
			break;
		case 6:
			status = 0b00111111;
			break;
		case 7:
			status = 0b01111111;
			break;
		case 8:
			status = 0b11111111;
			break;
		default
			status = 0;
			break;
		}
		

		pc.printf("\nVOLUME %d\r\n", vol);
		I2C_Start();		
		ack |= I2C_Output(SI4735_address | W);		
		ack |= I2C_Output(0x12);
		ack |= I2C_Output(0x00);
		ack |= I2C_Output(0x40);
		ack |= I2C_Output(0x00);
		ack |= I2C_Output(0x00);
		ack |= I2C_Output(vol);	
		I2C_Stop();	

		I2C_Start();		
		ack |= I2C_Output(0b0100 << 4 | 0b000 << 1 | W);
		ack |= I2C_Output(status);
		I2C_Stop();

		ACKCheck(ack);

	}

	uint8_t set_freq(uint32_t freq_hz) {
		pc.printf("\nTunig radio station...\r\n");
		uint8_t ack = 0;
		I2C_Start();
		ack |= I2C_Output(SI4735_address | W);
		ack |= I2C_Output(0x20);
		ack |= I2C_Output(0x00);
		ack |= I2C_Output(freq_hz >> 8);
		ack |= I2C_Output(freq_hz & 0xff);
		ack |= I2C_Output(0x00);
		I2C_Stop();
		ACKCheck(ack);
		wait_ms(100);
		pc.printf("Station tuned.\r\n\n");
	}

	uint8_t get_info(uint32_t &quality, uint32_t &strenght, uint32_t &stereo) {
		uint8_t S1, S2, isStation, STBL, MULT, FREQ;
		uint8_t ack = 0;
		I2C_Start();
		ack |= I2C_Output(SI4735_address | W);
		ack |= I2C_Output(0x23);			
		ack |= I2C_Output(0x00);			
											
		I2C_Start();
		ack |= I2C_Output(SI4735_address | R);
		S1 = I2C_Input();
		I2C_Ack();
		S2 = I2C_Input();
		I2C_Ack();
		isStation = I2C_Input() & 1;
		I2C_Ack();
		STBL = I2C_Input();
		I2C_Ack();
		strenght = I2C_Input();
		I2C_Ack();
		quality = I2C_Input();
		I2C_Ack();
		MULT = I2C_Input();
		I2C_Ack();
		FREQ = I2C_Input();
		I2C_NAck();
		I2C_Stop();

		ACKCheck(ack);
		if (isStation == 1) {
			pc.printf("Station tuned.");
		}
		pc.printf("Signal strenght: %d\r\n", strenght);
		pc.printf("Signal quality: %d\r\n", quality);
	}

	uint8_t tuning(uint8_t dire) {
		uint8_t ack = 0;
		I2C_Start();
		ack |= I2C_Output(SI4735_address | W);
		ack |= I2C_Output(0x21);
		ack |= I2C_Output(0 | dire << 3 | 1 << 2);
		I2C_Stop();
	}
};



int main(void){
	uint8_t S1, S2, RSSI, SNR, MULT, CAP;
	uint8_t ack = 0;
	DigitalIn volDown(PTC9);
	DigitalIn volUp(PTC10);
	DigitalIn freqDown(PTC11);
	DigitalIn freqUp(PTC12);
	I2C_Init();
	pc.baud( 115200 );
	pc.printf( "K64F-KIT is ready...\r\n" );
    /*if ( ( ack = SI4735_Init() ) != 0 )
    {
        pc.printf( "ERROR (%d)\r\n", ack );
    }
    else
        pc.printf( "OK\r\n" );*/
	ACKCheck(SI4735_Init());
    pc.printf( "\nTunig radio station...\r\n" );
    // Required frequency in MHz * 100
    //int freq = 10140; // Radiozurnal
	FMRadio.set_freq(10140);
    /*I2C_Start();
    ack |= I2C_Output( SI4735_address | W );
    ack |= I2C_Output( 0x20 );            // FM_TUNE_FREQ
    ack |= I2C_Output( 0x00 );            // ARG1
    ack |= I2C_Output( freq >> 8 );        // ARG2 - FreqHi
    ack |= I2C_Output( freq & 0xff );    // ARG3 - FreqLo
    ack |= I2C_Output( 0x00 );            // ARG4
    I2C_Stop();*/
	// Check ack!
	// if...

    // Tuning process inside SI4735
    wait_ms( 100 );
    pc.printf( "Station tuned.\r\n\n" );
   /*stlacanim tlacitka PTC11 si vyziadame nacitanie RDS dat, ktore sa nam nasledne vypisu do linux konzoly (treba spustit v konzole prikaz "minicom -D/dev/ttyACM0" bez uvodzoviek)*/

    uint8_t volume = 5;
	uint8_t direction;
	while(true){
		if(!volUp){
			while(!volUp){
			}
			if(volume < 8) {
				volume++;
			}

		}
		if(!volDown){
			while(!volDown){
			}
			if(volume > 0) {
				volume--;
			}
		}

		if (!freqUp) {
			direction = 1;
			FMRadio.tuning(direction);
		}
		if (!freqDown) {
			direction = 0;
			FMRadio.tuning(direction);
		}
    	/*if(!RDSinfo){
    		while(RDSinfo == false){
    		}
    		readBasicRDS();		//zavolani funkce na cteni RDS
    	}*/
		FMRadio.set_volume(volume*7);
		leds(FMRadio.LEDS(volume));
	}
	return 0;
}

string getStationName(){
	char nazovStanice [8];
	for(int i = 0; i < 8; i++){
		nazovStanice[i] = (char)0;
	}
	bool isComplete;
	while(true){
		uint8_t RDS0, RDS1, Sync, RDS3, B1HI, B1LO, B2HI, B2LO, B3HI, B3LO, B4HI, B4LO, status;		//nadefinujeme si premenne, ktore budeme nacitavat
		uint8_t ack = 0;
		isComplete = true;
		while(true){
			I2C_Start();								//zaciatok komunikacie
			ack |= I2C_Output( SI4735_address | W );	//zaadresovanie radioveho modulu (W - zapis, zapiseme dotaz na vydanie RDS sprav)
			ack |= I2C_Output( 0x24 );					// FM_RDS_STATUS
			ack |= I2C_Output( 1 );						// argument, ktory vyziada vnutorne prerusenie pre prijem RDS dat
			// repeated start
			I2C_Start();								//znovu zopakujeme zaciatok komunikacie
			ack |= I2C_Output( SI4735_address | R );	//vysleme na vystup adresu radia a ziadost o citanie
			RDS0 = I2C_Input();			//nacitame 1 bajt (8 bitov) do premennej RDS0
			I2C_Ack();					//vysleme potvrdzovaci bit, aby system vedel, ze bajt sme uspesne precitali (vid strana 29 - address verification)
			RDS1 = I2C_Input();			//nacitame dalsi bajt do premennej RDS1
			I2C_Ack();					//znova vysleme potvrdzovaci bit
			Sync = I2C_Input() & 1;
			I2C_Ack();
			RDS3 = I2C_Input();
			I2C_Ack();
			B1HI = I2C_Input();
			I2C_Ack();
			B1LO = I2C_Input();
			I2C_Ack();
			B2HI = I2C_Input();
			I2C_Ack();
			if((B2HI & 0xF800)>>11 == 1 || (B2HI & 0xF800)>>11 == 0){
				break;
			}
			int buffer = I2C_Input();
			I2C_NAck();
			I2C_Stop();
		}
		B2LO = I2C_Input();
		I2C_Ack();
		B3HI = I2C_Input();
		I2C_Ack();
		B3LO = I2C_Input();
		I2C_Ack();
		B4HI = I2C_Input();
		I2C_Ack();
		B4LO = I2C_Input();
		I2C_Ack();
		status = I2C_Input();
		I2C_NAck();			//ako potvrdzovaci bit posleme negovany ACK, teda sme ukoncili citanie
		I2C_Stop();			//ukoncenie komunikacie
		int blok2 = B2HI<<8 | B2LO;
		/*
		int blok3 = B3HI<<8 | B3LO;
		int blok4 = B4HI<<8 | B4LO;
		*/
		int poziciaZnakov = blok2 &3;
		nazovStanice[(poziciaZnakov*2)] = (char)B4HI;
		nazovStanice[(poziciaZnakov*2)+1] = (char)B4LO;
		for(int i = 0; i < 8; i++){
			if((int) nazovStanice[i] == 0){
				isComplete = false;
				break;
			}
		}
		if (isComplete){
			break;
		}
	}
	string stationName;
	for(int i = 0; i < 8; i++){
		stationName += (char)nazovStanice[i];
	}
	return stationName;
}


double getAlternativeFrequency(){
	uint8_t RDS0, RDS1, Sync, RDS3, B1HI, B1LO, B2HI, B2LO, B3HI, B3LO, B4HI, B4LO, status;		//nadefinujeme si premenne, ktore budeme nacitavat
	uint8_t ack = 0;
	while(true){
		I2C_Start();								//zaciatok komunikacie
		ack |= I2C_Output( SI4735_address | W );	//zaadresovanie radioveho modulu (W - zapis, zapiseme dotaz na vydanie RDS sprav)
		ack |= I2C_Output( 0x24 );					// FM_RDS_STATUS
		ack |= I2C_Output( 1 );						// argument, ktory vyziada vnutorne prerusenie pre prijem RDS dat
		// repeated start
		I2C_Start();								//znovu zopakujeme zaciatok komunikacie
		ack |= I2C_Output( SI4735_address | R );	//vysleme na vystup adresu radia a ziadost o citanie
		RDS0 = I2C_Input();			//nacitame 1 bajt (8 bitov) do premennej RDS0
		I2C_Ack();					//vysleme potvrdzovaci bit, aby system vedel, ze bajt sme uspesne precitali (vid strana 29 - address verification)
		RDS1 = I2C_Input();			//nacitame dalsi bajt do premennej RDS1
		I2C_Ack();					//znova vysleme potvrdzovaci bit
		Sync = I2C_Input() & 1;
		I2C_Ack();
		RDS3 = I2C_Input();
		I2C_Ack();
		B1HI = I2C_Input();
		I2C_Ack();
		B1LO = I2C_Input();
		I2C_Ack();
		B2HI = I2C_Input();
		I2C_Ack();
		if((B2HI & 0xF800)>>11 == 0){
			break;
		}
		int buffer = I2C_Input();
		I2C_NAck();
		I2C_Stop();
	}
	B2LO = I2C_Input();
	I2C_Ack();
	B3HI = I2C_Input();
	I2C_Ack();
	B3LO = I2C_Input();
	I2C_Ack();
	B4HI = I2C_Input();
	I2C_Ack();
	B4LO = I2C_Input();
	I2C_Ack();
	status = I2C_Input();
	I2C_NAck();			//ako potvrdzovaci bit posleme negovany ACK, teda sme ukoncili citanie
	I2C_Stop();			//ukoncenie komunikacie
	double frekvencia = 87.5;
	frekvencia += B3LO*0.1;
	return frekvencia;
}

string getRadiotext(){
	char radiotext[64];
	for(int i = 0; i < 64; i++){
		radiotext[i] = char(0);
	}
	bool isComplete;
	while(true){
		uint8_t RDS0, RDS1, Sync, RDS3, B1HI, B1LO, B2HI, B2LO, B3HI, B3LO, B4HI, B4LO, status;		//nadefinujeme si premenne, ktore budeme nacitavat
		uint8_t ack = 0;
		isComplete = true;
		while(true){
			I2C_Start();								//zaciatok komunikacie
			ack |= I2C_Output( SI4735_address | W );	//zaadresovanie radioveho modulu (W - zapis, zapiseme dotaz na vydanie RDS sprav)
			ack |= I2C_Output( 0x24 );					// FM_RDS_STATUS
			ack |= I2C_Output( 1 );						// argument, ktory vyziada vnutorne prerusenie pre prijem RDS dat
			// repeated start
			I2C_Start();								//znovu zopakujeme zaciatok komunikacie
			ack |= I2C_Output( SI4735_address | R );	//vysleme na vystup adresu radia a ziadost o citanie
			RDS0 = I2C_Input();			//nacitame 1 bajt (8 bitov) do premennej RDS0
			I2C_Ack();					//vysleme potvrdzovaci bit, aby system vedel, ze bajt sme uspesne precitali (vid strana 29 - address verification)
			RDS1 = I2C_Input();			//nacitame dalsi bajt do premennej RDS1
			I2C_Ack();					//znova vysleme potvrdzovaci bit
			Sync = I2C_Input() & 1;
			I2C_Ack();
			RDS3 = I2C_Input();
			I2C_Ack();
			B1HI = I2C_Input();
			I2C_Ack();
			B1LO = I2C_Input();
			I2C_Ack();
			B2HI = I2C_Input();
			I2C_Ack();
			if((B2HI & 0xF800)>>11 == 0b00100){
				break;
			}
			int buffer = I2C_Input();
			I2C_NAck();
			I2C_Stop();
		}
		B2LO = I2C_Input();
		I2C_Ack();
		B3HI = I2C_Input();
		I2C_Ack();
		B3LO = I2C_Input();
		I2C_Ack();
		B4HI = I2C_Input();
		I2C_Ack();
		B4LO = I2C_Input();
		I2C_Ack();
		status = I2C_Input();
		I2C_NAck();			//ako potvrdzovaci bit posleme negovany ACK, teda sme ukoncili citanie
		I2C_Stop();			//ukoncenie komunikacie
		int blok2 = B2HI<<8 | B2LO;
		int blok3 = B3HI<<8 | B3LO;
		int blok4 = B4HI<<8 | B4LO;

		int poziciaZnakov = blok2 & 0xF;
		radiotext[(poziciaZnakov*4)] = (char)B3HI;
		radiotext[(poziciaZnakov*4)+1] = (char)B3LO;
		radiotext[(poziciaZnakov*4)+2] = (char)B4HI;
		radiotext[(poziciaZnakov*4)+3] = (char)B4LO;
		for(int i = 0; i < 8; i++){
			if((int) radiotext[i] == 0){
				isComplete = false;
				break;
			}
		}
		if (isComplete){
			break;
		}
	}
	string radioTextString;
	for(int i = 0; i < 8; i++){
		radioTextString += (char)radiotext[i];
	}
	return radioTextString;
}

string getNameTypeOfProgram(int number){
	switch(number){
	case 0:		return "No programme type or undefined";
	case 1:		return "News";
	case 2:		return "Current Affairs";
	case 3:		return "Information";
	case 4:		return "Sport";
	case 5:		return "Educate";
	case 6:		return "Drama";
	case 7:		return "Culture";
	case 8:		return "Science";
	case 9:		return "Varied";
	case 10:	return "Pop M";
	case 11:	return "Rock M";
	case 12:	return "Easy M";
	case 13:	return "Light M";
	case 14:	return "Classics";
	case 15:	return "Other M";
	case 16:	return "Weather";
	case 17:	return "Finance";
	case 18:	return "Children's programmes";
	case 19:	return "Social Affairs";
	case 20:	return "Religion";
	case 21:	return "Phone In";
	case 22:	return "Travel";
	case 23:	return "Leisure";
	case 24:	return "Jazz Music";
	case 25:	return "Country Music";
	case 26:	return "National Music";
	case 27:	return "Oldies Music";
	case 28:	return "Folk Music";
	case 29:	return "Documentary";
	case 30:	return "Alarm Test";
	case 31:	return "Alarm";
	default: 	return "Nezname";
	}
}

void readBasicRDS(){
	uint8_t RDS0, RDS1, Sync, RDS3, B1HI, B1LO, B2HI, B2LO, B3HI, B3LO, B4HI, B4LO, status;		//nadefinujeme si premenne, ktore budeme nacitavat
	uint8_t ack = 0;
	I2C_Start();								//zaciatok komunikacie
	ack |= I2C_Output( SI4735_address | W );	//zaadresovanie radioveho modulu (W - zapis, zapiseme dotaz na vydanie RDS sprav)
	ack |= I2C_Output( 0x24 );					// FM_RDS_STATUS
	ack |= I2C_Output( 1 );						// argument, ktory vyziada vnutorne prerusenie pre prijem RDS dat
	// repeated start
	I2C_Start();								//znovu zopakujeme zaciatok komunikacie
	/*Nasleduje zmena smeru komunikacie (R - citame odpoved na vyssie zadany dotaz 0x24, vid dokumentacia str 36 apps_labexc.pdf
	 * potom dostaneme odpoved vo forme 13 bajtov, ktore nasledne postupne nacitame do premennych deklarovanyych na zaciatku tejto funkcie
	 * zoznam premennych a poradie, v ktorom ich nacitame je na strane 36
	 */
	ack |= I2C_Output( SI4735_address | R );	//vysleme na vystup adresu radia a ziadost o citanie
	RDS0 = I2C_Input();			//nacitame 1 bajt (8 bitov) do premennej RDS0
	I2C_Ack();					//vysleme potvrdzovaci bit, aby system vedel, ze bajt sme uspesne precitali (vid strana 29 - address verification)
	RDS1 = I2C_Input();			//nacitame dalsi bajt do premennej RDS1
	I2C_Ack();					//znova vysleme potvrdzovaci bit
	/*teraz nacitame bajt v ktorom nas zaujima len bit s najnizsou vahou, ktory nam povie, ci su data synchronizovane, alebo nie (strana 36)
	 * nie som si isty, ci 1 znamena ano synchronizovane, alebo nie nesychnronizovane
	 * potom staci prerobit podmienku vid nizsie if(Sync == 0) na 1
	 * jeden bit nacitame tak, ze cely nacitany bajt vymaskujeme jednotkou (binarne 0b00000001) teda bitovy AND
	 * bit som si oznacil ako Sync
	 */
	Sync = I2C_Input() & 1;
	I2C_Ack();
	if(Sync == 0){			//ak data nie su synchronizovane, netreba data dalej citat, mozeme vypisat do konzoly infromaciu a ukoncit nacitavanie (zakomentovane return)
		printf("RDS informace nejsou synchronizovany");
		//return;
	}
	RDS3 = I2C_Input();
	I2C_Ack();
	/* Nasleduje nacitavanie 4x2 polovice blokov oznacenych ako B1HI (high) a B1LO (low), ktore nesu jednotlive RDS informacie
	 * strana 36 - response, bajty 4-11
	 */
	B1HI = I2C_Input();
	I2C_Ack();
	B1LO = I2C_Input();
	I2C_Ack();
	B2HI = I2C_Input();
	I2C_Ack();
	B2LO = I2C_Input();
	I2C_Ack();
	B3HI = I2C_Input();
	I2C_Ack();
	B3LO = I2C_Input();
	I2C_Ack();
	B4HI = I2C_Input();
	I2C_Ack();
	B4LO = I2C_Input();
	I2C_Ack();
	status = I2C_Input();
	I2C_NAck();			//ako potvrdzovaci bit posleme negovany ACK, teda sme ukoncili citanie
	I2C_Stop();			//ukoncenie komunikacie

/* teraz si jednotlive polovice blokov (2x8bitov) spojime do jedneho 16 bitoveho cisla
 * HI polovicu posunieme o 8 bitov dolava, tj nam vpravo od nich vznikne 8 "prazdnych" pozicii, kam bitovym ORom "pripojime" LO polovicu
 */
	int blok1 = B1HI<<8 | B1LO;			//obsahuje cislo stanice - program identification
	int blok2 = B2HI<<8 | B2LO;			//obsahuje cislo skupiny, verziu skupiny(A alebo B), info ci sa vysielaju dopravne informacie, typ vysielaneho programu
	/*blok 3 v zavislosti od skupiny obsahuje: (strany 36-38)
	 * skupina 0A - alternativne frekvencie
	 * skupina 0B - PI code - neporozumel som, preco znova, ked sa vysiela aj v prvom bloku
	 * skupina 2A - radiotext prva dvojica
	 */
	int blok3 = B3HI<<8 | B3LO;
	/*blok 4 v zavislosti od skupiny obsahuje: 	(strany 36-38)
		 * skupina 0A - nazov stanice
		 * skupina 0B - nazov stanice
		 * skupina 2A - radiotext druha dvojica
		 */
	int blok4 = B4HI<<8 | B4LO;

	printf("Identifikacia stanice: %d\r\n", blok1);		//vypiseme cislo stanice
	int skupinaCislo = (blok2 & 0xF000) >>12;
	char skupinaZnak;
	if((blok2 & 0x800)>>11 == 1){
		skupinaZnak = 'B';
	}
	else skupinaZnak = 'A';
	int typProgramu = (blok2 & 0x3E0) >> 5;
	printf("Typ vysielania: %s", (getNameTypeOfProgram(typProgramu)).c_str());
	printf("Identifikacia skupiny: %d%c\r\n", skupinaCislo, skupinaZnak);	//strana 36 spodny obrazok vymaskujeme si prve 4 bity zlava pomocou AND aby sme dostali cislo skupiny (0b1111 0000 0000 0000 je hexa ako 0xf000)

	if((blok2 & 0x400)>>10 == 1){							//vymaskujeme si 1 bit urcujuci, ci sa vysielaju dopravne informacie (0b0000 0100 0000 0000 je hexa 0x400)
		printf("Dopravni spravy jsou vysilany");
	}
	else {
		printf("Dopravni spravy nejsou vysilany");
	}
}

/*void checkQualityOfSignal(){
	uint8_t S1, S2, isStation, STBL, RSSI, SNR, MULT, FREQ;
	uint8_t ack = 0;
	I2C_Start();
	ack |= I2C_Output( SI4735_address | W );
	ack |= I2C_Output( 0x23 );			// FM_RSQ_STATUS
	ack |= I2C_Output( 0x00 );			// ARG1
	// repeated start
	I2C_Start();
	ack |= I2C_Output( SI4735_address | R );	// change direction of communication - read data
	S1 = I2C_Input();
	I2C_Ack();
	S2 = I2C_Input();
	I2C_Ack();
	isStation = I2C_Input() & 1;			//posledny bit urcuje, ci bola nejaka stanica rozpoznana na tejto stanici, vymaskujeme si do ANDom s cislom 1 - 0b00000001 binarne, vid strana 35 signal quality
	I2C_Ack();
	STBL = I2C_Input();
	I2C_Ack();
	RSSI = I2C_Input();
	I2C_Ack();
	SNR = I2C_Input();
	I2C_Ack();
	MULT = I2C_Input();
	I2C_Ack();
	FREQ = I2C_Input();
	I2C_NAck();
	I2C_Stop();

	if ( ack != 0 ){
		printf( "Communication error!\r\n" );
		return;
	}
	if(isStation == 1){
		printf("Na aktualnej frekvencii bola najdena stanica.");
	}
	printf("Sila signalu: %d\r\n", RSSI );
	printf("Kvalita signalu: %d\r\n", SNR );
}*/

void readTunedFrequency(){
	uint8_t S1, S2, RSSI, SNR, MULT, CAP, freq;		//do tychto premennych si nacitame odpoved z radia, vid strana 35 status of receiver
	uint8_t ack = 0;
	I2C_Start();								//zaciatok komunikacie
	ack |= I2C_Output( SI4735_address | W );	//zaadresovanie radia
	ack |= I2C_Output( 0x22 );			// FM_TUNE_STATUS - poziadavka na odoslanie aktualne naladenej frekvencie
	ack |= I2C_Output( 0x00 );			// ARG1
	// repeated start
	I2C_Start();					//zopakovany start, zmenime smer komunikacie zo zapisu na citanie
	ack |= I2C_Output( SI4735_address | R );	// change direction of communication - read data
	S1 = I2C_Input();
	I2C_Ack();
	S2 = I2C_Input();
	I2C_Ack();
	freq = (int) I2C_Input() << 8;
	I2C_Ack();
	freq |= I2C_Input();
	I2C_Ack();
	RSSI = I2C_Input();
	I2C_Ack();
	SNR = I2C_Input();
	I2C_Ack();
	MULT = I2C_Input();
	I2C_Ack();
	CAP = I2C_Input();
	I2C_NAck();					//koniec citania, negovany ACK
	I2C_Stop();					//koniec komunikacie
	if ( ack != 0 )
		printf( "ERROR!\r\n" );
	else
		printf( "Tuned frequency: %d.%dMHz\r\n", freq / 100, freq % 100 );
}