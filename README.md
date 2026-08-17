# Mico's Pokémon Emerald Legacy

[![Build & Release](https://github.com/Mickosis/Mico_Emerald_Legacy/actions/workflows/build_and_release.yml/badge.svg)](https://github.com/Mickosis/Mico_Emerald_Legacy/actions)
[![Release](https://img.shields.io/github/v/release/Mickosis/Mico_Emerald_Legacy?style=for-the-badge&logo=github)](https://github.com/Mickosis/Mico_Emerald_Legacy/releases/latest)
[![License](https://img.shields.io/badge/license-MIT-blue.svg?style=for-the-badge)](LICENSE)

**Mico's Pokémon Emerald Legacy** is a customized enhancement built directly on top of [Pokémon Emerald Legacy](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy) by [TheSmithPlays](https://www.youtube.com/@smithplayspokemon) and [cRz-Shadows](https://github.com/cRz-Shadows). 

This fork brings together the most popular modern **Quality of Life (QoL)** and convenience features while **strictly preserving 100% authentic base Pokémon stats, movesets, learnsets, encounters, and battle mechanics**.

---

## 💾 Save File Compatibility

> [!IMPORTANT]
> **100% Compatible with Base Pokémon Emerald Legacy Saves!**
> Memory structures and save block offsets match base *Emerald Legacy* byte-for-byte. You can safely drop your existing `.sav` / `.dsv` save files straight into this ROM and continue your playthrough seamlessly!

---

## 🎮 Key Features & Enhancements

### 🐾 Visuals & Overworld Followers
- **Overworld Follower Pokémon**: Full Generation 1–3 Pokémon (all 386 species + shiny forms) follow behind the player in the overworld!
- **Interactive Dialogue & Emotions**: Turn around and press **A** to interact with your lead Pokémon. Your Pokémon responds with unique emotional reactions, sounds, and text dialogues based on friendship, status conditions, weather, map environment, and type effectiveness.
- **Always Enabled by Default**: Followers are active whenever you have a healthy party Pokémon without requiring complex configuration menus.
- **Authentic Vanilla Emerald Legacy Core**: Every single Pokémon base stat, learnset, TM/HM distribution, encounter table, and battle mechanic remains 100% authentic to base *Pokémon Emerald Legacy*.

### 🎒 Quality of Life & Training
- **EXP. All**: Key Item given by Mr. Stone at Devon Corp after delivering Steven's letter. Can be toggled On/Off in the Key Items pocket or registered to `SELECT`. When enabled, 50% of battle experience goes to participating Pokémon and 50% is shared evenly across all party members (with full EV gains for all recipients). Existing saves can talk to Mr. Stone to receive it immediately.
- **HM Field Move Quality of Life**: Pokémon in your party **no longer need to have HM moves in their 4 active moveslots** to use them in the field! As long as you possess the respective Gym Badge, have the HM in your Bag, and have at least one party Pokémon compatible with the move, you can clear obstacles and use field moves (including `FLY` and `FLASH` from the Party Menu) seamlessly.

### 🛡️ Strictly Vanilla Pokémon Balance
- ❌ **No stat changes** to Pokémon.
- ❌ **No learnset or moveset changes**.
- ❌ **No type chart / physical-special modifications**.
- ❌ **No artificial difficulty or Kaizo shifts**.

---

## 🕹️ Download & How to Patch

1. Download the latest **`Micos_Emerald_Legacy.bps`** patch from the [Releases Page](https://github.com/Mickosis/Mico_Emerald_Legacy/releases/latest).
2. Visit [Marc Robledo's ROM Patcher JS](https://marcrobledo.com/RomPatcher.js/) (or use Floating IPS / FLIPS).
3. Select your clean **Pokémon Emerald (USA, Europe)** ROM as the Source.
4. Select **`Micos_Emerald_Legacy.bps`** as the Patch file.
5. Click **Apply patch** to generate your `.gba` file!

---

## 🛠️ Building from Source

To compile the ROM locally on macOS or Linux:

```bash
# Clone the repository
git clone https://github.com/Mickosis/Mico_Emerald_Legacy.git
cd Mico_Emerald_Legacy

# Install dependencies (macOS via Homebrew)
brew install arm-none-eabi-binutils gcc

# Compile tools & ROM
make -j$(sysctl -n hw.ncpu)
```

---

## 🙏 Credits & Acknowledgements

### Original Emerald Legacy Creators:
- **TheSmithPlays** - Project Manager and Developer
- **cRz Shadows** - Lead Developer
- **Weebra, Aerogod, Disq, Isona, ZuperZACH, Karlos, Regi** - Developers & Artists

### Feature Implementation & Code Contributions:
- **Exclsior** - Follower Pokémon system, dynamic surfing sprites, stat editor, nature mints, ability capsules, secret base flying, and egg move tutor integration.
- **Pret Community (pokeemerald)** - Disassembly base, tutorials, and reverse-engineering tooling.
- **Voloved, Ghoulslash, ExpoSeed, Lunos, Mkol103, FieryMewtwo, TheXaman, LOuroboros, Jaizu, Buffel Saft, AkimotoBubble, Scyrous** - Individual feature engines and engine modifications.
