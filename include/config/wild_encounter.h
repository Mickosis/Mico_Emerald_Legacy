#ifndef GUARD_CONFIG_WILD_ENCOUNTER_OW_H
#define GUARD_CONFIG_WILD_ENCOUNTER_OW_H

// Vanilla random encounters — keep TRUE to have both random + OWE encounters
#define WE_VANILLA_RANDOM                   FALSE

// Overworld Wild Encounters (OWEs) — requires OW_POKEMON_OBJECT_EVENTS TRUE
#define WE_OW_ENCOUNTERS                    TRUE
#define WE_OWE_FLAG_DISABLED                0       // Replace 0 with a flag to disable generated OWEs.
#define WE_OWE_SPECIAL_ONLY                 FALSE   // If TRUE, generated OWEs can only be special spawns.
#define WE_OWE_BATTLE_PIKE                  TRUE    // If TRUE, OWEs can spawn in the Battle Pike.
#define WE_OWE_BATTLE_PYRAMID               TRUE    // If TRUE, OWEs can spawn in the Battle Pyramid.
#define WE_OWE_RESTRICT_METATILE            TRUE    // If TRUE, OWEs stay within the same encounter metatile type.
#define WE_OWE_RESTRICT_MAP                 TRUE    // If TRUE, OWEs stay within the current map bounds.
#define WE_OWE_UNRESTRICT_SIGHT             FALSE   // If TRUE, OWEs ignore movement restrictions when they can see the player.
#define WE_OWE_SPAWN_REPLACEMENT            TRUE    // If TRUE, oldest OWE objects respawn over time.
#define WE_OWE_FLEE_DESPAWN                 TRUE    // If TRUE, a fleeing OWE despawns if blocked for too long.
#define WE_OWE_SHINY_SPARKLE                TRUE    // If TRUE, shiny OWEs spawn with a sparkle animation.
#define WE_OWE_FEEBAS_SPOTS                 TRUE    // If TRUE, Feebas can appear as OWEs on special fishing tiles.
#define WE_OWE_DESPAWN_SOUND                TRUE    // If TRUE, plays SE_FLEE when an OWE despawns.
#define WE_OWE_APPROACH_FOR_BATTLE          TRUE    // If TRUE, OWEs take steps to be next to the player before battle.
#define WE_OWE_PREVENT_SHINY_DESPAWN        TRUE    // If TRUE, shiny OWEs won't despawn off-screen on the same map.
#define WE_OWE_PREVENT_FEEBAS_DESPAWN       TRUE    // If TRUE, Feebas OWEs won't despawn off-screen on the same map.
#define WE_OWE_DESPAWN_ON_ENTER_TOWN        TRUE    // If TRUE, despawns all OWEs upon entering a city or town.
#define WE_OWE_NO_REPEL_DEXNAV_COLLISION    TRUE   // If TRUE, OWEs can't be triggered by collision when Repel is active.

#endif // GUARD_CONFIG_WILD_ENCOUNTER_OW_H
