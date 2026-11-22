#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

// Icons: cube, ship, ball, ufo, wave, robot, spider, swing, jetpack, etc.
class $modify(AllIconsGameManager, GameManager) {
    bool isIconUnlocked(int id, IconType type) {
        if (Mod::get()->getSettingValue<bool>("unlock-icons")) return true;
        return GameManager::isIconUnlocked(id, type);
    }

    // Color 1, Color 2 (glow colors use the Color 2 list)
    bool isColorUnlocked(int id, UnlockType type) {
        if (Mod::get()->getSettingValue<bool>("unlock-colors")) return true;
        return GameManager::isColorUnlocked(id, type);
    }
};

// Catch-all so every unlock check (garage, glow, trails, effects) passes.
class $modify(AllIconsStatsManager, GameStatsManager) {
    bool isItemUnlocked(UnlockType type, int id) {
        bool icons = Mod::get()->getSettingValue<bool>("unlock-icons");
        bool colors = Mod::get()->getSettingValue<bool>("unlock-colors");

        switch (type) {
            case UnlockType::Cube:
            case UnlockType::Ship:
            case UnlockType::Ball:
            case UnlockType::Bird:
            case UnlockType::Dart:
            case UnlockType::Robot:
            case UnlockType::Spider:
            case UnlockType::Swing:
            case UnlockType::Jetpack:
            case UnlockType::Streak:
            case UnlockType::ShipFire:
            case UnlockType::Death:
            case UnlockType::GJItem:
                if (icons) return true;
                break;
            case UnlockType::Col1:
            case UnlockType::Col2:
                if (colors) return true;
                break;
            default:
                break;
        }
        return GameStatsManager::isItemUnlocked(type, id);
    }
};
