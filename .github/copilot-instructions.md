# 🤖 Agent Instructions & Repository Guidelines

Welcome to **Mico's Pokémon Emerald Legacy**. This document serves as the permanent system instructions for all AI coding agents (and human developers) contributing to this codebase.

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
     1. The compiled patch file: **`Micos_Emerald_Legacy.bps`** (100% clean, legal distribution)
     2. An automated commit changelog, save compatibility guarantee, and link to `README.md`.
   - The compiled ROM (**`pokeemerald.gba`**) is stored as a private GitHub Actions workflow artifact.

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
# Compile tools & ROM locally (macOS / Linux)
make -f make_tools.mk -j$(nproc 2>/dev/null || sysctl -n hw.ncpu)
make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu)

# Generate .bps patch against base Emerald Legacy
python3 tools/make_bps.py base_emerald_legacy.gba pokeemerald.gba Micos_Emerald_Legacy.bps

# Check Git status & diffs
git status
git diff include/global.h
```
