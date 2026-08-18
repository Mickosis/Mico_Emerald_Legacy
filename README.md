# 🌟 Mico's Pokémon Emerald Legacy

[![Build & Release](https://github.com/Mickosis/Mico_Emerald_Legacy/actions/workflows/build_and_release.yml/badge.svg)](https://github.com/Mickosis/Mico_Emerald_Legacy/actions)
[![Release](https://img.shields.io/github/v/release/Mickosis/Mico_Emerald_Legacy?style=for-the-badge&logo=github)](https://github.com/Mickosis/Mico_Emerald_Legacy/releases/latest)
[![License](https://img.shields.io/badge/license-MIT-blue.svg?style=for-the-badge)](LICENSE)

**Mico's Pokémon Emerald Legacy** is an enhanced edition of *Pokémon Emerald* built on top of [Pokémon Emerald Legacy](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy). It delivers a modern, vibrant Hoenn adventure with **Overworld Wild Encounters**, **Follower Pokémon**, **Custom Surfing Sprites**, and essential **Quality of Life upgrades**—while strictly preserving 100% authentic Generation 3 battle mechanics, Pokémon stats, learnsets, and game balance.

---

## 🎮 Key Features

### 🌿 Overworld Wild Encounters (OWEs)
Wild Pokémon physically appear and roam throughout tall grass, caves, water routes, and facilities across Hoenn!
- **Dynamic Behaviors**: Wild Pokémon react to your presence with distinct movement personalities:
  - **Wander**: Peacefully roams around its natural habitat patch.
  - **Chase**: Aggressive species (e.g. Zubat, Aron, Poochyena) spot you and charge towards you.
  - **Flee**: Timid Pokémon (e.g. Ralts, Skitty) get startled and run away when you approach.
  - **Watch**: Curious species stand in place and observe your movements.
  - **Approach**: Friendly Pokémon slowly walk towards you.
  - **Teleport / Despawn**: Rare species like Abra vanish if they spot you before you reach them.
- **🎧 Spatial 3D Directional Audio**: Route ambient cries originate directly from the physical Pokémon on screen with real-time stereo panning (left/right speaker) and distance-based volume scaling.
- **✨ Overworld Shiny Sparkles**: Shiny Pokémon render with their authentic shiny overworld palettes and play a dazzling star sparkle animation upon spawning. Shinies will **never despawn** when moving off-screen on the same map.
- **🌸 Sweet Scent Swarms**: Using the move **Sweet Scent** in the overworld instantly attracts a swarm of wild Pokémon rushing in from all directions.
- **🛡️ Repel Ward & Collision Bypass**: Using a Repel cleans lower-level Pokémon off your screen, and you can sprint or bike through lower-level wild Pokémon without triggering collision battles.
- **🏛️ Dungeon & Facility Spawns**: Overworld encounters are fully active in the **Battle Pyramid**, **Battle Pike**, and **Safari Zone** (with genuine Safari battle mechanics).
- **🐟 Secret Feebas Tile Detection**: Wild Feebas appears visibly swimming on the 6 special Route 119 fishing tiles and stays persistent once discovered.
- **❤️ Party Lead Ability Reactions**: 
  - **Cute Charm**: Wild Pokémon react with a **Heart ❤️ emote** and walk towards your lead.
  - **Intimidate**: Lower-level wild Pokémon get startled, hesitate, and **flee** from your lead.

---

### 🐾 Overworld Follower Pokémon
- **All 386 Pokémon + Shinies**: Every single Pokémon from Generations 1–3 follows directly behind you in the overworld!
- **Interactive Dialogue & Emotions**: Turn around and press **A** to interact with your follower. They react with unique emotes, sounds, and text dialogues based on friendship, status conditions, weather, map environment, and type effectiveness.

---

### 🏄 Custom Surfing Sprites
- Over **79 Pokémon species** across Generations 1–3 render with unique, dedicated surfing overworld sprites and normal/shiny palettes (including Lapras, Blastoise, Kyogre, Swampert, Wailord, Gyarados, Latios, Latias, Rayquaza, and more), seamlessly falling back to the classic surf blob for other species.

---

### 🎒 Quality of Life & Training
- **EXP. All**: Key Item obtained from Mr. Stone at Devon Corp after delivering Steven's letter. Can be toggled On/Off in your Key Items pocket or registered to `SELECT`. When enabled, 50% of battle EXP goes to active battlers and 50% is shared across party members (with full EV gains for all recipients).
- **HM Field Move Freedom**: Party Pokémon **no longer need HM moves occupying their 4 combat moveslots** to use them in the field! Having the Gym Badge, the HM in your Bag, and a compatible Pokémon in your party is all you need to clear obstacles and use field moves (including `FLY` and `FLASH`).

---

## 🕹️ Download & How to Patch

1. Download the latest **`Micos_Emerald_Legacy.bps`** patch from the [Releases Page](https://github.com/Mickosis/Mico_Emerald_Legacy/releases/latest).
2. Open [Marc Robledo's ROM Patcher JS](https://marcrobledo.com/RomPatcher.js/).
3. Select your clean **Pokémon Emerald (USA, Europe)** ROM as the Source.
4. Select **`Micos_Emerald_Legacy.bps`** as the Patch file.
5. Click **Apply patch** to generate your `.gba` file!

---

## 🛠️ Building from Source

```bash
# Clone the repository
git clone https://github.com/Mickosis/Mico_Emerald_Legacy.git
cd Mico_Emerald_Legacy

# Compile tools & ROM (Linux / macOS)
make -f make_tools.mk -j$(nproc 2>/dev/null || sysctl -n hw.ncpu)
make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu)

# Generate .bps patch
python3 tools/make_bps.py vanilla_emerald.gba pokeemerald.gba Micos_Emerald_Legacy.bps
```

---

## 🙏 Credits & Acknowledgements

- **Original Emerald Legacy Team**: [TheSmithPlays](https://www.youtube.com/@smithplayspokemon), [cRz-Shadows](https://github.com/cRz-Shadows), Weebra, Aerogod, Disq, Isona, ZuperZACH, Karlos, Regi.
- **Overworld Wild Encounters (OWE)**: [HashtagMarky](https://github.com/HashtagMarky) & [Bivurnum](https://github.com/bivurnum) (PR #8434 / pokeemerald-expansion).
- **Follower Pokémon & Custom Overworld Sprites**: [Exclsior](https://github.com/Exclsior) (Follower Pokémon engine, dynamic surfing sprites), Voloved, Ghoulslash, ExpoSeed, Lunos, Mkol103, FieryMewtwo, TheXaman, LOuroboros, Jaizu, Buffel Saft, AkimotoBubble, Scyrous.
- **Pret Community**: [pokeemerald](https://github.com/pret/pokeemerald) disassembly project and tooling.
