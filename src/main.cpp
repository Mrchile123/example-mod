#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // 1. Revisamos si el Safe Mode está activado en los ajustes
        bool isSafeMode = Mod::get()->getSettingValue<bool>("safe-mode");

        if (isSafeMode) {
            log::info("Safe Mode activo: No se entregarán recompensas reales.");
            
            // Opcional: Mostrar un aviso visual pequeño
            auto label = CCLabelBMFont::create("Safe Mode: ON", "goldFont.fnt");
            label->setScale(0.5f);
            label->setPosition({100, 20});
            this->addChild(label);
        } else {
            // 2. Si el Safe Mode está APAGADO, damos la recompensa
            // Ejemplo: Dar 5000 diamantes (SOLO SI EL USUARIO LO QUISO)
            auto gsm = GameStatsManager::sharedState();
            gsm->setStat("14", 5000); // "14" es el ID interno de los diamantes
            
            log::info("¡Recompensas entregadas! Ten cuidado con el baneo.");
        }

        return true;
    }
};
