#include "plugin.hpp"

Plugin* pluginInstance;

void init(Plugin* p) {
    pluginInstance = p;
    // --- REGISTRE O MÓDULO AQUI ---
    p->addModel(modelAndGate);
}