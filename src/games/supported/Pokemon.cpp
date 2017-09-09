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
	m_terminal = true;	
}


/* reset the state of the game */
void PokemonSettings::reset() {

    m_pokemons   = 0;
    m_trophies    = 0;
    m_won_battles   = 0;
    m_terminal = false; 
}



/* saves the state of the rom settings */
void PokemonSettings::saveState( Serializer & ser ) {
  ser.putInt(m_pokemons);
  ser.putInt(m_trophies);
  ser.putInt(m_won_battles);
  ser.putBool(m_terminal); 
}

// loads the state of the rom settings
void PokemonSettings::loadState( Deserializer & des ) {
  m_pokemons = des.getInt();
  m_trophies = des.getInt();
  m_won_battles = des.getInt();
  m_terminal = des.getBool(); 
}


ActionVect PokemonSettings::getStartingActions(){
	ActionVect startingActions;
	int num_of_nops(100);

	// wait for intro to end
	INSERT_NOPS(3.5*num_of_nops)
	// main Screen
	INSERT_ACTION_SINGLE_A(JOYPAD_START)
	// wait for cutscene to end
	INSERT_NOPS(11*num_of_nops)

	return startingActions;
}

