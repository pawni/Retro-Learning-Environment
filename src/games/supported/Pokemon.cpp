/* *****************************************************************************
 * A.L.E (Arcade Learning Environment)
 * Copyright (c) 2009-2013 by Yavar Naddaf, Joel Veness, Marc G. Bellemare and
 *   the Reinforcement Learning and Artificial Intelligence Laboratory
 * Released under the GNU General Public License; see License.txt for details.
 *
 * Based on: Stella  --  "An Atari 2600 VCS Emulator"
 * Copyright (c) 1995-2007 by Bradford W. Mott and the Stella team
 *
 * *****************************************************************************
 */
#include "../RomUtils.hpp"
#include <iomanip>
#include <bitset>

#include "../RomUtils.hpp"
#include "RleSystem.hxx"
#include "Pokemon.hpp"

using namespace rle;


PokemonSettings::PokemonSettings() {
    reset();

    minimalActions = {	JOYPAD_NOOP,
						JOYPAD_LEFT,
						JOYPAD_RIGHT,
						JOYPAD_UP,
						JOYPAD_DOWN,
						JOYPAD_A,
						JOYPAD_B,
						JOYPAD_SELECT,
						JOYPAD_START,	
    };
}


/* create a new instance of the rom */
RomSettings* PokemonSettings::clone() const {
    RomSettings* rval = new PokemonSettings();
    *rval = *this;
    return rval;
}


/* process the latest information from ALE */
void PokemonSettings::step(const RleSystem& system) {
	// update the reward
	reward_t pok1_8 = readRam(&system, 0xd2f7);
	reward_t pok9_16 = readRam(&system, 0xd2f8);
	reward_t pok17_24 = readRam(&system, 0xd2f9);
	reward_t pok25_32 = readRam(&system, 0xd2fa);
	reward_t pok33_40 = readRam(&system, 0xd2fb);
	reward_t pok41_48 = readRam(&system, 0xd2fc);
	reward_t pok49_56 = readRam(&system, 0xd2fd);
	reward_t pok57_64 = readRam(&system, 0xd2fe);
	reward_t pok65_72 = readRam(&system, 0xd2ff);
	reward_t pok73_80 = readRam(&system, 0xd300);
	reward_t pok81_88 = readRam(&system, 0xd301);
	reward_t pok89_96 = readRam(&system, 0xd302);
	reward_t pok97_104 = readRam(&system, 0xd303);
	reward_t pok105_112 = readRam(&system, 0xd304);
	reward_t pok113_120 = readRam(&system, 0xd305);
	reward_t pok121_128 = readRam(&system, 0xd306);
	reward_t pok129_136 = readRam(&system, 0xd307);
	reward_t pok137_144 = readRam(&system, 0xd308);
	reward_t pok145_152 = readRam(&system, 0xd309);

	reward_t badges = readRam(&system, 0xd356);

	int new_pok = 0;
	
	new_pok = new_pok + std::bitset<8>((pok1_8 ^ m_pok1_8)).count();
	new_pok = new_pok + std::bitset<8>((pok9_16 ^ m_pok9_16)).count();
	new_pok = new_pok + std::bitset<8>((pok17_24 ^ m_pok17_24)).count();
	new_pok = new_pok + std::bitset<8>((pok25_32 ^ m_pok25_32)).count();
	new_pok = new_pok + std::bitset<8>((pok33_40 ^ m_pok33_40)).count();
	new_pok = new_pok + std::bitset<8>((pok41_48 ^ m_pok41_48)).count();
	new_pok = new_pok + std::bitset<8>((pok49_56 ^ m_pok49_56)).count();
	new_pok = new_pok + std::bitset<8>((pok57_64 ^ m_pok57_64)).count();
	new_pok = new_pok + std::bitset<8>((pok65_72 ^ m_pok65_72)).count();
	new_pok = new_pok + std::bitset<8>((pok73_80 ^ m_pok73_80)).count();
	new_pok = new_pok + std::bitset<8>((pok81_88 ^ m_pok81_88)).count();
	new_pok = new_pok + std::bitset<8>((pok89_96 ^ m_pok89_96)).count();
	new_pok = new_pok + std::bitset<8>((pok97_104 ^ m_pok97_104)).count();
	new_pok = new_pok + std::bitset<8>((pok105_112 ^ m_pok105_112)).count();
	new_pok = new_pok + std::bitset<8>((pok113_120 ^ m_pok113_120)).count();
	new_pok = new_pok + std::bitset<8>((pok121_128 ^ m_pok121_128)).count();
	new_pok = new_pok + std::bitset<8>((pok129_136 ^ m_pok129_136)).count();
	new_pok = new_pok + std::bitset<8>((pok137_144 ^ m_pok137_144)).count();
	new_pok = new_pok + std::bitset<8>((pok145_152 ^ m_pok145_152)).count();

	m_pok1_8 = pok1_8;
	m_pok9_16 = pok9_16;
	m_pok17_24 = pok17_24;
	m_pok25_32 = pok25_32;
	m_pok33_40 = pok33_40;
	m_pok41_48 = pok41_48;
	m_pok49_56 = pok49_56;
	m_pok57_64 = pok57_64;
	m_pok65_72 = pok65_72;
	m_pok73_80 = pok73_80;
	m_pok81_88 = pok81_88;
	m_pok89_96 = pok89_96;
	m_pok97_104 = pok97_104;
	m_pok105_112 = pok105_112;
	m_pok113_120 = pok113_120;
	m_pok121_128 = pok121_128;
	m_pok129_136 = pok129_136;
	m_pok137_144 = pok137_144;
	m_pok145_152 = pok145_152;

	int new_badges = std::bitset<8>((badges ^ m_badges)).count();

	m_reward = new_badges * 10 + new_pok;

	m_terminal = false;
	if(m_badges == 255){
		m_terminal = true;
	}
}


