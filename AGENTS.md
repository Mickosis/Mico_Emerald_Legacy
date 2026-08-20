# 🤖 Agent Instructions & Repository Guidelines

Welcome to **Pokémon Modern Emerald**. This document serves as the permanent system instructions for all AI coding agents (and human developers) contributing to this codebase.

---

## 🏛️ Core Philosophy & Pillars

1. **Strict Vanilla Balance & Integrity**:
   - **DO NOT** modify Pokémon base stats, level-up learnsets, TM/HM learnsets, moves, evolutions, or wild encounter rosters unless explicitly directed by the user.
   - Any added features must focus on Quality of Life (QoL), convenience, and visual excellence while respecting Generation 3 game balance.

2. **Save File Compatibility Protocol (CRITICAL)**:
   - **NEVER** shift field offsets or increase the size of `struct SaveBlock1` (`0x3D88`), `struct SaveBlock2`, or `struct Pokemon`.
   - Any new save data (such as warps, flags, or configuration variables) **MUST** utilize pre-existing unused padding blocks (e.g. `unused_3598[0x18]`) rather than inserting new fields in the middle of save structs.
   - Always verify `git diff include/global.h` to confirm that all offsets remain 100% byte-for-byte compatible with base *Pokémon Emerald Legacy* (`cRz-Shadows/Pokemon_Emerald_Legacy`).

3. **Documentation Synchronization Protocol**:
   - Whenever a feature is added, modified, or removed, **always update `README.md`** immediately. `README.md` is the single source of truth for all feature descriptions, mechanics, and guides.

4. **Automated CI/CD & Release Protocol**:
   - Building the ROM and updating GitHub Releases is 100% automated via GitHub Actions (`.github/workflows/build_and_release.yml`).
   - Every release automatically includes:
     1. The compiled patch file: **`Modern_Emerald.bps`** (100% clean, legal distribution)
     2. An automated commit changelog, quick patching instructions, and link to `README.md`.
   - The compiled ROM (**`pokeemerald.gba`**) is stored as a private GitHub Actions workflow artifact.

---

## 🌿 Development & Branching Workflow

1. **Feature Branching Protocol**:
   - When beginning a new feature or multi-step system overhaul, **always ask the user** if they would like to create a dedicated feature branch (e.g. `feature/<feature-name>`) to keep `main` stable.

2. **One Feature per Commit Protocol**:
   - Keep commits clean, isolated, and granular: **1 distinct feature or bug fix per commit**.
   - Build only at the end of the feature or when validating for testing to conserve time and resources.

3. **Wild Pokémon & Encounter Generation Protocol**:
   - Always use the canonical engine function `CreateWildMon(speciesId, level)` for all battle encounters (OWEs, fishing, scripted spawns) rather than manual `CreateMon` calls, guaranteeing legal Trainer IDs, valid checksums, and preventing Bad EGG corruptions upon catching.

4. **Overworld & Follower Coexistence**:
   - Follower Pokémon and wild overworld spawns share the GBA 16-sprite object event limit. Always use dynamic replacement routines (`TryAndDespawnOldestGeneratedOWE_ToFreeObject`) to prevent sprite starvation crashes.

5. **Test Patch Destination Protocol**:
   - When generating local test `.bps` patches for verification, **always ask the user** for their preferred destination folder (e.g. `Downloads/`, `Desktop/`) rather than hardcoding a destination path.

---

## 🏷️ Commit Message & Semantic Versioning Rules

The repository automatically calculates version numbers and publishes GitHub Releases on push based on Conventional Commit prefixes:

| Commit Prefix | Version Bump | Example Commit Message | Description |
|---------------|--------------|------------------------|-------------|
| `feat:` | **MINOR** (`v1.0.0` → `v1.1.0`) | `feat: add post-game egg move tutor` | New user-facing feature or QoL |
| `fix:` | **PATCH** (`v1.0.0` → `v1.0.1`) | `fix: correct SaveBlock1 offset alignment` | Bug fix or alignment patch |
| `docs:` / `chore:` | **PATCH** (`v1.0.0` → `v1.0.1`) | `docs: update readme with new features` | Maintenance or documentation |
| `BREAKING CHANGE:` | **MAJOR** (`v1.0.0` → `v2.0.0`) | `feat!: overhaul memory structures` | Incompatible breaking change |

> [!IMPORTANT]
> **Always prefix your commit messages** with `feat:`, `fix:`, or `docs:` so the automated CI pipeline increments the version number appropriately and generates a clear changelog!

---

## 🛠️ Build & Verification Quick Reference

```bash
# Fast local compilation
./build_local.sh

# Or compile tools & ROM manually (macOS / Linux)
make -f make_tools.mk -j$(nproc 2>/dev/null || sysctl -n hw.ncpu)
make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu)

# Generate local test BPS patch against clean Emerald base (ask user for preferred destination directory)
python3 tools/make_bps.py vanilla_emerald.gba pokeemerald.gba <preferred_path>/Modern_Emerald_Test.bps

# Check Git status & diffs
git status
git diff include/global.h
```
