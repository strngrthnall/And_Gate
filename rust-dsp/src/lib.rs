#[repr(C)] // Garante que o C++ entenda o layout da memória dessa struct
pub struct GateState {
    is_active: bool, // O estado interno (memória)
}

#[no_mangle]
pub extern "C" fn process_schmitt_and(
    input_a: f32, 
    input_b: f32, 
    state_a: &mut GateState, // Recebemos a memória do C++ para ler/escrever
    state_b: &mut GateState
) -> f32 {
    // Parâmetros de Engenharia (Constantes)
    const THRESHOLD_HIGH: f32 = 2.0; // Liga acima de 2V
    const THRESHOLD_LOW: f32 = 1.0;  // Desliga abaixo de 1V
    const OUTPUT_HIGH: f32 = 10.0;
    const OUTPUT_LOW: f32 = 0.0;

    // Lógica do Schmitt Trigger para Entrada A
    if input_a >= THRESHOLD_HIGH {
        state_a.is_active = true;
    } else if input_a <= THRESHOLD_LOW {
        state_a.is_active = false;
    }
    // Se estiver entre LOW e HIGH, state_a.is_active não muda (Histerese)

    // Lógica do Schmitt Trigger para Entrada B
    if input_b >= THRESHOLD_HIGH {
        state_b.is_active = true;
    } else if input_b <= THRESHOLD_LOW {
        state_b.is_active = false;
    }

    // A Lógica AND final baseada nos estados limpos
    if state_a.is_active && state_b.is_active {
        OUTPUT_HIGH
    } else {
        OUTPUT_LOW
    }
}