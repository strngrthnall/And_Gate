#include "plugin.hpp"

struct GateState {
    bool is_active;
};

// --- DECLARAÇÃO FFI ---
// Diz ao C++ que esta função existe em algum lugar (na nossa lib Rust)
extern "C" {
    float process_schmitt_and(float input_a, float input_b, GateState* state_a, GateState* state_b);
}
// ----------------------

struct AndGateModule : Module {
    enum ParamId { NUM_PARAMS };
    enum InputId {
        INPUT_A,
        INPUT_B,
        NUM_INPUTS
    };
    enum OutputId {
        OUTPUT_RESULT,
        NUM_OUTPUTS
    };
    enum LightId { NUM_LIGHTS };

    GateState stateA = {false};
    GateState stateB = {false};

    AndGateModule() {
        config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
        configInput(INPUT_A, "Entrada A");
        configInput(INPUT_B, "Entrada B");
        configOutput(OUTPUT_RESULT, "Saída AND");
    }

    void process(const ProcessArgs& args) override {
        float in_a = inputs[INPUT_A].getVoltage();
        float in_b = inputs[INPUT_B].getVoltage();

        // Passamos o endereço de memória (&) das nossas variáveis de estado para o Rust alterar
        float out_val = process_schmitt_and(in_a, in_b, &stateA, &stateB);

        outputs[OUTPUT_RESULT].setVoltage(out_val);
    }
};

struct AndGateWidget : ModuleWidget {
    AndGateWidget(AndGateModule* module) {
        setModule(module);
        setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/AndGate.svg")));

        // Adicione seus Ports (Parafusos) aqui.
        // Exemplo posicional (ajuste as coordenadas x,y):
        addInput(createInputCentered<PJ301MPort>(mm2px(Vec(15, 40)), module, AndGateModule::INPUT_A));
        addInput(createInputCentered<PJ301MPort>(mm2px(Vec(15, 70)), module, AndGateModule::INPUT_B));
        addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(15, 100)), module, AndGateModule::OUTPUT_RESULT));
    }
};

Model* modelAndGate = createModel<AndGateModule, AndGateWidget>("AndGate");