/* reset the state of the game */
void PokemonSettings::reset() {

	m_pok1_8   = 0;
	m_pok9_16 = 0;
	m_pok17_24 = 0;
	m_pok25_32 = 0;
	m_pok33_40 = 0;
	m_pok41_48 = 0;
	m_pok49_56 = 0;
	m_pok57_64 = 0;
	m_pok65_72 = 0;
	m_pok73_80 = 0;
	m_pok81_88 = 0;
	m_pok89_96 = 0;
	m_pok97_104 = 0;
	m_pok105_112 = 0;
	m_pok113_120 = 0;
	m_pok121_128 = 0;
	m_pok129_136 = 0;
	m_pok137_144 = 0;
	m_pok145_152 = 0;

	m_badges    = 0;
	m_won_battles   = 0;
	m_terminal = false; 
}



/* saves the state of the rom settings */
void PokemonSettings::saveState( Serializer & ser ) {
	ser.putInt(m_pok1_8);
	ser.putInt(m_pok9_16);
	ser.putInt(m_pok17_24);
	ser.putInt(m_pok25_32);
	ser.putInt(m_pok33_40);
	ser.putInt(m_pok41_48);
	ser.putInt(m_pok49_56);
	ser.putInt(m_pok57_64);
	ser.putInt(m_pok65_72);
	ser.putInt(m_pok73_80);
	ser.putInt(m_pok81_88);
	ser.putInt(m_pok89_96);
	ser.putInt(m_pok97_104);
	ser.putInt(m_pok105_112);
	ser.putInt(m_pok113_120);
	ser.putInt(m_pok121_128);
	ser.putInt(m_pok129_136);
	ser.putInt(m_pok137_144);
	ser.putInt(m_pok145_152);

	ser.putInt(m_badges);
	ser.putInt(m_won_battles);
	ser.putBool(m_terminal); 
}

// loads the state of the rom settings
void PokemonSettings::loadState( Deserializer & des ) {
	m_pok1_8 = des.getInt();
	m_pok9_16 = des.getInt();
	m_pok17_24 = des.getInt();
	m_pok25_32 = des.getInt();
	m_pok33_40 = des.getInt();
	m_pok41_48 = des.getInt();
	m_pok49_56 = des.getInt();
	m_pok57_64 = des.getInt();
	m_pok65_72 = des.getInt();
	m_pok73_80 = des.getInt();
	m_pok81_88 = des.getInt();
	m_pok89_96 = des.getInt();
	m_pok97_104 = des.getInt();
	m_pok105_112 = des.getInt();
	m_pok113_120 = des.getInt();
	m_pok121_128 = des.getInt();
	m_pok129_136 = des.getInt();
	m_pok137_144 = des.getInt();
	m_pok145_152 = des.getInt();

	m_badges = des.getInt();
	m_won_battles = des.getInt();
	m_terminal = des.getBool(); 
}


ActionVect PokemonSettings::getStartingActions(){
	ActionVect startingActions;
	int num_of_nops(100);

	// wait for intro to end
	INSERT_NOPS(11*num_of_nops)
	// main screen
	INSERT_ACTION_SINGLE_A(JOYPAD_START)
	// wait text
	INSERT_NOPS(1*num_of_nops)
	// new game
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	// text
	INSERT_NOPS(1*num_of_nops)
	// text 
	INSERT_ACTION_SINGLE_A(JOYPAD_A)

	INSERT_NOPS(1*num_of_nops)

	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)

	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)

	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)

	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)

	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)

	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	// select name
	INSERT_ACTION_SINGLE_A(JOYPAD_DOWN)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)

	// text
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)

	// select rival name
	INSERT_ACTION_SINGLE_A(JOYPAD_DOWN)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)

	// text
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(1*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)
	INSERT_NOPS(5*num_of_nops)
	INSERT_ACTION_SINGLE_A(JOYPAD_DOWN)
	INSERT_ACTION_SINGLE_A(JOYPAD_A)

	return startingActions;
}

