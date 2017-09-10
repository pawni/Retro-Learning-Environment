/* *****************************************************************************
 * The line 67 is based on Xitari's code, from Google Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 * *****************************************************************************
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

#ifndef __POKEMON_SETTINGS_HPP__
#define __POKEMON_SETTINGS_HPP__

#include "../GameboySettings.hpp"
#include <unordered_set>
#include <queue>

namespace rle {

class PokemonSettings : public GameboySettings {

    public:

		PokemonSettings();

        // reset
        void reset();

        // the rom-name
        const char* rom() const { return "pokemon_red"; }

        // create a new instance of the rom
        RomSettings* clone() const;

        // process the latest information from ALE
        void step(const RleSystem& system);

        // saves the state of the rom settings
        void saveState( Serializer & ser );

        // loads the state of the rom settings
        void loadState( Deserializer & des );

        virtual const int lives() { return 0; }

        virtual ActionVect getStartingActions();
        int readRam(const RleSystem* system, int offset);

    private:
        int m_pok1_8;
	int m_pok9_16;
	int m_pok17_24;
	int m_pok25_32;
	int m_pok33_40;
	int m_pok41_48;
	int m_pok49_56;
	int m_pok57_64;
	int m_pok65_72;
	int m_pok73_80;
	int m_pok81_88;
	int m_pok89_96;
	int m_pok97_104;
	int m_pok105_112;
	int m_pok113_120;
	int m_pok121_128;
	int m_pok129_136;
	int m_pok137_144;
	int m_pok145_152;

        int m_badges;
	int m_won_battles;
};

} // namespace rle

#endif // __POKEMON_SETTINGS_HPP__
